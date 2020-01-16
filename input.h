#pragma once
#include "SDL.h"


class inputState
{

public:

	void getMousePosition(int& x, int& y);
	bool leftButtondown();
	void keyDown(const char* keydown);
};

//void inputState::keyDown(const char* keydown)
//{
//
//	SDL_Event ewent;
//
//	while (SDL_PollEvent(&ewent))
//	{
//		switch (ewent.type)
//		{
//		case SDL_KEYDOWN:
//			keydown = SDL_GetKeyName(ewent.key.keysym.sym);
//		}
//	}
//
//}

void inputState::getMousePosition(int& x, int& y)
{

	SDL_GetMouseState(&x, &y);

}

void getMousePositions(int& x, int& y)
{

	SDL_GetMouseState(&x, &y);

}

bool inputState::leftButtondown()
{

	if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		return true;
	}
	else
	{
		return false;
		// Probably need to add some error handling in this function to make sure it does not cause errors.
	}

}
