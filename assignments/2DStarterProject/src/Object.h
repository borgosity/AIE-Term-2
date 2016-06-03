#pragma once

#include "MtxVec3.h"

class SpriteBatch;
class Texture;
class Player;

class Object
{
public:
	Object();
<<<<<<< HEAD
	Object(float size, Vector3 & location, float mass);
=======
	Object(int size, Vector3 & location, float mass = 10.0f);
>>>>>>> origin/master
	~Object();

	// transform member functions
	void SetPosition(Vector3 position);
	void SetVelocity(Vector3 velocity);
	void ResetVelocity();
<<<<<<< HEAD
	void DecreaseSpawns(int spawnNum = 1);

	// collision detection
	bool IsColliding(std::shared_ptr<Object> object);
	bool IsColliding(Object * object);
	bool IsColliding(Player * player);
	bool IsColliding(Vector3 * position);
	
	// collision resolution
	void ApplyCollision(std::shared_ptr<Object> object);
	void ApplyCollision(Object * object);
	void ApplyCollision(Player * player);

	// gets 
	Vector3 GetPosition();
	const float GetSize();
	bool IsAlive();
	const int RespawnCount();
=======

	Vector3 GetPosition();

	// collision detection
	bool IsColliding(Object * object);
	bool IsColliding(Vector3 * position);
>>>>>>> origin/master

	void Update(float dt);
	void Draw(SpriteBatch* batch);
	void Reset();

private:
	
<<<<<<< HEAD
	// objects
	Vector3 m_position;		// current position
	Vector3 m_prevPos;		// last known position
	float m_rotation;		// object rotation
	Vector3 m_velocity;		// object velocity
	float m_mass;			// object mass
	

	// objects vitals
	float m_size;			// objects size
	float m_currentSize;	// objects current size
	int m_health;			// objectss health
	bool m_alive;			// is object alive?
	int m_spawnNum;			// number of evils twins to spawn
	int m_respawnNum;		// number of generations, decreases with each generation
=======
	float m_rotation;
	Vector3 m_position;	// current position
	Vector3 m_prevPos;  // last known position
	Vector3 m_velocity;
	Texture* m_objectSprite;
>>>>>>> origin/master

	// objects visuals
	Texture* m_objectSprite;
	
	// debug meber variables
	Font* m_fontDebug;
	bool m_debug;

	// auto movement member variables
	int m_direction;		// old direction checking
	int m_prevDir;			// old direction checking
	int m_xPlus;			// flag for checking if x is increasing (-1,0,1) -1 == (x == previous Value)
	int m_yPlus;			// flag for checking if y is increasing (-1,0,1) -1 == (x == previous Value)
<<<<<<< HEAD

=======
	float m_mass;			// object mass
	int m_size;				// object size
>>>>>>> origin/master

	// private member functions
	int RandomDir();				// old generate direction function
	void DirectionCheck();			// sets xPlus and yPlus flags
	void EdgeDectection();			// checks is Object has reached the edge and adds the correct direction of rotation
	void SlowDown(int extra = 0);	// slow Object down, extra is a multiplier if needed
	void Bounce(int extra = 0);		// speed Object up after hitting something, extra is a multiplier if needed
};

