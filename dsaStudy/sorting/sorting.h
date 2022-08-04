#ifndef SORTING_H
#define SORTING_H

#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>

#include "../util/util.h"

void insertionSortIncr(std::array<int, util::arraySize>& numbers);
void insertionSortDecr(std::array<int, util::arraySize>& numbers);

void selectionSortIncr(std::array<int, util::arraySize>& numbers);
void selectionSortDecr(std::array<int, util::arraySize>& numbers);

void mergeSort(std::array<int, util::arraySize>& numbers, int firstIndex = 0, int lastIndex = 9);

#endif