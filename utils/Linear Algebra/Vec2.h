#pragma once

#ifndef _LINEAR_ALGEBRA_
#define _LINEAR_ALGEBRA_

#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>

using namespace std;

struct Vec2 {
	float x, y;
	Vec2(float x = 0, float y = 0);
	float Len();
	static float DotProduct(Vec2 a, Vec2 b);
	void Print();

	bool operator==(Vec2& other);
	Vec2 operator+(Vec2& other);
	Vec2 operator-(Vec2& other);
	bool operator>(Vec2& other);
	bool operator<(Vec2& other);
	Vec2 operator*(float scalar);
};

#endif