#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <array>
#include <chrono>
#include <iostream>
#include <random>

namespace util
{
	inline constexpr int arraySize{ 15 };

	// findMaxSubarray.cpp
	inline constexpr int firstItemIndex{ 0 };
	inline constexpr int lastItemIndex{ 1 };
	inline constexpr int subarraySumIndex{ 2 };
}

void printContainer(const std::array<int, util::arraySize>& container);
int generateRandomNumber(int min = -10, int max = 10);
void generateContainer(std::array<int, util::arraySize>& container);

#endif