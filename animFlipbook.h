#pragma once
#include "sprite.h"
#include <iostream>
#include <charconv>
class animationTrack // need to make a new flipbook
{
	
	
	bool animTrigger = false; // default for this is false and if false it wont play.
	sprite* spriteList[]; // create a new array of sprites for it to loop through

public:
	void newList(sprite* spriteList[]);
	void setTrigger(bool trigger) { animTrigger = trigger; }
	bool playAnimation(SDL_Renderer* _renderer, int delayBetween);
	template<typename T>
	unsigned int getArraySize(T array[]);
	void setPath(const char* namingConvention);
};

/*
	ideas to get animation working:
	create a vector of the sprites.
	for loop with index++
	then do renderSprite(Sprites[index]); 

	ideas for states to work:
	AnimationStart will need to have the state passed.
	Each animation can have a state. If the state is true then the animation will play else it wont.
	
	states can also be called triggers.
	need to figure a way to flip through animation

	make a function to make animation states

	go through it and run it 

	make a set state and a get state

	state controller class
*/
template<typename T>
unsigned int animationTrack::getArraySize(T array1[])
{
	unsigned int sizeOfArray = sizeof(array1) / sizeof(array1[0]);
	return sizeOfArray;
}


// new function to iterate through path

void animationTrack::setPath(const char* nameOfFiles)
{
	/*
		general idea of this is to iterate through spriteList and +1 to the path of each so its WalkingAnim1 and second one is WalkingAnim2 ect
	*/

	unsigned int arraySz = getArraySize<sprite*>(this->spriteList);
	char lpBuf1[16];
	char lpBuf[90];
	for (unsigned int i = 0; i < arraySz; i++)
	{
		
		this->spriteList[i]->thisPath = strcat(lpBuf, this->spriteList[i]->thisPath);
		sprintf(lpBuf1,"%d",i);
		this->spriteList[i]->thisPath = strcat(lpBuf, lpBuf1);
		
		// For Debug Purposes

		std::cout << "DEBUG# Line 71 Path is: " << lpBuf << std::endl;

	}

}

void animationTrack::newList(sprite* spriteList1[])
{
	unsigned int sizeOfArray = sizeof(spriteList1) / sizeof(spriteList1[0]); // get how many sprites inside this list.
	for (unsigned int i = 0; i < sizeOfArray; i++) // now loop through all sprites and then add them
	{
		this->spriteList[i] = spriteList1[i]; // this code... very stupid for me to implement but you know i'll do this better later
	}
}


// for play anim i need to loop through it and destroy last one it made to save on memory

bool animationTrack::playAnimation(SDL_Renderer* _renderer, int delayBetween) // returns if isplaying delay is in MS
{
	unsigned int arraySz = getArraySize<sprite*>(this->spriteList);
	// now need to render each sprite in the array.

	for (unsigned int i = 0; i < arraySz; i++)
	{
		SDL_Delay(delayBetween);
		if (sizeof(this->spriteList[i]->thisPath) > 0)
		{
			this->spriteList[i]->loadSprite(_renderer, this->spriteList[i]->thisPath); // when in use need to setup a function to automatically find all.
			this->spriteList[i]->drawSprite(_renderer);
		}
		else
		{
			std::cout << "ERR# No path loaded." << std::endl;
		}
	}

	return false;
}
