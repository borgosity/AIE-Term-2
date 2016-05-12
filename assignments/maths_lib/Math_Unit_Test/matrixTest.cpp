#include "unittest.h"
#include <iostream>
#include <iomanip>

#ifndef NO_DEFAULT_STREAM_OPERATOR

	std::ostream& operator << (std::ostream& os, Matrix2& rhs) {
		float* a = (float*)rhs;
		for (int i = 0; i < 4; ++i) {
			os << std::setprecision(12) << a[i];
			if (!(i == 3 ))
				os << ",";
		}
		return os;
	}
	std::ostream& operator << (std::ostream& os, Matrix3& rhs) {
		float* a = (float*)rhs;
		for (int i = 0; i < 9; ++i) {
			os << std::setprecision(12) << a[i];
			if (!(i == 8))
				os << ",";
		}
		return os;
	}
	std::ostream& operator << (std::ostream& os, Matrix4& rhs) {
		float* a = (float*)rhs;
		for (int i = 0; i < 16; ++i) {
			os << std::setprecision(12) << a[i];
			if (!(i == 15))
				os << ",";
		}
		return os;
	}

#endif

static const float DEFAULT_TOLERANCE = 0.00001f;

bool compareM(float a, float b, float tolerance = DEFAULT_TOLERANCE) {
	if (abs(a - b) > tolerance)
		return false;
	return true;
}

bool compareM( Vector2& A,  Vector2& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance)
		return false;
	return true;
}

bool compareM( Vector3& A,  Vector3& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance || 
		abs(a[2] - b[2]) > tolerance)
		return false;
	return true;
}

bool compareM( Vector4& A,  Vector4& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || 
		abs(a[1] - b[1]) > tolerance || 
		abs(a[2] - b[2]) > tolerance || 
		abs(a[3] - b[3]) > tolerance)
		return false;
	return true;
}

bool compareM( Matrix2& A,  Matrix2& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance ||
		abs(a[2] - b[2]) > tolerance || abs(a[3] - b[3]) > tolerance)
		return false;
	return true;
}

bool compareM( Matrix3& A,  Matrix3& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance || abs(a[2] - b[2]) > tolerance ||
		abs(a[3] - b[3]) > tolerance || abs(a[4] - b[4]) > tolerance || abs(a[5] - b[5]) > tolerance ||
		abs(a[6] - b[6]) > tolerance || abs(a[7] - b[7]) > tolerance || abs(a[8] - b[8]) > tolerance)
		return false;
	return true;
}

bool compareM( Matrix4& A,  Matrix4& B, float tolerance = DEFAULT_TOLERANCE) {
	 float* a = ( float*)A;
	 float* b = ( float*)B;
	if (abs(a[0] - b[0]) > tolerance || abs(a[1] - b[1]) > tolerance || abs(a[2] - b[2]) > tolerance || abs(a[3] - b[3]) > tolerance ||
		abs(a[4] - b[4]) > tolerance || abs(a[5] - b[5]) > tolerance || abs(a[6] - b[6]) > tolerance || abs(a[7] - b[7]) > tolerance ||
		abs(a[8] - b[8]) > tolerance || abs(a[9] - b[9]) > tolerance || abs(a[10] - b[10]) > tolerance || abs(a[11] - b[11]) > tolerance ||
		abs(a[12] - b[12]) > tolerance || abs(a[13] - b[13]) > tolerance || abs(a[14] - b[14]) > tolerance || abs(a[15] - b[15]) > tolerance)
		return false;
	return true;
}

template <typename T>
void TEST(const char* msg, T& a, T& b) {
	if (compareM(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match - \n\tB: (" << b << ")\n";
	}
}

// needed for comparing a float variable with a const float
template <typename T>
void TEST(const char* msg, T& a, float b) {
	if (compareM(a, b) == false) {
		std::cout << "Test failed: " << msg << "\n\tA: (" << a << ")\n\t - does not match -\n\tB: (" << b << ")\n";
	}
}

bool runMatrixTests() {

	// vector addition
	Vector2 v2a(13.5f, -48.23f), v2b(5, 3.99f), v2c;
	v2c = v2a + v2b;
	Vector3 v3a(13.5f, -48.23f, 862), v3b(5, 3.99f, -12), v3c;
	v3c = v3a + v3b;
	Vector4 v4a(13.5f, -48.23f, 862, 0), v4b(5, 3.99f, -12, 1), v4c;
	v4c = v4a + v4b;

	// matrix rotation
	Matrix2 m2;
	Matrix3 m3a, m3b, m3c, m3d;
	Matrix4 m4a, m4b, m4c, m4d;
	m2.setRotateZ(4.576f);
	m3a.setRotateX(3.98f);
	m4a.setRotateX(4.5f);
	m3b.setRotateY(1.76f);
	m4b.setRotateY(-2.6f);
	m3c.setRotateZ(9.62f);
	m4c.setRotateZ(0.72f);

	TEST("Matrix2 rotate", m2, Matrix2(-0.135966f,-0.990713f,0.990713f,-0.135966f));
	TEST("Matrix3 rotate", m3a, Matrix3(1,0,0,0,-0.668648f,-0.743579f,0,0.743579f,-0.668648f));
	TEST("Matrix3 rotate", m3b, Matrix3(-0.188077f,0,-0.982154f,0,1,0,0.982154f,0,-0.188077f));
	TEST("Matrix3 rotate", m3c, Matrix3(-0.981005f,-0.193984f,0,0.193984f,-0.981005f,0,0,0,1));
	TEST("Matrix4 rotate", m4a, Matrix4(1,0,0,0,0,-0.210796f,-0.97753f,0,0,0.97753f,-0.210796f,0,0,0,0,1));
	TEST("Matrix4 rotate", m4b, Matrix4(-0.856889f,0,0.515501f,0,0,1,0,0,-0.515501f,0,-0.856889f,0,0,0,0,1));
	TEST("Matrix4 rotate", m4c, Matrix4(0.751806f,0.659385f,0,0,-0.659385f,0.751806f,0,0,0,0,1,0,0,0,0,1));

	// vector transform
	v2a = Vector2(13.5f, -48.23f);
	//v2c = m2 * v2a;
	//v3a = Vector3(13.5f, -48.23f, 862);
	//v3b = m3b * v3a;
	//v3c = m3c * v3a;
	//v4a = Vector4(13.5f, -48.23f, 862, 0);
	//Vector4 v4d = Vector4(13.5f, -48.23f, -54, 1);
	//v4b = m4b * v4a;
	//v4c = m4c * v4a;

	TEST("Vector2 matrix transform", v2c, Vector2(-49.6176567078f, -6.81697654724f));
	TEST("Vector3 matrix transform", v3b, Vector3(844.077941895f, -48.2299995422f, -175.38130188f));
	TEST("Vector3 matrix transform", v3c, Vector3(-22.5994224548f, 44.6950683594f, 862));
	TEST("Vector4 matrix transform", v4b, Vector4(-455.930236816f, -48.2299995422f, -731.678771973f, 0));
	TEST("Vector4 matrix transform", v4c, Vector4(41.951499939f, -27.3578968048f, 862, 0));

	// matrix multiply
	Matrix2 m2b, m2c;
	m2b.setRotateZ(-2.145f);
	m2c = m2 * m2b;
	m3d = m3a * m3c;
	m4d = m4c * m4b;

	TEST("Matrix2 multiply", m2c, Matrix2(-0.757975637913f, 0.652282953262f, -0.652282953262f, -0.757975637913f));
	TEST("Matrix3 multiply", m3d, Matrix3(-0.981004655361f, 0.129707172513f, 0.14424264431f, 0.193984255195f, 0.655946731567f, 0.729454636574f, 0, 0.743579149246f, -0.668647944927f));
	TEST("Matrix4 multiply", m4d, Matrix4(-0.644213855267f, -0.565019249916f, 0.515501439571f, 0, -0.659384667873f, 0.751805722713f, 0, 0, -0.387556940317f, -0.339913755655f, -0.856888711452f, 0, 0, 0, 0, 1));
	
	return true;
}