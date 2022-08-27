#include "searching.h"

// works by randomly permuting the array first and running a deterministic search algorithm
int scrambleSearch(std::array<int, util::arraySize>& numbers, int value)
{
	std::shuffle(std::begin(numbers), std::end(numbers), rnd::mt);

	for (int index{ 0 }; auto element : numbers)
	{
		if (element == value)
		{
			return index;
		}
		++index;
	}

	return -1;
}
