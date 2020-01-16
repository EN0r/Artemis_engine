#pragma once
#include "input.h"
#include "sprite.h"
#include "collisionFunctions.h"
#include "graphics.h"

class frame // this is polymorphic
{

protected:
	entity* thisEntity = new entity; // create a new entity for the frame so it's children can use it.
	sprite* thisSprite = new sprite(thisEntity); // this does not need to be assigned if the setBackRound is never called.
	graphics* _graphics = new graphics;
public:

	SDL_Rect* frameSize = new SDL_Rect;

	int cPosX; // these are the position of the mouse in the window
	int cPosY;

	bool visible = true; // is visible?

	inputState* mInput = new inputState;
	void updateMouse();

	~frame();

	// need to create a SetBackround function

	void loadSprite(SDL_Renderer* _renderer);

	bool setBackround(SDL_Renderer* _renderer, bool hasSprite, bool hasColor, SDL_Color color); // #1 - SDL_Renderer #2 - isSprite(False if none) #3 - Color

	bool draw(SDL_Renderer* _renderer);

	// need to add an constructor.
	frame(SDL_Rect* properties);


};

frame::frame(SDL_Rect* properties)
{
	frameSize = properties;
}


void frame::loadSprite(SDL_Renderer* _renderer)
{
	thisSprite->loadSprite(_renderer, thisSprite->thisPath);
}

bool frame::setBackround(SDL_Renderer* _renderer, bool hasSprite, bool hasColor, SDL_Color color)
{

	if (hasSprite == true)
	{
		// assign a sprite to it

		thisSprite->drawSprite(_renderer);
		return true;
	} 

	if (hasColor == true)
	{

		_graphics->fillRect(_renderer,frameSize,color);

	}

	if (hasSprite && hasColor)
	{
		std::cout << "ARGUMENT ERROR! LINE #29: PLEASE DO NOT HAVE A COLOR AND A SPRITE!" << std::endl;
		return false;

	}
	return false;
}





void frame::updateMouse()
{
	mInput->getMousePosition(cPosX,cPosY);
}

// frame components

class imageLabel : frame
{

protected:
	entity* thisE = new entity;
	sprite* thisSprite = new sprite(thisE);

public:
	float positionX = 0;
	float positionY = 0;
	int Width = 100;
	int Height = 100;

	
	imageLabel(SDL_Renderer* _renderer, sprite* spr); // takes a pointer to a sprite

	// need to make a init

	bool renderThis(SDL_Renderer* _renderer);
	void initSprite(SDL_Renderer* _renderer, sprite* spr);
};

void imageLabel::initSprite(SDL_Renderer* _renderer,sprite* spr)
{
	thisE->x = positionX;
	thisE->y = positionY;
	SDL_GetRendererOutputSize(_renderer, &Width, &Height);


	thisSprite = spr;

	thisSprite->loadSprite(_renderer, thisSprite->thisPath); // loads image inserted into sprite.
}

class imageButton : frame // use mouse class to detect if pressed
{

protected:
	SDL_Rect* mSize = new SDL_Rect;
	entity* thisE = new entity;
	sprite* thisSprite = new sprite(thisE);

public:
	float positionX = 0;
	float positionY = 0;
	int Width = 100;
	int Height = 100;



	bool clicked();
	void init(SDL_Renderer* _renderer, sprite* obj);

};

void imageButton::init(SDL_Renderer* _renderer, sprite* obj)
{
	thisE->x = positionX;
	thisE->y = positionY;
	SDL_GetRendererOutputSize(_renderer, &Width, &Height);


	thisSprite = obj;

	// initialising the mouse cursor.

	mSize->x = cPosX;
	mSize->y = cPosY;
	mSize->w = 1;
	mSize->h = 1;

	thisSprite->loadSprite(_renderer, thisSprite->thisPath); // loads image inserted into sprite.

}





bool imageButton::clicked()
{
	// Use AABB to detect if the mouse is colliding with it. If it is in the region then if they click it will trigger a function.

	// convert entity into sdl rect for pos/coords

	SDL_Rect* r = new SDL_Rect;
	r->x = thisE->x;
	r->y = thisE->y;
	r->w = thisE->w;
	r->h = thisE->h;

	if (AABB(r, mSize) && mInput->leftButtondown())
	{
		delete r;
		return true;
	}
	else
	{
		delete r;
		return false;
	}

	// release memory
	delete r;
	return false;
}



bool imageLabel::renderThis(SDL_Renderer* _renderer)
{
	if (visible)
	{
		thisSprite->drawSprite(_renderer);
		return true;
	}

	return true;
}