#pragma once
#include "GameObject.h"
#include "Texture.h"

class Player : public GameObject
{
public:
	Player();
	Player(Texture* texture, Vector2 position);

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	void Inputs() override;
	void AddForce(Vector2 force);

	void HandleInput(Input* input);


	~Player();
	
private:
	Vector2 m_velocity;
	Vector2 m_acceleration;
};

