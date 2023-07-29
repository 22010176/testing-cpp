#include "Matrix.h"

using namespace std;

/*
							*
	cols			0	1 2 3
	rows
		0				*	*	*	*   A[3][1]
		1				*	*	*	*
		2				*	*	*	*
	*	3				*	O	*	*
*/

float RoundNumber(float x, int pre) {
	int a = (int)powf(10, (float)pre);
	return roundf(x * a) / a;
}
inline void PrintMatrix(float** mat, uint32_t rows, uint32_t cols) {
	cout << endl;
	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < cols; j++) printf("%*.2f", 10, mat[i][j]);
		cout << endl;
	}
	cout << endl;
}
float** CreateMatrix(uint32_t rows, uint32_t cols) {
	float** a = new float* [rows];
	for (uint32_t i = 0; i < rows; i++) a[i] = new float[cols];
	return a;
}
float** GenerateMatrix(uint32_t rows, uint32_t cols) {
	float** a = new float* [rows];
	for (uint32_t i = 0; i < rows; i++) {
		a[i] = new float[cols];
		for (uint32_t j = 0; j < cols; j++) a[i][j] = (float)(rand() % 10000) / 100;
	}
	return a;
}
float** ModifyMatrix(float** a, uint32_t rows, uint32_t cols, int y0, int x0) {
	float** res = CreateMatrix(rows - 1, cols - 1);
	for (uint32_t i = 0, I = 0; i < rows; i++) {
		if (i == y0) { I++; continue; }
		for (uint32_t j = 0, J = 0; j < cols; j++) {
			if (j == x0) { J++; continue; }
			res[i - I][j - J] = a[i][j];
		}
	}
	return res;
}
float CalcDeterminant(float** A, uint32_t rows, uint32_t cols) {
	if (rows != cols) return 0;
	if (rows == 2) return A[0][0] * A[1][1] - A[0][1] * A[1][0];
	if (rows == 1) return A[0][0];

	float result = 0;
	for (uint32_t i = 0; i < cols; i++) {
		float** B = ModifyMatrix(A, rows, cols, 0, i);
		result += powf(-1, (float)i) * A[0][i] * CalcDeterminant(B, rows - 1, cols - 1);
		delete[] B;
	}
	return result;
}
float** _AlgebraicAdjoint(float** A, uint32_t rows, uint32_t cols) {
	if (rows != cols) return NULL;
	float** result = CreateMatrix(rows, cols);
	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < cols; j++) {
			float** B = ModifyMatrix(A, rows, cols, i, j);
			result[i][j] = powf(-1, (float)i + j) * CalcDeterminant(B, rows - 1, cols - 1);
			delete[] B;
		}
	}
	return result;
}
Matrix::Matrix(uint32_t rows, uint32_t cols, float** matrix) : cols(cols), rows(rows), mat(matrix ? matrix : GenerateMatrix(rows, cols)) {}
Matrix::Matrix(Vector2 a) : cols(2), rows(1) {
	mat = CreateMatrix(rows, cols);
	mat[0][0] = a.x, mat[1][0] = a.y;
}

float Matrix::Determinant() { return CalcDeterminant(mat, rows, cols); }
Matrix Matrix::ReverseMatrix() {
	if (rows != cols) return Matrix();
	return Matrix(rows, cols, _AlgebraicAdjoint(mat, rows, cols)).Tranpos() / Determinant();
}
Matrix Matrix::Tranpos() {
	float** a = CreateMatrix(cols, rows);
	for (uint32_t i = 0; i < cols; i++) for (uint32_t j = 0; j < rows; j++) a[i][j] = mat[j][i];
	return Matrix(cols, rows, a);
}
void Matrix::Print() { PrintMatrix(mat, rows, cols); }

Matrix Matrix::operator+(Matrix other) {
	if (other.rows != rows || other.cols != cols) return Matrix();
	Matrix result(rows, cols);
	for (uint32_t i = 0; i < rows; i++) for (uint32_t j = 0; j < cols; j++)
		result.mat[i][j] = other.mat[i][j] + mat[i][j];
	return result;
}
Matrix Matrix::operator-(Matrix other) {
	if (other.rows != rows || other.cols != cols) return Matrix();
	Matrix result(rows, cols);
	for (uint32_t i = 0; i < rows; i++) for (uint32_t j = 0; j < cols; j++)
		result.mat[i][j] = other.mat[i][j] - mat[i][j];
	return result;
}
Matrix Matrix::operator*(float other) {
	Matrix result(rows, cols);
	for (uint32_t i = 0; i < rows; i++) for (uint32_t j = 0; j < cols; j++)
		result.mat[i][j] = mat[i][j] * other;
	return result;
}
Matrix Matrix::operator/(float other) { return Matrix::operator*(1 / other); }
bool Matrix::operator== (Matrix other) {
	if (other.rows != rows || other.cols != cols) return false;
	for (uint32_t i = 0; i < rows; i++) for (uint32_t j = 0; j < cols; j++)
		if (other.mat[i][j] != mat[i][j]) return false;
	return true;
}
Matrix Matrix::operator*(Matrix other) {
	if (cols != other.rows) return Matrix();
	Matrix result(rows, other.cols);
	for (uint32_t i = 0; i < rows; i++) {
		for (uint32_t j = 0; j < other.cols; j++) {
			result.mat[i][j] = 0;
			for (uint32_t k = 0; k < cols; k++) result.mat[i][j] += mat[i][k] * other.mat[k][j];
		}
	}
	return result;
}