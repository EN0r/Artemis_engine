#include "graphics.h"
#include <iostream>
window* wind;

// graphics is deprecated

void graphics::drawText(SDL_Renderer* _renderer, const char* Text,float x, float y, float w, float h, SDL_Color color) // make this not so laggy and shit
{

	TTF_Font* font = TTF_OpenFont("Fonts/OpenSans-Regular.ttf", 25);

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, Text, color);

	SDL_Texture* message = SDL_CreateTextureFromSurface(_renderer, surfaceMessage); 
	
	if (message == NULL)
	{
		std::cout << "NULL";
	}

	TTF_CloseFont(font);

	SDL_Rect message_Rect;
	message_Rect.x = x;
	message_Rect.y = y;
	message_Rect.w = w;
	message_Rect.h = h;

	SDL_RenderCopy(_renderer, message, NULL, &message_Rect);

	SDL_DestroyTexture(message);
	SDL_FreeSurface(surfaceMessage);

}

void graphics::fillRect(SDL_Renderer* _renderer, SDL_Rect* pos, SDL_Color color)
{
	window* _instance = new window;
	_instance->setDrawColor(_renderer, color.r, color.b, color.g, color.a);

	SDL_RenderFillRect(_renderer,pos);

	delete _instance;

}

void graphics::drawRect(SDL_Renderer* _renderer ,float x, float y, float w, float h,int r,int g,int b,int a)
{
	SDL_Rect* size = new SDL_Rect;
	size->x = x;
	size->y = y;
	size->w = w;
	size->h = h;

	window* _instance = new window;
	_instance->setDrawColor(_renderer,r,g,b,a);

	SDL_RenderDrawRect(_renderer,size);
	delete _instance;
}