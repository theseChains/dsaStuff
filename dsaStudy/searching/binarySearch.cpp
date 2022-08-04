#include "searching.h"

// aka exercise 2.3-5

int binarySearch(std::array<int, 10>& sortedNumbers, int value)
{
	int right{ static_cast<int>(std::ssize(sortedNumbers)) - 1 };
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
			right = currentIndex + 1;
		}

		// if value is smaller ignore the left half
		if (sortedNumbers[currentIndex] < value)
		{
			left = currentIndex + 1;
		}
	}

	return -1;
}