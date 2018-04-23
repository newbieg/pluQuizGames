#include "gui_game.h"

int JUNKFROMOLDAPI = 0;

using namespace std;

int playGame(SDL_Window * window, SDL_Surface * screen)
{
	// draw a bkg
	SDL_Surface * bkg = NULL;
	SDL_Surface * loader = IMG_Load("images/01_bkg.png");
	if(loader == NULL)
	{
		cout << "Could not load bkg image\n";
		exit(0);
	}
	bkg = SDL_ConvertSurface(loader, screen->format, 0);
	SDL_FreeSurface(loader);
	SDL_Rect scr_size;
	SDL_BlitScaled(bkg, NULL, screen, &(screen->clip_rect) );
	SDL_UpdateWindowSurface(window);

	
	cout << "Made it to the game...\n";
}

