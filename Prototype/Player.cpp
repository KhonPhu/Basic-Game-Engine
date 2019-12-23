#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
	cout << "player constructor" << endl;

}

Player::Player(Texture* texture, Vector2 position)
{
	m_texture = texture;
	m_position = position;
	m_velocity = Vector2(0, 0);
	m_acceleration = Vector2(0, 0);
}

void Player::Update(float deltaTime)
{
	m_velocity += m_acceleration * deltaTime;
	m_position += m_velocity * deltaTime;
}

void Player::Draw(SDL_Renderer* renderer)
{
	m_texture->Draw(renderer, m_position.x, m_position.y);
}

void Player::Inputs()
{
}


void Player::AddForce(Vector2 force)
{
	m_acceleration += force;
}

void Player::HandleInput(Input* input)
{
	if(input->IsKeyDown(SDL_SCANCODE_W))
	{
		AddForce(Vector2(0, - 2));
	}
	if(input->IsKeyDown(SDL_SCANCODE_S))
	{
		AddForce(Vector2(0, 2));
	}
	if(input->IsKeyDown(SDL_SCANCODE_A))
	{
		AddForce(Vector2(-2, 0));
	}
	if(input->IsKeyDown(SDL_SCANCODE_D))
	{
		AddForce(Vector2(2, 0));
	}
}

Player::~Player()
{
	cout << "player destructor" << endl;
}
