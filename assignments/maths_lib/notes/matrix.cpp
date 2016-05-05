// KXA354 - Computer Graphics & Animation, 2/02
// Assignment 2 - 3D Graphics with GLUT
//
// matrix.cpp
//
// Class definitions for a matrix operations



#include "matrix.h"
#include "vertex.h"
#include "utility.h"
#include <iostream>
using namespace std;



// --------------------------------------------------------------------------------
// matrix constructor (called automatically when a new matrix object is created)
// initialises the matrix as an identity matrix
// --------------------------------------------------------------------------------
matrix::matrix()
{
	short i;

	for (i=0; i<4; i++)
		data[i][0] = data[i][1] = data[i][2] = data [i][3] = 0.0;
	
	for (i=0; i<4; i++)
		data[i][i] = 1.0;
		
}



// --------------------------------------------------------------------------------
// matrix initialiser
// we can call this to set the matrix to a specific set of values
// --------------------------------------------------------------------------------
void matrix::set(float r0c0, float r0c1, float r0c2, float r0c3,
				float r1c0, float r1c1, float r1c2, float r1c3,
				float r2c0, float r2c1, float r2c2, float r2c3,
				float r3c0, float r3c1, float r3c2, float r3c3)
{
	data[0][0] = r0c0; data[0][1] = r0c1; data[0][2] = r0c2; data[0][3] = r0c3;
	data[1][0] = r1c0; data[1][1] = r1c1; data[1][2] = r1c2; data[1][3] = r1c3;
	data[2][0] = r2c0; data[2][1] = r2c1; data[2][2] = r2c2; data[2][3] = r2c3;
	data[3][0] = r3c0; data[3][1] = r3c1; data[3][2] = r3c2; data[3][3] = r3c3;
}



// --------------------------------------------------------------------------------
// setTranslate
// builds a translation matrix
// --------------------------------------------------------------------------------
void matrix::setTranslate(float tx, float ty, float tz)
{
	matrix();				// reset to identity
	data[0][3] = tx;		// store the translation values
	data[1][3] = ty;
	data[2][3] = tz;
}



// --------------------------------------------------------------------------------
// setScale
// builds a uniform scaling matrix
// --------------------------------------------------------------------------------
void matrix::setScale(float s)
{
	matrix();				// reset to identity
	data[0][0] = s;			// store the same scaling factor for each axis
	data[1][1] = s;
	data[2][2] = s;
}



// --------------------------------------------------------------------------------
// setScale
// builds a non-uniform scaling matrix
// --------------------------------------------------------------------------------
void matrix::setScale(float s1, float s2, float s3)
{
	matrix();				// reset to identity
	data[0][0] = s1;		// store the scaling factor for each axis
	data[1][1] = s2;
	data[2][2] = s3;
}



// --------------------------------------------------------------------------------
// setRotateX
// builds an X-axis rotation matrix
// --------------------------------------------------------------------------------
void matrix::setRotateX(float rx)
{
	matrix();					// reset to identity
	data[1][1] = cos_d(rx);		// store the rotation values
	data[1][2] = -sin_d(rx);
	data[2][1] = sin_d(rx);
	data[2][2] = cos_d(rx);
}



// --------------------------------------------------------------------------------
// setRotateY
// builds an Y-axis rotation matrix
// --------------------------------------------------------------------------------
void matrix::setRotateY(float rx)
{
	matrix();					// reset to identity
	data[0][0] = cos_d(rx);		// store the rotation values
	data[0][2] = sin_d(rx);
	data[2][0] = -sin_d(rx);
	data[2][2] = cos_d(rx);
}



// --------------------------------------------------------------------------------
// setRotateZ
// builds an Z-axis rotation matrix
// --------------------------------------------------------------------------------
void matrix::setRotateZ(float rx)
{
	matrix();					// reset to identity
	data[0][0] = cos_d(rx);		// store the rotation values
	data[0][1] = -sin_d(rx);
	data[1][0] = sin_d(rx);
	data[1][1] = cos_d(rx);
}




// --------------------------------------------------------------------------------
// matrix printer (for debugging purposes)
// we can use this to display the contents of a matrix
// --------------------------------------------------------------------------------
void matrix::print(void)
{
	for (short i=0; i<4; i++)
	{
		for (short j=0; j<4; j++)
			cout << data[i][j] << ",";
		cout << endl;
	}
	cout << endl;
}




// --------------------------------------------------------------------------------
// Multiply two matrices
// --------------------------------------------------------------------------------
matrix operator*(matrix &a, matrix &b)
{
	matrix	temp;
	
	for (short i=0; i<4; i++)
		for (short j=0; j<4; j++)
			temp.data[i][j] =  ((a.data[i][0] * b.data[0][j]) +
								(a.data[i][1] * b.data[1][j]) +
								(a.data[i][2] * b.data[2][j]) +
								(a.data[i][3] * b.data[3][j]));
	return (temp);
}




// --------------------------------------------------------------------------------
// Multiply a matrix by a vector (gives a vector result)
// --------------------------------------------------------------------------------
vertex operator*(matrix &a, vertex &b)
{ 
	vertex	temp;
	
	for (short i=0; i<4; i++)
	{
		temp.data[i] =  (a.data[i][0] * b.data[0]) +
						(a.data[i][1] * b.data[1]) +
						(a.data[i][2] * b.data[2]) +
						(a.data[i][3] * b.data[3]);
	}
	return (temp);
}

// multiply this matrix by matrix a and put results in matrix b
void matrix::multiply(matrix &a, matrix* b)
{
	for (short i=0; i<4; i++)
		for (short j=0; j<4; j++)
			b->data[i][j] =  ((data[i][0] * a.data[0][j]) +
								(data[i][1] * a.data[1][j]) +
								(data[i][2] * a.data[2][j]) +
								(data[i][3] * a.data[3][j]));
}


// multiply vertex a by the matrix and put results into vertex b
void matrix::multiplyVertex(vertex &a, vertex* b)
{
	for (short i=0; i<4; i++)
	{
		b->data[i] =  (data[i][0] * a.data[0]) +
						(data[i][1] * a.data[1]) +
						(data[i][2] * a.data[2]) +
						(data[i][3] * a.data[3]);
	}
}

//multiply normal a by the matrix and put results into normal b
void matrix::multiplyNormal(float* a, float* b)
{
	for (short i=0; i<3; i++)
	{
		b[i] = (data[i][0] * a[0]) + (data[i][1] * a[1]) + (data[i][2] * a[2]);
	}
}



