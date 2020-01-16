#pragma once
#include "windows.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <time.h>
#include <WinUser.h>
#include "input.h"

class mouse
{
	int mX;
	int mY;

	int _sWidth;
	int _sHeight;

public:
	bool mouseScriptable = true;

	bool lockMovement();
	void gridMovement(SDL_Window* wind,SDL_Renderer* _renderer,int lock, int gridSize);
	
	template<typename T>
	bool isNegativeX(T val);
};

int roundUp(int numToRound, int multiple) // credit to some guy on stackoverflow for this code
{
	if (multiple == 0)
	{
		return numToRound;
	}

	int roundDown = ((int)(numToRound) / multiple) * multiple;
	int roundUp = roundDown + multiple;
	int roundCalc = roundUp;
	return (roundCalc);
}


// make this function to know what direction the mouse is moving in x axis
template<typename T>
bool mouse::isNegativeX(T x)
{
	getMousePositions(mX,mY);


}

void mouse::gridMovement(SDL_Window* wind,SDL_Renderer* _renderer,int lockValue, int gridSize)
{
	getMousePositions(mX, mY);
	SDL_GetRendererOutputSize(_renderer, &_sWidth, &_sHeight);

	float newPosX = roundUp(mX,gridSize);
	float newPosY = roundUp(mY, gridSize);

	SDL_WarpMouseInWindow(wind,newPosX,newPosY);

}