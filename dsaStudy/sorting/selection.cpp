#include "sorting.h"

// aka exercise 2.2-2

void selectionSortIncr(std::array<int, util::arraySize>& numbers)
{
	int size{ static_cast<int>(std::size(numbers)) };
	for (int i{ 0 }; i < size - 1; ++i)
	{
		int smallestNumber{ std::numeric_limits<int>::max() };
		int smallestNumberIndex{};
		for (int j{ i + 1 }; j < size; ++j)
		{
			if (numbers[j] < smallestNumber)
			{
				smallestNumber = numbers[j];
				smallestNumberIndex = j;
			}
		}
		numbers[smallestNumberIndex] = numbers[i];
		numbers[i] = smallestNumber;
	}
}

void selectionSortDecr(std::array<int, util::arraySize>& numbers)
{
	int size{ static_cast<int>(std::size(numbers)) };
	for (int i{ 0 }; i < size - 1; ++i)
	{
		int biggestNumber{ std::numeric_limits<int>::min() };
		int biggestNumberIndex{};
		for (int j{ i + 1 }; j < size; ++j)
		{
			if (numbers[j] > biggestNumber)
			{
				biggestNumber = numbers[j];
				biggestNumberIndex = j;
			}
		}
		numbers[biggestNumberIndex] = numbers[i];
		numbers[i] = biggestNumber;
	}
}