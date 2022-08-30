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

	std::array<int, util::arraySize> result{};
    countingSort(numbers, result, 10);
    std::cout << "sorted array:\n";
    printArray(result);

	return 0;
}
