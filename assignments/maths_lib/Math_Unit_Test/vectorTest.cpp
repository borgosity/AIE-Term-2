#include "unittest.h"
#include <iostream>
#include <iomanip>

#ifndef NO_DEFAULT_STREAM_OPERATOR

	std::ostream& operator << (std::ostream& os, Vector2& rhs) { 
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1]; return os; }
	std::ostream& operator << (std::ostream& os, Vector3& rhs) {
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1] << "," << std::setprecision(12) << a[2]; return os; }
	std::ostream& operator << (std::ostream& os, Vector4& rhs) {
		float* a = (float*)rhs;
		os << std::setprecision(12) << a[0] << "," << std::setprecision(12) << a[1] << "," << std::setprecision(12) << a[2] << "," << std::setprecision(12) << a[3]; return os; }

#endif

static const float DEFAULT_TOLERANCE = 0.00001f;

bool compare(float a, float b, float tolerance = DEFAULT_TOLERANCE) {
	if (abs(a - b) > tolerance)
		return false;
	return true;
}

bool compare( Vector2& A,  Vector2& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance)
		return false;
	return true;
}

bool compare( Vector3& A,  Vector3& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance || 
		abs(a[2] - b[2]) > tolerance)
		return false;
	return true;
}

bool compare( Vector4& A,  Vector4& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance || 
		abs(a[2] - b[2]) > tolerance || 
		abs(a[3] - b[3]) > tolerance)
		return false;
	return true;
}

template <typename T>
void TEST(const char* msg, T& a, T& b) {
	if (compare(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match - \n\tB: (" << b << ")\n";
	}
}

// needed for comparing a float variable with a const float
template <typename T>
void TEST(const char* msg, T& a, float b) {
	if (compare(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match -\n\tB: (" << b << ")\n";
	}
}

bool runUnitTests() {

	// vector addition
	Vector2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	Vector3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	Vector4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	TEST("Vector2 addition", v2c, Vector2(18.5f,-44.24f));
	TEST("Vector3 addition", v3c, Vector3(18.5f,-44.24f,850));
	TEST("Vector4 addition", v4c, Vector4(18.5f,-44.24f,850,1));

	// vector subtraction
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	v2c = v2a - v2b;
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = v3a - v3b;
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a - v4b;

	TEST("Vector2 subtraction", v2c, Vector2(8.5f,-52.22f));
	TEST("Vector3 subtraction", v3c, Vector3(8.5f,-52.22f,874));
	TEST("Vector4 subtraction", v4c, Vector4(8.5f,-52.22f,874,-1));

	// vector post-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = v2a * 2.482f;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = v3a * 0.256f;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = v4a * 4.89f;

	TEST("Vector2 post-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	TEST("Vector3 post-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 post-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector pre-scale
	v2a = Vector2(13.5f, -48.23f);
	v2c = 2.482f * v2a;
	v3a = Vector3(13.5f, -48.23f, 862);
	v3c = 0.256f * v3a;
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	v4c = 4.89f * v4a;

	TEST("Vector2 pre-scale", v2c, Vector2(33.5069999695f, -119.706863403f));
	TEST("Vector3 pre-scale", v3c, Vector3(3.45600008965f, -12.3468809128f, 220.672012329f));
	TEST("Vector4 pre-scale", v4c, Vector4(66.0149993896f, -235.844696045f, 4215.1796875f, 0));

	// vector dot product
	v2a = Vector2(13.5f, -48.23f); v2b = Vector2(5, 3.99f);
	float dot2 = v2a.dot(v2b);
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	float dot3 = v3a.dot(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	float dot4 = v4a.dot(v4b);

	TEST("Vector2 dot", dot2, -124.937698364f);
	TEST("Vector3 dot", dot3, -10468.9375f);
	TEST("Vector4 dot", dot4, -10468.9375f);

	// vector cross product
	v3a = Vector3(13.5f, -48.23f, 862); v3b = Vector3(5, 3.99f, -12);
	v3c = v3a.cross(v3b);
	v4a = Vector4(13.5f, -48.23f, 862, 0); v4b = Vector4(5, 3.99f, -12, 1);
	v4c = v4a.cross(v4b);

	TEST("Vector3 cross", v3c, Vector3(-2860.62011719f, 295.014984131f, 295.014984131f));
	TEST("Vector4 cross", v4c, Vector4(-2860.62011719f, 295.014984131f, 295.014984131f, 0));

	// vector magnitude
	v2a = Vector2(13.5f, -48.23f);
	float mag2 = v2a.magnitude();
	v3a = Vector3(13.5f, -48.23f, 862);
	float mag3 = v3a.magnitude();
	v4a = Vector4(13.5f, -48.23f, 862, 0);
	float mag4 = v4a.magnitude();

	TEST("Vector2 magnitude", mag2, 50.0837593079f);
	TEST("Vector3 magnitude", mag3, 863.453735352f);
	TEST("Vector4 magnitude", mag4, 863.453735352f);

	// vector normalise
	v2a = Vector2(-13.5f, -48.23f);
	v2a.normalise();
	v3a = Vector3(13.5f, -48.23f, 862);
	v3a.normalise();
	v4a = Vector4(243, -48.23f, 862, 0);
	v4a.normalise();

	TEST("Vector2 normalise", v2a, Vector2(-0.269548f,-0.962987f));
	TEST("Vector3 normalise", v3a, Vector3(0.0156349f,-0.0558571f,0.998316f));
	TEST("Vector4 normalise", v4a, Vector4(0.270935f,-0.0537745f,0.961094f,0));
	
	return true;
}

















