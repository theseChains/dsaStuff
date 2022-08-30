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

// O(n * lgn)
void heapSort(std::array<int, util::arraySize>& numbers);

// O(n * lgn)
void quickSort(std::array<int, util::arraySize>& numbers, int firstIndex = 0, int lastIndex = util::arraySize - 1);
void randomizedQuickSort(std::array<int, util::arraySize>& numbers, int firstIndex = 0, int lastIndex = util::arraySize - 1);
void hoareQuickSort(std::array<int, util::arraySize>& numbers, int firstIndex = 0, int lastIndex = util::arraySize - 1);
void tailRecursiveQuickSort(std::array<int, util::arraySize>& numbers, int firstIndex = 0, int lastIndex = util::arraySize - 1);
void modifiedTailRecursiveQuickSort(std::array<int, util::arraySize>& numbers, int firstIndex = 0, int lastIndex = util::arraySize - 1);

// O(n)
void countingSort(const std::array<int, util::arraySize>& numbers, std::array<int, util::arraySize>& result, int workingStorageSize);

#endif
