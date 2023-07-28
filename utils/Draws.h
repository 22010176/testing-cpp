#pragma once

#ifndef _Draws_SDL_
#define _Draws_SDL_
#include <SDL.h>
#include <string>
#include <SDL_ttf.h>

using namespace std;

SDL_Rect CreateRect(int x, int y, int w, int h);
void DisplayText(SDL_Renderer* renderer, const char content[], SDL_Rect rect, SDL_Color color = { 255,255,255 }, const char path[] = "fonts/Source_Code_Pro/static/SourceCodePro-Regular.ttf");
void DisplayText(SDL_Renderer* renderer, string content, SDL_Rect rect, SDL_Color color = { 255,255,255 }, const char path[] = "fonts/Source_Code_Pro/static/SourceCodePro-Regular.ttf");
void DrawRect(SDL_Renderer* renderer, int x, int y, int width, int height);

#endif // !_Draws_SDL_
