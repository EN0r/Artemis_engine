#include "game.h"
#include "input.h"
#include "guiMain.h"
#include "layerHandler.h"
#include "ECS.h"
#include "sprite.h"
graphics* _graphics = new graphics;

inputState* _inputState = new inputState;

layers* _layer = new layers;

SDL_Color color3;

/*

	ATM memory leak free :) 26/12/19

*/



/*
	returns color. Instead of constantly creating new color in update i decided
	that i will make a SetColor function instead of having 500 objects of color
	to prevent a memory leak
*/

SDL_Color SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) 
{
	color3 = { r , g , b , a };
	return color3;
}

game::~game()
{
	delete _graphics;
	delete _layer;
	delete _inputState;
	
}

void game::Update(SDL_Renderer* _renderer)
{
	
	SDL_SetRenderDrawColor(_renderer, 20, 10, 50, 255);
	SDL_RenderClear(_renderer);


	// Anything in this gap is rendered at the very bottom


	// Call all layer systens
	
	_layer->mapLayer(_renderer);
	_layer->spriteLayer(_renderer);
	_layer->playerLayer(_renderer);
	_layer->textLayer(_renderer);
	_layer->drawLayer(_renderer);
	_layer->uiLayer(_renderer);

	// Anything in this gap is rendered at the very top


}

void game::Start(SDL_Renderer* _renderer, SDL_Window* _window)
{
	// usually we need to init/Load the sprite data into the component
	_layer->start(_renderer,_window);


}