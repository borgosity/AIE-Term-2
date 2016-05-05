// KXA354 - Computer Graphics & Animation, 2/02
// Assignment 2 - 3D Graphics with GLUT
//
// vertex.cpp
//
// Class definition for a vertex



#include "vertex.h"
#include <iostream>
using namespace std;


// -----------------------------------------------------------------------------------------
// vertex constructor
// -----------------------------------------------------------------------------------------
vertex::vertex()
{
}




// -----------------------------------------------------------------------------------------
// destructor
// -----------------------------------------------------------------------------------------
vertex::~vertex()
{
}



// -----------------------------------------------------------------------------------------
// vector printer (for debugging purposes)
// we can use this to display the contents of a vertex
// -----------------------------------------------------------------------------------------
void vertex::print()
{
	for (short i=0; i<4; i++)
		cout << data[i] << ",";
	cout << endl << endl;
}




