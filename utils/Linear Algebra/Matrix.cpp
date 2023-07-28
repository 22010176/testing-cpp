#include "Matrix.h"

double** CreateMatrix(uint32_t rows, uint32_t cols) {
	double** a = (double**)malloc(rows * sizeof(double*));
	for (uint32_t i = 0; i < cols; i++) {
		double* b; b = (double*)malloc(cols * sizeof(double)); while (!b);
		a[i] = b;
	}
	return a;
}

Matrix::Matrix(uint32_t rows, uint32_t cols) :cols(cols), rows(rows), mat(CreateMatrix(rows, cols)) {}
Matrix::~Matrix() {
	for (uint32_t i = 0; i < rows; i++) delete mat[i];
	delete mat;	delete this;
}
double  Matrix::Determinant() {
	if (rows != cols)	return 0;
	return 1;
}

Matrix Matrix::operator+(Matrix other) {
	if (other.rows != rows || other.cols != cols) return Matrix(0, 0);
	Matrix result(rows, cols);
	for (uint32_t i = 0; i < rows; i++) for (uint32_t j = 0; j < cols; j++)
		result.mat[i][j] = other.mat[i][j] + mat[i][j];
	return result;
}
Matrix Matrix::operator-(Matrix other) {
	if (other.rows != rows || other.cols != cols) return Matrix(0, 0);
	Matrix result(rows, cols);
	for (uint32_t i = 0; i < rows; i++) for (uint32_t j = 0; j < cols; j++)
		result.mat[i][j] = other.mat[i][j] - mat[i][j];
	return result;
}
Matrix Matrix::operator*(double other) {
	Matrix result(rows, cols);
	for (uint32_t i = 0; i < rows; i++) for (uint32_t j = 0; j < cols; j++)
		result.mat[i][j] = mat[i][j] * other;
	return result;
}
bool Matrix::operator== (Matrix other) {
	if (other.rows != rows || other.cols != cols) return false;
	for (uint32_t i = 0; i < rows; i++) for (uint32_t j = 0; j < cols; j++)
		if (other.mat[i][j] != mat[i][j]) return false;
	return true;
}
Matrix Matrix::operator*(Matrix other) {
	if (cols != other.rows) return Matrix(0, 0);
	Matrix result(rows, other.cols);
	for (int i = 0; i < cols; i++) {
		
	}
	return result;
}