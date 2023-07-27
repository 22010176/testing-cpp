#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
#include <vector>

#include "utils/Bezier.h"
#include "utils/Vector.h"

#include <SDL.h>

using namespace std;

#define WIDTH 500
#define HEIGHT 500

SDL_Rect CreateRect(int x, int y, int w, int h) {
	SDL_Rect a;	a.x = x, a.y = y, a.w = w, a.h = h;
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
				rects.push_back(CreateRect(x - (w / 2), y - (h / 2), w, h));
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