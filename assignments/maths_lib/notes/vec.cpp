// KXA354 - Computer Graphics & Animation, 2/03
// Assignment 2 - 3D Graphics with GLUT
//
// vec.cpp
//
// Class definition for a vector



#include "vec.h"
#include <cmath>
#include <iostream>
using namespace std;


// -----------------------------------------------------------------------------------------
// vec constructor
// -----------------------------------------------------------------------------------------
vec::vec()
{
	set(0, 0, 0);
}

// -----------------------------------------------------------------------------------------
// destructor
// -----------------------------------------------------------------------------------------
vec::~vec()
{
}

// set the fields of the vec
void vec::set(float x, float y, float z)
{
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

// copy the data from the parameter vector
void vec::copy(vec v)
{
	data[0] = v.data[0];
	data[1] = v.data[1];
	data[2] = v.data[2];
}


// add offset to a vec
void vec::add(float x, float y, float z)
{
	data[0] += x;
	data[1] += y;
	data[2] += z;
}

// add another vector onto this one
void vec::add(vec &b)
{
	data[0] = data[0] + b.data[0];
	data[1] = data[1] + b.data[1];
	data[2] = data[2] + b.data[2];
}

// subtract one vec from another
void vec::subtract(vec &b)
{
	data[0] = data[0] - b.data[0];
	data[1] = data[1] - b.data[1];
	data[2] = data[2] - b.data[2];
}

// normalise the vector
void vec::normalise()
{
	float length = sqrt(data[0]*data[0]+data[1]*data[1]+data[2]*data[2]);
	scale(1.0/length);
}


// scale the vector
void vec::scale(float scaleFactor)
{
	data[0] = data[0] * scaleFactor;
	data[1] = data[1] * scaleFactor;
	data[2] = data[2] * scaleFactor;	
}	

//calculate the crossProduct of the vectors
void vec::crossProduct(vec &b, vec *c)
{
	c->set(data[1]*b.data[2]-data[2]*b.data[1], -data[0]*b.data[2]+data[2]*b.data[0], data[0]*b.data[1]-data[1]*b.data[0]);
}

//calculate the crossProduct of the vectors
float vec::dotProduct(vec &b)
{
	return data[0]*b.data[0] + data[1]*b.data[1] + data[2]*b.data[2];
}				

float vec::getData(int i)
{
	return data[i];
}


// -----------------------------------------------------------------------------------------
// vec printer (for debugging purposes)
// we can use this to display the contents of a vec
// -----------------------------------------------------------------------------------------
void vec::print()
{
	for (short i=0; i<3; i++)
		cout << data[i] << ",";
	cout << endl;
}




