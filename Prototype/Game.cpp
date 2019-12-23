#include <iostream>
#include "Game.h"



using namespace std;

Game::Game() {
	// initialize SDL  
	sdlWindow = nullptr;

	sdlRenderer = nullptr;

	lastUpdateTimer = 0;

	anim = nullptr;

	input = nullptr;


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

		//Initialize Input
		input = new Input();

		// TODO : Initialize objects here

		//Map init
		Texture* mapTexture = new Texture();
		mapTexture->LoadImageFromFile("../assets/BACKGROUND.bmp", sdlRenderer);

		//Player init
		Texture* playerTexture = new Texture();
		playerTexture->LoadImageFromFile("../assets/Santa_Stand.bmp", sdlRenderer);

		//Enemy int
		Texture* enemyTexture1 = new Texture();
		enemyTexture1->LoadImageFromFile("../assets/Enemy1.bmp", sdlRenderer);

		//Shop init
		Texture* shopTexture = new Texture();
		shopTexture->LoadImageFromFile("../assets/Shop.bmp", sdlRenderer);

		//Items init
		Texture* itemTexture = new Texture();
		itemTexture->LoadImageFromFile("../assets/Potion.bmp", sdlRenderer);

		//NPC init
		Texture* npcTexture = new Texture();
		npcTexture->LoadImageFromFile("../assets/NPC.bmp", sdlRenderer);

		// Location of the Objects
		Vector2 mapVector = Vector2(0, 0);
		Vector2 playerVector = Vector2(100, 200);
		Vector2 enemy1Vector = Vector2(600, 100);
		Vector2 shopVector = Vector2(400, 400);
		Vector2 itemVector = Vector2(100, 300);
		Vector2 npcVector = Vector2(200, 0);

		// create objects 
		GameObject* map = new Background(mapTexture, mapVector);
		GameObject* player = new Player(playerTexture, playerVector);
		GameObject* enemy1 = new Player(enemyTexture1, enemy1Vector);
		GameObject* shop = new Player(shopTexture, shopVector);
		GameObject* item = new Player(itemTexture, itemVector);
		GameObject* npc = new Player(npcTexture, npcVector);

		// add the map object to the array 
		m_gameObjects.push_back(map);
		m_gameObjects.push_back(player);
		m_gameObjects.push_back(enemy1);
		m_gameObjects.push_back(shop);
		m_gameObjects.push_back(item);
		m_gameObjects.push_back(npc);

		// check if texture load successfully 
		if (mapTexture != nullptr) 
		{
			cout << "Load map texture - success" << endl;
		}
		else {
			cout << "Load map texture - failed" << endl;
			return false;
		}
		if (playerTexture != nullptr)
		{
			cout << "Load player texture - success" << endl;
			anim = new Animation(playerTexture, 1, 0.1f);
		}
		else {
			cout << "Load player texture - failed" << endl;
		}
		if (enemyTexture1 != nullptr)
		{
			cout << "Load enemy texture - success" << endl;
		}
		else {
			cout << "Load enemy texture - failed" << endl;
		}
		if (shopTexture != nullptr)
		{
			cout << "Load shop texture - success" << endl;
		}
		else {
			cout << "Load shop texture - failed" << endl;
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
		m_gameObjects[i]->Inputs();
	}

	SDL_Event e;
	// handle events on queue 
	while(SDL_PollEvent(&e))
	{
		// 'ESC' key is pressed, or close button is pressed on SDL window. 
		if(e.type == SDL_QUIT)
		{
			cout << "Quit" << endl;
			isGameOver = true;
		}
		if (e.type == SDL_SCANCODE_W)
		{
			cout << "Up" << endl;
		}
		if (e.type == SDL_SCANCODE_S)
		{
			cout << "Down" << endl;
		}
		if (e.type == SDL_SCANCODE_A)
		{
			cout << "Left" << endl;
		}
		if (e.type == SDL_SCANCODE_D)
		{
			cout << "Right" << endl;
		}
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

	//TODO: update stuff here
	anim->Update(deltaTime);
}
void Game::Draw() {
	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);

	// call the draw function of all the game objects
	for (int i = 0; i < m_gameObjects.size(); ++i) {
		m_gameObjects[i]->Draw(sdlRenderer);
	}
	anim->Draw(sdlRenderer, 100, 200);

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
		
		//Start game loop
		while (!isGameOver) {

			//check for input
			ProcessInput();
			// update object
			Update();
			//draw on the windows
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