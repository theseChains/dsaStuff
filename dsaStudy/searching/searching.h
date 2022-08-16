#ifndef SEARCHING_H
#define SEARCHING_H

#include "../util/util.h"

int linearSearch(const std::array<int, util::arraySize>& numbers, int value);
int binarySearch(const std::array<int, util::arraySize>& sortedNumbers, int value);

#endif