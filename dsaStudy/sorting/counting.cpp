#include "sorting.h"

void countingSort(const std::array<int, util::arraySize>& numbers, std::array<int, util::arraySize>& result, int workingStorageSize)
{
	// working storage size is the amount of distinct elements
	// for example, range of 0 through 9 of array numbers is 10 distinct elements
	std::vector<int> workingStorage(workingStorageSize);
	int size{ static_cast<int>(std::size(numbers)) };
	
	for (int j{ 0 }; j < size; ++j)
	{
		workingStorage[numbers[j]] = workingStorage[numbers[j]] + 1;
		// count how many of each element there is 
		// workingStorage[i] now has the number of elements equal to i
	}

	for (int i{ 1 }; i <= workingStorageSize; ++i)
	{
		workingStorage[i] += workingStorage[i - 1];
		// workingStorage[i] now contains the number of elements less or equal to i
		// we are doing this by running the same sum through this array
	}

	for (int j{ size - 1 }; j >= 0; --j)
	{
		// there are workingStorage[numbers[j] - 1] elements less than or equal to numbers[j]
		// so, for each numbers[j], the value workingStorage[numbers[j] - 1] is the correct final
		// position of numbers[j]. we decrement it in the last line so that the next element
		// with a value equal to numbers[j] goes immediately before numbers[j] (if it exists)
		result[workingStorage[numbers[j]] - 1] = numbers[j];
		--workingStorage[numbers[j]];
	}
}
