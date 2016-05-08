#include "Vector2.h"



Vector2::Vector2()
{
	m_x = 0.0f;
	m_y = 0.0f;
}

Vector2::Vector2(float x = 0.0f, float y = 0.0f)
{
	m_x = x;
	m_y = y;
}

Vector2::Vector2(Vector2 & v2)
{
	m_x = v2.m_x;
	m_y = v2.m_y;
}


Vector2::~Vector2()
{
}

Vector2 Vector2::scale(float scaler)
{
	Vector2 result(scaler * m_x, scaler * m_y);
	return result;
}

float Vector2::dot(Vector2 & v2)
{
	float result = (m_x * v2.m_x) + (m_y * v2.m_y);
	return result;
}

Vector2 &Vector2::operator=(Vector2 & v2)
{
	m_x = v2.m_x;
	m_y = v2.m_y;

	return *this;
}

Vector2 & Vector2::operator+=(const Vector2 & v2b)
{
	m_x += v2b.m_x;
	m_y += v2b.m_y;

	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 & v2b)
{
	m_x -= v2b.m_x;
	m_y -= v2b.m_y;

	return *this;
}

Vector2 & Vector2::operator*=(const Vector2 & v2b)
{
	m_x *= v2b.m_x;
	m_y *= v2b.m_y;

	return *this;
}


Vector2 operator+(Vector2 & v2a, Vector2 & v2b)
{
	Vector2 result(v2a);
	result += v2b;

	return result;
}

Vector2 operator-(Vector2 & v2a, Vector2 & v2b)
{
	Vector2 result(v2a);
	result -= v2b;

	return result;
}

Vector2 operator*(Vector2 & v2a, Vector2 & v2b)
{
	Vector2 result(v2a);
	result *= v2b;

	return result;
}

Vector2 operator*(float f, Vector2 & v2)
{
	Vector2 result(f * v2.m_x, f * v2.m_y);
	return result;
}

Vector2 operator*(Vector2 & v2, float f)
{
	Vector2 result(v2.m_x * f, v2.m_y * f);
	return result;
}

//Vector2 operator*(Vector2 & v2, Matrix2 & m2)
//{
//	Vector2 result;
//	result.m_x = v2.m_x * m2.column[0]->m_x + v2.m_y * m2.column[0]->m_y;
//	result.m_y = v2.m_x * m2.column[1]->m_x + v2.m_y * m2.column[1]->m_y;
//	return result;
//}
//
//Vector2 operator*(Matrix2 & m2, Vector2 & v2)
//{
//	Vector2 result;
//	//result.m_x = m2.column1.m_x * v2.m_x + m2.column1.m_y * v2.m_y;
//	//result.m_y = m2.column2.m_x * v2.m_x + m2.column2.m_y * v2.m_y;
//	return result;
//}
