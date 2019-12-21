#pragma once
#include "GameObject.h"
class Enemy :public GameObject {
public:
	Enemy();
	Enemy(Texture* texture, int posX, int posY);
	void Draw(SDL_Renderer* renderer)override;
	void Update(float deltaTime)override;
	void Input();
	~Enemy();
};


