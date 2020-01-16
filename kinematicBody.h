#pragma once
#include "sprite.h"

class kinematicBody
{
private:
	bool hasSpriteAssigned = false; // default is false
	int x, y;
	float velocity = 0.0f;
	bool reactToPhysics = false; // will create custom physics for this as it's kinematic
	const char* componentName = "kinematicBody2D";

public:
	
	sprite* renderSprite;
	kinematicBody(sprite* entSprite);
	~kinematicBody();

	const char* getName() { return componentName; }

	float getVelocity();
	void moveSprite(entity* _ent,SDL_Renderer* _renderer,int xpos,int ypos); // only works if sprite is assigned


};

kinematicBody::kinematicBody(sprite* entSprite = NULL) // does not have to be assigned
{
	this->renderSprite = entSprite; // if is player or enemy then this is defined
	if (entSprite != NULL)
	{
		this->hasSpriteAssigned = true;
	}

}

kinematicBody::~kinematicBody()
{
	delete this->renderSprite;
}

float kinematicBody::getVelocity()
{
	// calculate velocity using s = d/t

	float x1 = this->x;
	SDL_Delay(1000);
	float x2 = this->x;

	return x1 - x2 / 2;

}



// move sprite
void kinematicBody::moveSprite(entity* _ent,SDL_Renderer* _renderer, int x, int y)
{


	/*
		idea:
		redraw from current position to next pos
	*/
	_ent->x = x;
	_ent->y = y;
	this->renderSprite->drawSprite(_renderer);
}

//void kinematicBody::moveSpriteTo(SDL_Renderer* _renderer, int x, int y) // difference from this and movesprite is that the sprite does not get teleported and instead moves pixel by pixel
//{
//
//}