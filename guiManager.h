#pragma once
#include "SDL.h"
#include "graphics.h"
#include "SDL_image.h"
#include <string>
#include "text.h"

class frame // not using sprite class as it;s spesifically for gameObjects
{

	SDL_Surface* surface = new SDL_Surface;
	SDL_Texture* texture;


	//create new graphics handle
	graphics g; // not pointer to make it so it does not go out of scope and not needed to cleanup

public:
	bool hasImage = false;
	const char* title = "UNASSIGNED";
	SDL_Rect* settings = new SDL_Rect;
	SDL_Color backroundColor = { 120,120,120,255 };
	SDL_Color textColor = { 100,100,100,255 };
	SDL_Color barColor = { 0,0,0,255 };

	SDL_Rect* barThickness = new SDL_Rect;

	text* _t = new text;

	frame(int x, int y, int w, int h);
	~frame(); // memory cleanup
	int titlesize = 20;

	void drawBackround(SDL_Renderer* _renderer);

	void loadBackround(SDL_Renderer* _renderer, const char* path);

};

frame::frame(int x, int y, int w, int h)
{
	this->settings->x = x;
	this->settings->w = w;
	this->settings->h = h;
	this->settings->y = y;
}

void frame::loadBackround(SDL_Renderer* _renderer, const char* path = NULL)
{
	if (hasImage)
	{
		surface = IMG_Load(path);
		texture = SDL_CreateTextureFromSurface(_renderer, surface);
	}
	else
	{
		_t->settings->x = this->settings->x;
		_t->settings->y = this->settings->y;
		_t->settings->w = this->settings->w;
		_t->settings->h = 40;
		_t->loadText(_renderer, title, textColor, titlesize);
		hasImage = false;
	}
}


void frame::drawBackround(SDL_Renderer* _renderer)
{
	if (hasImage)
	{
		SDL_RenderCopy(_renderer, texture, NULL, settings);
	}
	else
	{

		
		g.fillRect(_renderer, settings, backroundColor);
		_t->drawText(_renderer);
		barThickness->x = settings->x;
		barThickness->y = _t->settings->y + (titlesize + 5);
		barThickness->w = settings->w;
		barThickness->h = 2;
		g.fillRect(_renderer,barThickness,barColor);

	}
}













class button
{

public:
	
	button(frame _frame);

};