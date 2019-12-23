#include "GameObject.h"
#include <iostream>

using namespace std;

GameObject::GameObject()
{
	cout << "gameobject constructor" << endl;
	m_position = Vector2(0, 0);
	m_texture = nullptr;	
}

GameObject::~GameObject()
{
}

void GameObject::HandleInput(Input* input)
{
}
