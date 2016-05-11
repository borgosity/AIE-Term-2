#include "Vector4.h"



Vector4::Vector4()
{
	m_x = 0.0f;
	m_y = 0.0f;
	m_z = 0.0f;
	m_w = 0.0.f
}

Vector4::Vector4(float x, float y, float z, float w)
{
	m_x = x;
	m_y = y;
	m_z = z;
	m_w = w;
}

Vector4::Vector4(Vector4 & v4)
{
	m_x = v4.m_x;
	m_y = v4.m_y;
	m_z = v4.m_z;
	m_w = v4.m_w;
}


Vector4::~Vector4()
{
}

Vector4 Vector4::scale(float scaler)
{
	Vector4 result(scaler * m_x, scaler * m_y, scaler * m_z, scaler * m_w);
	return result;
}

float Vector4::dot(Vector4 & v4)
{
	float result = (m_x * v4.m_x) + (m_y * v4.m_y) + (m_z * v4.m_z) + (m_w * v4.m_w);
	return result;
}

float Vector4::magnitude()
{
	float result;

	result = sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z) + (m_w * m_w));

	return result;
}

void Vector4::normalise()
{
	float length = this->magnitude();
	m_x = m_x / length;
	m_y = m_y / length;
	m_z = m_z / length;
	m_w = m_w / length;
}

Vector4 &Vector4::operator=(Vector4 & v4)
{
	m_x = v4.m_x;
	m_y = v4.m_y;
	m_z = v4.m_z;
	m_w = v4.m_w;

	return *this;
}

Vector4 & Vector4::operator+=(const Vector4 & v4b)
{
	m_x += v4b.m_x;
	m_y += v4b.m_y;
	m_z += v4b.m_z;
	m_w += v4b.m_w;

	return *this;
}

Vector4 & Vector4::operator-=(const Vector4 & v4b)
{
	m_x -= v4b.m_x;
	m_y -= v4b.m_y;
	m_z -= v4b.m_z;
	m_w -= v4b.m_w;

	return *this;
}

Vector4 & Vector4::operator*=(const Vector4 & v4b)
{
	m_x *= v4b.m_x;
	m_y *= v4b.m_y;
	m_z *= v4b.m_z;
	m_w *= v4b.m_w;

	return *this;
}


Vector4 operator+(Vector4 & v4a, Vector4 & v4b)
{
	Vector4 result(v4a);
	result += v4b;

	return result;
}

Vector4 operator-(Vector4 & v4a, Vector4 & v4b)
{
	Vector4 result(v4a);
	result -= v4b;

	return result;
}

Vector4 operator*(Vector4 & v4a, Vector4 & v4b)
{
	Vector4 result(v4a);
	result *= v4b;

	return result;
}

Vector4 operator*(float f, Vector4 & v4)
{
	Vector4 result(f * v4.m_x, f * v4.m_y, f * v4.m_z, f * v4.m_w);
	return result;
}

Vector4 operator*(Vector4 & v4, float f)
{
	Vector4 result(v4.m_x * f, v4.m_y * f, v4.m_z * f, v4.m_w * f);
	return result;
}

