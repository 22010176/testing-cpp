#include "Linear_Algebra.h"

Vector2::Vector2(double x, double y) : x(x), y(y) {}
Vector2::Vector2() {}
double Vector2::DotProduct(Vector2 a, Vector2 b) { return a.x * b.x + a.y * b.y; }
double Vector2::Len() { return sqrt(x * x + y * y); }

bool Vector2::operator==(Vector2& other) { return x == other.x && y == other.y; }
bool Vector2::operator>(Vector2& other) { return this->Len() > other.Len(); }
bool Vector2::operator<(Vector2& other) { return this->Len() < other.Len(); }
Vector2 Vector2::operator+(Vector2& other) { return Vector2(x + other.x, y + other.y); }
Vector2 Vector2::operator-(Vector2& other) { return Vector2(x - other.x, y - other.y); }
Vector2 Vector2::operator*(double scalar) { return Vector2(x * scalar, y * scalar); }
