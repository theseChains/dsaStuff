#include "exercises.h"

// exercise 2.1-4

void addBinaryIntegers(const std::array<int, 9>& firstNumber, const std::array<int, 9>& secondNumber)
{
	std::array<int, util::arraySize> result{};

	bool firstIteration{ true };
	int carriedForward{ 0 };
	int startIndex{ static_cast<int>(std::size(firstNumber)) - 1 }; // 8
	for (int i{ startIndex }; i >= 0; --i)
	{
		if (firstIteration)
		{
			result[static_cast<std::size_t>(i) + 1] = (firstNumber[i] + secondNumber[i]) % 2;
			carriedForward = (firstNumber[i] + secondNumber[i] == 2) ? 1 : 0;
			firstIteration = false;
		}
		else
		{
			result[static_cast<std::size_t>(i) + 1] = (firstNumber[i] + secondNumber[i] + carriedForward) % 2;
			carriedForward = (firstNumber[i] + secondNumber[i] + carriedForward >= 2) ? 1 : 0;
		}
	}
	// first digit of the result
	if (carriedForward)
		result[0] = 1;

	printArray(result);
}