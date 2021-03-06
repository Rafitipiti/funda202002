#include "MAINGAME.h"
#include <iostream>
using namespace std;

MAINGAME::MAINGAME()
{
	window = nullptr;
	witdh = 800;
	height = 600;
	gamestate = GameState::PLAY;
}

MAINGAME::~MAINGAME()
{
}

void MAINGAME::run()
{
	init();
	//TODO SPRITE
	update();
}

void MAINGAME::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			gamestate = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION: 
			cout << event.motion.x << event.motion.y << endl;
			break;
		}
	}
}

void MAINGAME::init()
{
	window = SDL_CreateWindow("Clase 01", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, witdh, height, SDL_WINDOW_OPENGL);
	if (window == nullptr) {
		//TODO mostrar error
	}
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK) {
		//TODO mostrar error de glew
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
}

void MAINGAME::draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//TODO update sprite
	SDL_GL_SwapWindow(window);
}

void MAINGAME::update()
{
	while (gamestate != GameState::EXIT) {
		processInput();
		draw();
	}
}
