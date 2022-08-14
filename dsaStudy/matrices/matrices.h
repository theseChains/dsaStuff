#ifndef MATRIX_FUNCTIONS_H
#define MATRIX_FUNCTIONS_H

#include "../util/util.h"

square_matrix_type squareMatrixMultiply(const square_matrix_type& firstMatrix, const square_matrix_type& secondMatrix);
square_matrix_type strassenMultiplication(const square_matrix_type& firstMatrix, const square_matrix_type& secondMatrix);

#endif