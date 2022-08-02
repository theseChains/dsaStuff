#include "sorting.h"

// key represents the current element
void insertionSortIncr(std::array<int, 10>& numbers)
{
	// start with the second element
	for (int j{ 1 }; j < std::ssize(numbers); ++j)
	{
		// the subarray numbers[0..j - 1] consists of the elements 
		// originally in numbers[0..j - 1], but in sorted order
		int key{ numbers[j] };
		int i{ j - 1 };
		while (i >= 0 && numbers[i] > key)
		{
			numbers[static_cast<std::size_t>(i) + 1] = numbers[i];
			--i;
		}
		// insert numbers[j] into the sorted sequence numbers[0..j - 1]
		numbers[static_cast<std::size_t>(i) + 1] = key;
	}
}

void insertionSortDecr(std::array<int, 10>& numbers)
{
	// start with the second element
	for (int j{ 1 }; j < std::ssize(numbers); ++j)
	{
		// the subarray numbers[0..j - 1] consists of the elements 
		// originally in numbers[0..j - 1], but in sorted order
		int key{ numbers[j] };
		int i{ j - 1 };
		while (i >= 0 && numbers[i] < key)
		{
			numbers[static_cast<std::size_t>(i) + 1] = numbers[i];
			--i;
		}
		// insert numbers[j] into the sorted sequence numbers[0..j - 1]
		numbers[static_cast<std::size_t>(i) + 1] = key;
	}
}