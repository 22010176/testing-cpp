#pragma once

#ifndef _MATRIX_
#define _MATRIX_

#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>

#include "Linear.h"
using namespace std;

struct Matrix {
	float** mat; uint32_t rows, cols;

	Matrix(uint32_t rows = 0, uint32_t cols = 0, float** matrix = NULL);
	Matrix(Vector2 a);

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
float RoundNumber(float x, int pre = 2);
#endif