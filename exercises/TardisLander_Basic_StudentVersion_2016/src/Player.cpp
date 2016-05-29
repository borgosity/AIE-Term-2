#include <GLFW/glfw3.h>
#include "Player.h"
#include "GameDefs.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Matrix3.h"
#include "Vector2.h"
#include "Application2D.h"

Player::Player()
{
	m_sprite = new Texture("./bin/textures/ship.png");
	m_pFireSprite = new Texture("./bin/textures/fire.png");
	
	Reset();
}

Player::~Player(void)
{
	delete m_sprite;
	delete m_pFireSprite;
}

void Player::Reset() {
	m_position.x = HALF_SCRW;
	m_position.y = HALF_SCRH;
	m_velocity.x = 0;
	m_velocity.y = 1;
	m_rotation = 0.0;
	m_bIsDead = false;
	m_bHasLanded = false;
	m_bFlameOn = false;
}

void Player::Update(float dt) {
	if(m_bHasLanded)
		return;

	//drop ship due to gravity
	m_velocity.y -= GRAVITY;

	Application2D* app = Application2D::getInstance();
	
	//turn ship left or right
	if(app->IsKeyDown(GLFW_KEY_LEFT))
		m_rotation += 0.1;
	if(app->IsKeyDown(GLFW_KEY_RIGHT))
		m_rotation -= 0.1;

	 //calculate thrust according to current rotation
	if(app->IsKeyDown(GLFW_KEY_UP)) {
		m_bFlameOn = true;
		m_velocity.y += SPEED; 
	}
	else {
		m_bFlameOn = false;
	}

	Matrix3 m = Matrix3::CreateRotation(m_rotation * (M_PI / 180));
	Vector3 v = m * m_velocity;
	m_position += v * dt;

	if (m_position.y - PLAYER_HALFH < GROUND_Y) {
		float speed = m_velocity.Length() * dt;
		if (speed > 0.8f) {
			// CRASH!!!
			m_bIsDead = true;
		}
		m_bHasLanded = true;
		m_velocity.y = 0;
		m_velocity.x = 0;
	}
}

void Player::Draw(SpriteBatch* spritebatch) {	
	Matrix3 transpose = Matrix3::CreateTranslation(Vector3(m_position.x, m_position.y, 0));
	Matrix3 rotation = Matrix3::CreateRotation(m_rotation * (M_PI / 180));
	Matrix3 translation = rotation * transpose;

	spritebatch->drawSpriteTransformed3x3(m_sprite, translation.m);

	if (m_bFlameOn) {
		Matrix3 transpose = Matrix3::CreateTranslation(Vector3(m_position.x, m_position.y, 0));
		Matrix3 offset = Matrix3::CreateTranslation(Vector3(0, -110, 1));	//can be thought of as displacement from ship
		Matrix3 rotation = Matrix3::CreateRotation(m_rotation * (M_PI / 180));
		Matrix3 translation = offset * rotation * transpose;
		spritebatch->drawSpriteTransformed3x3(m_pFireSprite, translation.m);
	}
}
