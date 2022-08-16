#ifndef EXERCISES_H
#define EXERCISES_H

#include "../util/util.h"

void addBinaryIntegers(const std::array<int, 9>& firstNumber, const std::array<int, 9>& secondNumber);

// O(n^2)
int slowMaxSubarraySum(const std::array<int, util::arraySize>& numbers);

// returns first index, last index and sum of the subarray - in that order
// O(n * lgn)
std::array<int, 3> findMaxSubarray(const std::array<int, util::arraySize>& numbers, int firstIndex = 0, int lastIndex = util::arraySize - 1);

// O(n)
int fastMaxSubarraySum(const std::array<int, util::arraySize>& numbers);

#endif