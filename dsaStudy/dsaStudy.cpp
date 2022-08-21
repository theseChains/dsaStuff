#include "data-structures/heap/d-ary-heap.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    std::vector<int> dAryHeap{ 9, 7, 8, 6, 6, 5, 2, 3, 4 };

    std::cout << "inserting number 10...\n";
    dAryHeapInsert(dAryHeap, 10, 3);
    std::cout << "the d-ary heap now looks like:\n";
    printVector(dAryHeap);

    return 0;
}