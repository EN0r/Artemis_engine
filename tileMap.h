#pragma once
#include <iostream>
#include <vector>
#include "tile.h"
#include "Window.h"
#include <cmath>
#include "graphics.h"
#include "vec2.h"
class tileMap
{
private:
	std::vector<tile> placedTiles;
	std::vector<vec2> gridPlaces;
	int _sWidth;
	int _sHeight;
	graphics* _graphics = new graphics;

public:

	int _totWidth = 10; // More higher this value laggier but bigger tilemap. Anything above 2000 is not reccomended. Default: 1000
	int _totHeight = 80; // More higher this value laggier but bigger tilemap. Anything above 1000 is not reccomended.Default: 800
	int gridSize = 16;

	bool enableGrid = true;
	tileMap(SDL_Renderer* _renderer);
	void drawTile();
	void tileGrid(SDL_Renderer* _renderer); 

};



// draw tile grid

void tileMap::tileGrid(SDL_Renderer* _renderer)
{
	if (enableGrid == true)
	{
		
		float grdDrawSizeW = ceil(_totWidth / gridSize); // how many grids draw on current screen()
		float grdDrawSizeH = ceil(_totHeight / gridSize); // now loop through and draw. This is, VERY VERY Slow so it will need to be reworked.

		// draw on x axis
		unsigned int origPosX = 0; // default at 0x0 ( NOT HEX )
		unsigned int origPosY = 0;
		unsigned int yCount = 0;
		vec2 storep;
		for (unsigned int c = 0; c < grdDrawSizeW; c++)
		{
			origPosX = origPosX + gridSize;
			storep.x = origPosX;
			storep.y = origPosY;
			gridPlaces.push_back(storep); // needa make store function

			std::cout << "Grid Operation started." << std::endl;

			if (c == grdDrawSizeW - 1) // when it hits last box to render it puts y down by 1
			{
				c = 0;
				origPosY = origPosY + gridSize;
				yCount++;

				gridPlaces.push_back(storep);
				storep.y = origPosY;
				storep.x = origPosX;
				if (yCount == grdDrawSizeH) // need to make draw function to iterate through array and draw
				{
					gridPlaces.push_back(storep);
					storep.y = origPosY;
					storep.x = origPosX;
					std::cout << "Grid Operation done." << std::endl;
				}

			}


		}
		

	}
	else
	{
		std::cout << "Tile grid Disabled." << std::endl;
	}


}

tileMap::tileMap(SDL_Renderer* _renderer)
{

	// initialise game window screen
	SDL_GetRendererOutputSize(_renderer, &_sWidth, &_sHeight);
	_graphics = new graphics;
}