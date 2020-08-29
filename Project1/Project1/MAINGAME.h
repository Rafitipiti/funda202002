#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>

enum class GameState {
	PLAY,EXIT
};

class MAINGAME {
private:
	int witdh;
	int height;
	SDL_Window* window;
	//TODO-SPRITE
	void processInput();
	void init();
public:
	MAINGAME();
	~MAINGAME();
	GameState gamestate;
	void run();
	void draw();
	void update();
};

