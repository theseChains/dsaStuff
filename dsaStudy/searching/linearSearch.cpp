#include "searching.h"

int linearSearch(const std::array<int, util::arraySize>& numbers, int value)
{
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