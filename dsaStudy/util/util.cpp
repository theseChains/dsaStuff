#include "util.h"

void printContainer(std::array<int, 10>& container)
{
	for (auto element : container)
	{
		std::cout << element << ' ';
	}

	std::cout << '\n';
}