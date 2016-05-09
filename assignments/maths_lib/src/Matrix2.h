#pragma once
#include "Vector2.h"
//class Vector2;

class Matrix2
{
public:
	Matrix2();
	Matrix2(float a);
	Matrix2(float c1x, float c1y, 
		    float c2x, float c2y);
	Matrix2(Vector2 & c1v, Vector2 & c2v);
	Matrix2(Matrix2 & m2);
	~Matrix2();

	void setRotateX(float x);
	void setRotateY(float y);
	void setRotateZ(float z);
	operator float*();

	// operator member functions
	friend Matrix2 operator* (Matrix2 & m2a, Matrix2 & m2b);

	//Vector2 column[2]();
	Vector2 * m_column1 = new Vector2;
	Vector2 * m_column2 = new Vector2;
};

