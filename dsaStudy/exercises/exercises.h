#ifndef EXERCISES_H
#define EXERCISES_H

#include <array>

#include "../util/util.h"

void addBinaryIntegers(const std::array<int, 9>& firstNumber, const std::array<int, 9>& secondNumber);
int slowMaxSubarraySum(const std::array<int, util::arraySize>& numbers);

#endif