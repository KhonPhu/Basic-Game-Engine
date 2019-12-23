#pragma once
#include <math.h>
#include <vector>

class Vector2
{
public:
	int x;
	int y;

public:
	Vector2();
	Vector2(int x, int y);
	~Vector2();

	float Length();

	Vector2 operator+(const Vector2& anotherV);

	Vector2 operator+=(const Vector2& anotherV);

	Vector2 operator-(const Vector2& anotherV);

	Vector2 operator-=(const Vector2& anotherV);

	Vector2 operator*(const float& scalar);

	Vector2 operator*=(const float& scalar);

	void Normalize();

	Vector2 Normalized();


};

