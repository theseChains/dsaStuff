#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "../../util/util.h"

void maxHeapify(std::array<int, util::arraySize>& heap, int index, int size);
void minHeapify(std::array<int, util::arraySize>& heap, int index, int size);
void iterativeMaxHeapify(std::array<int, util::arraySize>& heap, int index, int size);
void buildMaximumHeap(std::array<int, util::arraySize>& heap);

#endif