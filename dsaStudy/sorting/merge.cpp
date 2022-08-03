#include "sorting.h"

void merge(std::array<int, 10>& numbers, int firstIndex, int middleIndex, int lastIndex)
{
	const int firstSubarraySize{ middleIndex - firstIndex + 1 };
	const int secondSubarraySize{ lastIndex - middleIndex };

	std::vector<int> firstSubarray(firstSubarraySize + 1);
	std::vector<int> secondSubarray(secondSubarraySize + 1);

	for (int i{ 0 }; i < firstSubarraySize; ++i)
	{
		firstSubarray[i] = numbers[static_cast<std::size_t>(firstIndex) + i];
	}

	for (int j{ 0 }; j < secondSubarraySize; ++j)
	{
		secondSubarray[j] = numbers[static_cast<std::size_t>(middleIndex) + j + 1];
	}

	firstSubarray[firstSubarraySize] = 99;
	secondSubarray[secondSubarraySize] = 99;

	int firstSubIndex{ 0 };
	int secondSubIndex{ 0 };
	for (int k{ firstIndex }; k <= lastIndex; ++k)
	{
		if (firstSubarray[firstSubIndex] <= secondSubarray[secondSubIndex])
		{
			numbers[k] = firstSubarray[firstSubIndex];
			++firstSubIndex;
		}
		else
		{
			numbers[k] = secondSubarray[secondSubIndex];
			++secondSubIndex;
		}
	}
}

void mergeSort(std::array<int, 10>& numbers, int firstIndex, int lastIndex)
{
	if (firstIndex < lastIndex)
	{
		int middleIndex{ (firstIndex + lastIndex) / 2 };
		mergeSort(numbers, firstIndex, middleIndex);
		mergeSort(numbers, middleIndex + 1, lastIndex);
		merge(numbers, firstIndex, middleIndex, lastIndex);
	}
}