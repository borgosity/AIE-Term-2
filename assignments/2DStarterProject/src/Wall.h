#pragma once

#include "MtxVec3.h"

class SpriteBatch;
class Texture;

class Wall
{
public:
	Wall();
	Wall(float mass);
	~Wall();

	void Update(float dt);
	void Draw(SpriteBatch* batch);
	void Reset();
	// movement member functions
	void MoveWall(int direction);
	void ChangeDirection();
	void ResetVelocity();

private:
	
	float m_rotation;
	Vector3 m_position;	// current position
	Vector3 m_prevPos;  // last known position
	Vector3 m_velocity;
	Texture* m_WallSprite;

	// debug meber variables
	Font* m_fontDebug;
	bool m_debug;

	// auto movement member variables
	int m_direction;		// old direction checking
	int m_prevDir;			// old direction checking
	int m_xPlus;			// flag for checking if x is increasing (-1,0,1) -1 == (x == previous Value)
	int m_yPlus;			// flag for checking if y is increasing (-1,0,1) -1 == (x == previous Value)
	float m_mass;

	// private member functions
	int RandomDir();				// old generate direction function
	void DirectionCheck();			// sets xPlus and yPlus flags
	void EdgeDectection();			// checks is Wall has reached the edge and adds the correct direction of rotation
	void SlowDown(int extra = 0);	// slow Wall down, extra is a multiplier if needed
	void Bounce(int extra = 0);		// speed Wall up after hitting something, extra is a multiplier if needed
};

