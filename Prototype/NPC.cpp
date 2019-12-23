#include "NPC.h"
#include<iostream>

NPC::NPC()
{
	std::cout << "NPC constructor" << std::endl;

}

NPC::NPC(Texture* texture, Vector2 position)
{
	m_texture = texture;
	m_position = position;
	m_velocity = Vector2(0, 0);
	m_acceleration = Vector2(0, 0);
}

void NPC::Draw(SDL_Renderer* renderer)
{
	m_texture->Draw(renderer, m_position.x, m_position.y);
}

void NPC::Update(float deltaTime)
{
	m_velocity += m_acceleration * deltaTime;
	m_position += m_velocity * deltaTime;
}

void NPC::Inputs()
{
}

void NPC::AddForce(Vector2 force)
{
	m_acceleration += force;
}

void NPC::HandleInput(Input* input)
{
	AddForce(Vector2(-5, 5));
}

NPC::~NPC()
{
	std::cout << "NPC destructor" << std::endl;
}