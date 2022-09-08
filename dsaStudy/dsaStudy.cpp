#include "searching/order-statistics/orderStatistics.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};
    
    std::array<int, util::arraySize> numbers{ generateArray(1, 100) };
    std::cout << "initial array:\n";
    printArray(numbers);
    std::cout << '\n';

    std::cout << "number bigger than exactly 2 numbers of the array: " << 
        randomizedSelect(numbers, 3) << '\n';

    std::cout << "sorted array:\n";
    std::sort(std::begin(numbers), std::end(numbers));
    printArray(numbers);
    std::cout << '\n';

    return 0;
}
