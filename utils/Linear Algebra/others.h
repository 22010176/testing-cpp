#pragma once

#ifndef _OTHERS_LINEAR_
#define _OTHERS_LINEAR_
#include <cmath>

#include "Matrix.h"
#include "Vec2.h"

float RoundNumber(float x, int pre = 2);

Matrix Vec2ToMat(Vec2 vec, int type = 0);
Vec2 MatToVec2(Matrix mat);

#endif