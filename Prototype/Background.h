#pragma once
#include "GameObject.h"
#include "Texture.h"

class Background : public GameObject
{
public:
	Background();
	Background(Texture* texture, int posX, int posY);

	void Update(float deltaTime) override;
	void Draw(SDL_Renderer* renderer) override;
	void Input() override;


	~Background();
};

