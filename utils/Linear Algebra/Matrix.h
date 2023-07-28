#pragma once

#ifndef _MATRIX_
#define _MATRIX_

#include <cmath>
#include <cstdlib>
#include <cstdint>

struct Matrix {
private:
	double _der;
public:
	double** mat;
	uint32_t rows, cols;
	Matrix(uint32_t rows, uint32_t cols);
	~Matrix();
	double Determinant();
	
	Matrix operator+(Matrix other);
	Matrix operator-(Matrix other);
	Matrix operator*(Matrix other);
	Matrix operator*(double other);
	bool operator== (Matrix other);
};

double** CreateMatrix(uint32_t rows, uint32_t cols);
#endif