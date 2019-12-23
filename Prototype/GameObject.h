#pragma once
#include "Texture.h"
#include "Vector2.h"
#include "Input.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Inputs() = 0;
	virtual void HandleInput(Input* input);


protected:
	Vector2 m_position;
	Texture* m_texture;
};

