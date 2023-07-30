#include "Programs.h"

function<Vector2(Vector2)> ChangeBasis(float div = 50, float x0 = 0, float y0 = 0, float angle = 0) {
	return [=](Vector2 pos) {	return Vector2();	};
}

void _main(int a, char* b[]) {
	uint32_t WIDTH = 500, HEIGHT = 500, OldWidth = 0, OldHeight = 0, fps = 60;

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Window* window = SDL_CreateWindow("", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	bool isRunning = true;
	SDL_Event event;

	uint32_t tick = SDL_GetTicks();
	int x0 = WIDTH / 2, y0 = HEIGHT / 2, div = 50;
	function<Vector2(Vector2)> _basis = ChangeBasis((float)div, -(float)x0, -(float)y0, (float)180);
	int mouseX, mouseY;
	while (isRunning) {
		if (SDL_GetTicks() - tick < 1000 / fps) continue;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_GetMouseState(&mouseX, &mouseY);

		Vector2 pos = _basis(Vector2(mouseX, mouseY));

		string content = to_string(mouseX) + " " + to_string(mouseY);

		DisplayText(renderer, content, CreateRect(0, 0, 15 * (int)content.length(), 20));
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
