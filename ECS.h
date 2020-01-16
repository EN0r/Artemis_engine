#pragma once
#include <iostream>
#include <vector>
// Need a pool

// not a real ECS but it just works without any memory issues.

class pool // only want 1 pool ever declared in whole code.
{
	int amount;
public:
	virtual ~pool() = default;

};



// Need a entity object

class entity : public pool // Multiple can exist
{
	
	const char* name = "entity";

public:

	SDL_Rect* thisSz = new SDL_Rect;
	float x = 0.0f; // both of these are defaulted at /NULLPTR
	float y = 0.0f;

	//default to 16
	int w = 16;
	int h = 16;
	

	// enable/disable coll
	bool canCollide = true; // true is default
	
	// need a vector of components instead of names 0_0
	std::vector<const char*> componentList; // component name
	// need to remove these sooner or later due to it not following ECS format.
	void setName(const char* N) { this->name = N; }
	const char* getName() { return this->name; }
	void initEnt();
};

void entity::initEnt()
{
	thisSz->x = x;
	thisSz->y = y;
	thisSz->w = w;
	thisSz->h = h;
}
// Need's components to be added to entity

/*
	end usage is : // using Sprite as a example
	comp = component<sprite>()->newInstance();
*/
template<typename _component> // datatype of the component
class component : public entity // create a holder for all components instead of using a vector and use the getChildren function in the system
{
	// create component instance function to return.

	

	// create a children function in _system



public:

	_component newInstance();

};

template<typename _component>
_component newInstance()
{
	_component* comp = new _component;
	return comp;
}

class _system
{
public:


	// Add Component
	template<typename _componentName>
	_componentName* addComponent(entity* ent, _componentName* name);

	template<typename _componentName>
	_componentName* getComponent(entity* ent, _componentName* name);

};


// class functions


template<typename _componentName>
_componentName* _system::getComponent(entity* ent, _componentName* componentPtr) // fix this returns NULL
{

	unsigned int index = 0;
	for (index = 0; index < ent->componentList.size(); index++) // if the component has no objects assigned in the vector this gets skipped
	{
		if (ent->componentList[index] == componentPtr->getName())
		{
			std::cout << " component was found of that name." << std::endl;
			return componentPtr;
		}
		else
		{
			std::cout << "No component of that name was found." << std::endl;
			// add errror handling for later
			return NULL;
		}
	}
	
	return componentPtr;
}


template<typename _componentName>
_componentName* _system::addComponent(entity* ent, _componentName* componentPtr)
{

	//typename std::vector<_componentName>::iterator it = std::find(ent->componentList.begin(), ent->componentList.end(), _componentName->name);
	unsigned int index = 0;
	for (index = 0; index < ent->componentList.size(); index++)
	{
		if (ent->componentList[index] == componentPtr->getName())
		{
			std::cout << "Component already found. Aborting operation." << std::endl;
			return componentPtr;
		}
		else
		{
			ent->componentList.insert(ent->componentList.begin() , componentPtr->getName());
			return componentPtr;
		}
	}

	//if (it != ent->componentList.end())
	//{
	//	std::cout << "Component already found. Aborting operation." << std::endl;
	//}
	//else
	//{
	//	std::cout << "done." << std::endl;
	//	ent->componentList.push_back(_componentName->name);
	//}

	return NULL;
}