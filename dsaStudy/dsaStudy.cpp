#include "sorting/sorting.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    std::array<int, util::arraySize> numbers{ generateArray() };
    std::cout << "initial array:\n";
    printArray(numbers);
    std::cout << '\n';

    modifiedTailRecursiveQuickSort(numbers);
    std::cout << "sorted array:\n";
    printArray(numbers);

    return 0;
}