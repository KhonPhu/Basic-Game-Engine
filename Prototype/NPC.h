#pragma once
#include "GameObject.h"
class NPC : public GameObject
{
public:
	NPC();
	NPC(Texture* texture, Vector2 position);

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	void Inputs() override;
	void AddForce(Vector2 force);

	void HandleInput(Input* input);


	~NPC();

private:
	Vector2 m_velocity;
	Vector2 m_acceleration;
};

