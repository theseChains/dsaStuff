#include "util.h"

int random::getNumber(int min, int max)
{
	std::uniform_int_distribution range{ min, max };

	return range(mt);
}

void printArray(const std::array<int, util::arraySize>& array)
{
	for (const auto element : array)
	{
		std::cout << element << ' ';
	}

	std::cout << '\n';
}

std::array<int, util::arraySize> generateArray(int minNumber, int maxNumber)
{
	std::array<int, util::arraySize> array{};

	for (auto& element : array)
	{
		element = random::getNumber(minNumber, maxNumber);
	}

	return array;
}

void printVector(const std::vector<int>& vector)
{
	for (const auto element : vector)
	{
		std::cout << element << ' ';
	}

	std::cout << '\n';
}

void printMatrix(const square_matrix_type& matrix)
{
	for (const auto& row : matrix)
	{
		for (const auto element : row)
		{
			std::cout << element << ' ';
		}
		std::cout << '\n';
	}
}

square_matrix_type generateMatrix(int minNumber, int maxNumber)
{
	square_matrix_type matrix(util::squareMatrixSize, std::vector<int>(util::squareMatrixSize));

	for (auto& row : matrix)
	{
		for (auto& element : row)
		{
			element = random::getNumber(minNumber, maxNumber);
		}
	}

	return matrix;
}