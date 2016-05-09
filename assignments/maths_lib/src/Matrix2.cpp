#include "Matrix2.h"



Matrix2::Matrix2()
{
	m_column1->m_x = 0.0f;
	m_column1->m_y = 0.0f;
	m_column2->m_x = 0.0f;
	m_column2->m_y = 0.0f;
}

Matrix2::Matrix2(float a)
{
	m_column1->m_x = a;
	m_column1->m_y = a;
	m_column2->m_x = a;
	m_column2->m_y = a;
}

Matrix2::Matrix2(float c1x = 0.0f, float c1y = 0.0f, 
				 float c2x = 0.0f, float c2y = 0.0f)
{
	m_column1->m_x = c1x;
	m_column1->m_y = c1y;
	m_column2->m_x = c1x;
	m_column2->m_y = c1y;
}

Matrix2::Matrix2(Vector2 & c1v, Vector2 & c2v)
{
	m_column1 = &c1v;
	m_column2 = &c2v;
}

Matrix2::Matrix2(Matrix2 & m2)
{
	m_column1 = m2.m_column1;
	m_column2 = m2.m_column2;
}


Matrix2::~Matrix2()
{
}
