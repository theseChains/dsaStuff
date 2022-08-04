#ifndef SEARCHING_H
#define SEARCHING_H

#include <array>
#include <iostream>
#include <iterator>

int linearSearch(std::array<int, 10>& numbers, int value);
int binarySearch(std::array<int, 10>& sortedNumbers, int value);

#endif