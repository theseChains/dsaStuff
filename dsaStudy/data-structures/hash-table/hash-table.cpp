#include "hash-table.h"

MyHashTable::MyHashTable(int numberOfBuckets)
    : m_numberOfBuckets{ numberOfBuckets }, m_table(numberOfBuckets)
{
}

void MyHashTable::insertItem(int key)
{
    // here i assume that key is equal to the value of x.key so we remove the key itself
    // find list index
    int listIndex{ myHashFunction(key) }; // calculate hash value of the key
    // O(1) insert time
    // segfault..
    m_table[listIndex].push_front(key); // insert key in the slot denoted by the has value
}

void MyHashTable::deleteItem(int key)
{
    int listIndex{ myHashFunction(key) };
    m_table[listIndex].remove(key);
}

std::optional<int> MyHashTable::searchItem(int key)
{
    int listIndex{ myHashFunction(key) };

    auto found{ std::ranges::find(m_table[listIndex], key) };

    if (found != m_table[listIndex].end())
    {
        return *found;
    }
    else
    {
        return std::nullopt;
    }
}

int MyHashTable::myHashFunction(int key)
{
    return (key % m_numberOfBuckets);
}

void MyHashTable::displayHash() const
{
    for (int i{ 0 }; i < m_numberOfBuckets; ++i)
    {
        std::cout << i;
        for (const auto& item : m_table[i])
        {
            std::cout << " --> " << item;
        }
        std::cout << '\n';
    }
}
