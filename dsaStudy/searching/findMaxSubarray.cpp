#include "searching.h"

std::array<int, 3> findMaxCrossingSubarray(std::array<int, util::arraySize>& numbers, int low, int middle, int high);

std::array<int, 3> findMaxSubarray(std::array<int, util::arraySize>& numbers, int firstIndex, int lastIndex)
{
	// base case: only one element
	if (firstIndex == lastIndex)
	{
		return std::to_array({ firstIndex, lastIndex, numbers[firstIndex] }); // return array indices and sum (the element itself in this case)
	}
	else
	{
		int middleIndex{ firstIndex + (lastIndex - firstIndex) / 2 };
		std::array<int, 3> leftMaxSubarray{ findMaxSubarray(numbers, firstIndex, middleIndex) };
		std::array<int, 3> rightMaxSubarray{ findMaxSubarray(numbers, middleIndex + 1, lastIndex) };
		std::array<int, 3> crossingMaxSubarray{ findMaxCrossingSubarray(numbers, firstIndex, middleIndex, lastIndex) };

		if (leftMaxSubarray[util::subarraySumIndex] >= rightMaxSubarray[util::subarraySumIndex]
			&& leftMaxSubarray[util::subarraySumIndex] >= crossingMaxSubarray[util::subarraySumIndex])
		{
			return leftMaxSubarray;
		}
		else if (rightMaxSubarray[util::subarraySumIndex] >= leftMaxSubarray[util::subarraySumIndex]
			&& rightMaxSubarray[util::subarraySumIndex] >= crossingMaxSubarray[util::subarraySumIndex])
		{
			return rightMaxSubarray;
		}
		else
		{
			return crossingMaxSubarray;
		}
	}
}

// find the maximum subarray that crosses the midpoint
// this algorithm is simpler because the subarray MUST 
// contain the midpoint
std::array<int, 3> findMaxCrossingSubarray(std::array<int, util::arraySize>& numbers, int low, int middle, int high)
{
	int leftSum{ -1000 };
	int sum{ 0 };

	int maxLeftIndex{};
	for (int i{ middle }; i >= low; --i)
	{
		sum += numbers[i];
		if (sum > leftSum)
		{
			leftSum = sum;
			maxLeftIndex = i;
		}
	}

	int rightSum{ -1000 };
	sum = 0;

	int maxRightIndex{};
	for (int j{ middle + 1 }; j < high; ++j)
	{
		sum += numbers[j];
		if (sum > rightSum)
		{
			rightSum = sum;
			maxRightIndex = j;
		}
	}

	// return the array indices and the sum
	return std::to_array({ maxLeftIndex, maxRightIndex, leftSum + rightSum });
}