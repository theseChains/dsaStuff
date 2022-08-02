#ifndef SORTING_H
#define SORTING_H

#include <array>
#include <cstddef>
#include <iostream>
#include <iterator>

void insertionSortIncr(std::array<int, 10>& numbers);
void insertionSortDecr(std::array<int, 10>& numbers);

void mergeSort(std::array<int, 10>& numbers);

#endif