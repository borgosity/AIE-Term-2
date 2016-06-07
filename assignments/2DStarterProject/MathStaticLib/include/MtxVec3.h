#pragma once
#include <math.h>
#include "MtxVec2.h"

class Matrix3;
/***************************************************************************

***************************************************************************/
class Vector3
{
public:
	// member variables
	float m_x;
	float m_y;
	float m_z;

	// constructors
	Vector3();
	Vector3(float x, float y, float z);
	Vector3(Vector3 & v3);
	Vector3(Vector2 & v2);
	~Vector3();

	// member functions
	Vector3 scale(float scaler);
	Vector3 cross(Vector3 & v3);
	float dot(Vector3 & v3);
	float magnitude();
	void normalise();

	// operator oveloads 
	operator float*();
	Vector3 & operator= (Vector3 & v3);
	Vector3 & operator= (Vector2 & v2);
	Vector3 & operator+= (const Vector3 & v3b);
	friend Vector3 operator+ (Vector3 & v3a, Vector3 & v3b);
	Vector3 & operator-= (const Vector3 & v3b);
	friend Vector3 operator- (Vector3 & v3a, Vector3 & v3b);
	Vector3 & operator*= (const Vector3 & v3b);
	friend Vector3 operator* (Vector3 & v3a, Vector3 & v3b);
	friend Vector3 operator* (float f, Vector3 & v3);
	friend Vector3 operator* (Vector3 & v3, float f);
	friend Vector3 operator* (Vector3 & v3, Matrix3 & m3);
	friend Vector3 operator* (Matrix3 & m3, Vector3 & v3);

private:
	// float casting member variable
	float m_fcast[3];
};
/***************************************************************************

***************************************************************************/
class Matrix3
{
public:
	// member variables
	Vector3 * m_column1 = new Vector3;
	Vector3 * m_column2 = new Vector3;
	Vector3 * m_column3 = new Vector3;

	// constructors
	Matrix3();
	Matrix3(int a);
	Matrix3(float c1x, float c1y, float c1z,
		float c2x, float c2y, float c2z,
		float c3x, float c3y, float c3z);
	Matrix3(Vector3 & c1v, Vector3 & c2v, Vector3 & c3v);
	Matrix3(Matrix3 & m3);
	~Matrix3();

	// member functions
	void setRotateX(float x);
	void setRotateY(float y);
	void setRotateZ(float z);

	void CreateTranslation(Vector3 & vector3);
	void CreateTranslation(float x, float y, float z = 1.0f);
	void CreateRotation(float radians);

	// operator overloads
	Matrix3 &operator= (Matrix3 & m3);
	operator float*();
	Matrix3 &operator*= (const Matrix3 & m3b);
	friend Matrix3 operator* (Matrix3 & m3a, Matrix3 & m3b);

private:
	// float casting member variable
	float m_fcast[9];
};

