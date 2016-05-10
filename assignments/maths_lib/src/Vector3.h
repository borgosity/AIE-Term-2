#pragma once
#include "Matrix3.h"

class Vector3
{
public:
	float m_x;
	float m_y;
	float m_z;

	Vector3();
	Vector3(float x, float y, float z);
	Vector3(Vector3 & v3);
	~Vector3();

	Vector3 scale(float scaler);
	Vector3 cross(Vector3 & v3);
	float dot(Vector3 & v3);
	float magnitude();
	void normalise();
	//operator float*();

	// operator oveloads 
	Vector3 & operator= (Vector3 & v3);
	Vector3 & operator+= (const Vector3 & v3b);
	friend Vector3 operator+ (Vector3 & v3a, Vector3 & v3b);
	Vector3 & operator-= (const Vector3 & v3b);
	friend Vector3 operator- (Vector3 & v3a, Vector3 & v3b);
	Vector3 & operator*= (const Vector3 & v3b);
	friend Vector3 operator* (Vector3 & v3a, Vector3 & v3b);
	friend Vector3 operator* (float f, Vector3 & v3);
	friend Vector3 operator* (Vector3 & v3, float f);
	//friend Vector3 operator* (Vector3 & v3, Matrix3 & m3);
	//friend Vector3 operator* (Matrix3 & m3, Vector3 & v3);
};


