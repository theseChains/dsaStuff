#include "exercises.h"

// exercise 4.1-5

int fastMaxSubarraySum(const std::array<int, util::arraySize>& numbers)
{
	int maxSum{ numbers[0] };
	int currentMax{ numbers[0] };

	for (int i{ 1 }; i < util::arraySize; ++i)
	{
		currentMax = std::max(numbers[i], currentMax + numbers[i]);
		maxSum = std::max(maxSum, currentMax);
	}

	return maxSum;
}