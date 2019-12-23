#pragma once
#include "GameObject.h"
#include "Texture.h"

class Background : public GameObject
{
public:
	Background();
	Background(Texture* texture, Vector2 position);

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	void Inputs() override;


	~Background();

private:
	Vector2 m_velocity;
	Vector2 m_acceleration;
};

