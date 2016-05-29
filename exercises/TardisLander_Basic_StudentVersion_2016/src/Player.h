#pragma once

#include "Vector3.h"

class SpriteBatch;
class Texture;

class Player 
{
public:
	Player();
	~Player();

	void Update(float dt);
	void Draw(SpriteBatch* batch);
	void Reset();

	inline bool IsDead() {return m_bIsDead;}
	inline bool HasLanded() {return m_bHasLanded;}

private:
	Texture* m_sprite;
	Texture* m_pFireSprite;

	bool m_bFlameOn;
	float m_rotation;
	Vector3 m_position;
	Vector3 m_velocity;
	bool m_bIsDead;
	bool m_bHasLanded;
};

