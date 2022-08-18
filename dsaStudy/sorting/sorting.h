#ifndef SORTING_H
#define SORTING_H

#include "../util/util.h"

// O(n^2)
void insertionSortIncr(std::array<int, util::arraySize>& numbers);
void insertionSortDecr(std::array<int, util::arraySize>& numbers);

// O(n^2)
void selectionSortIncr(std::array<int, util::arraySize>& numbers);
void selectionSortDecr(std::array<int, util::arraySize>& numbers);

// O(n * lgn)
void mergeSort(std::array<int, util::arraySize>& numbers, int firstIndex = 0, int lastIndex = util::arraySize - 1);

//
void makeMaxHeap(std::array<int, util::arraySize>& numbers, int index);
void makeMinHeap(std::array<int, util::arraySize>& numbers, int index);
void iterativeMakeMaxHeap(std::array<int, util::arraySize>& numbers, int index);



#endif