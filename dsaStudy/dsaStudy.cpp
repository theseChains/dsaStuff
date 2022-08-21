#include "data-structures/heap/d-ary-heap.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    std::vector<int> dAryHeap{ 9, 7, 8, 6, 6, 5, 2, 3, 4 };

    std::cout << "max element extracted: " << extractMax(dAryHeap, 3) << '\n';
    std::cout << "d-ary heap now:\n";
    printVector(dAryHeap);

    return 0;
}