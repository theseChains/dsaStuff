#ifndef D_ARY_HEAP_H
#define D_ARY_HEAP_H

#include "../../util/util.h"

// d-ary heap is like a binary heap, but non-leaf nodes have d children instead of 2 children

int getChildIndex(int parentIndex, int child, int numberOfChildren);
int getParentIndex(int index, int numberOfChildren);
void dAryMaxHeapify(std::vector<int>& dAryHeap, int numberOfChildren, std::size_t size, int index);
int dAryHeapExtractMax(std::vector<int>& dAryHeap, int numberOfChildren);
void dAryHeapIncreaseKey(std::vector<int>& dAryHeap, int key, std::size_t index, int numberOfChildren);
void dAryHeapInsert(std::vector<int>& dAryHeap, int key, int numberOfChildren);

#endif