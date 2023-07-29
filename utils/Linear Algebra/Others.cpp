#include "Linear_Algebra.h"

float RoundNumber(float x, int pre) {
	int a = (int)powf(10, (float)pre);
	return roundf(x * a) / a;
}
