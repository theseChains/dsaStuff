#ifndef EXERCISES_H
#define EXERCISES_H

#include "../util/util.h"

void addBinaryIntegers(const std::array<int, 9>& firstNumber, const std::array<int, 9>& secondNumber);

// O(n^2)
int slowMaxSubarraySum(const std::array<int, util::arraySize>& numbers);

// O(n)
int fastMaxSubarraySum(const std::array<int, util::arraySize>& numbers);

#endif