#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>

#include <SDL.h>

using namespace std;

#define WIDTH 500
#define HEIGHT 500

struct Vector2 {
	double x, y;
	Vector2(double x, double y) : x(x), y(y) {}
};

long Factorial(int x) {
	if (x < 0) return 0;
	long a = 1; for (int i = 1; i <= x; i++) a *= i;
	return a;
}

uint64_t* CalcFactorials(int x) {
	uint64_t* a = new uint64_t[x + 1]; a[0] = 1;
	for (int i = 1; i <= x; i++) a[i] = a[i - 1] * i;
	return a;
}
int CalcC(int n, int x) { return Factorial(n) / (Factorial(x) * Factorial(n - x)); }

vector<Vector2> GetBezierCo(vector<Vector2> points) {
	int len = (int)points.size();
	if (len < 2) return vector<Vector2>();
	vector <Vector2> result;
	uint64_t* f = CalcFactorials(len);
	for (int i = 0; i < len; i++) {
		uint64_t a = f[len - 1] / (f[i] * f[len - i - 1]);
		Vector2 c(points[i].x * a, points[i].y * a);
		result.push_back(c);
	}
	delete[] f;
	return result;
}

void DrawBezierCurf(SDL_Renderer* renderer, vector<Vector2>Points, double dx = 0.05) {
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

SDL_Rect* CreateRect(int x, int y, int w, int h) {
	SDL_Rect* a = new SDL_Rect;
	a->x = x, a->y = y, a->w = w, a->h = h;
	return a;
}

int main(int, char* []) {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	bool isRunning = true;
	SDL_Event event;

	int x, y, w = 10, h = 10;

	vector<SDL_Rect> rects;
	vector<Vector2> Points;

	while (isRunning) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				SDL_GetMouseState(&x, &y);
				rects.push_back(*CreateRect(x - (w / 2), y - (h / 2), w, h));
				Points.push_back(Vector2((float)x, (float)y));
				break;
			}
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
		for (int i = 0; i < rects.size(); i++) SDL_RenderDrawRect(renderer, &rects[i]);
		DrawBezierCurf(renderer, Points, 0.001);
		SDL_RenderPresent(renderer);
	}

	for (SDL_Rect i : rects) SDL_free(&i);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}