#include "red-black-tree.h"

MyRedBlackTree::MyRedBlackTree()
{
    m_null = new Node{};
    m_null->m_color = Color::black;
    m_null->m_left = nullptr;
    m_null->m_right = nullptr;

    m_root = m_null;
}

void MyRedBlackTree::leftRotate(Node* nodeToRotate)
{
    // we switch our node with it's right x
    Node* rightChild{ nodeToRotate->m_right };
    // turn right x's left subtree into our node's right subtree
    // this preserves the bst property since none of the left subtrees of the right
    // subtrees of a node will have an element smaller than the node
    nodeToRotate->m_right = rightChild->m_left;

    if (rightChild->m_left != m_null)
    {
        // link the x's left child with our node if it exists
        rightChild->m_left->m_parent = nodeToRotate;
    }

    rightChild->m_parent = nodeToRotate->m_parent; // switch parent

    if (nodeToRotate->m_parent == m_null)
    {        // if the node was the root, set the new root
        m_root = rightChild;
    }
    else if (nodeToRotate == nodeToRotate->m_parent->m_left)
    {
        // if the node was the left x, set the new left child
        nodeToRotate->m_parent->m_left = rightChild;
    }
    else
    {
        // if the node was the right x, set the new right child
        nodeToRotate->m_parent->m_right = rightChild;
    }

    // put the node on the left
    rightChild->m_left = nodeToRotate;
    // link them
    nodeToRotate->m_parent = rightChild;
}

void MyRedBlackTree::rightRotate(Node* nodeToRotate)
{
    // now we switch our node with it's left x
    // this algorithm is symmetric to leftRotate
    Node* leftChild{ nodeToRotate->m_left };

    // turn right subtree of x into node's left subtree
    nodeToRotate->m_left = leftChild->m_right;
    if (leftChild->m_right != m_null)
    {
        // link new x with the node
        leftChild->m_right->m_parent = nodeToRotate;
    }

    // switch parents
    leftChild->m_parent = nodeToRotate->m_parent;

    if (nodeToRotate->m_parent == m_null)
    {
        m_root = leftChild;
    }
    else if (nodeToRotate == nodeToRotate->m_parent->m_left)
    {
        nodeToRotate->m_parent->m_left = leftChild;
    }
    else
    {
        nodeToRotate->m_parent->m_right = leftChild;
    }

    leftChild->m_right = nodeToRotate;
    nodeToRotate->m_parent = leftChild;
}

// works similarly to binary search tree insertion, except we color the new node red
// and call an auxiliary fixup function at the end to recolor nodes and perform rotations
void MyRedBlackTree::insertKey(int newKey)
{
    Node* newNode{ new Node{} };
    newNode->m_parent = nullptr;
    newNode->m_left = m_null;
    newNode->m_right = m_null;
    newNode->m_color = Color::red;
    newNode->m_key = newKey;

    Node* parent{ m_null };
    Node* top{ m_root };

    while (top != m_null)
    {
        // find the place for new node's parent
        parent = top;
        if (newNode->m_key < top->m_key)
        {
            top = top->m_left;
        }
        else
        {
            top = top->m_right;
        }
    }

    // link parent with new node
    newNode->m_parent = parent;

    // link new node with parent
    if (parent == m_null)
    {
        m_root = newNode;
    }
    else if (newNode->m_key < parent->m_key)
    {
        parent->m_left = newNode;
    }
    else
    {
        parent->m_right = newNode;
    }

    // set left and right to m_null to maintain proper tree structure
    newNode->m_left = m_null;
    newNode->m_right = m_null;
    // color this red to save the fifth property
    newNode->m_color = Color::red;

    // call the auxiliary function to fix property 2 and 4 that might be violated
    insertFixup(newNode);
}

void MyRedBlackTree::insertFixup(Node* newNode)
{
    // this loop maintains the following three-part invariant at the start of each iteration:
    // 1. Node newNode is red
    // 2. If newNode->m_parent is the root, the newNode->m_parent is black
    // 3. If the tree violates any properties, then it violates at most one of them (property 2 or 4)
    while (newNode->m_parent->m_color == Color::red)
    {
        // if the uncle is a left x
        if (newNode->m_parent == newNode->m_parent->m_parent->m_left)
        {
            Node* uncleNode{ newNode->m_parent->m_parent->m_right };
            // case 1: both newNode and its uncle are red
            if (uncleNode->m_color == Color::red)
            {
                // since newNode->m_parent->m_parent is black (due to the uncle being red),
                // we can color both the newNode's parent and the uncle black, fixing the problem
                // of newNode and newNode->m_parent both being red
                newNode->m_parent->m_color = Color::black;
                uncleNode->m_color = Color::black;
                // and we can color newNode->m_parent->m_parent red, thereby maintaining property 5
                newNode->m_parent->m_parent->m_color = Color::red;
                newNode = newNode->m_parent->m_parent;
                // now we repeat the while loop with the new newNode, it moved up two levels
            }
            // cases 2 and 3 aren't mutually exclusive, case 2 falls through to case 3
            // they correct the lone violation of property 4
            else
            {
                // case 2: newNode's uncle is black and newNode is a right x
                if (newNode == newNode->m_parent->m_right)
                {
                    // we simply transform this situation into case 3
                    newNode = newNode->m_parent;
                    leftRotate(newNode);
                }

                // case 3: newNode's uncle is black and newNode is a left x
                newNode->m_parent->m_color = Color::black; // since the newNode is red
                newNode->m_parent->m_parent->m_color = Color::red; // switch this also
                // make the newNode->m_parent the parent of both newNode and
                // newNode->m_parent->m_paren to maintain the red black tree properties
                rightRotate(newNode->m_parent->m_parent);
            }
        }
        // same as the first clause, left and right exchanged
        else
        {
            Node* uncleNode{ newNode->m_parent->m_parent->m_left };
            if (uncleNode->m_color == Color::red)
            {
                newNode->m_parent->m_color = Color::black;
                uncleNode->m_color = Color::black;
                newNode->m_parent->m_parent->m_color = Color::red;
                newNode = newNode->m_parent->m_parent;
            }
            else
            {
                if (newNode == newNode->m_parent->m_left)
                {
                    newNode = newNode->m_parent;
                    rightRotate(newNode);
                }

                newNode->m_parent->m_color = Color::black;
                newNode->m_parent->m_parent->m_color = Color::red;
                leftRotate(newNode->m_parent->m_parent);
            }
        }
    }

    m_root->m_color = Color::black;
}

void MyRedBlackTree::deleteKey(int keyToDelete)
{
    Node* nodeToDelete{ m_null };
    // gotta find the node first
    Node* indexNode{ m_root };
    while (indexNode != m_null)
    {
        if (indexNode->m_key == keyToDelete)
        {
            nodeToDelete = indexNode;
        }

        if (indexNode->m_key <= keyToDelete)
        {
            indexNode = indexNode->m_right;
        }
        else
        {
            indexNode = indexNode->m_left;
        }
    }

    if (nodeToDelete == m_null)
    {
        std::cout << "Key " << keyToDelete << " not found in the tree\n";
        return;
    }

    // the algorithm begins here
    // we maintain nodeToMoveOrRemove as the node either removed from the tree or moved within the tree
    Node* nodeToMoveOrRemove{ nodeToDelete };
    // keep the color of nodeToDelete since it might change
    Color originalColor{ nodeToMoveOrRemove->m_color };
    // this node moves into the nodeToMoveOrRemove's original position
    Node* x{};
    // no left child
    if (nodeToDelete->m_left == m_null)
    {
        // set the right child
        x = nodeToDelete->m_right;
        // switch the nodes
        transplant(nodeToDelete, nodeToDelete->m_right);
    }
    // no right child
    else if (nodeToDelete->m_right == m_null)
    {
        // same as if no left child
        x = nodeToDelete->m_left;
        transplant(nodeToDelete, nodeToDelete->m_left);
    }
    // if the nodeToDelete has two children
    else
    {
        // nodeToMoveOrRemove is now the successor of nodeToDelete
        // thus, it will move into nodeToDelete's position in the tree
        nodeToMoveOrRemove = findMinimum(nodeToDelete->m_right);
        // save the color of nodeToMoveOrRemove
        originalColor = nodeToMoveOrRemove->m_color;
        x = nodeToMoveOrRemove->m_right;

        // if the successor is a child of nodeToDelete
        if (nodeToMoveOrRemove->m_parent == nodeToDelete)
        {
            x->m_parent = nodeToMoveOrRemove;
        }
        else
        {
            transplant(nodeToMoveOrRemove, nodeToMoveOrRemove->m_right);
            nodeToMoveOrRemove->m_right = nodeToDelete->m_right;
            nodeToMoveOrRemove->m_right->m_parent = nodeToMoveOrRemove;
        }

        // we replace the node to delete with it's successor
        transplant(nodeToDelete, nodeToMoveOrRemove);
        // link left child
        nodeToMoveOrRemove->m_left = nodeToDelete->m_left;
        // link parent for left child
        nodeToMoveOrRemove->m_left->m_parent = nodeToMoveOrRemove;
        nodeToMoveOrRemove->m_color = nodeToDelete->m_color;
    }

    delete nodeToDelete;
    // we can safely delete or move the red node, but not a black node
    // thus we must fix the red-black tree property violations by calling deleteFixup
    if (originalColor == Color::black)
    {
        deleteFixup(x);
    }
}

// restores properties 1, 2 and 4
void MyRedBlackTree::deleteFixup(Node* node)
{
    // the goal of the loop is to move teh extra black node up the tree
    while (node != m_root && node->m_color == Color::black)
    {
        // within this loop, node always points to a nonroot doubly black node
        if (node == node->m_parent->m_left)
        {
            Node* sibling{ node->m_parent->m_right };

            if (sibling->m_color == Color::red)
            {
                // case 1: node's sibling is red, we convert this case into case 2, 3 or 4
                sibling->m_color = Color::black;
                node->m_parent->m_color = Color::red;
                leftRotate(node->m_parent);
                sibling = node->m_parent->m_right;
            }

            // only this case makes the loop repeat
            if (sibling->m_left->m_color == Color::black &&
                    sibling->m_right->m_color == Color::black)
            {
                // case 2: node's sibling is black, both of sibling's children are black
                // here we take one black off both node and sibling, leaving node with only
                // one black and leaving sibling red
                sibling->m_color = Color::red;
                // to compensate for this, we add an extra black to parent of node, which was
                // originally red or black, we do this by repeating the loop with node->parent
                // as the new node
                node = node->m_parent;
            }
            else
            {
                if (sibling->m_right->m_color == Color::black)
                {
                    // case 3: node's sibling is black, sibling's left child is red, right child is black
                    // here we can switch the colors of sibling and its left child and then
                    // perform a right rotation on sibling without violating the properties
                    sibling->m_left->m_color = Color::black;
                    sibling->m_color = Color::red;
                    rightRotate(sibling);
                    sibling = node->m_parent->m_right;
                    // the new sibling of node is now a black node with a red right child,
                    // thus we have trasnformed case 3 into case 4
                }

                // case 4: node's sibling is black, sibling's right child is red
                // here we can remove the extra black on node, making it singly black
                sibling->m_color = node->m_parent->m_color;
                node->m_parent->m_color = Color::black;
                sibling->m_right->m_color = Color::black;
                leftRotate(node->m_parent);
                // this causes teh loop to terminate
                node = m_root;
            }
        }
        // same as above with right and left exchanged
        else
        {
            Node* sibling{ node->m_parent->m_left };

            if (sibling->m_color == Color::red)
            {
                // case 1:
                sibling->m_color = Color::black;
                node->m_parent->m_color = Color::red;
                rightRotate(node->m_parent);
                sibling = node->m_parent->m_left;
            }

            if (sibling->m_right->m_color == Color::black &&
                    sibling->m_left->m_color == Color::black)
            {
                // case 2:
                sibling->m_color = Color::red;
                node = node->m_parent;
            }
            else
            {
                if (sibling->m_left->m_color == Color::black)
                {
                    // case 3:
                    sibling->m_right->m_color = Color::black;
                    sibling->m_color = Color::red;
                    leftRotate(sibling);
                    sibling = node->m_parent->m_left;
                }

                // case 4:
                sibling->m_color = node->m_parent->m_color;
                node->m_parent->m_color = Color::black;
                sibling->m_left->m_color = Color::black;
                rightRotate(node->m_parent);
                node = m_root;
            }
        }
    }

    node->m_color = Color::black;
}

void MyRedBlackTree::transplant(Node* firstNode, Node* secondNode)
{
    if (firstNode->m_parent == m_null)
    {
        m_root = secondNode;
    }
    else if (firstNode == firstNode->m_parent->m_left)
    {
        firstNode->m_parent->m_left = secondNode;
    }
    else
    {
        firstNode->m_parent->m_right = secondNode;
    }
    // switch parent, doesnt matter if secondNode is m_null:
    secondNode->m_parent = firstNode->m_parent;
}

Node* MyRedBlackTree::findMinimum(Node* node)
{
    while (node->m_left != m_null)
    {
        node = node->m_left;
    }

    return node;
}

void MyRedBlackTree::printHelper(Node* currentNode, std::string indent, bool last)
{
    if (currentNode != m_null)
    {
        std::cout << indent;

        if (last)
        {
            std::cout << "R----";
            indent += "   ";
        }
        else
        {
            std::cout << "L----";
            indent += "|  ";
        }

        std::string colorString{ currentNode->m_color == Color::red ? "Red" : "Black" };
        std::cout << currentNode->m_key << '(' << colorString << ")\n";
        printHelper(currentNode->m_left, indent, false);
        printHelper(currentNode->m_right, indent, true);
    }
}

void MyRedBlackTree::printTree()
{
    if (m_root)
    {
        printHelper(this->m_root, "", true);
    }
}
