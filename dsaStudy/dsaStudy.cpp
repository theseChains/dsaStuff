#include "data-structures/hash-table/hash-table.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    MyHashTable hashTable{ 10 }; // 10 buckets

    for (int i{ 0 }; i < 10; ++i)
    {
        hashTable.insertItem(rnd::getNumber(1, 100));
    }

    if (hashTable.searchItem(10))
    {
        std::cout << "10 was found\n";
        hashTable.deleteItem(10);
    }

    hashTable.displayHash();

    return 0;
}
