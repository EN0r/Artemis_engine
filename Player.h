#pragma once
#include "ECS.h"
#include "sprite.h"
#include "graphics.h"
class player
{
	entity* playerEntity;

	SDL_Color gOver = { 255,255,255,255 };

private:

	// encapsulating here
	bool isMoving = false;

	graphics handle;

public:

	bool getMovementState() { return isMoving; }

	~player();
	player(entity* _ent);

	int x, y;
	const char* name;
	int health;
	float walkSpeed = 1.0f;
	float jumpPower = 250.0f;
	void gameOver(SDL_Renderer* _renderer,sprite* plrSprite);
};

player::player(entity* _ent) // Move entity position to move the *player*
{
	this->playerEntity = _ent; // makes the pointer of this to the entity passed
	this->x = _ent->x;
	this->y = _ent->y;
}

player::~player()
{
	delete playerEntity;
}

void player::gameOver(SDL_Renderer* _renderer,sprite* plrSprite)
{
	handle.drawText(_renderer,"GAME OVER",325,200,200,200, gOver);
}
