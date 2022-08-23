#include "sorting.h"

int partition(std::array<int, util::arraySize>& numbers, int firstIndex, int lastIndex)
{
	// partition always selects and element x = A[last] as a pivot element
	// around which to partition the subarray A[first..last]
	int pivot{ numbers[lastIndex] };

	// the forward index and the backward index are indices that mark
	// the borders of elements, that are strictly larger than the pivot
	// to be precise, those elements have indices of i + 1 to j - 1
	// elements with indices firstIndex to i are smaller or equal to the pivot
	int backwardIndex{ firstIndex - 1 };

	for (int forwardIndex{ firstIndex }; forwardIndex < lastIndex; ++forwardIndex)
	{
		if (numbers[forwardIndex] <= pivot)
		{
			// move left-hand border by 1 and swap the elements
			++backwardIndex;
			std::swap(numbers[backwardIndex], numbers[forwardIndex]);
		}
	}

	// swap pivot with the rightmost element larger than pivot
	std::swap(numbers[backwardIndex + 1], numbers[lastIndex]);

	// elements bigger than pivot are now on the right-hand side of the array
	// with pivot separating them from elements smaller or equal to the pivot

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

// randomized version
// here, instead of permuting the input, we select a random element from the 
// subarray A[firstIndex..lastIndex] as the pivot. this is also called random sampling

int randomizedPartition(std::array<int, util::arraySize>& numbers, int firstIndex, int lastIndex)
{
	int randomPivotIndex{ random::getNumber(firstIndex, lastIndex) };
	std::swap(numbers[lastIndex], numbers[randomPivotIndex]);
	return partition(numbers, firstIndex, lastIndex);
}

void randomizedQuickSort(std::array<int, util::arraySize>& numbers, int firstIndex, int lastIndex)
{
	if (firstIndex < lastIndex)
	{
		int pivot{ randomizedPartition(numbers, firstIndex, lastIndex) };
		randomizedQuickSort(numbers, firstIndex, pivot - 1);
		randomizedQuickSort(numbers, pivot + 1, lastIndex);
	}
}