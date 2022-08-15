#include "exercises/exercises.h"
#include "matrices/matrices.h"
#include "searching/searching.h"
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

    std::array<int, 10> digits{};
    for (int i{ 0 }; i < 10000; ++i)
    {
        int number{ generateRandomNumber() };
        ++digits[number];
    }

    std::cout << "mersenne twister probabilities:\n";
    std::array<double, 10> probabilities{};
    for (int i{ 0 }; i < 10; ++i)
    {
        probabilities[i] = digits[i] / 10000.0;
        std::cout << "number " << i << " percentage: " << probabilities[i] * 100 << "%\n";
    }

    return 0;
}