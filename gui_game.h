#ifndef WHYWOULDANYONEWANTTOPLAYTHISGAME
#define WHYWOULDANYONEWANTTOPLAYTHISGAME

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>

// a non-sdl based class which handles paths to images for each animation.
//
class animation
{
	public:
		// if the pictures follow name_number.format
		// then the user only need know the number of pics per cycle
		animation(std::string firstPicture, int pictureCount);
		// if the user does not follow the above format, they
		// can still make an empty animation and add the files
		// so long as they add them in sequence using addPicture()
		animation();
		// add a picture at path to the end of an animation sequence
		bool addPicture(std::string path, int pictureCount = 0);
		// return the path to the picture at index
		std::string getPicture(int index);

	private:
		std::vector<std::string> pictures;
};



// what do we need as far as the player and enemy?
// they need health points if they can take multiple hits, and
// they need a position. 
// May extend this class in the future...
class player
{
	public:
		player(double px, double py);
		bool setXY(double px, double py);
		bool isAlive();
		bool addLife(double number);
		bool takeHit(double number);


	private:
		double hp, x, y;

};

bool openWindow(SDL_Surface * window);

bool updateWindow(SDL_Surface * window);

// index is there as we assume enemyList is an array of onscreen enemies.
// xDir and yDir are the positions that we wish the enemy to end up at.
// eventually the enemy should have a speed assigned to it and it will
// be animated as it walks to this new position.
bool moveEnemies(player * enemyList, int index, double xDir, double yDir);


// index is there as we assume playerList is an array of active players.
// xDir and yDir are the positions that we wish the player to end up at.
// eventually the player should have a speed assigned to it and will
// be animated as it walks to this new position.
bool movePlayer(player * playerList, int index, double xDir, double yDir);

// returns the player's score at the end of the game.
int playGame(SDL_Window* window, SDL_Surface* screen);


#endif
