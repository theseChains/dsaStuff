#include "orderStatistics.h"

// finding smallest element with n - 1 comparisons
// this algorithm is optimal with respect to the number of comparisons performed

int minimum(const std::array<int, util::arraySize>& numbers)
{
	int minimum{ numbers[0] };
	for (std::size_t i{ 1 }; i < std::size(numbers); ++i)
	{
		if (minimum > numbers[i])
		{
			minimum = numbers[i];
		}
	}

	return minimum;
}
