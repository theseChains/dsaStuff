#include "matrices.h"

// strassen algorithm for matrix multiplication
// aka exercise 4.2-2

square_matrix_type add(const square_matrix_type& firstMatrix, const square_matrix_type& secondMatrix, std::size_t size)
{
	square_matrix_type matrix(size, std::vector<int>(size));

	for (std::size_t i{ 0 }; i < size; ++i)
	{
		for (std::size_t j{ 0 }; j < size; ++j)
		{
			matrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
		}
	}

	return matrix;
}

square_matrix_type subtract(const square_matrix_type& firstMatrix, const square_matrix_type& secondMatrix, std::size_t size)
{
	square_matrix_type matrix(size, std::vector<int>(size));

	for (std::size_t i{ 0 }; i < size; ++i)
	{
		for (std::size_t j{ 0 }; j < size; ++j)
		{
			matrix[i][j] = firstMatrix[i][j] - secondMatrix[i][j];
		}
	}

	return matrix;
}

square_matrix_type strassenMultiplication(const square_matrix_type& firstMatrix, const square_matrix_type& secondMatrix)
{
	std::size_t size{ std::size(firstMatrix) }; // size of a column

	if (size == 1)
	{
		square_matrix_type result(size, std::vector<int>(size));
		result[0][0] = firstMatrix[0][0] * secondMatrix[0][0];
		return result;
	}

	square_matrix_type result(size, std::vector<int>(size));
	std::size_t halfSize{ size / 2 };

	square_matrix_type firstTopLeft(halfSize, std::vector<int>(halfSize));		// A11
	square_matrix_type firstTopRight(halfSize, std::vector<int>(halfSize));		// A12
	square_matrix_type firstBottomLeft(halfSize, std::vector<int>(halfSize));	// A21
	square_matrix_type firstBottomRight(halfSize, std::vector<int>(halfSize));	// A22

	square_matrix_type secondTopLeft(halfSize, std::vector<int>(halfSize));		// B11
	square_matrix_type secondTopRight(halfSize, std::vector<int>(halfSize));	// B12
	square_matrix_type secondBottomLeft(halfSize, std::vector<int>(halfSize));	// B21
	square_matrix_type secondBottomRight(halfSize, std::vector<int>(halfSize)); // B22

	// fill the sub matrices
	for (std::size_t i{ 0 }; i < halfSize; ++i)
	{
		for (std::size_t j{ 0 }; j < halfSize; ++j)
		{
			firstTopLeft[i][j] = firstMatrix[i][j];
			firstTopRight[i][j] = firstMatrix[i][j + halfSize];
			firstBottomLeft[i][j] = firstMatrix[i + halfSize][j];
			firstBottomRight[i][j] = firstMatrix[i + halfSize][j + halfSize];

			secondTopLeft[i][j] = secondMatrix[i][j];
			secondTopRight[i][j] = secondMatrix[i][j + halfSize];
			secondBottomLeft[i][j] = secondMatrix[i + halfSize][j];
			secondBottomRight[i][j] = secondMatrix[i + halfSize][j + halfSize];
		}
	}

	square_matrix_type firstProduct{ strassenMultiplication(firstTopLeft, subtract(secondTopRight, secondBottomRight, halfSize)) };
	square_matrix_type secondProduct{ strassenMultiplication(add(firstTopLeft, firstTopRight, halfSize), secondBottomRight) };
	square_matrix_type thirdProduct{ strassenMultiplication(add(firstBottomLeft, firstBottomRight, halfSize), secondTopLeft) };
	square_matrix_type fourthProduct{ strassenMultiplication(firstBottomRight, subtract(secondBottomLeft, secondTopLeft, halfSize)) };
	square_matrix_type fifthProduct{ strassenMultiplication(add(firstTopLeft, firstBottomRight, halfSize), 
		add(secondTopLeft, secondBottomRight, halfSize)) };
	square_matrix_type sixthProduct{ strassenMultiplication(subtract(firstTopRight, firstBottomRight, halfSize), 
		add(secondBottomLeft, secondBottomRight, halfSize)) };
	square_matrix_type seventhProduct{ strassenMultiplication(subtract(firstTopLeft, firstBottomLeft, halfSize), 
		add(secondTopLeft, secondTopRight, halfSize)) };

	// C11 = P5 + P4 - P2 + P6
	square_matrix_type resultTopLeft{ subtract(add(add(fifthProduct, fourthProduct, halfSize), 
		sixthProduct, halfSize), secondProduct, halfSize) };
	// C12 = P1 + P2
	square_matrix_type resultTopRight{ add(firstProduct, secondProduct, halfSize) };
	// C21 = P3 + P4
	square_matrix_type resultBottomLeft{ add(thirdProduct, fourthProduct, halfSize) };
	// C22 = P5 + P1 - P3 - P7
	square_matrix_type resultBottomRight{ subtract(subtract(add(fifthProduct, firstProduct, halfSize), 
		thirdProduct, halfSize), seventhProduct, halfSize) };

	// copy values in the result matrix
	for (std::size_t i{ 0 }; i < halfSize; ++i)
	{
		for (std::size_t j{ 0 }; j < halfSize; ++j)
		{
			result[i][j] = resultTopLeft[i][j];
			result[i][j + halfSize] = resultTopRight[i][j];
			result[i + halfSize][j] = resultBottomLeft[i][j];
			result[i + halfSize][j + halfSize] = resultBottomRight[i][j];
		}
	}

	return result;
}
