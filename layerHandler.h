#pragma once
#include "SDL.h"
#include <iostream>
#include <vector>
#include "game.h"
#include "sprite.h"
#include "ECS.h"
#include "windows.h"
#include "spriteSheets.h"
#include "collider.h"
#include "animFlipbook.h"
#include "kinematicBody.h"
#include "Player.h"
#include "kbdHook.h"
#include "uiComponents.h"
#include "tileMap.h"
#include "mouse.h"




_system* _sys = new _system;
entity* playerE;
entity* floor1;
sprite* _playerSprite;
Keyboard hook;
sprite* _groundSprite;
kinematicBody* kinematic;
player* playerCharacter;
tileMap* t;
animationTrack* aTrack = new animationTrack;
mouse m;

bool grounded;

class layers
{
	

public:

	SDL_Window* wind;

	void mapLayer(SDL_Renderer* _renderer);
	void textLayer(SDL_Renderer* _renderer);
	void drawLayer(SDL_Renderer* _renderer);
	void uiLayer(SDL_Renderer* _renderer);
	void spriteLayer(SDL_Renderer* _renderer);
	void start(SDL_Renderer* _renderer,SDL_Window* window);
	void playerLayer(SDL_Renderer* _renderer);
	void end();
};


// info each sprite roughly takes 3mb of memory
entity* _groundEnt;
void layers::start(SDL_Renderer* _renderer, SDL_Window* window)
{ 
	wind = window;

	playerE = new entity;
	floor1 = new entity;
	_playerSprite = new sprite(playerE);
	_groundSprite = new sprite(floor1);

	t = new tileMap(_renderer);

	playerE->w = 160;
	playerE->h = 160;
	playerE->x = 100;
	playerE->y = 100;

	floor1->x = 0;
	floor1->y = 500;
	floor1->w = 1000;
	floor1->h = 100;
	
	//init
	t->tileGrid(_renderer);
	hook.initHook();
	playerCharacter = new player(playerE);
	_sys->addComponent<sprite>(playerE,_playerSprite);
	_sys->getComponent<sprite>(playerE, _playerSprite)->loadSprite(_renderer,"Assets/Sprites/Animations/Idle/idle.png");
	kinematic = new kinematicBody(_playerSprite);
	_sys->addComponent<kinematicBody>(playerE,kinematic);

	// add sprite to ground entity
	_sys->addComponent<sprite>(floor1, _groundSprite);
	_sys->getComponent<sprite>(floor1, _groundSprite)->loadSprite(_renderer, "Assets/Sprites/Tiles/Dirtsingle.png");
	

	playerCharacter->health = 100;

}


void layers::mapLayer(SDL_Renderer* _renderer)
{

}

int spawnpointx = 50;
int spawnpointy = 0;



void layers::playerLayer(SDL_Renderer* _renderer)
{
	_playerSprite->drawSprite(_renderer);


	playerE->initEnt();
}

void layers::spriteLayer(SDL_Renderer* _renderer)
{	
//	_ent->setName("testEntity");
//	
//		std::cout << keyDown << std::endl;

	//Implement gravity

	if (!AABB(floor1->thisSz,playerE->thisSz))
	{	
		playerE->y = playerE->y + 0.3;
		grounded = false;
	}
	if (AABB(floor1->thisSz, playerE->thisSz))
	{
		grounded = true;
	}

	if (findInMap("d"))
	{
		_playerSprite->flip = SDL_FLIP_NONE;
		playerE->x = playerE->x + 0.5;

	}

	if (findInMap("a"))
	{
		_playerSprite->flip = SDL_FLIP_HORIZONTAL;
		playerE->x = playerE->x - 0.5;
	}

	if (findInMap("1"))
	{
		playerCharacter->health = 0;
	}

	if (playerE->y > 1500)
	{
		playerE->y = spawnpointy;
		playerE->x = spawnpointx;
	}
	
	if (findInMap("space") && grounded == true)
	{
		float t = 10;
		float njp = playerCharacter->jumpPower / t;
		for (size_t i = 0; i < t; i++)
		{
			playerE->y = playerE->y - njp;
		}
	}
	

	// check if player is D-E-A-D

	if (playerCharacter->health <= 0)
	{

		playerCharacter->gameOver(_renderer,_playerSprite);
	}


	
	_groundSprite->drawSprite(_renderer);
	

	floor1->initEnt();
	playerE->initEnt();
}

void layers::textLayer(SDL_Renderer* _renderer)
{
	
}

void layers::drawLayer(SDL_Renderer* _renderer)
{

}

void layers::uiLayer(SDL_Renderer* _renderer)
{
	
}