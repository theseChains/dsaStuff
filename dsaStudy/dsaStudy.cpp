#include "sorting/sorting.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};
    
    std::array<double, util::arraySize> numbers{ generateRealArray() };
    std::cout << "initial array:\n";
    printArray(numbers);

    return 0;
}
