#pragma once

#ifndef _MATRIX_
#define _MATRIX_

#include <cstdint>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>

struct Matrix {
	float** mat; uint32_t rows, cols;

	Matrix(uint32_t rows = 0, uint32_t cols = 0, float** matrix = NULL);

	float Determinant();
	Matrix Tranpos();
	Matrix ReverseMatrix();
	void Print();

	Matrix operator+(Matrix other);
	Matrix operator-(Matrix other);
	Matrix operator*(Matrix other);
	Matrix operator*(float other);
	Matrix operator/(float other);
	bool operator== (Matrix other);
};

#endif // !_MATRIX_
