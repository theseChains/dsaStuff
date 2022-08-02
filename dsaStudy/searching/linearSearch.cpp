#include "searching.h"

int linearSearch(std::array<int, 10>& numbers, int value)
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