#pragma once

#include "MtxVec3.h"

class SpriteBatch;
class Texture;

class Object
{
public:
	Object();
	Object(int size, Vector3 & location, float mass = 10.0f);
	~Object();

	// transform member functions
	void SetPosition(Vector3 position);
	void SetVelocity(Vector3 velocity);
	void ResetVelocity();

	Vector3 GetPosition();

	// collision detection
	bool IsColliding(Object * object);
	bool IsColliding(Vector3 * position);

	void Update(float dt);
	void Draw(SpriteBatch* batch);
	void Reset();

private:
	
	float m_rotation;
	Vector3 m_position;	// current position
	Vector3 m_prevPos;  // last known position
	Vector3 m_velocity;
	Texture* m_objectSprite;

	// debug meber variables
	Font* m_fontDebug;
	bool m_debug;

	// auto movement member variables
	int m_direction;		// old direction checking
	int m_prevDir;			// old direction checking
	int m_xPlus;			// flag for checking if x is increasing (-1,0,1) -1 == (x == previous Value)
	int m_yPlus;			// flag for checking if y is increasing (-1,0,1) -1 == (x == previous Value)
	float m_mass;			// object mass
	int m_size;				// object size

	// private member functions
	int RandomDir();				// old generate direction function
	void DirectionCheck();			// sets xPlus and yPlus flags
	void EdgeDectection();			// checks is Object has reached the edge and adds the correct direction of rotation
	void SlowDown(int extra = 0);	// slow Object down, extra is a multiplier if needed
	void Bounce(int extra = 0);		// speed Object up after hitting something, extra is a multiplier if needed
};

