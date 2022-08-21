#ifndef D_ARY_HEAP_H
#define D_ARY_HEAP_H

#include "../../util/util.h"

// d-ary heap is like a binary heap, but non-leaf nodes have d children instead of 2 children

int getChildIndex(int parentIndex, int child, int numberOfChildren);
int getParentIndex(int index, int numberOfChildren);
int extractMax(std::vector<int>& dAryHeap, int numberOfChildren);

#endif