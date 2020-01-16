#pragma once
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

class text
{
private:
	TTF_Font* font;
	SDL_Surface* surfMessage;
	SDL_Texture* texture;
	

public:
	SDL_Rect* settings = new SDL_Rect;

	void loadText(SDL_Renderer* _renderer, const char* text, SDL_Color color, int textSize);
	~text();
	void drawText(SDL_Renderer* _renderer);

};

text::~text()
{
	SDL_FreeSurface(surfMessage);
	TTF_CloseFont(font);
	SDL_DestroyTexture(texture);


	delete settings;
	delete font;
	delete texture;
	delete surfMessage;
}

void text::loadText(SDL_Renderer* _renderer, const char* text, SDL_Color color, int textSize)
{

	font = TTF_OpenFont("Fonts/OpenSans-Regular.ttf", textSize);
	surfMessage = TTF_RenderText_Solid(font, text, color);
	texture = SDL_CreateTextureFromSurface(_renderer, surfMessage);

}

void text::drawText(SDL_Renderer* _renderer)
{
	SDL_RenderCopy(_renderer,texture,NULL,settings);

}