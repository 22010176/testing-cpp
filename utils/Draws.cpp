#include "Draws.h"

SDL_Rect CreateRect(int x, int y, int w, int h) { SDL_Rect a = { x,y,w,h };	return a; }
void DrawRect(SDL_Renderer* renderer, int x, int y, int width, int height) {
	SDL_Rect a = CreateRect(x, y, width, height);
	SDL_RenderFillRect(renderer, &a);
	SDL_free(&a);
}
void DisplayText(SDL_Renderer* renderer, const char content[], SDL_Rect rect, SDL_Color color, const char path[]) {
	TTF_Font* font = TTF_OpenFont(path, 500);
	SDL_Surface* text = TTF_RenderText_Solid(font, content, color);
	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text);
	SDL_RenderCopy(renderer, text_texture, NULL, &rect);

	SDL_DestroyTexture(text_texture);
	SDL_FreeSurface(text);
	TTF_CloseFont(font);
}

void DisplayText(SDL_Renderer* renderer, string content, SDL_Rect rect, SDL_Color color, const char path[]) {
	TTF_Font* font = TTF_OpenFont(path, 500);
	SDL_Surface* text = TTF_RenderText_Solid(font, content.c_str(), color);
	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text);
	SDL_RenderCopy(renderer, text_texture, NULL, &rect);

	SDL_DestroyTexture(text_texture);
	SDL_FreeSurface(text);
	TTF_CloseFont(font);
}