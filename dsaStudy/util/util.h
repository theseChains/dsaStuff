#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <optional>
#include <random>
#include <set>
#include <utility>
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

namespace rnd
{
	inline std::mt19937 mt{ std::random_device{}() };

	int getNumber(int min = 0, int max = 9);

	// for bucket sort
	double getRealNumber(double min = 0.0, double max = 1.0);
}

// arrays
template <typename T>
void printArray(const std::array<T, util::arraySize>& array)
{
	for (const auto& element : array)
	{
		std::cout << element << ' ';
	}

	std::cout << '\n';
}

std::array<int, util::arraySize> generateArray(int minNumber = 0, int maxNumber = 9);

std::array<double, util::arraySize> generateRealArray(int minNumber = 0.0, int maxNumber = 1.0);

void printVector(const std::vector<int>& vector);

// matrices
using square_matrix_type = std::vector<std::vector<int>>;

void printMatrix(const square_matrix_type& matrix);
square_matrix_type generateMatrix(int minNumber = 0, int maxNumber = 9);

#endif
