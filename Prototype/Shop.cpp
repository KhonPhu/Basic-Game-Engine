#include "Shop.h"
#include <iostream>

using namespace std;

Shop::Shop()
{
	cout << "Shop constructor" << endl;

}

Shop::Shop(Texture* texture, Vector2 position)
{
	m_texture = texture;
	m_position = position;
	
}

void Shop::Update(float deltaTime)
{
	
}

void Shop::Draw(SDL_Renderer* renderer)
{
	m_texture->Draw(renderer, m_position.x, m_position.y);
}

void Shop::Inputs()
{
}


void Shop::AddForce(Vector2 force)
{
	
}

void Shop::HandleInput(Input* input)
{
	
}

Shop::~Shop()
{
	cout << "Shop destructor" << endl;
}

