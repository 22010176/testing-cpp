#include "others.h"

float RoundNumber(float x, int pre) {
	int a = (int)powf(10, (float)pre);
	return roundf(x * a) / a;
}

Matrix Vec2ToMat() { return Matrix(); }

Vector2 MatToVec2() { return Vector2(); }