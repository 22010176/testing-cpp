#include "main.h"

void DrawGrid(SDL_Renderer* renderer, int div, int x, int y) {
	int width, height;
	SDL_GetRendererOutputSize(renderer, &width, &height);
	int rectSize = 2, i = 1;
	bool posVe = true, negVe = true, posHo = true, negHo = true;

	SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
	while (posVe || negVe || posHo || negHo) {
		int vePos = i * div - rectSize / 2, hoPos = i * div - rectSize / 2;

		if (x + vePos >= width) posVe = false;
		if (x - vePos <= 0) negVe = false;
		if (y + hoPos >= height) negHo = false;
		if (y - hoPos <= 0) posHo = false;

		if (posVe) DrawRect(renderer, x + vePos - rectSize / 2, 0, rectSize, height); // positive Vertical
		if (negVe) DrawRect(renderer, x - vePos - rectSize / 2, 0, rectSize, height); // positive Vertical
		if (posHo) DrawRect(renderer, 0, y + hoPos - rectSize / 2, width, rectSize); // positive Vertical
		if (negVe) DrawRect(renderer, 0, y - hoPos - rectSize / 2, width, rectSize); // positive Vertical
		i++;
	}
}

void DrawAxis(SDL_Renderer* renderer, uint32_t x, uint32_t y) {
	int width, height;
	SDL_GetRendererOutputSize(renderer, &width, &height);
	SDL_Color color = { 255,255,255 };

	int axisSize = 5, fontSize = 20;

	DisplayText(renderer, "fonts/Source_Code_Pro/static/SourceCodePro-Regular.ttf", color, "O", CreateRect(x - axisSize - fontSize, y - axisSize - fontSize * 2, fontSize, fontSize * 2));

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	DrawRect(renderer, 0, y - axisSize / 2, width, axisSize);			// Ox
	DrawRect(renderer, x - axisSize / 2, 0, axisSize, height);		// Oy
}

void DrawOxyCoordinate(SDL_Renderer* renderer, int x, int y, int div) {
	DrawGrid(renderer, div, x, y);
	DrawAxis(renderer, x, y);
}

double GetRange(uint32_t div, uint32_t size) { return size / div; }
Vector2 GetCoordinates(double range, double origin, double div) { return Vector2((origin - range) / div, (range - origin) / div); }