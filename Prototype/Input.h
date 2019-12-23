#pragma once
#include "Vector2.h"
#include <SDL.h>

class Input
{
private:

	// keyboard specifications 
	const Uint8* m_keyboardState;


public:
	Input();
	~Input();


	// @brief   updates the mouse events 
	void UpdateInput();


	// @briefkey pressed 
	bool IsKeyDown(SDL_Scancode key);
	// @briefkey released 
	bool IsKeyUp(SDL_Scancode key);



};

