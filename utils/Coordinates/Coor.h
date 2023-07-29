#pragma once

#ifndef _Coordinate_XY_
#define  _Coordinate_XY_

#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <SDL.h>
#include <functional>

#include "../Draws.h"
#include "../Linear Algebra/Linear.h"

using namespace std;

struct Vertex { Vector2 a, b; };

void DrawAxis(SDL_Renderer* renderer, uint32_t x, uint32_t y);
void DrawGrid(SDL_Renderer* renderer, int div, int x, int y);

void DrawOxyCoordinate(SDL_Renderer* renderer, int x, int y, int div);

double GetRange(int div, int size);
double GetCoordinates(double range, double origin, double div, double pos);
void DisplayPos(SDL_Renderer* renderer, int x0, int y0, int x, int y, int div);
#endif // !_Coordinate_XY_
