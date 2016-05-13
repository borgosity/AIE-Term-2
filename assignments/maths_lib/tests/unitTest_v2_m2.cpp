#include "unitTest_v2_m2.h"
#include <iostream>

#include "MTXVec2.h"

void test1_initialise()
{
	Vector2 * vec1 = new Vector2();
	Vector2 vec2;

	std::cout << " vec 1 x = " << vec1->m_x << std::endl;
	std::cout << " vec 1 y = " << vec1->m_y << std::endl;
	std::cout << " vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;
}

void test2_becomes()
{
	Vector2 * vec1 = new Vector2(3.13f, 4.13f);

	float x = 3.23f;
	float y = 4.23f;
	Vector2 vec2(x, y);

	Vector2 vec3 = vec2;

	std::cout << "\n vec 1 x = " << vec1->m_x << std::endl;
	std::cout << " vec 1 y = " << vec1->m_y << std::endl;
	std::cout << " vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;
	std::cout << " vec 3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y = " << vec3.m_y << std::endl;
}

void test3_scale()
{
	float x = 3.23f;
	float y = 4.23f;
	Vector2 vec2(x, y);
	std::cout << "\n vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;

	Vector2 vec3(vec2.scale(2.0f));
	std::cout << " vec 3 x scaled = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y scaled = " << vec3.m_y << std::endl;

}

void test4_dot()
{
	float x = 3.23f;
	float y = 4.23f;
	Vector2 vec2(x, y);
	std::cout << " \n vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;

	Vector2 vec3(vec2.scale(2.0f));
	std::cout << " vec 3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y = " << vec3.m_y << std::endl;

	float dotProd = vec3.dot(vec2);
	std::cout << " dot product = " << dotProd << std::endl;

}

void test5_operators()
{
	float x = 3.23f;
	float y = 4.23f;
	Vector2 vec2(x, y);
	std::cout << " \n vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;

	Vector2 vec3(vec2.scale(2.0f));
	std::cout << " vec 3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y = " << vec3.m_y << std::endl;

	vec3 -= vec2;
	std::cout << "\n vec 2-=3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2-=3 y = " << vec3.m_y << std::endl;

	vec3 = vec3 - vec2;
	std::cout << " vec 2-3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2-3 y = " << vec3.m_y << std::endl;

	vec3 += vec2;
	std::cout << "\n vec 2+=3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2+=3 y = " << vec3.m_y << std::endl;

	vec3 = vec3 + vec2;
	std::cout << " vec 2+=3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2+=3 y = " << vec3.m_y << std::endl;

	vec3 *= vec2;
	std::cout << "\n vec 2*=3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2*=3 y = " << vec3.m_y << std::endl;

	vec3 = vec2 * vec3;
	std::cout << " vec 2*3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 2*3 y = " << vec3.m_y << std::endl;

	vec3 = 2.0f * vec2;
	std::cout << "\n vec float*2 x = " << vec3.m_x << std::endl;
	std::cout << " vec float*2 y = " << vec3.m_y << std::endl;

	vec3 = vec2 * 2.0f;
	std::cout << " vec 2*float x = " << vec3.m_x << std::endl;
	std::cout << " vec 2*float y = " << vec3.m_y << std::endl;
}
void test6_normalise()
{
	Vector2 v2a(-13.5f, -48.23f);
	v2a.normalise();
	std::cout << "\n vec normalised x = " << v2a.m_x << std::endl;
	std::cout << " vec normalised y = " << v2a.m_y << std::endl;
	std::cout << "                    -0.269548f, -0.962987f" << std::endl;
}
void test7_magnitude()
{
	Vector2 v2a(13.5f, -48.23f);
	float mag2 = v2a.magnitude();
	std::cout << " vec magnitude/length = " << mag2 << std::endl;
	std::cout << "                        50.0837593079f" << std::endl;
}

void runTests_2()
{
	test1_initialise();
	test2_becomes();
	test3_scale();
	test4_dot();
	test5_operators();
	test6_normalise();
	test7_magnitude();

}