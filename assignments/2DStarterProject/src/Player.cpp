#include "Player.h"
#include "GameDef.h"



Player::Player()
{
}


Player::~Player()
{
	Reset();
}

void Player::Update(float dt)
{
}

void Player::Draw(SpriteBatch * batch)
{
}

void Player::Reset()
{
	m_position.m_x = HALF_SCRW;
	m_position.m_y = HALF_SCRH;
	m_velocity.m_x = 0;
	m_velocity.m_y = 1;
	m_rotation = 0.0;
}
