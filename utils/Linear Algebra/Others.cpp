#include "others.h"

float RoundNumber(float x, int pre) {
	int a = (int)powf(10, (float)pre);
	return roundf(x * a) / a;
}

Matrix Vec2ToMat(Vec2 vec, int type) {
	float x = vec.x, y = vec.y;
	float** data = type ? new float* [1] {new float[2] {x, y}} : new float* [2] {new float{ x }, new float{ y }};
	return type ? Matrix(1, 2, data) : Matrix(2, 1, data);
}

Vec2 MatToVec2(Matrix mat) {
	float** _mat = mat.mat;
	return Vec2(_mat[0][0], mat.rows == 1 ? _mat[0][1] : mat.cols == 1 ? _mat[1][0] : 0);
}