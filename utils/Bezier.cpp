#include "Bezier.h"

uint64_t Factorial(int x) {
	if (x < 0) return 0;
	uint64_t a = 1; for (int i = 1; i <= x; i++) a *= (uint64_t)i;
	return a;
}

uint64_t* CalcFactorials(int x) {
	uint64_t* a = new uint64_t[x + 1]; a[0] = 1;
	for (int i = 1; i <= x; i++) a[i] = a[i - 1] * i;
	return a;
}

vector<Vector2> GetBezierCo(vector<Vector2> points) {
	int len = (int)points.size();
	if (len < 2) return vector<Vector2>();
	vector<Vector2> result;
	uint64_t* f = CalcFactorials(len);
	for (int i = 0; i < len; i++) {
		uint64_t a = f[len - 1] / (f[i] * f[len - i - 1]);
		Vector2 c(points[i].x * a, points[i].y * a);
		result.push_back(c);
	}
	delete[] f;
	return result;
}

void DrawBezierCurf(SDL_Renderer* renderer, vector<Vector2> Points, double dx) {
	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	int len = (int)Points.size();
	if (len < 2) return;
	
	vector<Vector2> Cof = GetBezierCo(Points);
	double x0 = Points[0].x, y0 = Points[0].y, x = 0, y = 0;
	for (double i = 0; i <= 1.f + dx / 2; i += dx) {
		x = y = 0;
		for (int j = 0; j < len; j++) {
			Vector2 a = Cof[j];
			x += a.x * pow(i, j) * pow(1 - i, len - 1 - j);
			y += a.y * pow(i, j) * pow(1 - i, len - 1 - j);
		}
		SDL_RenderDrawLine(renderer, (uint32_t)x0, (uint32_t)y0, (uint32_t)x, (uint32_t)y);
		x0 = x, y0 = y;
	}
	Cof.~vector();
}