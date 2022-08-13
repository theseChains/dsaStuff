#include "util.h"

int generateRandomNumber(int min, int max)
{
	static std::mt19937 mt{ static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };

	std::uniform_int_distribution range{ min, max };

	return range(mt);
}

void printArray(const std::array<int, util::arraySize>& array)
{
	for (auto element : array)
	{
		std::cout << element << ' ';
	}

	std::cout << '\n';
}

void generateArray(std::array<int, util::arraySize>& array)
{
	for (int i{ 0 }; i < util::arraySize; ++i)
	{
		array[i] = generateRandomNumber();
	}
}

void printMatrix(const square_matrix_type& matrix)
{
	for (int i{ 0 }; i < util::squareMatrixSize; ++i)
	{
		for (int j{ 0 }; j < util::squareMatrixSize; ++j)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void generateMatrix(square_matrix_type& matrix)
{
	for (int i{ 0 }; i < util::squareMatrixSize; ++i)
	{
		for (int j{ 0 }; j < util::squareMatrixSize; ++j)
		{
			matrix[i][j] = generateRandomNumber();
		}
	}
}