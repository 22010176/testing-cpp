#pragma once

#ifndef _Linear_
#define _Linear_

#include <cmath>
#include <functional>

struct Vector2 {
	double x, y;
	Vector2();
	Vector2(double x, double y);
	double Len();
	static double DotProduct(Vector2 a, Vector2 b);

	bool operator==(Vector2& other);
	Vector2 operator+(Vector2& other);
	Vector2 operator-(Vector2& other);
	bool operator>(Vector2& other);
	bool operator<(Vector2& other);
	Vector2 operator*(double scalar);
};

namespace BasisTransform {
	Vector2 LinearTransform(double matrix[2][2], Vector2 vec);
	Vector2 GeneralTransform(double (*f1)(Vector2), double(*f2)(Vector2), Vector2 coor);
}

#endif // !_Linear_
