#ifndef HASH_TABLE_DATA_STRUCTURE_H
#define HASH_TABLE_DATA_STRUCTURE_H

#include "../../util/util.h"

// a hash table is an effective data structure for implementing dictionaries
// under reasonable assumptions, the average time to search for an element in a hash table is O(1)
// instead of using the key as an array index directly, the array index is computed from the key

// a direct-address table can be used when the universe U of keys is reasonably small,
// we can assume that no two elements have the same key
// the dictionary operations are trivial to implement:
inline int directAddressSearch(std::map<std::string, int>& directAddressTable, const std::string& key)
{
    return directAddressTable[key];
}

inline void directAddressInsert(std::map<std::string, int>& directAddressTable,
        const std::map<std::string, int>::value_type& newElement)
{
    // T[x.key] = x;
    directAddressTable[newElement.first] = newElement.second;
}

inline void directAddressDelete(std::map<std::string, int>& directAddressTable,
        const std::map<std::string, int>::value_type& elementToDelete)
{
    // assign some special value
    directAddressTable[elementToDelete.first] = 0;
}

// the downside of direct-address tables is that storing a table T of size U might be impractical
// when the set of keys K is much smaller than the universe U of all possible keys, a hash table
// requires much less storage than a direct-address table. with direct addressing an element with
// key k is stored in slot k, with hashing, this element is stored in slot h(k), that is, we use
// a hash function h to compute the slot from the key k. two keys may hash to the same slot, this
// is called a collision, we can solve it by chaining - putting all the elements that hash to the
// same slot into the same linked list.

class MyHashTable
{
private:
    int m_numberOfBuckets{};
    // a linked list for each hash value
    std::vector<std::list<int>> m_table{};

public:
    MyHashTable(int numberOfBuckets);

    void insertItem(int key);
    void deleteItem(int key);
    std::optional<int> searchItem(int key);

    int myHashFunction(int key);

    void displayHash() const;
};

#endif
