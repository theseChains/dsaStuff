#include "util.h"

int rnd::getNumber(int min, int max)
{
	std::uniform_int_distribution range{ min, max };

	return range(mt);
}

double rnd::getRealNumber(double min, double max)
{
	std::uniform_real_distribution range{ min, max };

	return range(mt);
}

std::array<int, util::arraySize> generateArray(int minNumber, int maxNumber)
{
	std::array<int, util::arraySize> array{};

	for (auto& element : array)
	{
		element = rnd::getNumber(minNumber, maxNumber);
	}

	return array;
}

std::array<double, util::arraySize> generateRealArray(int minNumber, int maxNumber)
{
	std::array<double, util::arraySize> array{};

	for (auto& element : array)
	{
		element = rnd::getRealNumber(minNumber, maxNumber);
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
			element = rnd::getNumber(minNumber, maxNumber);
		}
	}

	return matrix;
}
