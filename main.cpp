#include "Window.h"
#include "graphics.h"
#include "game.h"
#include "editor.h"

/*

	PERSONAL NOTE TO SELF:
		MAKE SURE TO CREATE WINDOW BEFORE GETTING RENDERER OBJECT!!!
		IF I DO RENDERER WONT EXIST IN CURRENT CONTEXT!
		ALSO, MAKE SURE TO INITIALIZE SDL AND TTF
*/

bool quit = false;

int main(int argc, char* argv[])
{

	// grab window instance

	window* _window = new window;

	// grab game instance

	game* _game = new game;
	
	// sdl based variables

	editor editorHand;

	// Main sdl stuffs

	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();

	//SDL_Window* window = SDL_CreateWindow("Hi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	//SDL_Renderer* _renderer = SDL_CreateRenderer(window, -1, 0);


	// implement a settings file to dictate size.
	SDL_Event windowEvent;
	SDL_Window* window = _window->createWindow("game",900,700);
	SDL_Renderer* _renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Window* editor = _window->createWindow("editor",800,600);
	SDL_Renderer* _editRenderer = SDL_CreateRenderer(editor, -1, 0);

	delete _window;

	_game->Start(_renderer, window);
	editorHand.editorStart(_editRenderer,editor);
	while (true)
	{
		
		


		if (SDL_PollEvent(&windowEvent))
		{

			if (SDL_QUIT == windowEvent.type)
			{

				quit = true;

				break;

			}

		}


		// game loop
		SDL_RenderPresent(_renderer);
		SDL_RenderPresent(_editRenderer);
		_game->Update(_renderer);
		editorHand.editorUpdate(_editRenderer, editor);
		
	}
	

	
	SDL_DestroyWindow(window);
	SDL_Quit();
	TTF_Quit();
	return 0;

}