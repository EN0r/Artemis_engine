#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "vector"
#include <cmath>

/*

	split the spritesheet into cells specified by the user (DEFAULT PARAM = 16x16)


*/


class spriteSheet
{
	const char* name = "spriteSheet";
	int iCellFound = 10; // How many cells there should be
	SDL_Rect* cellSize = new SDL_Rect;
	SDL_Rect* surfSize = new SDL_Rect;
	std::vector<SDL_Rect> cells; // cell array to store cells
	// use vector2 for cell positions

	//define column
	int column, row;

	SDL_Surface* surf;
	SDL_Texture* selectedText;

public:
	

	const char* getName() { return name;}
	void initSpriteSheet(const char* path);
	void createCells(int w = 16, int h = 16); // size of cells. Default = 16x16
	void selectCell(int cellid); // adds cell to the surface
	void renderCell(SDL_Renderer* _renderer,int cellID, int x, int y); // renders selected cell by calling rendercopyEX
	~spriteSheet();

private:


};

spriteSheet::~spriteSheet()
{
	SDL_DestroyTexture(selectedText);
	SDL_FreeSurface(surf);
}

void spriteSheet::initSpriteSheet(const char* path)
{
	// load image to the surf

	surf = IMG_Load(path);

	if (!surf)
		std::cout << "ERR# IMAGE NOT INITIALISING." << std::endl;
}

void spriteSheet::createCells(int w, int h)
{
	// GET WIDTH/HEIGHT OF SURF
	surfSize->w = surf->w;
	surfSize->h = surf->h;
	
	// GET CELL HOW MANY CELLS CAN FIT IN 1

	row = std::floor((surf->w / w));
	column = std::floor((surf->h / h));

	// for loop iterate through each row and column
	
	for (unsigned int i = 0; i < row; i + w) // iterate through each row
	{
		for (unsigned int c = 0; i < column; c + h)
		{

			SDL_Rect Rect;
			Rect.x = i;
			Rect.y = c;
			if (i == row) // if it is at end of row Row goes from left to right and column is top to bot
			{
				Rect.y = Rect.y + h;
			}
			Rect.w = w;
			Rect.h = h;

			this->cells.insert(this->cells.begin(), Rect); // now can blit from this and rendercopy it.

		}
	}

}

void spriteSheet::renderCell(SDL_Renderer* _renderer,int cellID, int x, int y)
{
	SDL_Rect thisPos;
	thisPos.x = x;
	thisPos.y = y;
	SDL_BlitSurface(this->surf,&cells[cellID],NULL,&thisPos);

	SDL_RenderCopy(_renderer,this->selectedText,NULL,&thisPos);
}