#pragma once
#include "guiManager.h"
#include "text.h"

class editor
{
protected:

	frame* _frame = new frame(600,0,200,600);
	text _t;

public:
	void editorStart(SDL_Renderer* _renderer, SDL_Window* _window);
	void editorUpdate(SDL_Renderer* _renderer, SDL_Window* _window);
};

void editor::editorStart(SDL_Renderer* _renderer, SDL_Window* _window)
{
	int padding = 20;

	_frame->hasImage = false;
	_frame->title = "SETTINGS";
	_frame->titlesize = 30;
	_frame->loadBackround(_renderer);
	_frame->_t->settings->x = _frame->_t->settings->x + (padding - 7);
	_frame->_t->settings->w = _frame->_t->settings->w - padding;
}

void editor::editorUpdate(SDL_Renderer* _renderer, SDL_Window* _window)
{
	SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
	SDL_RenderClear(_renderer);

	_frame->drawBackround(_renderer);

}

void editorQuit()
{

}
