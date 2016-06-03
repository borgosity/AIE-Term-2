#pragma once

#include "Collisions.h"

Vector3 GetReflection(Vector3 & v, Vector3 & normal)
{
	// final velocity vector
	Vector3 reflection;

	// find projection (P) of Vi(vecA(initial velocity)) on N(normalised vecB(collision normal))
	// ------------------------------------------------------------------------------------------
	// P = (-Vi.Dot(N)) * N
	Vector3 projection((-v.dot(normal)) * normal);

	// final velocity(Vf)
	// P = projection of Vi on to the collision normal
	// Vi = Initial velocity of object A prior to collision with stationary object B
	// --------------------------------------------------------------------------------------
	// Vf = 2 * P + Vi

	reflection = (2 * projection) + v;

	return reflection;
}
