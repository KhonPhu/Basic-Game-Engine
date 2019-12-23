#include "Enemy.h"
#include<iostream>

Enemy::Enemy()
{
	std::cout << "Enemy constructor" << std::endl;

}

Enemy::Enemy(Texture* texture, Vector2 position)
{
	m_texture = texture;
	m_position = position;
	m_velocity = Vector2(0, 0);
	m_acceleration = Vector2(0, 0);
}

void Enemy::Draw(SDL_Renderer* renderer)
{
	m_texture->Draw(renderer, m_position.x, m_position.y);
}

void Enemy::Update(float deltaTime)
{
	m_velocity += m_acceleration * deltaTime;
	m_position += m_velocity * deltaTime;
}

void Enemy::Inputs()
{
}

void Enemy::AddForce(Vector2 force)
{
	m_acceleration += force;
}

void Enemy::HandleInput(Input* input)
{
	AddForce(Vector2(-5, 5));
}

Enemy::~Enemy()
{
	std::cout << "Enemy destructor" << std::endl;
}