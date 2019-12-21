#include <iostream>
#include "Game.h"
#include"Enemy.h"


using namespace std;

Game::Game() {
	// initialize SDL  
	sdlWindow = nullptr;

	sdlRenderer = nullptr;

	lastUpdateTimer = 0;



	// if the initialization was not successful 
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		// disable the game loop
		isGameOver = true;
		//print failed message
		cout << "Initialize SDL - failed" << endl;
	}
	else {
		// enable to game loop
		isGameOver = false;
		//print a success message
		cout << "Initialize SDL - success" << endl;
	}
}
bool Game::Start() {
	// create the renderer for the window created. 
	sdlRenderer = SDL_CreateRenderer(sdlWindow, 0, -1);
	if (sdlRenderer != nullptr) {
		cout << "Create Renderer - success" << endl;

		// TODO : Initialize objects here

		Texture* mapTexture = new Texture();
		mapTexture->LoadImageFromFile("../assets/BACKGROUND.bmp", sdlRenderer);
		// create a map object 
		GameObject* map = new Background(mapTexture, 0, 0);
		// add the map object to the array 
		m_gameObjects.push_back(map);



		//initialize enemy texture
		Texture* enemyTexture = new Texture();
		enemyTexture->LoadImageFromFile("../assets/knight.bmp", sdlRenderer);
		//create teh first enemy
		GameObject* enemy1 = new Enemy(enemyTexture, 10, 20);
		//add the first enemy to the array
		m_gameObjects.push_back(enemy1);


		Texture* enemyTexture1 = new Texture();
		enemyTexture1->LoadImageFromFile("../assets/knight.bmp", sdlRenderer);
		//Create teh second enemy
		GameObject* enemy2 = new Enemy(enemyTexture1, 25, 653);
		//add the second enemy to the array
		m_gameObjects.push_back(enemy2);

		//load the texture 
		if (mapTexture != nullptr) {

			cout << "Load map texture - success" << endl;


		}
		else {
			cout << "Load map texture - failed" << endl;
			return false;
		}

		// Get the current clock time 
		lastUpdateTimer = SDL_GetTicks();

		return true;
	}
	cout << "Create Rendereer - failed" << endl;

	return false;
		 
}
void Game::ProcessInput() {
	//TODO: get ur input here
	
	// call the input function of all the game objects 
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->Input();
	}
}
void Game::Update() {
	// calculate deltaTime 
	// current time - time since last update 
	unsigned int ticks = SDL_GetTicks() - lastUpdateTimer;
	// change this from milliseconds to seconds 
	float deltaTime = ticks / 100.0f;

	// call the update function of all the game objects 
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->Update(deltaTime);
	}

	// Get the current time  
	lastUpdateTimer = SDL_GetTicks();
	//cout << "DeltaTime: " << deltaTime << endl;

	//TODO: update stuff here
	//anim->Update(deltaTime);
	//m_player->Update(deltaTime);
}
void Game::Draw() {
	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);

	for (int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->Draw(sdlRenderer);
	}

	SDL_RenderPresent(sdlRenderer);
}
void Game::Shutdown() {

}
void Game::Run(const char* title, int width, int height, bool fullscreen) {
	int creationFlag = 0;
	if (!fullscreen) {
		creationFlag = SDL_WINDOW_SHOWN;
	}
	else {
		creationFlag = SDL_WINDOW_FULLSCREEN;
	}
	sdlWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, creationFlag);

	if (sdlWindow != nullptr && Start()) {
		cout << "CreateWindow - Success" << endl;
		while (!isGameOver) {
			ProcessInput();
			Update();
			Draw();
		}
	}
	else {
		cout << "CreateWindow - Failed" << endl;
	}
	//clean up
	Shutdown();
	Destroy();
}
void Game::Destroy() {
	SDL_DestroyWindow(sdlWindow);
	SDL_DestroyRenderer(sdlRenderer);
	SDL_Quit();
}
Game::~Game() {

}