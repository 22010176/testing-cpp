#pragma once

#ifndef _Vector_Pro
#define _Vector_Pro
#include <cmath>

struct Vector2 {
	double x, y;

	Vector2(double x, double y);
	Vector2();
	double Len();
	static double Dot(Vector2 a, Vector2 b);
};

#endif // !_Vector_
