#pragma once
//#include "Matrix2.h"
#include <math.h>

class Vector2
{
public:
	float m_x;
	float m_y;
	
	Vector2();
	Vector2(float x, float y);
	Vector2(Vector2 & v2);
	~Vector2();

	Vector2 scale(float scaler);
	float dot(Vector2 & v2);
	float magnitude();
	void normalise();
	operator float*();

	// operator oveloads 
	Vector2 &operator= (Vector2 & v2);
	Vector2 &operator+= (const Vector2 & v2b);
	friend Vector2 operator+ (Vector2 & v2a, Vector2 & v2b);
	Vector2 &operator-= (const Vector2 & v2b);
	friend Vector2 operator- (Vector2 & v2a, Vector2 & v2b);
	Vector2 &operator*= (const Vector2 & v2b);
	friend Vector2 operator* (Vector2 & v2a, Vector2 & v2b);
	friend Vector2 operator* (float f, Vector2 & v2);
	friend Vector2 operator* (Vector2 & v2, float f);
//	friend Vector2 operator* (Vector2 & v2, Matrix2 & m2);
//	friend Vector2 operator* (Matrix2 & m2, Vector2 & v2);
};


