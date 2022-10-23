#ifndef RED_BLACK_TREE_DATA_STRUCTURE_H
#define RED_BLACK_TREE_DATA_STRUCTURE_H

#include "../../util/util.h"

// red-black trees guarantee that basic dynamic-set operations take O(lgn) time in the worst case
// a red-black tree is a bst with one extra bit of storage per node: its color
// red-black trees ensure that no path is twice as long as any other
//
// red-black properties: 1) every node is either red or black
// 2) the root is black
// 3) every leaf (nullptr) is black
// 4) if a node is red, then both children are black
// 5) all simple paths from the node to descendats leaves contain the same number of black nodes

enum class Color
{
    red,
    black
};

struct Node
{
    int m_key{};
    Node* m_left{};
    Node* m_right{};
    Node* m_parent{};
    Color m_color{};
};

class MyRedBlackTree
{
private:
    Node* m_null{}; // a single variable to represent every leaf of the tree
    Node* m_root{};

public:
    MyRedBlackTree();

    // insertion and deletion works in O(lgn) time
    void insertKey(int newKey);
    void deleteKey(int keyToDelete);

    void printHelper(Node* currentNode, std::string indent = "", bool last = true);
    void printTree();

private:
    // we need to preserve the color and pointer structure if we insert or delete an element
    // we can do this by defining these subroutines to preserve the binary-search-tree property
    void leftRotate(Node* nodeToRotate);
    void rightRotate(Node* nodeToRotate);

    void insertFixup(Node* newNode);

    // deletion auxiliary functions
    void transplant(Node*& firstNode, Node*& secondNode);
    void deleteFixup(Node* node);
    Node* findMinimum(Node* node);
};

#endif
