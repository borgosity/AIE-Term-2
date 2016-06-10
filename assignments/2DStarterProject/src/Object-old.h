#pragma once

#include "MtxVec3.h"
#include "SceneNode.h"

class SpriteBatch;
class Texture;
class Player;

class Object : public SceneNode
{
public:
	// constructors
	Object();
	Object(float size, Vector3 & location, float mass);
	~Object();

	// transform member functions
	void SetPosition(Vector3 position) { m_position = position; }
	void SetVelocity(Vector3 velocity) { m_velocity = velocity; }
	void ResetVelocity();
	void DecreaseSpawns(int spawnNum = 1) { m_spawnNum -= spawnNum; }

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
	Vector3 GetPosition() { return m_position; }
	const float GetSize() { return m_currentSize; }
	bool IsAlive() { return m_alive; }
	const int RespawnCount() { return m_respawnNum; }

	// game updates
	void Update(float dt);
	void Draw(SpriteBatch* batch);
	void Reset();

private:
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

	// private member functions
	void EdgeDectection();			// checks is Object has reached the edge and adds the correct direction of rotation
	void SlowDown(int extra = 0);	// slow Object down, extra is a multiplier if needed
	void Bounce(int extra = 0);		// speed Object up after hitting something, extra is a multiplier if needed
};

