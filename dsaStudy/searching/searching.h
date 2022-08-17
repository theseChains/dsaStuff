#ifndef SEARCHING_H
#define SEARCHING_H

#include "../util/util.h"

// searching a sorted array

int binarySearch(const std::array<int, util::arraySize>& sortedNumbers, int value);

// searching an unsorted array

int deterministicSearch(const std::array<int, util::arraySize>& numbers, int value);
int randomSearch(const std::array<int, util::arraySize>& numbers, int value);
int scrambleSearch(std::array<int, util::arraySize>& numbers, int value);

#endif