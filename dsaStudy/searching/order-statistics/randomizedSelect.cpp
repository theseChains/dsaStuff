#include "orderStatistics.h"

// same as in quiksort algorithm

int orStPartition(std::array<int, util::arraySize>& numbers, int firstIndex, int lastIndex)
{
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

int orStRandomizedPartition(std::array<int, util::arraySize>& numbers, int firstIndex, int lastIndex)
{
	int randomPivotIndex{ rnd::getNumber(firstIndex, lastIndex) };
	std::swap(numbers[lastIndex], numbers[randomPivotIndex]);
	return orStPartition(numbers, firstIndex, lastIndex);
}

int randomizedSelect(std::array<int, util::arraySize>& numbers, int index, 
	int firstIndex, int lastIndex)
{
	if (firstIndex == lastIndex)
	{
		return numbers[firstIndex];
	}

	int pivotIndex{ orStRandomizedPartition(numbers, firstIndex, lastIndex) };
	int numberOfElementsBeforePivot{ pivotIndex - firstIndex + 1 };
	
	if (index == numberOfElementsBeforePivot) // the pivot value is the answer
	{
		return numbers[pivotIndex];
	}
	else if (index < numberOfElementsBeforePivot)
	{
		return randomizedSelect(numbers, index, firstIndex, pivotIndex - 1);
	}
	else
	{
		return randomizedSelect(numbers, index - numberOfElementsBeforePivot, pivotIndex + 1,
			lastIndex);
	}
}
