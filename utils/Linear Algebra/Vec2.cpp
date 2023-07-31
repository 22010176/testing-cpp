#include "Vec2.h"

Vec2::Vec2(float x, float y) : x(x), y(y) {}
float Vec2::DotProduct(Vec2 a, Vec2 b) { return a.x * b.x + a.y * b.y; }
float Vec2::Len() { return sqrt(x * x + y * y); }

bool Vec2::operator==(Vec2& other) { return x == other.x && y == other.y; }
bool Vec2::operator>(Vec2& other) { return this->Len() > other.Len(); }
bool Vec2::operator<(Vec2& other) { return this->Len() < other.Len(); }
Vec2 Vec2::operator+(Vec2& other) { return Vec2(x + other.x, y + other.y); }
Vec2 Vec2::operator-(Vec2& other) { return Vec2(x - other.x, y - other.y); }
Vec2 Vec2::operator*(float scalar) { return Vec2(x * scalar, y * scalar); }

void Vec2::Print() {
	
}