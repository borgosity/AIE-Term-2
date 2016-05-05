// KXA354 - Computer Graphics & Animation, 2/02
// Assignment 2 - 3D Graphics with GLUT
//
// matrix.h
//
// This class defines a//
// Matrix and vector class declarations for 3x3 matrix and
// 3 row vector.



#ifndef _MATRIX_H
#define _MATRIX_H



class vertex;							// "preannounce" the vertex class so we can have
										// the vertex class as a friend of the matrix class
	


// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------

class matrix
{
	public:
		float	data[4][4];
		
	public:
		matrix();											// default constructor
		
		void set(float, float, float, float,				// initialiser
				 float, float, float, float, 
				 float, float, float, float, 
				 float, float, float, float);
				 
		void setTranslate(float, float, float);				// init as translation matrix
		void setScale(float);								// init as uniform scale matrix
		void setScale(float, float, float);					// init as nonuniform scale matrix
		void setRotateX(float);								// init as x-axis rotation matrix
		void setRotateY(float);								// init as y-axis rotation matrix
		void setRotateZ(float);								// init as z-axis rotation matrix
		
		// Tony's overloaded operators - retained for use in the extrusion class
		friend matrix operator*(matrix &a, matrix &b);		// multiply 2 matrices
		friend vertex operator*(matrix &a, vertex &b);		// multiply matrix by vector (vertex)
		
		// matrix multiplication functions
		void multiply(matrix &a, matrix* b); // multiply by a matrix
		void multiplyVertex(vertex &a, vertex* b); // multiply by vertex
		void multiplyNormal(float*, float*); // multiply a normal by the matrix
		void print(void);
};


#endif


		


