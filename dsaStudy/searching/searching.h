#ifndef SEARCHING_H
#define SEARCHING_H

#include <array>
#include <iostream>
#include <iterator>
#include <limits>

#include "../util/util.h"

int linearSearch(std::array<int, util::arraySize>& numbers, int value);
int binarySearch(std::array<int, util::arraySize>& sortedNumbers, int value);

// returns first index, last index and sum of the subarray - in that order
std::array<int, 3> findMaxSubarray(std::array<int, util::arraySize>& numbers, int firstIndex = 0, int lastIndex = util::arraySize - 1);

#endif