#pragma once
#include "MtxVec2.h"

/***************************************************************************

***************************************************************************/
Matrix2::Matrix2()
{
	m_column1->m_x = 0.0f;
	m_column1->m_y = 0.0f;

	m_column2->m_x = 0.0f;
	m_column2->m_y = 0.0f;
}
/***************************************************************************

***************************************************************************/
Matrix2::Matrix2(int a)
{
	float fa = (float)a;

	m_column1->m_x = fa;
	m_column1->m_y = fa;

	m_column2->m_x = fa;
	m_column2->m_y = fa;
}
/***************************************************************************

***************************************************************************/
Matrix2::Matrix2(float c1x = 0.0f, float c1y = 0.0f, 
				 float c2x = 0.0f, float c2y = 0.0f)
{
	m_column1->m_x = c1x;
	m_column1->m_y = c1y;

	m_column2->m_x = c2x;
	m_column2->m_y = c2y;
}
/***************************************************************************

***************************************************************************/
Matrix2::Matrix2(Vector2 & c1v, Vector2 & c2v)
{
	m_column1 = &c1v;
	m_column2 = &c2v;
}
/***************************************************************************

***************************************************************************/
Matrix2::Matrix2(Matrix2 & m2)
{
	m_column1 = m2.m_column1;
	m_column2 = m2.m_column2;
}
/***************************************************************************

***************************************************************************/
Matrix2::~Matrix2()
{
}
/***************************************************************************

***************************************************************************/
void Matrix2::setRotateZ(float z)
{
	//c1x = cos(z), c1y = sin(z)
	//c2x = -sin(z), c2y = cos(z)

	m_column1->m_x = (float)cos(z);
	m_column1->m_y = (float)sin(z);

	m_column2->m_x = (float)-sin(z);
	m_column2->m_y = (float)cos(z);
}
/***************************************************************************

***************************************************************************/
Matrix2 & Matrix2::operator=(Matrix2 & m2)
{
	m_column1 = m2.m_column1;
	m_column2 = m2.m_column2;

	return *this;
}
/***************************************************************************

***************************************************************************/
Matrix2::operator float*()
{
	float result[4] = { m_column1->m_x, m_column1->m_y, 
						m_column2->m_x, m_column2->m_y };

	for (int i = 0; i < 4; i++)
	{
		m_fcast[i] = result[i];
	}

	return m_fcast;
}
/***************************************************************************

***************************************************************************/
Matrix2 & Matrix2::operator*=(const Matrix2 & m2b)
{
	m_column1->m_x *= m2b.m_column1->m_x;
	m_column1->m_y *= m2b.m_column1->m_y;

	m_column2->m_x *= m2b.m_column2->m_x;
	m_column2->m_y *= m2b.m_column2->m_y;

	return *this;
}
/***************************************************************************

***************************************************************************/
Matrix2 operator*(Matrix2 & m2a, Matrix2 & m2b)
{
	Matrix2 result(m2a);

	//result *= m2b;

	result.m_column1->m_x = (m2a.m_column1->m_x * m2b.m_column1->m_x) +	(m2a.m_column2->m_x * m2b.m_column1->m_y);
	result.m_column1->m_y = (m2a.m_column1->m_y * m2b.m_column1->m_x) + (m2a.m_column2->m_y * m2b.m_column1->m_y);

	result.m_column2->m_x = (m2a.m_column1->m_x * m2b.m_column2->m_x) + (m2a.m_column2->m_x * m2b.m_column2->m_y);
	result.m_column2->m_y = (m2a.m_column1->m_y * m2b.m_column2->m_x) + (m2a.m_column2->m_y * m2b.m_column2->m_y);


	return result;
}
