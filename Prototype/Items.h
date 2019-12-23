#pragma once
#include "GameObject.h"
class Items : public GameObject
{
public:
	Items();
	Items(Texture* texture, Vector2 position);

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	void Inputs() override;
	void AddForce(Vector2 force);

	void HandleInput(Input* input);


	~Items();

private:
	Vector2 m_velocity;
	Vector2 m_acceleration;
};

