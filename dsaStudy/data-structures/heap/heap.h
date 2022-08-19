#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include "../../util/util.h"

void makeMaxHeap(std::array<int, util::arraySize>& heap, int index, int size);
void makeMinHeap(std::array<int, util::arraySize>& heap, int index, int size);
void iterativeMakeMaxHeap(std::array<int, util::arraySize>& heap, int index, int size);
void buildMaxHeap(std::array<int, util::arraySize>& heap);

#endif