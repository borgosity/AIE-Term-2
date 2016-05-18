#pragma once
#include <math.h>
#include "MtxVec3.h"

class Matrix4;
/***************************************************************************

***************************************************************************/
class Vector4
{
public:
	// member variables	
	float m_w;
	float m_x;
	float m_y;
	float m_z;

	// constructors
	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4(Vector4 & v4);
	Vector4(Vector3 & v3);
	Vector4(Vector2 & v2);
	~Vector4();

	// member functions
	Vector4 scale(float scaler);
	Vector4 cross(Vector4 & v4);
	float dot(Vector4 & v4);
	float magnitude();
	void normalise();
	
	// operator overloads
	operator float*();
	Vector4 & operator=(Vector4 & v4);
	Vector4 & operator=(Vector3 & v3);
	Vector4 & operator=(Vector2 & v2);
	Vector4 & operator+=(const Vector4 & v4b);
	friend Vector4 operator+ (Vector4 & v4a, Vector4 & v4b);
	Vector4 & operator-=(const Vector4 & v4b);
	friend Vector4 operator- (Vector4 & v4a, Vector4 & v4b);
	Vector4 & operator*=(const Vector4 & v4b);
	friend Vector4 operator* (Vector4 & v4a, Vector4 & v4b);
	friend Vector4 operator* (float f, Vector4 & v4);
	friend Vector4 operator* (Vector4 & v4, float f);
	friend Vector4 operator* (Vector4 & v4, Matrix4 & m4);
	friend Vector4 operator* (Matrix4 & m4, Vector4 & v4);

private:
	// float casting member variable
	float m_fcast[4];
};
/***************************************************************************

***************************************************************************/
class Matrix4
{
public:
	// member variables
	Vector4 * m_column1 = new Vector4;
	Vector4 * m_column2 = new Vector4;
	Vector4 * m_column3 = new Vector4;
	Vector4 * m_column4 = new Vector4;

	// constructors
	Matrix4();
	Matrix4(int a);
	Matrix4(float c1x, float c1y, float c1z, float c1w,
		float c2x, float c2y, float c2z, float c2w,
		float c3x, float c3y, float c3z, float c3w,
		float c4x, float c4y, float c4z, float c4w);
	Matrix4(Vector4 & c1v, Vector4 & c2v, Vector4 & c3v, Vector4 & c4v);
	Matrix4(Matrix4 & m4);
	~Matrix4();

	// member functions
	void setRotateX(float x);
	void setRotateY(float y);
	void setRotateZ(float z);

	// operator overloads
	Matrix4 &operator= (Matrix4 & m4);
	operator float*();
	Matrix4 &operator*= (const Matrix4 & m4b);
	friend Matrix4 operator* (Matrix4 & m4a, Matrix4 & m4b);

private:
	// float casting member variable
	float m_fcast[16];
};


