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
#include "luaMain.h"




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

	luaCpp c;
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
void layers::start(SDL_Renderer* _renderer, SDL_Window* window) // implemented lua support!
{ 
	c.setRenderer(_renderer);
	c.initLua();
	c.startLua("luaScripts/main.lua");

	lua_getglobal(c.getState(), "Start");
	if (lua_pcall(c.getState(), 0, 0, 0))
	{
		std::cout << "WARNING  # Start function not found!" << "\n";
		return;
	}
}


void layers::mapLayer(SDL_Renderer* _renderer)
{

}




void layers::playerLayer(SDL_Renderer* _renderer)
{

}

void layers::spriteLayer(SDL_Renderer* _renderer)
{	
	lua_getglobal(c.getState(),"Update");
	if (lua_pcall(c.getState(), 0, 0, 0))
	{
		std::cout << "WARNING # Update function not found!" << "\n";
		return;
	}
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