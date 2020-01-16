#pragma once

#include <SDL.h>

class window
{

private:

	
	SDL_Window* _window;
	

public:
	
	SDL_GLContext _context;
	
	SDL_Window* getWindow() { return _window; }; // Returns window

	SDL_Window* createWindow(const char* _windowName, int _screenWidth, int _screenHeight);
	
	int getWidth();
	int getHeight();
	bool setDrawColor(SDL_Renderer* _renderer,int r, int g, int b, int a);
};

