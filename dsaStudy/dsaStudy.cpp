#include "exercises/exercises.h"
#include "matrices/matrices.h"
#include "randomized/randomized.h"
#include "searching/searching.h"
#include "sorting/sorting.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};

    std::array<int, util::arraySize> numbers{ generateArray() };
    std::cout << "initial array: ";
    printArray(numbers);

    heapSort(numbers);
    std::cout << "sorted array: ";
    printArray(numbers);

    return 0;
}