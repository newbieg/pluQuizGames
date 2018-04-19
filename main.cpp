#include "sdl_game.h"
#include <iostream>


using namespace std;

int SCREENW = 640;
const int SCREENH = 480;

int main()
{
	cout << "Init the Window...\n";
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Could not init Video SDL\n";
		return 0;
	}
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREENW, SCREENH, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		cout << "Could not init window with the settup\n";
		SDL_Quit();
		return 0;
	}
	screen = SDL_GetWindowSurface(window);
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xff, 0xff, 0xff));

	SDL_UpdateWindowSurface(window);
	SDL_Delay(3000);


	/*OK, so the window is created, now let's play the game.
	 * We'll leave this to the sdl_game.h file to handle.*/

	playGame(window, screen);


	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;


}
