#pragma once
#include "Windows.h"
#include <iostream>
#include <string>
#include <vector> 
#include "SDL.h"

template<typename scene>
class levelProxy
{
protected:
	std::vector<scene*> levels;
public:

};
















// CRTP

//class level // active levels
//{
//
//protected:
//	virtual void getLevels() = 0;
//public:
//	std::string levelName = "Unassigned.lvl"; // save as levelfile NEED TODO
//	int levelID = NULL; // if levelID is null obviously Something went wrong
//	bool isActive = NULL;
//
//};
///*
//
//	general idea is to create levels that are linked to level manager
//	and then i loop through all levels w/ a index and if it has the id of the level that's passed to levelname
//	it calls the levelMain function and levelStart functions
//
//
//*/
//
//class levelManager
//{
//	int levelsRegistered = 0; // how many levels there has been loaded in playtime.
//	level* loadedLevel;
//protected:
//	virtual void listLevels() = 0;
//public:
//
//	bool enteredLevel(level* levelListener); // Is going to be a trigger. At the moment it's useless.
//
//	bool loadLevel(SDL_Renderer* _renderer, level* LevelName);
//	void unloadLevel(); // when unloading a level a loading screen appears.
//	void renderLoadedLevel(SDL_Renderer* _renderer); // this->loadedLevel.levelMain();
//};
//
//template<typename CRTP>
//class levelProxy : levelManager
//{
//
//public:
//
//	CRTP* p;
//
//	virtual void listLevels()
//	{
//		p& = dynamic_cast<CRTP*>(this); // set p to reference
//		if (p->levelID == 0)
//		{
//			p->levelID = levelManager.levelsRegistered + 1;
//
//		}
//	}
//
//	void clearList() // always want to clearList to free up memory.
//	{
//		ZeroMemory(p,NULL);
//		p = NULL;
//	}
//};
//
//
//bool levelManager::loadLevel(SDL_Renderer* _renderer, level* lvlID)
//{
//	int debSZ = sizeof(loadedLevel);
//
//	if (lvlID->levelID == NULL)
//	{
//		// assign level ID
//		lvlID->levelID = levelsRegistered + 1;
//	}
//
//	if (lvlID->levelID == NULL) // If it still hasnt set the levelID then return false
//		return false;
//
//	// if it hasn't returned by now then it's sure to exist
//	if (sizeof(lvlID) == debSZ) // already has a level loaded
//		return false;
//
//
//	this->loadedLevel = lvlID;
//	if (loadedLevel->levelID == lvlID->levelID)
//		return true;
//	// now need to return true :)
//	return true;
//}
//
//void levelManager::renderLoadedLevel(SDL_Renderer* _renderer)
//{
//	if (loadedLevel->levelID == 0)
//		return;
//
//	loadedLevel->isActive = true;
//}
//
//void levelManager::unloadLevel()
//{
//	ZeroMemory(loadedLevel, NULL); // ZeroMem The level
//	loadedLevel = NULL; // Always a good practice to NULLIFY memory after zeroMeming it
//	
//}
//
//
////template <typename Derived>
////class scene : level // inherits from level
////{
////protected:
////	Derived* pPtr = new Derived*
////
////public:
////	virtual void getLevels()
////	{
////		p& = dynamic_cast<Derived*>(this);
////	}
////
////	Derived* getParent() { return pPtr; }
////};
////
////
