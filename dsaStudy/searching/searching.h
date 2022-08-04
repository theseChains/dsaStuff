#ifndef SEARCHING_H
#define SEARCHING_H

#include <array>
#include <iostream>
#include <iterator>

#include "../util/util.h"

int linearSearch(std::array<int, util::arraySize>& numbers, int value);
int binarySearch(std::array<int, util::arraySize>& sortedNumbers, int value);

#endif