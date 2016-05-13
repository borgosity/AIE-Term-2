#include "MtxVec3.h"
#include <math.h>

/***************************************************************************

***************************************************************************/
Matrix3::Matrix3()
{
	m_column1->m_x = 0.0f;
	m_column1->m_y = 0.0f;
	m_column1->m_z = 0.0f;
			 
	m_column2->m_x = 0.0f;
	m_column2->m_y = 0.0f;
	m_column2->m_z = 0.0f;
			 
	m_column3->m_x = 0.0f;
	m_column3->m_y = 0.0f;
	m_column3->m_z = 0.0f;
}
/***************************************************************************

***************************************************************************/
Matrix3::Matrix3(int a)
{
	float fa = (float)a;

	m_column1->m_x = fa;
	m_column1->m_y = fa;
	m_column1->m_z = fa;
					
	m_column2->m_x = fa;
	m_column2->m_y = fa;
	m_column2->m_z = fa;
					
	m_column3->m_x = fa;
	m_column3->m_y = fa;
	m_column3->m_z = fa;
	
}
/***************************************************************************

***************************************************************************/
Matrix3::Matrix3(float c1x, float c1y, float c1z, 
				 float c2x, float c2y, float c2z, 
				 float c3x, float c3y, float c3z)
{
	m_column1->m_x = c1x;
	m_column1->m_y = c1y;
	m_column1->m_z = c1z;

	m_column2->m_x = c2x;
	m_column2->m_y = c2y;
	m_column2->m_z = c2z;

	m_column3->m_x = c3x;
	m_column3->m_y = c3y;
	m_column3->m_z = c3z;
}
/***************************************************************************

***************************************************************************/
Matrix3::Matrix3(Vector3 & c1v, Vector3 & c2v, Vector3 & c3v)
{
	m_column1 = &c1v;
	m_column2 = &c2v;
	m_column3 = &c3v;
}
/***************************************************************************

***************************************************************************/
Matrix3::Matrix3(Matrix3 & m3)
{
	m_column1 = m3.m_column1;
	m_column2 = m3.m_column2;
	m_column3 = m3.m_column3;
}
/***************************************************************************

***************************************************************************/
Matrix3::~Matrix3()
{
}
/***************************************************************************

***************************************************************************/
void Matrix3::setRotateX(float x)
{

	//c1x = 1, c1y = 0      , c1z = 0
	//c2x = 0, c2y = cos(x) , c2z = sin(x)
	//c3x = 0, c3y = -sin(x), c3z = cos(x)
	m_column1->m_x =	1.0f;
	m_column1->m_y =	0.0f;
	m_column1->m_z =	0.0f;
					 
	m_column2->m_x =	0.0f;
	m_column2->m_y =	(float)cos(x);
	m_column2->m_z =	(float)sin(x);
					 
	m_column3->m_x =	0.0f;
	m_column3->m_y =	(float)-sin(x);
	m_column3->m_z =	(float)cos(x);
}
/***************************************************************************

***************************************************************************/
void Matrix3::setRotateY(float y)
{
	//c1x = cos(y), c1y = 0, c1z = -sin(y)
	//c2x = 0     , c2y = 1, c2z = 0
	//c3x = sin(y), c3y = 0, c3z = cos(y)

	m_column1->m_x = (float)cos(y);
	m_column1->m_y = 0.0f;
	m_column1->m_z = (float)-sin(y);

	m_column2->m_x = 0.0f;
	m_column2->m_y = 1.0f;
	m_column2->m_z = 0.0f;

	m_column3->m_x = (float)sin(y);
	m_column3->m_y = 0.0f;
	m_column3->m_z = (float)cos(y);
}
/***************************************************************************

***************************************************************************/
void Matrix3::setRotateZ(float z)
{
	//c1x = cos(y) , c1y = sin(y), c1z = 0
	//c2x = -sin(y), c2y = cos(y), c2z = 0
	//c3x = 0      , c3y = 0     , c3z = 1

	m_column1->m_x = (float)cos(z);
	m_column1->m_y = (float)sin(z);
	m_column1->m_z = 0.0f;

	m_column2->m_x = (float)-sin(z);
	m_column2->m_y = (float)cos(z);
	m_column2->m_z = 0.0f;

	m_column3->m_x = 0.0f;
	m_column3->m_y = 0.0f;
	m_column3->m_z = 1.0f;
}
/***************************************************************************

***************************************************************************/
Matrix3 & Matrix3::operator=(Matrix3 & m3)
{
	m_column1 = m3.m_column1;
	m_column2 = m3.m_column2;
	m_column3 = m3.m_column3;

	return *this;
}
/***************************************************************************

***************************************************************************/
Matrix3::operator float*()
{
	float result[9] = { m_column1->m_x, m_column1->m_y, m_column1->m_z,
						m_column2->m_x, m_column2->m_y, m_column2->m_z,
						m_column3->m_x, m_column3->m_y, m_column3->m_z };
	return result;
}
/***************************************************************************

***************************************************************************/
Matrix3 & Matrix3::operator*=(const Matrix3 & m3b)
{
	m_column1->m_x = m3b.m_column1->m_x;
	m_column1->m_y = m3b.m_column1->m_y;
	m_column1->m_z = m3b.m_column1->m_z;

	m_column2->m_x = m3b.m_column2->m_x;
	m_column2->m_y = m3b.m_column2->m_y;
	m_column2->m_z = m3b.m_column2->m_z;

	m_column3->m_x = m3b.m_column3->m_x;
	m_column3->m_y = m3b.m_column3->m_y;
	m_column3->m_z = m3b.m_column3->m_z;

	return *this;
}
/***************************************************************************

***************************************************************************/
Matrix3 operator*(Matrix3 & m3a, Matrix3 & m3b)
{
	Matrix3 result(m3a);

	result *= m3b;

	return result;
}
