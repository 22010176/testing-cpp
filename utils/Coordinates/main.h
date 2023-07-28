#pragma once

#ifndef _Coordinate_XY_
#define  _Coordinate_XY_

#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <SDL.h>

#include "../Draws.h"
#include "../Vector.h"

using namespace std;

void DrawAxis(SDL_Renderer* renderer, uint32_t x, uint32_t y);
void DrawGrid(SDL_Renderer* renderer, int div, int x, int y);

void DrawOxyCoordinate(SDL_Renderer* renderer, int x, int y, int div);

double GetRange(uint32_t div, uint32_t size);
Vector2 GetCoordinates(double range, double pos, double div);
#endif // !_Coordinate_XY_
