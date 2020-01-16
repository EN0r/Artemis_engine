#pragma once
#include <iostream>
#include "SDL.h"
#include "graphics.h"


class game
{

public:

	void Update(SDL_Renderer* _renderer);
	void Start(SDL_Renderer* _renderer,SDL_Window* _window);
	void Render(SDL_Renderer* _renderer);
	~game();

};

