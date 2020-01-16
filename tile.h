#pragma once
#include "sprite.h"

class tile // USAGE: You initialise the x and y before you use, Default for tilesize is 16. Also, you will need to set the path of the sprite.
{
protected:
	entity* entComponent = new entity;
public:
	sprite* tileSprite;
	int x;
	int y;
	int tilesize = 16; // default size = 16
	
	tile(SDL_Renderer* _renderer);
};

tile::tile(SDL_Renderer* _renderer) // Warning: Tilesize is both w/h.
{
	entComponent->x = x;
	entComponent->y = y;
	entComponent->w = tilesize;
	entComponent->h = tilesize;
	if (entComponent->w = 0 || entComponent->h)
		std::cout << "ERR# There was a problem initialising the tilesize on line #21" << std::endl;
	tileSprite = new sprite(entComponent);
	
	tileSprite->loadSprite(_renderer,tileSprite->thisPath);

}
