#include "Bezier.h"
#include "Vector.h"

Vector2::Vector2(double x, double y) : x(x), y(y) {}
Vector2::Vector2() : x(0), y(0) {}

double Vector2::Dot(Vector2 a, Vector2 b) { return a.x * b.x + a.y * b.y; }
double Vector2::Len() { return sqrt(x * x + y * y); }

