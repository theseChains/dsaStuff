#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <algorithm>
#include <array>
#include <chrono>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <random>
#include <vector>

namespace util
{
	inline constexpr int arraySize{ 10 };

	inline constexpr int squareMatrixSize{ 8 };

	// findMaxSubarray.cpp
	inline constexpr int firstItemIndex{ 0 };
	inline constexpr int lastItemIndex{ 1 };
	inline constexpr int subarraySumIndex{ 2 };
}

int generateRandomNumber(int min = 0, int max = 9);

// arrays
void printArray(const std::array<int, util::arraySize>& array);

std::array<int, util::arraySize> generateArray();

// matrices
using square_matrix_type = std::vector<std::vector<int>>;

void printMatrix(const square_matrix_type& matrix);
square_matrix_type generateMatrix();

#endif