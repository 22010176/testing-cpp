#pragma once

#ifndef _Bezier_
#define _Bezier_

#include <cstdint>
#include <cmath>
#include <cstdlib>
#include <SDL.h>
#include <vector>
#include "Linear Algebra/Vec2.h"

using namespace std;

vector<Vec2> GetBezierCo(vector<Vec2> points);
void DrawBezierCurf(SDL_Renderer* renderer, vector<Vec2> Points, double dx = 0.01);
uint64_t* CalcFactorials(int x);
uint64_t Factorial(int x);

#endif