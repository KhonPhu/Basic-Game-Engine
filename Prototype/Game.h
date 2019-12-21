#pragma once
#include "Game.h"

//using SDL & Texture class
#include "Texture.h"
#include "Background.h"
#include <vector>

class Game
{
public:
	Game();
	bool Start();
	void ProcessInput();
	void Update();
	void Draw();
	void Shutdown();
	void Run(const char* title, int width, int height, bool fullscreen);
	void Destroy();
	~Game();

private:
	// the window we will be redenering to
	SDL_Window* sdlWindow;
	// 2D redenring context for a window
	SDL_Renderer* sdlRenderer;
	//flag for the game loop
	bool isGameOver;

	// gets the current time since last update
	unsigned int lastUpdateTimer;
	//creating the game object
	std::vector<GameObject*> m_gameObjects;
};