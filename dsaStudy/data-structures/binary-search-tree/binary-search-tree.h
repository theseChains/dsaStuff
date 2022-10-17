#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "../../util/util.h"

// basic operations take time proportional to the height of the tree, for a complete tree with
// n nodes such operations as search, minimum, maximum, predecessor, successor, insert and delete
// run in O(lgn) worst-case time if a tree is a linear chain of n nodes, however, the same
// operations take O(n) worst-case time

// binary search tree property: the left subtree of a node contains only nodes with keys lesser
// than the node's key, the right subree of a node contains only elements with keys greater than
// the node's key, the left and right subtrees each must also be a binary search tree

// the implementation is similar to a linked list
class MyBinarySearchTree
{
private:
    int m_key{};
    MyBinarySearchTree* m_left{};
    MyBinarySearchTree* m_right{};
    MyBinarySearchTree* m_parent{};

    // auxiliary subroutine
    void transplant(MyBinarySearchTree*& root, MyBinarySearchTree*& firstNode,
            MyBinarySearchTree*& secondNode);

public:
    MyBinarySearchTree() = default;

    MyBinarySearchTree(int key);

    // inorder tree walk - walk through elements in sorted order
    void inorderWalk(MyBinarySearchTree* root);

    MyBinarySearchTree* search(MyBinarySearchTree* root, int key);

    // iterative version, usually a bit more efficient
    MyBinarySearchTree* iterativeSearch(MyBinarySearchTree* root, int key);

    MyBinarySearchTree* minimum(MyBinarySearchTree* root);

    MyBinarySearchTree* maximum(MyBinarySearchTree* root);

    // the successor of a node x is the node with the smallest key greater than x.key
    MyBinarySearchTree* successor(MyBinarySearchTree* root);

    MyBinarySearchTree* predecessor(MyBinarySearchTree* root);

    void insert(MyBinarySearchTree* root, int newKey);

    void remove(MyBinarySearchTree* root, int keyToRemove);
};

#endif
