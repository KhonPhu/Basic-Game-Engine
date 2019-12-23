#include "Items.h"
#include <iostream>

using namespace std;

Items::Items()
{
	cout << "Item constructor" << endl;

}

Items::Items(Texture* texture, Vector2 position)
{
	m_texture = texture;
	m_position = position;

}

void Items::Update(float deltaTime)
{

}

void Items::Draw(SDL_Renderer* renderer)
{
	m_texture->Draw(renderer, m_position.x, m_position.y);
}

void Items::Inputs()
{
}


void Items::AddForce(Vector2 force)
{

}

void Items::HandleInput(Input* input)
{

}

Items::~Items()
{
	cout << "Item destructor" << endl;
}
