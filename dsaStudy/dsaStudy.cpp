﻿#include "exercises/exercises.h"
#include "matrices/matrices.h"
#include "searching/searching.h"
#include "sorting/sorting.h"
#include "util/util.h"
#include "util/timer.h"

int main()
{
    Timer timer{};
    std::array<int, util::arraySize> numbers{};
    generateArray(numbers);
    std::cout << "initial array:\n";
    printArray(numbers);
    std::cout << '\n';

    square_matrix_type firstMatrix{};
    square_matrix_type secondMatrix{};
    generateMatrix(firstMatrix);
    generateMatrix(secondMatrix);
    
    std::cout << "first matrix:\n";
    printMatrix(firstMatrix);
    std::cout << "second matrix:\n";
    printMatrix(secondMatrix);

    std::cout << "matrices multiplied:\n";
    square_matrix_type result{ squareMatrixMultiply(firstMatrix, secondMatrix) };
    printMatrix(result);

    std::cout << "sorted array:\n";
    mergeSort(numbers);
    printArray(numbers);

    std::cout << "number 7 is at index: " << binarySearch(numbers, 7) << '\n';

    return 0;
}