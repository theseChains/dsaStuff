#include "searching.h"

// aka exercise 2.3-5

int binarySearch(const std::array<int, util::arraySize>& sortedNumbers, int value)
{
	int right{ util::arraySize - 1 };
	int left{ 0 };
	
	while (left <= right)
	{
		int currentIndex{ left + (right - left) / 2 }; // mid point at first

		if (sortedNumbers[currentIndex] == value)
		{
			return currentIndex;
		}

		// if value is smaller ignore the right half
		if (sortedNumbers[currentIndex] > value)
		{
			right = currentIndex - 1;
		}

		// if value is smaller ignore the left half
		else
		{
			left = currentIndex + 1;
		}
	}

	return -1;
}