#include "exercises/exercises.h"
#include "searching/searching.h"
#include "sorting/sorting.h"
#include "util/util.h"

int main()
{
    std::array<int, 10> numbers{ 5, 3, 9, 5, 0, 2, 1, 8, 6, 7 };
    
    std::cout << "number 0 is at index: " << linearSearch(numbers, 0) << '\n';

    selectionSortIncr(numbers);
    printContainer(numbers);

    selectionSortDecr(numbers);
    printContainer(numbers);

    std::array<int, 9> firstNumber{ 1, 0, 0, 0, 0, 0, 0, 0, 0 };
    std::array<int, 9> secondNumber{ 1, 0, 0, 0, 0, 0, 0, 0, 0 };
    addBinaryIntegers(firstNumber, secondNumber);

    return 0;
}