#include "unitTest_v2_m2.h"

#include <iostream>
#include "..\src\Vector2.h"

void test1()
{
	Vector2 * vec1 = new Vector2();
	Vector2 vec2;

	std::cout << " vec 1 x = " << vec1->m_x << std::endl;
	std::cout << " vec 1 y = " << vec1->m_y << std::endl;
	std::cout << " vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;
}

void test2()
{
	Vector2 * vec1 = new Vector2(3.1, 4.1);

	float x = 3.2;
	float y = 4.2;
	Vector2 vec2(x, y);

	Vector2 vec3 = vec2;

	std::cout << "\n vec 1 x = " << vec1->m_x << std::endl;
	std::cout << " vec 1 y = " << vec1->m_y << std::endl;
	std::cout << " vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;
	std::cout << " vec 3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y = " << vec3.m_y << std::endl;
}

void test3()
{
	float x = 3.2;
	float y = 4.2;
	Vector2 vec2(x, y);
	std::cout << "\n vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;

	Vector2 vec3(vec2.scale(2.0f));
	std::cout << " vec 3 x scaled = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y scaled = " << vec3.m_y << std::endl;

}

void test4()
{
	float x = 3.2;
	float y = 4.2;
	Vector2 vec2(x, y);
	std::cout << " \n vec 2 x = " << vec2.m_x << std::endl;
	std::cout << " vec 2 y = " << vec2.m_y << std::endl;

	Vector2 vec3(vec2.scale(2.0f));
	std::cout << " vec 3 x = " << vec3.m_x << std::endl;
	std::cout << " vec 3 y = " << vec3.m_y << std::endl;

	float dotProd = vec3.dot(vec2);
	std::cout << " dot product = " << dotProd << std::endl;

}

void test5()
{
	float x = 3.2;
	float y = 4.2;
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

void runTests()
{
	test1();
	test2();
	test3();
	test4();
	test5();


}