#include "util.h"

void printContainer(const std::array<int, util::arraySize>& container)
{
	for (auto element : container)
	{
		std::cout << element << ' ';
	}

	std::cout << '\n';
}

int generateRandomNumber(int min, int max)
{
	static std::mt19937 mt{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };

	std::uniform_int_distribution range{ min, max };

	return range(mt);
}

void generateContainer(std::array<int, util::arraySize>& container)
{
	for (int i{ 0 }; i < util::arraySize; ++i)
	{
		container[i] = generateRandomNumber();
	}
}