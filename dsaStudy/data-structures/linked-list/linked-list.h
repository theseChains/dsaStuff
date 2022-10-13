#ifndef LINKED_LIST_DATA_STRUCTURE_H
#define LINKED_LIST_DATA_STRUCTURE_H

#include "../../util/util.h"

class Node
{
public:
    int m_key{};
    Node* m_next{};
    Node* m_previous{};

    Node() = default;

    Node(int key) : m_key{ key }
    {}
};

class MyLinkedList
{
private:
    Node* m_head{};
public:
    MyLinkedList() = default;

    Node* findKey(int keyToFind);
    void insertNode(Node*& node);
    void deleteNode(Node*& node);
};

Node* MyLinkedList::findKey(int keyToFind)
{
    Node* indexNode{ m_head };
    while (indexNode != nullptr && indexNode->m_key != keyToFind)
    {
        indexNode = indexNode->m_next;
    }
    return indexNode;
}

void MyLinkedList::insertNode(Node*& node)
{
    node->m_next = m_head;
    if (m_head != nullptr)
    {
        m_head->m_previous = node;
    }
    m_head = node;
    node->m_previous = nullptr;
}

// if we wish to delete the element we must first call the search function to find a proper pointer
void MyLinkedList::deleteNode(Node*& node)
{
    // if there are elements before this one, rearrange the pointers
    if (node->m_previous != nullptr)
    {
        node->m_previous->m_next = node->m_next;
    }
    else
    {
        // reset the first element if it is to be deleted
        m_head = node->m_next;
    }
    // if there are elements after this one, rearrange the pointers
    if (node->m_next != nullptr)
    {
        node->m_next->m_previous = node->m_previous;
    }

    delete node;
}

#endif
