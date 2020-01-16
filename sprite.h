#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "ECS.h"


class sprite // this component 
{
	
private:
	
	SDL_Rect* thisPos = new SDL_Rect;
	SDL_Surface* thisSurface;
	SDL_Texture* thisTexture;
	entity* _ent;

protected:
	
	const char* name = "sprite"; // component name read only
public:

	SDL_RendererFlip flip = SDL_FLIP_NONE;

	const char* thisPath;
	double angle = NULL; // can be changed

	sprite(entity* ent);
	~sprite();
	const char* getName() { return name; }
	// load sprite
	void loadSprite(SDL_Renderer* _renderer, const char* path);
	// draw sprite
	void drawSprite(SDL_Renderer* _renderer);


};

sprite::sprite(entity* ent)
{
	_ent = ent;

}

sprite::~sprite()
{
	SDL_DestroyTexture(thisTexture);
	SDL_FreeSurface(thisSurface);
	delete _ent;
	delete thisPos;
}

void sprite::drawSprite(SDL_Renderer* _renderer)
{
	thisPos->x = _ent->x;
	thisPos->y = _ent->y;
	thisPos->w = _ent->w;
	thisPos->h = _ent->h;
	SDL_RenderCopyEx(_renderer, this->thisTexture, NULL, this->thisPos, angle,NULL,flip);
}

void sprite::loadSprite(SDL_Renderer* _renderer, const char* path)
{
	

	thisSurface = IMG_Load(path);
	
	if (thisSurface == NULL)
		std::cout << "Something went wrong. ERR #IMG_LOAD" << std::endl;
	thisPath = path;
	thisPos->x = _ent->x;
	thisPos->y = _ent->y;
	thisPos->w = _ent->w;
	thisPos->h = _ent->h;

	if (thisSurface == NULL)
		std::cout << "Something went wrong. ERR #SURFACE_INIT" << std::endl;

	thisTexture = SDL_CreateTextureFromSurface(_renderer,thisSurface);
	
	

}