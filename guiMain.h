#pragma once
#include "graphics.h"
#include <iostream>
#include <vector>
#include "input.h"
#include "collisionFunctions.h"

bool checkBoxClicked1 = false;
bool buttonDown = false;

int frame1Storedx;
int frame1Storedy;

class artemisFrame
{

	// Properties about this frame:
	bool draggable = true;
	int x;
	int y;
	int w;
	int h;

	int mx;
	int my;

	int border = 2;

	

	std::vector<const char*> elementList = { "checkBox", "textLabel" };

	SDL_Color thisColor = { 255,255,255,255 };
	SDL_Color backColor = { 10,10,10,225 };
	// Define possible objects

	struct checkBox
	{
		artemisFrame* parentFrame;
		int w;
		int h;
		SDL_Color hoveredColor;
		SDL_Color defaultColor;
		int screenX;
		int screenY;
		int padX = 10;
		int padY = 10;
	};

	struct button
	{
		artemisFrame* parentFrame;
		int w;
		int h;
		SDL_Color hoveredColor;
		SDL_Color defaultColor;
		int screenX;
		int screenY;
		int padX = 10;
		int padY = 10;
	};

public:

	

	artemisFrame(graphics* _graphics, SDL_Renderer* _renderer,SDL_Rect* size);

	bool addElement(SDL_Renderer* _renderer,const char* elementName, artemisFrame* frame, SDL_Color color, SDL_Color hoveredColor = { 0,0,200,255 });

	void setColor(SDL_Color newColor) { thisColor = newColor; } // used to set border color

private:

	bool createElement(const char* name, SDL_Renderer* _renderer, artemisFrame* parentFrame , SDL_Color color = { 0,0,255,255 }, SDL_Color hoveredColor = { 0,0,200,255 });

};



artemisFrame::artemisFrame(graphics* _graphics,SDL_Renderer* _renderer,SDL_Rect* size)
{
	// When you construct update *this* variables

	inputState* _input = new inputState;





	this->x = size->x;
	this->y = size->y;
	this->w = size->w;
	this->h = size->h;

	// Make it a usable object 
	
	SDL_Rect* sizeFill = new SDL_Rect;
	sizeFill->w = size->w - (border + 1);
	sizeFill->h = size->h - (border + 1);
	sizeFill->x = size->x + 1;
	sizeFill->y = size->y + 1;



	//if (_input->leftButtondown() && AABB(size, mouseBox) && this->draggable == true || _input->leftButtondown() && AABB(sizeFill, mouseBox) && this->draggable == true)
	//{

	//	sizeFill->x = this->mx + 1;
	//	sizeFill->y = this->my + 1;

	//	frame1Storedx = sizeFill->x;
	//	frame1Storedy = sizeFill->y;

	//	std::cout << this->mx << this->my << std::endl;

	//	_graphics->drawRect(_renderer, this->mx, this->my, size->w, size->h, this->thisColor.r, this->thisColor.b, this->thisColor.b, this->thisColor.a);
	//	_graphics->fillRect(_renderer, sizeFill, this->backColor);
	//	

	//	delete mouseBox;
	//	delete _input;
	//	delete sizeFill;
	//	return;
	//}

	_graphics->drawRect(_renderer, this->x, this->y, size->w, size->h, this->thisColor.r, this->thisColor.b, this->thisColor.b, this->thisColor.a);
	
	_graphics->fillRect(_renderer, sizeFill, this->backColor);

	delete _input;
	delete sizeFill;
}

bool artemisFrame::createElement(const char* name, SDL_Renderer* _renderer, artemisFrame* parentFrame, SDL_Color color, SDL_Color hoveredColor)
{ 
	if (name == "checkBox") // Messy way to detect input but you know it is what it is.
	{
		
		// init graphics link
		graphics* _graphics = new graphics;
		// main

		inputState* _inputState = new inputState;

		checkBox* thisCheckbox = new checkBox; // init the struct

		thisCheckbox->parentFrame = parentFrame;
		thisCheckbox->defaultColor = color;
		thisCheckbox->hoveredColor = hoveredColor;
		thisCheckbox->w = 20;
		thisCheckbox->h = 20;

		/*
		
			Maths of positioning:
				checkBox->x = artemisFrame.x + checkBoxPadding.y; checkbox padding will be of type vector2
				checkBox->y = artemisFrame.y + checkBoxPadding.y;
		
		*/

		thisCheckbox->screenX = parentFrame->x + thisCheckbox->padX;
		thisCheckbox->screenY = parentFrame->y + thisCheckbox->padY;

		// init a new sdl_rect so we can draw a rectangle.

		SDL_Rect* totalPosition = new SDL_Rect;
		totalPosition->x = thisCheckbox->screenX;
		totalPosition->y = thisCheckbox->screenY;
		totalPosition->w = thisCheckbox->w;
		totalPosition->h = thisCheckbox->h;
		
		int posY;
		int posX;

		_inputState->getMousePosition(posX, posY);
		
		SDL_Rect* mouseBox = new SDL_Rect;
		mouseBox->x = posX;
		mouseBox->y = posY;
		mouseBox->w = 1;
		mouseBox->h = 1;

		if (_inputState->leftButtondown() && AABB(totalPosition,mouseBox)) // detects if mouse hitbox is over the button
		{
			if (!checkBoxClicked1)
			{

				checkBoxClicked1 = true;
				_graphics->fillRect(_renderer, totalPosition, thisCheckbox->hoveredColor);
				
				delete totalPosition;
				delete _graphics;
				return true;
			}

			if (checkBoxClicked1)
			{
				checkBoxClicked1 = false;
				_graphics->drawRect(_renderer, totalPosition->x, totalPosition->y, totalPosition->w, totalPosition->h, color.r, color.b, color.g, color.a);

				delete totalPosition;
				delete _graphics;
				return false;
			}

			//Memory cleanup

			delete totalPosition;
			delete _graphics;
			return true;
		} else {
			
			if (checkBoxClicked1 == true)
			{
				_graphics->fillRect(_renderer, totalPosition, thisCheckbox->hoveredColor);
				delete totalPosition;
				delete _graphics;
				delete _inputState;
				return true;
			}
			else
			{
				_graphics->drawRect(_renderer, totalPosition->x, totalPosition->y, totalPosition->w, totalPosition->h, color.r, color.b, color.g, color.a);
				delete totalPosition;
				delete _graphics;
				delete _inputState;
				return false;

			}

			//_graphics->drawRect(_renderer,totalPosition->x, totalPosition->y, totalPosition->w, totalPosition->h,color.r, color.b, color.g, color.a);

			//Memory cleanup

			delete totalPosition;
			delete _graphics;
			delete _inputState;
			return false;
		}



	}


	// button

	if (name == "button") // Messy way to detect input but you know it is what it is.
	{

		// init graphics link
		graphics* _graphics = new graphics;
		// main

		int posY = 0;
		int posX = 0;

		inputState* _inputState = new inputState;

		checkBox* button = new checkBox; // init the struct

		button->parentFrame = parentFrame;
		button->defaultColor = color;
		button->hoveredColor = hoveredColor;
		button->w = 20;
		button->h = 20;


		button->screenX = parentFrame->x + button->padX;
		button->screenY = parentFrame->y + button->padY;

		// init a new sdl_rect so we can draw a rectangle.

		SDL_Rect* totalPosition = new SDL_Rect;
		totalPosition->x = button->screenX;
		totalPosition->y = button->screenY;
		totalPosition->w = button->w;
		totalPosition->h = button->h;

		_inputState->getMousePosition(posX, posY);

		SDL_Rect* mouseBox = new SDL_Rect;
		mouseBox->x = posX;
		mouseBox->y = posY;
		mouseBox->w = 1;
		mouseBox->h = 1;

		if (_inputState->leftButtondown() && AABB(totalPosition, mouseBox)) // detects if mouse hitbox is over the button
		{
			if (!buttonDown)
			{

				buttonDown = true;
				_graphics->fillRect(_renderer, totalPosition, button->hoveredColor);

				delete totalPosition;
				delete _graphics;
				return true;
			}


			//Memory cleanup

			delete totalPosition;
			delete _graphics;
			return true;
		}
		else 
		{
			_graphics->drawRect(_renderer, totalPosition->x, totalPosition->y, totalPosition->w, totalPosition->h, color.r, color.b, color.g, color.a);
			delete totalPosition;
			delete _graphics;
			delete _inputState;
			return false;

		}

			//_graphics->drawRect(_renderer,totalPosition->x, totalPosition->y, totalPosition->w, totalPosition->h,color.r, color.b, color.g, color.a);

			//Memory cleanup

			delete totalPosition;
			delete _graphics;
			delete _inputState;
			return false;
		}

}

bool artemisFrame::addElement(SDL_Renderer* _renderer,const char* elementName, artemisFrame* frame, SDL_Color color ,SDL_Color hoveredColor) // Adds element of a type to the selected frame
{
	bool clicked = createElement(elementName , _renderer, frame);
	return clicked;
}