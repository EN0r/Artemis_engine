#pragma once
#include "SDL.h"

bool AABB(SDL_Rect* A, SDL_Rect* B) // returns true if collides
{
	if (A->x < B->x + B->w && A->x + A->w > B->x + B->h && A->y < B->y + B->h && A->y + A->h > B->y)
		return true;

	return false;

}