#include "exercises/exercises.h"
#include "searching/searching.h"
#include "sorting/sorting.h"
#include "util/util.h"

int main()
{
    std::array<int, util::arraySize> numbers{};
    generateContainer(numbers);

    std::cout << "initial array:\n";
    printContainer(numbers);
    std::cout << '\n';

    std::array<int, 3> maxSubarrayInfo{ findMaxSubarray(numbers) };

    std::cout << "maximum subarray first index: " << maxSubarrayInfo[util::firstItemIndex]
        << "\nmaximum subarray last index: " << maxSubarrayInfo[util::lastItemIndex]
        << "\nthe subarray sum: " << maxSubarrayInfo[util::subarraySumIndex] << "\n\n";

    std::cout << "(slow algo) max subarray sum: " << slowMaxSubarraySum(numbers) << "\n\n";

    std::cout << "sorted array:\n";
    mergeSort(numbers);
    printContainer(numbers);

    std::cout << "number 7 is at index: " << binarySearch(numbers, 7) << '\n';

    return 0;
}