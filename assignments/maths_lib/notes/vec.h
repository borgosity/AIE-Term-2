// vec.h
//
// This is a class used to represent 3-component vectors, such as 3-dimensional forces, velocity
// acceleration etc.


#pragma once

// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------
class vec
{
	public:
		float			data[3];						// the coordinate data for this vec
		
		vec();											// default destructor
		~vec();											// destructor

		void set(float, float, float);					// initialisers
		void copy(vec v);								// copy the data from the parameter vector
		void add(float x, float y, float z);			// add an offset to the vec
		void add(vec &b);			// add two vecs
		void subtract(vec &b);		// subtract a vec from another
		void scale(float scaleFactor);		// scale the vector
		void normalise();
		void crossProduct(vec &b, vec *c);
		float dotProduct(vec &b);
		float getData(int i);
		void print(void);



};

