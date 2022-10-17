#include "binary-search-tree.h"

MyBinarySearchTree::MyBinarySearchTree(int key)
    : m_key{ key }
    , m_left{ nullptr }
    , m_right{ nullptr }
    , m_parent{ nullptr }
{
}

void MyBinarySearchTree::inorderWalk(MyBinarySearchTree* root)
{
    // takes O(n) time
    if (root != nullptr)
    {
        // print the value of the key of the root after printing the left child key and
        // before printing the right child key
        inorderWalk(root->m_left);
        std::cout << root->m_key << ' ';
        inorderWalk(root->m_right);
    }
}

MyBinarySearchTree* MyBinarySearchTree::search(MyBinarySearchTree* root, int key)
{
    if (root == nullptr || key == root->m_key)
    {
        return root;
    }

    if (key < root->m_key)
    {
        // search recursively in the left subtree
        return search(root->m_left, key);
    }
    else
    {
        // search recursively in the right subtree
        return search(root->m_right, key);
    }
}

MyBinarySearchTree* MyBinarySearchTree::iterativeSearch(MyBinarySearchTree* root, int key)
{
    while (root != nullptr && key != root->m_key)
    {
        if (root->m_key < key)
        {
            root = root->m_left;
        }
        else
        {
            root = root->m_right;
        }
    }

    return root;
}

MyBinarySearchTree* MyBinarySearchTree::minimum(MyBinarySearchTree* root)
{
    while (root->m_left != nullptr)
    {
        root = root->m_left;
    }

    return root;
}

MyBinarySearchTree* MyBinarySearchTree::maximum(MyBinarySearchTree* root)
{
    while (root->m_right != nullptr)
    {
        root = root->m_right;
    }

    return root;
}

MyBinarySearchTree* MyBinarySearchTree::successor(MyBinarySearchTree* root)
{
    // if the right subtree exists, the smallest key greater than root->m_key will be there
    if (root->m_right != nullptr)
    {
        return minimum(root->m_right);
    }

    MyBinarySearchTree* parent{ root->m_parent };
    // go up the tree to find the lowest successor of x whose left child is also an ancestor of x
    while (parent != nullptr && root == parent->m_right)
    {
        root = parent;
        parent = parent->m_parent;
    }

    return parent;
}

MyBinarySearchTree* MyBinarySearchTree::predecessor(MyBinarySearchTree* root)
{
    if (root->m_left != nullptr)
    {
        return maximum(root->m_left);
    }

    MyBinarySearchTree* parent{ root->m_parent };
    while (parent != nullptr && root == parent->m_left)
    {
        root = parent;
        parent = parent->m_parent;
    }

    return parent;
}

void MyBinarySearchTree::insert(MyBinarySearchTree* root, int newKey)
{
    MyBinarySearchTree* parent{};
    MyBinarySearchTree* newNode{ new MyBinarySearchTree{ newKey } };

    // travel down the tree to find the right spot
    while (root != nullptr)
    {
        parent = root;
        if (newNode->m_key < root->m_key)
        {
            root = root->m_left;
        }
        else
        {
            root = root->m_right;
        }
    }
    newNode->m_parent = parent;

    if (parent == nullptr)
    {
        root = newNode; // tree was empty
    }
    else if (newNode->m_key < parent->m_key)
    {
        parent->m_left = newNode;
    }
    else
    {
        parent->m_right = newNode;
    }
}

// this subroutine replaces the first node with the second node
void MyBinarySearchTree::transplant(MyBinarySearchTree*& root, MyBinarySearchTree*& firstNode,
        MyBinarySearchTree*& secondNode)
{
    if (firstNode->m_parent == nullptr)
    {
        // if the first node is the root
        root = secondNode;
    }
    else if (firstNode == firstNode->m_parent->m_left)
    {
        // if the first node is a left child
        firstNode->m_parent->m_left = secondNode;
    }
    else
    {
        // if the first node is a right child
        firstNode->m_parent->m_right = secondNode;
    }

    if (secondNode != nullptr)
    {
        // swap the parents, now first node's parent is the second node's parent
        // and first node's parent ends up having second node as its appropriate child
        secondNode->m_parent = firstNode->m_parent;
    }
}

void MyBinarySearchTree::remove(MyBinarySearchTree* root, int keyToRemove)
{
    // this shouldn't be here, we should rather pass the node to remove itself, but whatever
    MyBinarySearchTree* nodeToDelete{ search(root, keyToRemove) };

    if (nodeToDelete->m_left == nullptr)
    {
        // if the left child of the node doesn't exist, then just replace it by its right child,
        // which may or may not be nullptr (this also handles the case where the node has no children)
        transplant(root, nodeToDelete, nodeToDelete->m_right);
    }
    else if (nodeToDelete->m_right == nullptr)
    {
        // if the right child doesn't exist, replace it with the left child
        transplant(root, nodeToDelete, nodeToDelete->m_left);
    }
    else
    {
        // if both children exist:
        // find the successor of the node to delete
        MyBinarySearchTree* nodeToDeleteSuccessor{ minimum(nodeToDelete->m_right) };

        if (nodeToDeleteSuccessor->m_parent != nodeToDelete)
        {
            // if the successor is not node's to delete right child
            transplant(root, nodeToDeleteSuccessor, nodeToDeleteSuccessor->m_right);
            nodeToDeleteSuccessor->m_right = nodeToDelete->m_right;
            nodeToDeleteSuccessor->m_right->m_parent = nodeToDeleteSuccessor;
        }

        transplant(root, nodeToDelete, nodeToDeleteSuccessor);
        nodeToDeleteSuccessor->m_left = nodeToDelete->m_left;
        nodeToDeleteSuccessor->m_left->m_parent = nodeToDeleteSuccessor;
    }
}
