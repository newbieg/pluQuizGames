#include "gui_game.h"

#define FPS 60

const int BKGIMAGECOUNT = 3;
const int ITEMCOUNT = 10;

SDL_Surface* bkg[BKGIMAGECOUNT];
SDL_Surface* items[ITEMCOUNT];
SDL_Surface* screen;
SDL_Surface* currentBKG;

using namespace std;

// We need to load images into ram, get a basic array of items, etc.
void loadResources(int lvlIndex); // lvlIndex is used to set the currentBKG
SDL_Surface* loadImage(string path);
void setBkg();
void addItem();
void cleanup();
void clearBkg();

void drawDelay(unsigned int frameTick); // modulate the FPS of the game, reduce cpu load.


int playGame(SDL_Window * window, SDL_Surface * scr)
{
	screen = scr;
	loadResources(0);
	// draw a bkg
	clearBkg();
	SDL_UpdateWindowSurface(window);
	
	cout << "Made it to the game...\n";

	unsigned int tickData;

	bool playing = true;
	int count = 1000;
	while(count > 0)
	{
		count --;
		tickData = SDL_GetTicks();

		// detect end of game...
		playing = false;
		/* We got some stuff to set up like double buffering,
		 actuall key interface, 
		 and item motion, as well as dettecting when an Item drops
		 too far. 
		 */



		drawDelay(tickData); // leave here, it's the pause between frames...
	}

	cleanup();
}

SDL_Surface* loadImage(string path)
{
	SDL_Surface* retSurf = NULL;
	SDL_Surface * loader = IMG_Load(path.c_str());
	if(loader == NULL)
	{
		cout << "Could not load image: " << path << "\n";
		exit(0);
	}
	retSurf = SDL_ConvertSurface(loader, screen->format, 0);
	SDL_FreeSurface(loader);
	
	return retSurf;
}

void loadResources(int lvlIndex)
{

	bkg[0] = loadImage("images/01_bkg.png");
	bkg[1] = loadImage("images/02_bkg.png");
	bkg[2] = loadImage("images/03_bkg.png");

	items[0] = loadImage("images/banana.png");
	items[1] = loadImage("images/avocado.png");
	items[1] = loadImage("images/cherries.png");

	currentBKG = bkg[lvlIndex];
}



void cleanup()
{
 	for(int i = 0; i < BKGIMAGECOUNT; i ++)
	{
		SDL_FreeSurface(bkg[i]);
	}

}



void clearBkg()
{
	SDL_Rect scr_size;
	SDL_BlitScaled(currentBKG, NULL, screen, &(screen->clip_rect) );
}



void drawDelay(unsigned int frameTick)
{
	if((1000/FPS) > SDL_GetTicks() - frameTick)
	{
		SDL_Delay((1000 / FPS) - (SDL_GetTicks() - frameTick));
	}
}


