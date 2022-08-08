#include "exercises/exercises.h"
#include "searching/searching.h"
#include "sorting/sorting.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};
    std::array<int, util::arraySize> numbers{};
    generateContainer(numbers);

    std::cout << "initial array:\n";
    printContainer(numbers);
    std::cout << '\n';

    timer.reset();
    std::array<int, 3> maxSubarrayInfo{ findMaxSubarray(numbers) };
    std::cout << "O(nlgn) max subarray elapsed time (ms): " << timer.elapsed() << '\n';

    std::cout << "maximum subarray first index: " << maxSubarrayInfo[util::firstItemIndex]
        << "\nmaximum subarray last index: " << maxSubarrayInfo[util::lastItemIndex]
        << "\nthe subarray sum: " << maxSubarrayInfo[util::subarraySumIndex] << "\n\n";

    timer.reset();
    int slowSum{ slowMaxSubarraySum(numbers) };
    std::cout << "O(n^2) max subarray elapsed time (ms): " << timer.elapsed() << '\n';
    std::cout << "(slow algo) max subarray sum: " << slowSum << "\n\n";

    std::cout << "sorted array:\n";
    mergeSort(numbers);
    printContainer(numbers);

    std::cout << "number 7 is at index: " << binarySearch(numbers, 7) << '\n';

    return 0;
}