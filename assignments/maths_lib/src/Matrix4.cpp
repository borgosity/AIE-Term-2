#include "MtxVec4.h"
#include <math.h>

/***************************************************************************

***************************************************************************/
Matrix4::Matrix4()
{
	m_column1->m_x = 0.0f;
	m_column1->m_y = 0.0f;
	m_column1->m_z = 0.0f;
	m_column1->m_w = 0.0f;

	m_column2->m_x = 0.0f;
	m_column2->m_y = 0.0f;
	m_column2->m_z = 0.0f;
	m_column2->m_w = 0.0f;

	m_column3->m_x = 0.0f;
	m_column3->m_y = 0.0f;
	m_column3->m_z = 0.0f;
	m_column3->m_w = 0.0f;

	m_column4->m_x = 0.0f;
	m_column4->m_y = 0.0f;
	m_column4->m_z = 0.0f;
	m_column4->m_w = 0.0f;
}
/***************************************************************************

***************************************************************************/
Matrix4::Matrix4(int a)
{
	float fa = (float)a;

	m_column1->m_x = fa;
	m_column1->m_y = fa;
	m_column1->m_z = fa;
	m_column1->m_w = fa;
					 
	m_column2->m_x = fa;
	m_column2->m_y = fa;
	m_column2->m_z = fa;
	m_column2->m_w = fa;
					 
	m_column3->m_x = fa;
	m_column3->m_y = fa;
	m_column3->m_z = fa;
	m_column3->m_w = fa;
					 
	m_column4->m_x = fa;
	m_column4->m_y = fa;
	m_column4->m_z = fa;
	m_column4->m_w = fa;
}
/***************************************************************************

***************************************************************************/
Matrix4::Matrix4(float c1x, float c1y, float c1z, float c1w, 
				 float c2x, float c2y, float c2z, float c2w, 
				 float c3x, float c3y, float c3z, float c3w, 
				 float c4x, float c4y, float c4z, float c4w)
{
	m_column1->m_x = c1x;
	m_column1->m_y = c1y;
	m_column1->m_z = c1z;
	m_column1->m_w = c1w;

	m_column2->m_x = c1x;
	m_column2->m_y = c1y;
	m_column2->m_z = c1z;
	m_column2->m_w = c1w;

	m_column3->m_x = c1x;
	m_column3->m_y = c1y;
	m_column3->m_z = c1z;
	m_column3->m_w = c1w;

	m_column4->m_x = c1x;
	m_column4->m_y = c1y;
	m_column4->m_z = c1z;
	m_column4->m_w = c1w;
}
/***************************************************************************

***************************************************************************/
Matrix4::Matrix4(Vector4 & c1v, Vector4 & c2v, Vector4 & c3v, Vector4 & c4v)
{
	m_column1 = &c1v;
	m_column2 = &c2v;
	m_column3 = &c3v;
	m_column3 = &c4v;
}
/***************************************************************************

***************************************************************************/
Matrix4::Matrix4(Matrix4 & m4)
{
	m_column1 = m4.m_column1;
	m_column2 = m4.m_column2;
	m_column3 = m4.m_column3;
	m_column4 = m4.m_column4;
}
/***************************************************************************

***************************************************************************/
Matrix4::~Matrix4()
{
}
/***************************************************************************

***************************************************************************/
void Matrix4::setRotateX(float x)
{
	//c1x = 1, c1y = 0      , c1z = 0	  , c1w = 0
	//c2x = 0, c2y = cos(x) , c2z = sin(x), c2w = 0
	//c3x = 0, c3y = -sin(x), c3z = cos(x), c3w = 0
	//c4x = 0, c4y = 0      , c4z = 0     , c4w = 0

	m_column1->m_x = 1.0f;
	m_column1->m_y = 0.0f;
	m_column1->m_z = 0.0f;
	m_column1->m_w = 0.0f;

	m_column2->m_x = 0.0f;
	m_column2->m_y = (float)cos(x);
	m_column2->m_z = (float)sin(x);
	m_column2->m_w = 0.0f;

	m_column3->m_x = 0.0f;
	m_column3->m_y = (float)-sin(x);
	m_column3->m_z = (float)cos(x);
	m_column3->m_w = 0.0f;

	m_column4->m_x = 0.0f;
	m_column4->m_y = 0.0f;
	m_column4->m_z = 0.0f;
	m_column4->m_w = 0.0f;
}
/***************************************************************************

***************************************************************************/
void Matrix4::setRotateY(float y)
{
	//c1x = cos(y), c1y = 0, c1z = -sin(y), c1w = 0
	//c2x = 0     , c2y = 1, c2z = 0	  , c2w = 0
	//c3x = sin(y), c3y = 0, c3z = cos(y) , c3w = 0
	//c4x = 0, c4y = 0      , c4z = 0     , c4w = 0

	m_column1->m_x = (float)cos(y);
	m_column1->m_y = 0.0f;
	m_column1->m_z = (float)-sin(y);
	m_column1->m_w = 0.0f;

	m_column2->m_x = 0.0f;
	m_column2->m_y = 1.0f;
	m_column2->m_z = 0.0f;
	m_column2->m_w = 0.0f;

	m_column3->m_x = (float)sin(y);
	m_column3->m_y = 0.0f;
	m_column3->m_z = (float)cos(y);
	m_column2->m_w = 0.0f;

	m_column4->m_x = 0.0f;
	m_column4->m_y = 0.0f;
	m_column4->m_z = 0.0f;
	m_column4->m_w = 0.0f;
}
/***************************************************************************

***************************************************************************/
void Matrix4::setRotateZ(float z)
{
	//c1x = cos(y) , c1y = sin(y), c1z = 0, c1w = 0
	//c2x = -sin(y), c2y = cos(y), c2z = 0, c2w = 0
	//c3x = 0      , c3y = 0     , c3z = 1, c3w = 0
	//c4x = 0, c4y = 0      , c4z = 0     , c3w = 0

	m_column1->m_x = (float)cos(z);
	m_column1->m_y = (float)sin(z);
	m_column1->m_z = 0.0f;
	m_column1->m_w = 0.0f;

	m_column2->m_x = (float)-sin(z);
	m_column2->m_y = (float)cos(z);
	m_column2->m_z = 0.0f;
	m_column3->m_w = 0.0f;

	m_column3->m_x = 0.0f;
	m_column3->m_y = 0.0f;
	m_column3->m_z = 1.0f;
	m_column3->m_w = 0.0f;

	m_column4->m_x = 0.0f;
	m_column4->m_y = 0.0f;
	m_column4->m_z = 0.0f;
	m_column4->m_w = 0.0f;
}
/***************************************************************************

***************************************************************************/
Matrix4 & Matrix4::operator=(Matrix4 & m4)
{
	m_column1 = m4.m_column1;
	m_column2 = m4.m_column2;
	m_column3 = m4.m_column3;
	m_column4 = m4.m_column4;

	return *this;
}
/***************************************************************************

***************************************************************************/
Matrix4::operator float*()
{
	float result[16] = { m_column1->m_x, m_column1->m_y, m_column1->m_z, m_column1->m_w,
						 m_column2->m_x, m_column2->m_y, m_column2->m_z, m_column2->m_w,
						 m_column3->m_x, m_column3->m_y, m_column3->m_z, m_column3->m_w,
						 m_column4->m_x, m_column4->m_y, m_column4->m_z, m_column4->m_w, };
	return result;
}
/***************************************************************************

***************************************************************************/
Matrix4 & Matrix4::operator*=(const Matrix4 & m4b)
{
	m_column1->m_x = m4b.m_column1->m_x;
	m_column1->m_y = m4b.m_column1->m_y;
	m_column1->m_z = m4b.m_column1->m_z;
	m_column1->m_w = m4b.m_column1->m_w;

	m_column2->m_x = m4b.m_column2->m_x;
	m_column2->m_y = m4b.m_column2->m_y;
	m_column2->m_z = m4b.m_column2->m_z;
	m_column2->m_w = m4b.m_column2->m_w;

	m_column3->m_x = m4b.m_column3->m_x;
	m_column3->m_y = m4b.m_column3->m_y;
	m_column3->m_z = m4b.m_column3->m_z;
	m_column3->m_w = m4b.m_column3->m_w;

	return *this;
}
/***************************************************************************

***************************************************************************/
Matrix4 operator*(Matrix4 & m4a, Matrix4 & m4b)
{
	Matrix4 result(m4a);

	result *= m4b;

	return result;
}
