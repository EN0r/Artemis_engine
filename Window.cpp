#include "Window.h"

SDL_Window* window::createWindow(const char* _windowName, int _screenWidth, int _screenHeight)
{
	SDL_Window* wind = SDL_CreateWindow(_windowName,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth,_screenHeight,SDL_WINDOW_SHOWN);
	if (wind == nullptr )
	{
		return NULL;
	}
	return wind;
}



bool window::setDrawColor(SDL_Renderer* _renderer,int r, int g, int b, int a)
{
	if (SDL_SetRenderDrawColor(_renderer, r, g, b, a) == 0)
	{
		return true;
	}
	return false;
}
