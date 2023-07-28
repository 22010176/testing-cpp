#include "Linear.h"

Vector2::Vector2(double x, double y) : x(x), y(y) {}
Vector2::Vector2() : x(0), y(0) {}

double Vector2::DotProduct(Vector2 a, Vector2 b) { return a.x * b.x + a.y * b.y; }
double Vector2::Len() { return sqrt(x * x + y * y); }

bool Vector2::operator==(Vector2& other) { return x == other.x && y == other.y; }
bool Vector2::operator>(Vector2& other) { return this->Len() > other.Len(); }
bool Vector2::operator<(Vector2& other) { return this->Len() < other.Len(); }
Vector2 Vector2::operator+(Vector2& other) { return Vector2(x + other.x, y + other.y); }
Vector2 Vector2::operator-(Vector2& other) { return Vector2(x - other.x, y - other.y); }
Vector2 Vector2::operator*(double scalar) { return Vector2(x * scalar, y * scalar); }

Vector2 BasisTransform::LinearTransform(double matrix[2][2], Vector2 vec) {
	return Vector2(vec.x * matrix[0][0] + vec.y * matrix[0][1], vec.x * matrix[1][0] + vec.y * matrix[1][1]);
}

Vector2 BasisTransform::GeneralTransform(double (*f1)(Vector2), double(*f2)(Vector2), Vector2 coor) {
	return Vector2(f1(coor), f2(coor));
}