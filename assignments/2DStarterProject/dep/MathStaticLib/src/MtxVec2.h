#pragma once
#include <math.h>

class Matrix2;
/***************************************************************************

***************************************************************************/
class Vector2
{
public:
	// member variables
	float m_x;
	float m_y;

	// constructors
	Vector2();
	Vector2(float x, float y);
	Vector2(Vector2 & v2);
	~Vector2();

	// member variables
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
	friend Vector2 operator* (Vector2 & v2, Matrix2 & m2);
	friend Vector2 operator* (Matrix2 & m2, Vector2 & v2);
private:
	// float casting member variable
	float m_fcast[2];

};
/***************************************************************************

***************************************************************************/
class Matrix2
{
public:
	// member variables
	Vector2 * m_column1 = new Vector2;
	Vector2 * m_column2 = new Vector2;

	// constructors
	Matrix2();
	Matrix2(int a);
	Matrix2(float c1x, float c1y,
		float c2x, float c2y);
	Matrix2(Vector2 & c1v, Vector2 & c2v);
	Matrix2(Matrix2 & m2);
	~Matrix2();

	// memeber functions
	void setRotateZ(float z);

	// operator overloads
	Matrix2 &operator= (Matrix2 & m2);
	operator float*();
	Matrix2 &operator*= (const Matrix2 & m2b);
	friend Matrix2 operator* (Matrix2 & m2a, Matrix2 & m2b);

private:
	// float casting member variable
	float m_fcast[4];
};


