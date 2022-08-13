#ifndef SEARCHING_H
#define SEARCHING_H

#include "../util/util.h"

int linearSearch(const std::array<int, util::arraySize>& numbers, int value);
int binarySearch(const std::array<int, util::arraySize>& sortedNumbers, int value);

// returns first index, last index and sum of the subarray - in that order
// O(n * lgn)
std::array<int, 3> findMaxSubarray(const std::array<int, util::arraySize>& numbers, int firstIndex = 0, int lastIndex = util::arraySize - 1);

#endif