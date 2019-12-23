#include "Vector2.h"
#include <SDL.h>

Vector2::Vector2()
{
	x = 0;
	y = 0;
}

Vector2::Vector2(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2::~Vector2()
{
}

float Vector2::Length()
{
	return sqrtf(x * x + y * y);
}

Vector2 Vector2::operator+(const Vector2 & anotherV)
{
	return Vector2(this->x + anotherV.x, this->y + anotherV.y);
}

Vector2 Vector2::operator+=(const Vector2 & anotherV)
{
	this->x += anotherV.x;
	this->y += anotherV.y;
	return* this;
}

Vector2 Vector2::operator-(const Vector2 & anotherV)
{
	return Vector2(this->x - anotherV.x, this->y - anotherV.y);
}

Vector2 Vector2::operator-=(const Vector2& anotherV)
{
	this->x -= anotherV.x;
	this->y -= anotherV.y;
	return* this;
}

Vector2 Vector2::operator*(const float &scalar)
{
	return Vector2(this->x * scalar, this->y * scalar);
}
Vector2 Vector2::operator*=(const float &scalar)
{
	this->x *= scalar;
	this->y *= scalar;
	return*this;
}

void Vector2::Normalize()
{
	float mag = sqrtf(x * x + y * y);
	this->x /= mag;
	this->y /= mag;
}

Vector2 Vector2::Normalized()
{
	Vector2 result = Vector2(0,0);
	float mag = sqrtf(x * x + y * y);
	result.x = this->x / mag;
	result.y = this->y / mag;

	return result;
}



