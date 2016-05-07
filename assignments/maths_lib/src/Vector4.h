#pragma once
#include "Matrix4.h"

class Vector4
{
public:
	float m_w;
	float m_x;
	float m_y;
	float m_z;

	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4(Vector4 & v4);
	~Vector4();
	Vector4 cross(Vector4 & v4);
	float dot(Vector4 & v4);
	float magnitude();
	void normalise();
	operator float*();
};
Vector4 operator+ (Vector4 & v4a, Vector4 & v4b);
Vector4 operator- (Vector4 & v4a, Vector4 & v4b);
Vector4 operator* (Vector4 & v4a, Vector4 & v4b);
Vector4 operator* (float f, Vector4 & v4);
Vector4 operator* (Vector4 & v4, float f);
Vector4 operator* (Vector4 & v4, Matrix4 & m4);
Vector4 operator* (Matrix4 & m4, Vector4 & v4);

