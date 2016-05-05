// KXA354 - Computer Graphics & Animation, 2/02
// Assignment 2 - 3D Graphics with GLUT
//
// vertex.h
//
// This is a class used to represent a vertex.  The core requirement is that
// this class provide storage for a 4 row vector to represent a point in
// 3D space.
//
// Other data members of this class are not required for simple 3D applications
// but with advanced lighting models (such as Gouraud and Phong shading) each
// vertex will have its own average brightness and "surface normal" coefficients
// so it makes sense to allocate storage space in the object for this information 
// as well.


#ifndef _VERTEX_H
#define _VERTEX_H



class matrix;							// "preannounce" the matrix class so we can have
										// the matrix class as a friend of the vertex class


// -----------------------------------------------------------------------------------------
// class declaration
// -----------------------------------------------------------------------------------------
class vertex
{
	public:
		float			data[4];						// the coordinate data for this vertex
		float			normal[3];						// the normal for this vertex (for lighting)
		
		vertex();										// default destructor
		~vertex();										// destructor

		void set(float X, float Y, float Z)				// initialiser
			{	data[0] = X;
				data[1] = Y;
				data[2] = Z;
				data[3] = 1; }	



		// accessor functions
		float	getX() { return data[0]; }
		float	getY() { return data[1]; }
		float	getZ() { return data[2]; }
		
		void	setX(float X) { data[0] = X; }
		void	setY(float Y) { data[1] = Y; }
		void	setZ(float Z) { data[2] = Z; }

		friend vertex  operator*(matrix &a, vertex &b);	// multiply matrix by vector (vertex)

		void 	print(void);
};


#endif

