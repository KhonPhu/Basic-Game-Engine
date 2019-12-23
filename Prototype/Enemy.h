#pragma once
#include "GameObject.h"
#include "Texture.h"

class Enemy :public GameObject {
public:
	Enemy();
	Enemy(Texture* texture, Vector2 position);

	void Draw(SDL_Renderer* renderer)override;
	void Update(float deltaTime)override;
	void Inputs();
	void AddForce(Vector2 force);

	void HandleInput(Input* input);


	~Enemy();

private:
	Vector2 m_velocity;
	Vector2 m_acceleration;
};


