#include "Background.h"
#include <iostream>

using namespace std;


Background::Background()
{
	m_position.x = 0;
	m_position.y = 0;
	m_texture = nullptr;
	cout << "Map Founded" << endl;

}

Background::Background(Texture* texture, Vector2 position)
{
	m_texture = texture;
	m_position = position;
}

void Background::Update(float deltaTime)
{
}

void Background::Draw(SDL_Renderer* renderer)
{
	m_texture->Draw(renderer, m_position.x, m_position.y);
}

void Background::Inputs()
{
}

Background::~Background()
{
	cout << "map destructor" << endl;
}
