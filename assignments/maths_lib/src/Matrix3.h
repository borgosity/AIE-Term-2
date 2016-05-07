#pragma once
class Matrix3
{
public:
	//Vector3 column1;
	//Vector3 column2;
	//Vector3 column3;

	Matrix3();
	Matrix3(float c1x, float c1y, float c1z, 
			float c2x, float c2y, float c2z,
			float c3x, float c3y, float c3z);
	Matrix3(Matrix3 & m3);
	~Matrix3();
	void setRotateX(float x);
	void setRotateY(float y);
	void setRotateZ(float z);
	operator float*();
};
Matrix3 operator* (Matrix3 & m3a, Matrix3 & m3b);
