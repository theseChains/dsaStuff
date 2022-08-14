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

    square_matrix_type firstMatrix{ generateMatrix() };
    square_matrix_type secondMatrix{ generateMatrix() };

    std::cout << "matrices multiplied:\n";
    timer.reset();
    square_matrix_type resultNaive{ squareMatrixMultiply(firstMatrix, secondMatrix) };
    unsigned long long naiveTime{ timer.elapsed() };
    std::cout << '\n';

    timer.reset();
    square_matrix_type resultStrassen{ strassenMultiplication(firstMatrix, secondMatrix) };
    unsigned long long strassenTime{ timer.elapsed() };
    std::cout << '\n';

    std::cout << "time to compute naive algorithm (O(n^3)) in ms: " << naiveTime << "\nresult:\n";
    std::cout << "time to compute naive algorithm (O(n^3)) in ms: " << strassenTime << "\nresult:\n";

    std::cout << "sorted array:\n";
    mergeSort(numbers);
    printArray(numbers);

    std::cout << "number 7 is at index: " << binarySearch(numbers, 7) << '\n';

    return 0;
}