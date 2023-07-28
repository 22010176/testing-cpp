#pragma once

#ifndef _Draws_SDL_
#define _Draws_SDL_
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>

using namespace std;

SDL_Rect CreateRect(int x, int y, int w, int h);
void DisplayText(SDL_Renderer* renderer, const char path[], SDL_Color color, const char content[], SDL_Rect rect);
void DisplayText(SDL_Renderer* renderer, const char path[], SDL_Color color, string content, SDL_Rect rect);
void DrawRect(SDL_Renderer* renderer, int x, int y, int width, int height);

#endif // !_Draws_SDL_
