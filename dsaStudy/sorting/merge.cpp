#include "sorting.h"

void merge(std::array<int, util::arraySize>& numbers, int firstIndex, int middleIndex, int lastIndex)
{
	const int firstSubarraySize{ middleIndex - firstIndex + 1 };
	const int secondSubarraySize{ lastIndex - middleIndex };

	std::vector<int> firstSubarray(firstSubarraySize);
	std::vector<int> secondSubarray(secondSubarraySize);

	for (int i{ 0 }; i < firstSubarraySize; ++i)
	{
		firstSubarray[i] = numbers[static_cast<std::size_t>(firstIndex) + i];
	}

	for (int j{ 0 }; j < secondSubarraySize; ++j)
	{
		secondSubarray[j] = numbers[static_cast<std::size_t>(middleIndex) + j + 1];
	}

	int firstSubIndex{ 0 };
	int secondSubIndex{ 0 };
	int numbersIndex{ firstIndex };
	while (firstSubIndex < firstSubarraySize && secondSubIndex < secondSubarraySize)
	{
		if (firstSubarray[firstSubIndex] <= secondSubarray[secondSubIndex])
		{
			numbers[numbersIndex] = firstSubarray[firstSubIndex];
			++firstSubIndex;
			++numbersIndex;
		}
		else
		{
			numbers[numbersIndex] = secondSubarray[secondSubIndex];
			++secondSubIndex;
			++numbersIndex;
		}
	}

	// add the remaining elements if they exist
	for (; firstSubIndex < firstSubarraySize; ++firstSubIndex)
	{
		numbers[numbersIndex] = firstSubarray[firstSubIndex];
		++numbersIndex;
	}

	for (; secondSubIndex < secondSubarraySize; ++secondSubIndex)
	{
		numbers[numbersIndex] = secondSubarray[secondSubIndex];
		++numbersIndex;
	}
}

void mergeSort(std::array<int, util::arraySize>& numbers, int firstIndex, int lastIndex)
{
	if (firstIndex < lastIndex)
	{
		int middleIndex{ (firstIndex + lastIndex) / 2 };
		mergeSort(numbers, firstIndex, middleIndex);
		mergeSort(numbers, middleIndex + 1, lastIndex);
		merge(numbers, firstIndex, middleIndex, lastIndex);
	}
}
