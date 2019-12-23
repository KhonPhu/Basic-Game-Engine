#include "Input.h"


Input::Input()
{
	m_keyboardState = NULL;
}

Input::~Input()
{
}

void Input::UpdateInput()
{
	SDL_Event e;
	while(SDL_PollEvent(&e))
	{
		switch(e.type)
		{
		case SDL_KEYDOWN :
			m_keyboardState = SDL_GetKeyboardState(NULL);
			break;
		case SDL_KEYUP :
			m_keyboardState = SDL_GetKeyboardState(NULL);
			break;

		}
	}

}


bool Input::IsKeyDown(SDL_Scancode key)
{
	if(m_keyboardState != nullptr)
	{
		if(m_keyboardState[key] == true)
			return true;
	}
	return false;
}

bool Input::IsKeyUp(SDL_Scancode key)
{
	if (m_keyboardState != nullptr)
	{
		if (m_keyboardState[key] == true)
			return false;
	}
	return true;
}

