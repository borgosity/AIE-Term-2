#include "Vector3.h"



Vector3::Vector3()
{
	m_x = 0.0f;
	m_y = 0.0f;
	m_z = 0.0f;
}

Vector3::Vector3(float x, float y, float z)
{
	m_x = x;
	m_y = y;
	m_z = z;
}

Vector3::Vector3(Vector3 & v3)
{
	m_x = v3.m_x;
	m_y = v3.m_y;
	m_z = v3.m_z;
}

Vector3::Vector3(Vector2 & v2)
{
	m_x = v2.m_x;
	m_y = v2.m_y;
	m_z = 0.0f;
}


Vector3::~Vector3()
{
}

Vector3 Vector3::scale(float scaler)
{
	Vector3 result(scaler * m_x, scaler * m_y, scaler * m_z);
	return result;
}

Vector3 Vector3::cross(Vector3 & v3)
{
	float x = (m_y * v3.m_z) - (m_z * v3.m_y);
	float y = (m_z * v3.m_x) - (m_x * v3.m_z);
	float z = (m_x * v3.m_y) - (m_y * v3.m_x);

	m_x = x;
	m_y = y;
	m_z = z;
	
	return *this;
}

float Vector3::dot(Vector3 & v3)
{
	float result = (m_x * v3.m_x) + (m_y * v3.m_y) + (m_z * v3.m_z);
	return result;
}

float Vector3::magnitude()
{
	float result;

	result = sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));

	return result;
}

void Vector3::normalise()
{
	float length = this->magnitude();
	m_x = m_x / length;
	m_y = m_y / length;
	m_z = m_z / length;
}

Vector3::operator float*()
{
	float result[3] = { m_x, m_y, m_z };
	return result;
}

Vector3 &Vector3::operator=(Vector3 & v3)
{
	m_x = v3.m_x;
	m_y = v3.m_y;
	m_z = v3.m_z;

	return *this;
}

Vector3 & Vector3::operator=(Vector2 & v2)
{
	m_x = v2.m_x;
	m_y = v2.m_y;
	m_z = 0.0f;

	return *this;
}

Vector3 & Vector3::operator+=(const Vector3 & v3b)
{
	m_x += v3b.m_x;
	m_y += v3b.m_y;
	m_z += v3b.m_z;

	return *this;
}

Vector3 & Vector3::operator-=(const Vector3 & v3b)
{
	m_x -= v3b.m_x;
	m_y -= v3b.m_y;
	m_z -= v3b.m_z;

	return *this;
}

Vector3 & Vector3::operator*=(const Vector3 & v3b)
{
	m_x *= v3b.m_x;
	m_y *= v3b.m_y;
	m_z *= v3b.m_z;

	return *this;
}


Vector3 operator+(Vector3 & v3a, Vector3 & v3b)
{
	Vector3 result(v3a);
	result += v3b;

	return result;
}

Vector3 operator-(Vector3 & v3a, Vector3 & v3b)
{
	Vector3 result(v3a);
	result -= v3b;

	return result;
}

Vector3 operator*(Vector3 & v3a, Vector3 & v3b)
{
	Vector3 result(v3a);
	result *= v3b;

	return result;
}

Vector3 operator*(float f, Vector3 & v3)
{
	Vector3 result(f * v3.m_x, f * v3.m_y, f * v3.m_z);
	return result;
}

Vector3 operator*(Vector3 & v3, float f)
{
	Vector3 result(v3.m_x * f, v3.m_y * f, v3.m_z * f);
	return result;
}

