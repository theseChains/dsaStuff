#ifndef ORDER_STATISTICS_H
#define ORDER_STATISTICS_H

#include "../../util/util.h"

// the ith order statistic of a set of n elements is the ith smallest element
// the minimum of a set of elements is the first order statistic (i = 1)
// the maximum is the nth order statistic (i = n)
// a median is the "halfway point" of the set

int minimum(const std::array<int, util::arraySize>& numbers);

// selection problem:
// given i, find an element x in array A that is larger than exactly i - 1 other elements of A

// this algorithm is modeled after the quicksort algorithm, but here we work on only one side of the partition
// thus, the expected running time is theta(n)

int randomizedSelect(std::array<int, util::arraySize>& numbers, int index, int firstIndex = 0,
	int lastIndex = util::arraySize - 1);

#endif
