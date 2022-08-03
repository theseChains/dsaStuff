#include "exercises/exercises.h"
#include "searching/searching.h"
#include "sorting/sorting.h"
#include "util/util.h"

int main()
{
    std::array<int, 10> numbers{ 5, 3, 9, 5, 0, 2, 1, 8, 6, 7 };

    mergeSort(numbers);
    printContainer(numbers);

    return 0;
}