#pragma once

#include "MtxVec3.h"
#include "SceneNode.h"

class SpriteBatch;
class Texture;
class Sprite;
class Object;
class Wall;

class Player : public SceneNode
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
	void SetRotation(float rotate) { m_rotation += rotate; }
	void SetSize(float size) { m_size += size; }

	// gets
	Vector3 GetPosition() { return m_position; }
	const float GetSize() { return m_currentSize; }
	bool IsAlive() { return m_alive; }
	int Score() { return m_points; }

private:
	
	// players 
	SceneNode* m_root;		// player root 
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
	int m_points;			// player points

	// players visuals
	Texture* m_playerSprite;
	Texture* m_tailSprite;
	Sprite* m_spike1;
	Sprite* m_spike1a;
	Sprite* m_spike2;
	Sprite* m_spike2a;
	Sprite* m_spike3;
	Sprite* m_spike3a;
	Sprite* m_spike4;
	Sprite* m_spike4a;

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
	void EdgeDectection();			// checks is player has reached the edge and adds the correct direction of rotation
	void SlowDown(int extra = 0);	// slow player down, extra is a multiplier if needed
	void Bounce(int extra = 0);		// speed player up after hitting something, extra is a multiplier if needed

		
};

