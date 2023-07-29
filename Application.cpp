#include <cstdint> 
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <ctime>

#include "utils/Bezier.h"
#include "utils/Linear Algebra/Linear.h"
#include "utils/Linear Algebra/Matrix.h"
#include "utils/Coordinates/Coor.h"
#include "utils/Draws.h"

#include <SDL.h>
#include <SDL_ttf.h>

using namespace std;
uint32_t WIDTH = 500, HEIGHT = 500, OldWidth = 0, OldHeight = 0, fps = 60;

void _main(int a, char* b[]) {
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Window* window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool isRunning = true;
	SDL_Event event;

	uint32_t tick = SDL_GetTicks();
	while (isRunning) {
		if (SDL_GetTicks() - tick < 1000 / fps) continue;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			}
		}
		SDL_RenderPresent(renderer);
		tick = SDL_GetTicks();
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int a, char* b[]) {
	srand(time(0)); // generate Random
	_main(a, b);
	return 0;
}