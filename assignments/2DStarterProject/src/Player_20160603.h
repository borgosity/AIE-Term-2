#pragma once

#include "MtxVec3.h"

class SpriteBatch;
class Texture;
class Object;
class Wall;

class Player
{
public:
	Player();
	Player(float size, float mass);
	~Player();

	void Update(float dt);
	void Draw(SpriteBatch* batch);
	void Reset();

	// movement member functions
	void ResetVelocity();

	// collision detection
	bool IsColliding(Player * player);
	bool IsColliding(std::shared_ptr<Object> object);
	bool IsColliding(Object * object);
	bool IsColliding(Vector3 * position);

	// collision resolution
	void ApplyCollision(int damage);
	void ApplyCollision(std::shared_ptr<Object> object);
	void ApplyCollision(Object * object);

	// sets
	void SetRotation(float rotate);
	void SetSize(float size);

	// gets
	Vector3 GetPosition();
	const float GetSize();
	bool IsAlive();


private:
	
	// players 
	Vector3 m_position;		// current position
	Vector3 m_prevPos;		// last known position
	float m_rotation;		// players rotation
	Vector3 m_velocity;		// player velocity
	float m_mass;			// player mass

	// players vitals
	float m_size;			// players original size
	float m_currentSize;	// players current size
	int m_health;			// players health
	bool m_alive;			// is player alive?

	// players visuals
	Texture* m_playerSprite;
	Font* m_fontHUD;

	// debug member variables
	Font* m_fontDebug;
	bool m_debug;

	// movement member variables
	int m_direction;		// old direction checking
	int m_prevDir;			// old direction checking
	int m_xPlus;			// flag for checking if x is increasing (-1,0,1) -1 == (x == previous Value)
	int m_yPlus;			// flag for checking if y is increasing (-1,0,1) -1 == (x == previous Value)

	// private member functions
	int RandomDir();				// old generate direction function
	void DirectionCheck();			// sets xPlus and yPlus flags
	void EdgeDectection();			// checks is player has reached the edge and adds the correct direction of rotation
	void SlowDown(int extra = 0);	// slow player down, extra is a multiplier if needed
	void Bounce(int extra = 0);		// speed player up after hitting something, extra is a multiplier if needed
};

