#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

SDL_Texture * loadTexture(std::string fileName);
SDL_Renderer * renderer = NULL;
SDL_Texture * texture = NULL;
SDL_Window * window = NULL;


using namespace std;

void setRect(SDL_Rect & rectangle, int x, int y, int bx, int by);

int main()
{
	window = SDL_CreateWindow("Renderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		cout << " Failed to create Window\n";
		return 0;
	}
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		cout << "Renderer Creation failed\n";
		return 0;
	}
	SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_Rect drawRect;
	setRect(drawRect, 0, 0, 300, 300);
	SDL_RenderSetViewport(renderer, &drawRect);
	int imgFlags = IMG_INIT_PNG;
	if(!(IMG_Init(imgFlags) & imgFlags))
	{
		cout << "Could not init image flags\n";
		return 0;
	}

	texture = loadTexture("images/01_bkg.png");
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	SDL_RenderPresent(renderer);

	SDL_Delay(3000);


	return 0;
}

SDL_Texture * loadTexture(std::string fileName)
{
	SDL_Texture * newTexture = NULL;
	SDL_Surface * temp = IMG_Load(fileName.c_str());
	if(temp == NULL)
	{
		cout << "Failed to load image from loadTexture(" << fileName << ")\n";
		return NULL;
	}
	newTexture = SDL_CreateTextureFromSurface(renderer, temp);
	if(newTexture == NULL)
	{
		cout << "Failed to set Texture from surface in loadTexture(" << fileName << ")\n";
		return NULL;
	}

	SDL_FreeSurface(temp);
	return newTexture;
}



void setRect(SDL_Rect &rectangle, int x, int y, int bx, int by)
{
	rectangle.x = x;
	rectangle.y = y;
	rectangle.w = bx;
	rectangle.h = by;
}

