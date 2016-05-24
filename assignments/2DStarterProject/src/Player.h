#pragma once

#include "MtxVec3.h"

class SpriteBatch;

class Player
{
public:
	Player();
	~Player();

	void Update(float dt);
	void Draw(SpriteBatch* batch);
	void Reset();

private:
	float m_rotation;
	Vector3 m_position;
	Vector3 m_velocity;
	
};

