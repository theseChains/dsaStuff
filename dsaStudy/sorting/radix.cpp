#include "sorting.h"

void countingSortForRadix(std::array<int, util::arraySize>& numbers, int size, int digit)
{
    // we are sorting digits, there are 10 of them, so out working storage size is going to be 10
	std::vector<int> workingStorage(10);
	std::array<int, util::arraySize> result{};

	for (int j{ 0 }; j < size; ++j)
	{
		++workingStorage[(numbers[j] / digit) % 10];
	}

	for (int i{ 1 }; i <= 10; ++i)
	{
		workingStorage[i] += workingStorage[i - 1];
	}

	for (int j{ size - 1 }; j >= 0; --j)
	{
		result[workingStorage[(numbers[j] / digit) % 10] - 1] = numbers[j];
		--workingStorage[(numbers[j] / digit) % 10];
	}

	// copy results back to our array
	for (int i{ 0 }; i < size; ++i)
	{
		numbers[i] = result[i];
	}
}

void radixSort(std::array<int, util::arraySize>& numbers)
{
	// the way this works is for each digit of the number we run a stable sorting algorithm
	// for example sorting 4 numbers:
	// 329 ->                    -> 436 ->                      -> 329 ->             -> 329
	// 839 -> sort by last digit -> 329 -> second to last digit -> 436 -> first digit -> 436
	// 436 ->                    -> 839 ->                      -> 839 ->             -> 839
	// thus, to ensure that we don't change the order of the numbers, we must use a stable sort
	
	int size{ static_cast<int>(std::size(numbers)) };
	int maximum{ *std::max_element(std::begin(numbers), std::end(numbers)) };
	
	// iterate through every digit place by checking if the largest numbers last digit was reached
	for (int digitPlace{ 1 }; maximum / digitPlace > 0; digitPlace *= 10)
	{
		// counting sort is a good stable sort choice
		countingSortForRadix(numbers, size, digitPlace);
	}
}
