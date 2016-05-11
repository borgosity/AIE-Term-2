#include "unitTest_v3_m3.h"

#include <iostream>
#include "..\src\Vector3.h"

void v3test1_initialise()
{
	Vector3 * vec1 = new Vector3();
	Vector3 vec2;

	std::cout << " vec 1 x = " << vec1->m_x << std::endl;
	std::cout << " vec 1 y = " << vec1->m_y << std::endl;
	std::cout << " vec 1 z = " << vec1->m_y << std::endl;
	std::cout << " vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;
	std::cout << " vec 2 z = " << vec2.m_y << std::endl;
}

void v3test2_becomes()
{
	Vector3 * vec1 = new Vector3(3.13f, 4.13f, 5.13f);

	float x = 3.23f;
	float y = 4.23f;
	float z = 5.23f;
	Vector3 vec2(x, y, z);

	Vector3 vec3 = vec2;

	std::cout << "\n vec 1 x = " << vec1->m_x << std::endl;
	std::cout << " vec 1 y = " << vec1->m_y << std::endl;
	std::cout << " vec 1 z = " << vec1->m_z << std::endl;

	std::cout << " vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;
	std::cout << " vec 2 z = " << vec2.m_z << std::endl;

	std::cout << " vec 3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y = " << vec3.m_y << std::endl;
	std::cout << " vec 3 z = " << vec3.m_z << std::endl;
}

void v3test3_scale()
{
	float x = 3.23f;
	float y = 4.23f;
	float z = 5.23f;

	Vector3 vec2(x, y, z);
	std::cout << "\n vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;
	std::cout << " vec 2 z = " << vec2.m_z << std::endl;

	Vector3 vec3(vec2.scale(2.0f));
	std::cout << " vec 3 x scaled = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y scaled = " << vec3.m_y << std::endl;
	std::cout << " vec 3 z scaled = " << vec3.m_z << std::endl;

}

void v3test4_dot()
{
	float x = 13.5f;
	float y = -48.23f;
	float z = 862;

	Vector3 vec2(x, y, z);
	std::cout << " \n vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;
	std::cout << " vec 2 z = " << vec2.m_z << std::endl;

	Vector3 vec3(vec2.scale(2.482f));
	std::cout << " vec 3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y = " << vec3.m_y << std::endl;
	std::cout << " vec 3 z = " << vec3.m_z << std::endl;

	Vector3 v3a(13.5f, -48.23f, 862);
	Vector3 v3b(5, 3.99f, -12);

	float dotProd = v3a.dot(v3b);
	std::cout << "\n dot product = " << dotProd << std::endl;
	std::cout << "                 -10468.9375f" << std::endl;

}



void v3test5_operators()
{
	float x = 3.23f;
	float y = 4.23f;
	float z = 5.23f;

	Vector3 vec2(x, y, z);
	std::cout << " \n vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;
	std::cout << " vec 2 z = " << vec2.m_z << std::endl;

	Vector3 vec3(vec2.scale(2.0f));
	std::cout << " vec 3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y = " << vec3.m_y << std::endl;
	std::cout << " vec 3 z = " << vec3.m_z << std::endl;

	vec3 -= vec2;
	std::cout << "\n vec 2-=3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2-=3 y = " << vec3.m_y << std::endl;
	std::cout << " vec 2-=3 z = " << vec3.m_z << std::endl;

	vec3 = vec3 - vec2;
	std::cout << " vec 2-3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2-3 y = " << vec3.m_y << std::endl;
	std::cout << " vec 2-3 z = " << vec3.m_z << std::endl;

	vec3 += vec2;
	std::cout << "\n vec 2+=3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2+=3 y = " << vec3.m_y << std::endl;
	std::cout << " vec 2+=3 z = " << vec3.m_z << std::endl;

	vec3 = vec3 + vec2;
	std::cout << " vec 2+=3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2+=3 y = " << vec3.m_y << std::endl;
	std::cout << " vec 2+=3 z = " << vec3.m_z << std::endl;

	vec3 *= vec2;
	std::cout << "\n vec 2*=3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2*=3 y = " << vec3.m_y << std::endl;
	std::cout << " vec 2*=3 z = " << vec3.m_z << std::endl;

	vec3 = vec2 * vec3;
	std::cout << " vec 2*3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2*3 y = " << vec3.m_y << std::endl;
	std::cout << " vec 2*3 z = " << vec3.m_z << std::endl;

	vec3 = 2.0f * vec2;
	std::cout << "\n vec float*2 x = " << vec3.m_x << std::endl;
	std::cout << " vec float*2 y = " << vec3.m_y << std::endl;
	std::cout << " vec float*2 z = " << vec3.m_z << std::endl;

	vec3 = vec2 * 2.0f;
	std::cout << " vec 2*float x = " << vec3.m_x << std::endl;
	std::cout << " vec 2*float y = " << vec3.m_y << std::endl;
	std::cout << " vec 2*float z = " << vec3.m_z << std::endl;
}
void v3test6_normalise()
{
	Vector3 v2a(13.5f, -48.23f, 862);
	v2a.normalise();
	std::cout << "\n vec normalised x = " << v2a.m_x << std::endl;
	std::cout << " vec normalised y = " << v2a.m_y << std::endl;
	std::cout << " vec normalised z = " << v2a.m_z << std::endl;

	std::cout << "                    0.0156349f, -0.0558571f, 0.998316f" << std::endl;
}
void v3test7_magnitude()
{
	Vector3 v2a(13.5f, -48.23f, 862);
	float mag2 = v2a.magnitude();
	std::cout << "\n vec magnitude/length = " << mag2 << std::endl;
	std::cout << "                        863.453735352f" << std::endl;
}

void v3test8_cross()
{
	Vector3 v3a(13.5f, -48.23f, 862);
	Vector3 v3b(5, 3.99f, -12);
	
	
	Vector3 v3c(v3a.cross(v3b));
	
	std::cout << "\n vec cross x = " << v3c.m_x << " = -2860.62011719f" << std::endl;
	std::cout << " vec cross y = " << v3c.m_y << " = 4472" << std::endl;
	std::cout << " vec cross z = " << v3c.m_z << " = 295.014984131f" << std::endl;

}

void runTests_3()
{
	v3test1_initialise();
	v3test2_becomes();
	v3test3_scale();
	v3test4_dot();
	v3test5_operators();
	v3test6_normalise();
	v3test7_magnitude();
	v3test8_cross();

}