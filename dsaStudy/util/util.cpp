#include "util.h"

int generateRandomNumber(int min, int max)
{
	static std::mt19937 mt{ std::random_device{}() };

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

std::array<int, util::arraySize> generateArray(int minNumber, int maxNumber)
{
	std::array<int, util::arraySize> array{};

	for (int i{ 0 }; i < util::arraySize; ++i)
	{
		array[i] = generateRandomNumber(minNumber, maxNumber);
	}

	return array;
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

square_matrix_type generateMatrix(int minNumber, int maxNumber)
{
	square_matrix_type matrix(util::squareMatrixSize, std::vector<int>(util::squareMatrixSize));

	for (int i{ 0 }; i < util::squareMatrixSize; ++i)
	{
		for (int j{ 0 }; j < util::squareMatrixSize; ++j)
		{
			matrix[i][j] = generateRandomNumber(minNumber, maxNumber);
		}
	}

	return matrix;
}