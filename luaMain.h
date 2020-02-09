#pragma once
#include "Windows.h"
#include "string"
#include <iostream>
#include "SDL.h"
#include "sprite.h"
#include "ECS.h"

extern "C"
{
#include "Vendor/lua5.3/include/lua.h"
#include "Vendor/lua5.3/include/lauxlib.h"
#include "Vendor/lua5.3/include/lualib.h"
}

#ifdef _WIN32
#pragma comment(lib, "Vendor/lua5.3/liblua53.a")
#endif

class luaCpp
{
protected:
	lua_State* L = luaL_newstate();
	SDL_Renderer* _renderer;
public:
	
	lua_State* getState() { return L; }

	void setRenderer(SDL_Renderer* _renderer1)
	{
		_renderer = _renderer1;
	}

	bool checkLua(lua_State* L, int r);
	void initLua(); // define lua funcs here
	void startLua(std::string fileDirectory);
	void luaRun();

	~luaCpp();
};

class lua_Pencil : public luaCpp
{
protected:
	entity* ent = new entity();
	sprite* nSprite = new sprite(ent);

public:

	bool lua_LoadSprite(int x, int y, int w, int h, std::string path);
	bool lua_DrawSprite();
	lua_Pencil();
};

luaCpp::~luaCpp()
{
	lua_close(L);
}

lua_Pencil::lua_Pencil()
{
	_renderer = _renderer;
}

bool lua_Pencil::lua_DrawSprite() // need to work on the glue
{
	this->nSprite->drawSprite(this->_renderer);
	return 0;
}

bool lua_Pencil::lua_LoadSprite(int x, int y, int w, int h,std::string path)
{
	this->ent->x = x;
	this->ent->y = y;
	this->ent->w = w;
	this->ent->h = h;
	nSprite->loadSprite(this->_renderer,path.c_str());
	return true;
}

// custom functions
static int pause(lua_State* L)
{
	system("pause");
	return 0;
}

static int lua_loadSprite(lua_State* L)
{
	lua_Debug ar;
	lua_Pencil penis;
	lua_getstack(L, 1, &ar);
	lua_getinfo(L, "nSl", &ar);
	int line = ar.currentline;

	int parameters = lua_gettop(L);
	if (parameters > 4)
	{
		std::cout << "ERROR # Not enough parameters for loadSprite at line :" << line << ":" << "\n";
	}

	int parameter1 = lua_tointeger(L,1);
	if (parameter1 == NULL)
	{
		std::cout << "ERROR # Invalid parameter #1 for loadSprite at line :" << line << ":" << "\n";
	}

	int parameter2 = lua_tointeger(L, 2);
	if (parameter2 == NULL)
	{
		std::cout << "ERROR # Invalid parameter #2 for loadSprite at line :" << line << ":" << "\n";
	}

	int parameter3 = lua_tointeger(L, 3);
	if (parameter3 == NULL)
	{
		std::cout << "ERROR # Invalid parameter #3 for loadSprite at line :" << line << ":" << "\n";
	}

	int parameter4 = lua_tointeger(L, 4);
	if (parameter4 == NULL)
	{
		std::cout << "ERROR # Invalid parameter #4 for loadSprite at line :" << line << ":" << "\n";
	}

	const char* parameter5 = lua_tostring(L, 5);
	if (parameter5 == NULL)
	{
		std::cout << "ERROR # Invalid parameter #5 for loadSprite at line :" << line << ":" << "\n";
	}

	if (parameters == 5)
	{
		lua_pushboolean(L, penis.lua_LoadSprite(parameter1, parameter2, parameter3, parameter4, parameter5));
	}
	
	return 0;
}

static int lua_drawSprite(lua_State* L) // DrawGlue
{
	lua_Pencil penis;
	return 0;
}

static int clearConsole(lua_State* L)
{
	system("cls");
	return 0;
}


static int consoleColor(lua_State* L)
{
	int color = static_cast<int> (luaL_checknumber(L, 1));
	system(" COLOR " + color);
	return 0;
}

static int wait(lua_State* L)
{

	int time = static_cast<int> (luaL_checknumber(L, 1));
	Sleep(time);
	return 0;
}


// Lua stuffs

bool luaCpp::checkLua(lua_State* L, int r)
{
	if (r != LUA_OK)
	{
		std::string err = lua_tostring(L, -1);
		std::cout << err << "\n";
		return false;
	}
	return true;
}

void luaCpp::initLua()
{
	luaL_openlibs(L);
}

void luaCpp::startLua(std::string fileDirectory)
{

	// register custom functions here
	lua_register(L, "wait", wait);
	lua_register(L, "clearConsole", clearConsole);
	lua_register(L, "fontColor", consoleColor);
	lua_register(L, "pause", pause);
	lua_register(L, "loadSprite", lua_loadSprite);



	checkLua(L, luaL_dofile(L, fileDirectory.c_str())); // open file and look for errors

}

void luaCpp::luaRun()
{

	lua_getglobal(L, "Update");
	if (lua_pcall(L, 0, 0, 0))
	{
		std::cout << "WARNING # Update function not found!" << "\n";
		return;
	}

	lua_getglobal(L, "Start");
	if (lua_pcall(L, 0, 0, 0))
	{
		std::cout << "WARNING  # Start function not found!" << "\n";
		return;
	}



}
