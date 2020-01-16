#pragma once
#include "ECS.h"
#include "SDL.h"
#include "collisionFunctions.h"


class collider
{
	SDL_Rect* _entSz = new SDL_Rect;
	entity* _thisEnt;
	const char* name = "Collider2D";
	entity* _ent;
public:
	collider(entity* _ent);
	~collider();

	const char* getName() { return name; }
	bool detectAllCollisions(entity* _thisEnt,pool* entitylist[], int arraySize);

private:

};

collider::~collider()
{
	delete _entSz;
	delete _thisEnt;
}

collider::collider(entity* _ent)
{
	_thisEnt = _ent;

	_entSz->x = _ent->x;
	_entSz->y = _ent->y;
	_entSz->w = _ent->w;
	_entSz->h = _ent->h;
}

bool collider::detectAllCollisions(entity* _thisEnt, pool* entitylist[], int arraySize) // need the entity list and the entity which you want to detect collision with
{
	for (int i = 0; i < arraySize; i++)
	{
		entitylist[i];
		_ent = dynamic_cast<entity*>(entitylist[i]);
		
		// create entity rect
		
		
		if (_ent->canCollide == true)
		{
			SDL_Rect* newRect = new SDL_Rect;
			newRect->x = _ent->x;
			newRect->y = _ent->y;
			newRect->w = _ent->w;
			newRect->h = _ent->h;

			SDL_Rect* _ThisRect = new SDL_Rect;
			_ThisRect->x = _thisEnt->x;
			_ThisRect->y = _thisEnt->y;
			_ThisRect->w = _thisEnt->w;
			_ThisRect->h = _thisEnt->h;

			if (AABB(newRect, _ThisRect))
			{
				return true;
			}

			
			delete _ThisRect;
			delete newRect;
			delete _ent;
			return false;
		}
		
	}
	return false;
}