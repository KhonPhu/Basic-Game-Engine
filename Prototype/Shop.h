#pragma once
#include "GameObject.h"
class Shop : public GameObject
{
public:
	Shop();
	Shop(Texture* texture, Vector2 position);

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	void Inputs() override;
	void AddForce(Vector2 force);

	void HandleInput(Input* input);


	~Shop();

private:
	Vector2 m_velocity;
	Vector2 m_acceleration;
};

