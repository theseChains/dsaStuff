#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <array>
#include <chrono>
#include <iostream>
#include <random>

namespace util
{
	inline constexpr int arraySize{ 15 };
}

void printContainer(std::array<int, util::arraySize>& container);
int generateRandomNumber(int min = -5, int max = 20);
void generateContainer(std::array<int, util::arraySize>& container);

#endif