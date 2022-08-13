#include "matrices.h"

square_matrix_type squareMatrixMultiply(const square_matrix_type& firstMatrix, const square_matrix_type& secondMatrix)
{
	std::size_t size{ firstMatrix.size() };
	square_matrix_type newMatrix{};

	for (std::size_t i{ 0 }; i < size; ++i)
	{
		for (std::size_t j{ 0 }; j < size; ++j)
		{
			for (std::size_t k{ 0 }; k < size; ++k)
			{
				newMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}

	return newMatrix;
}