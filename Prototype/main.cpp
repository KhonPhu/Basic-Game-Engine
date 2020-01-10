#include <iostream>
#include <SDL.h>
#include "Game.h"

using namespace std;

int main(int argc, char** argv)
{
	Game* game = new Game();

	game->Run("Welcome", 800, 600, false);

	delete game;
	return 0;

	//Dummy Text
}