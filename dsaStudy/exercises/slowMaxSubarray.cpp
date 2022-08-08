#include "exercises.h"

// exercise 4.1-2

int slowMaxSubarraySum(const std::array<int, util::arraySize>& numbers)
{
	int maxSum{ -1000 };
	for (int i{ 0 }; i < util::arraySize; ++i)
	{
		int sum{ 0 };
		for (int j{ i }; j < util::arraySize; ++j)
		{
			sum += numbers[j];

			if (sum > maxSum)
			{
				maxSum = sum;
			}
		}
	}

	return maxSum;
}