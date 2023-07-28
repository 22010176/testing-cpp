#include <cstdint> 
#include <iostream>
#include <cmath>
#include <vector>
#include <string>

#include "utils/Bezier.h"
#include "utils/Vector.h"
#include "utils/Coordinates/main.h"
#include "utils/Draws.h"

#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;

uint32_t WIDTH = 500, HEIGHT = 500, OldWidth = 0, OldHeight = 0, fps = 60;

int main(int, char* []) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Window* window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_Color color = { 255,255,255 };
	int x, y, aw, ah;

	bool isRunning = true;
	SDL_Event event;
	string result;

	vector<SDL_Rect> rects;
	vector<Vector2> Points;

	int x0 = WIDTH / 2, y0 = HEIGHT / 2, div = 100;
	uint32_t tick = SDL_GetTicks();
	Vector2 rangeOx = GetCoordinates(WIDTH, x0, div), rangeOy = GetCoordinates(HEIGHT, y0, div);
	
	while (isRunning) {
		if (SDL_GetTicks() - tick < 1000 / fps) continue;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		DrawOxyCoordinate(renderer, x0, y0, div);

		result = "";
		SDL_GetMouseState(&x, &y);
		result += std::to_string(x) + ", " + std::to_string(y);

		SDL_GetRendererOutputSize(renderer, &aw, &ah);
		if (aw != WIDTH || ah != HEIGHT) {
			OldWidth = WIDTH, OldHeight = HEIGHT;
			WIDTH = aw, HEIGHT = ah;
			x0 = WIDTH / 2, y0 = HEIGHT / 2;

			rangeOx = GetCoordinates(WIDTH, x0, div), rangeOy = GetCoordinates(HEIGHT, y0, div);
		}

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			case SDL_MOUSEBUTTONDOWN:
				break;
			}
		}
		DisplayText(renderer, "./fonts/Source_Code_Pro/static/SourceCodePro-Bold.ttf", color, result, CreateRect(0, 0, (int)result.length() * 15, 25));
		SDL_RenderPresent(renderer);
		tick = SDL_GetTicks();
	}

	for (SDL_Rect i : rects) SDL_free(&i);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}