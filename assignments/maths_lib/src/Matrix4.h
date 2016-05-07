#pragma once
class Matrix4
{
public:
	//Vector4 column1;
	//Vector4 column2;
	//Vector4 column3;
	//Vector4 column4;

	Matrix4();
	Matrix4(float c1x, float c1y, float c1z, float c1w, 
		    float c2x, float c2y, float c2z, float c2w, 
		    float c3x, float c3y, float c3z, float c3w, 
		    float c4x, float c4y, float c4z, float c4w);
	Matrix4(Matrix4 & m4);
	~Matrix4();
	void setRotateX(float x);
	void setRotateY(float y);
	void setRotateZ(float z);
	operator float*();
};
Matrix4 operator* (Matrix4 & m4a, Matrix4 & m4b);

