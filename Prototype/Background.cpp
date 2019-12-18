#include "Background.h"
#include <iostream>

using namespace std;

Background::Background()
{
	m_positionX = 0;
	m_positionY = 0;
	m_texture = nullptr;
	cout << "Map Founded" << endl;

}

Background::Background(Texture* texture, int posX, int posY)
{
	m_texture = texture;
	m_positionX = posX;
	m_positionY = posY;
}

void Background::Update(float deltaTime)
{
}

void Background::Draw(SDL_Renderer* renderer)
{
	m_texture->Draw(renderer, m_positionX, m_positionY);
}

void Background::Input()
{
}

Background::~Background()
{
	cout << "map destructor" << endl;
}
