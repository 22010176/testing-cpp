#pragma once

#ifndef _LINEAR_ALGEBRA_
#define _LINEAR_ALGEBRA_

#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

struct Vector2 {
	double x = 0, y = 0;
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

float RoundNumber(float x, int pre = 2);

#endif