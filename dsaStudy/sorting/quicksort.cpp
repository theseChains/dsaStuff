#include "sorting.h"

int partition(std::array<int, util::arraySize>& numbers, int firstIndex, int lastIndex)
{
	// partition always selects and element x = A[last] as a pivot element
	// around which to partition the subarray A[first..last]
	int pivot{ numbers[lastIndex] };
	int backwardIndex{ firstIndex - 1 };

	for (int forwardIndex{ firstIndex }; forwardIndex < lastIndex; ++forwardIndex)
	{
		if (numbers[forwardIndex] <= pivot)
		{
			++backwardIndex;
			std::swap(numbers[backwardIndex], numbers[forwardIndex]);
		}
	}

	std::swap(numbers[backwardIndex + 1], numbers[lastIndex]);

	return backwardIndex + 1;
}

void quickSort(std::array<int, util::arraySize>& numbers, int firstIndex, int lastIndex)
{
	if (firstIndex < lastIndex)
	{
		int pivot{ partition(numbers, firstIndex, lastIndex) };
		quickSort(numbers, firstIndex, pivot - 1);
		quickSort(numbers, pivot + 1, lastIndex);
	}
}