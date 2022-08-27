#include "searching.h"

// here we may go through the same number twice
int randomSearch(const std::array<int, util::arraySize>& numbers, int value)
{
	// zero-initialized
	std::array<int, util::arraySize> checkedIndices{}; // 0 - unchecked, 1 - checked
	int checkedCounter{ 0 };
	int size{ static_cast<int>(std::size(numbers)) };

	while (checkedCounter != size)
	{
		int index{ rnd::getNumber(0, size - 1) };
		if (numbers[index] == value)
		{
			return index;
		}
		if (!checkedIndices[index])
		{
			checkedIndices[index] = 1;
			++checkedCounter;
		}
	}

	return -1;
}
