#include <SDL/SDL.h>
#include "MAINGAME.h"

int main(int arg, char** argv) {
	SDL_Init(SDL_INIT_EVERYTHING);
	MAINGAME game;
	game.run();
	system("PAUSE");
	return 0;
}