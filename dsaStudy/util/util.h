#ifndef UTIL_FUNCTIONS_H
#define UTIL_FUNCTIONS_H

#include <array>
#include <chrono>
#include <iostream>
#include <random>

namespace util
{
	inline constexpr int arraySize{ 10 };
}

void printContainer(std::array<int, util::arraySize>& container);
int generateRandomNumber();
void generateContainer(std::array<int, util::arraySize>& container);

#endif