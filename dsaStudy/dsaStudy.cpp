#include "exercises/exercises.h"
#include "searching/searching.h"
#include "sorting/sorting.h"
#include "util/util.h"

int main()
{
    std::array<int, util::arraySize> numbers{};
    generateContainer(numbers);

    mergeSort(numbers);
    printContainer(numbers);

    std::cout << "number 7 is at index: " << binarySearch(numbers, 7) << '\n';

    return 0;
}