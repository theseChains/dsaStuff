#include "util.h"

void printContainer(std::array<int, 10>& container)
{
	for (auto element : container)
	{
		std::cout << element << ' ';
	}

	std::cout << '\n';
}

int generateRandomNumber()
{
	static std::mt19937 mt{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };

	std::uniform_int_distribution range{ 0, 9 };

	return range(mt);
}

void generateContainer(std::array<int, util::arraySize>& container)
{
	/*for (auto element : container)
	{
		element = generateRandomNumber();
	}*/

	for (int i{ 0 }; i < util::arraySize; ++i)
	{
		container[i] = generateRandomNumber();
	}
}