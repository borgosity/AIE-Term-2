#pragma once
// std lib includes
#include <random>
#include <math.h>
#include <string>
// dependency includes
#include <GLFW/glfw3.h>
// basic code includes
#include "Sprite.h"
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
// my code includes
#include "Application2D.h"
#include "Player.h"
#include "GameDef.h"


/*****************************************************************************************************************
	Default Player Constructor
******************************************************************************************************************/
Player::Player()
{
	// set player attributes
	m_playerSprite = new Texture("./bin/textures/player.png");
	m_fontHUD = new Font("./bin/font/consolas.ttf", 25);
	m_mass = 10.0f;
	m_size = 100.0f;
	m_currentSize = m_size;
	m_health = 100;
	m_alive = true;

	// add spikes
	m_spike1 = new Sprite("./bin/textures/tailBig.png");
	AddChild(m_spike1, this);
	m_spike1a = new Sprite("./bin/textures/tailBig.png");
	AddChild(m_spike1a, m_spike1);

	m_spike2 = new Sprite("./bin/textures/tailBig.png");
	AddChild(m_spike2, this);
	m_spike2a = new Sprite("./bin/textures/tailBig.png");
	AddChild(m_spike2a, m_spike2);

	m_spike3 = new Sprite("./bin/textures/tailBig.png");
	AddChild(m_spike3, this);
	m_spike3a = new Sprite("./bin/textures/tailBig.png");
	AddChild(m_spike3a, m_spike3);

	m_spike4 = new Sprite("./bin/textures/tailBig.png");
	AddChild(m_spike4, this);
	m_spike4a = new Sprite("./bin/textures/tailBig.png");
	AddChild(m_spike4a, m_spike4);

	// set local transforms for spikes
	Matrix3 spike1(0); 
	spike1.CreateTranslation(Vector3(0.0f, -75.0f, 1.0f));
	m_spike1->SetLocalTransform(spike1);
	Matrix3 spike1a(0); 
	spike1a.CreateTranslation(Vector3(0.0f, -25.0f, 1.0f));
	m_spike1a->SetLocalTransform(spike1a);

	Matrix3 spike2(0); 
	spike2.CreateTranslation(Vector3(0.0f, 75.0f, 1.0f));
	m_spike2->SetLocalTransform(spike2);
	Matrix3 spike2a(0); 
	spike2a.CreateTranslation(Vector3(0.0f, 25.0f, 1.0f));
	m_spike2a->SetLocalTransform(spike2a);

	Matrix3 spike3(0); 
	spike3.CreateTranslation(Vector3(-75.0f, 0.0f, 1.0f));
	m_spike3->SetLocalTransform(spike3);
	Matrix3 spike3a(0); 
	spike3a.CreateTranslation(Vector3(-25.0f, 0.0f, 1.0f));
	m_spike3a->SetLocalTransform(spike3a);

	Matrix3 spike4(0); 
	spike4.CreateTranslation(Vector3(75.0f, 0.0f, 1.0f));
	m_spike4->SetLocalTransform(spike4);
	Matrix3 spike4a(0); 
	spike4a.CreateTranslation(Vector3(25.0f, 0.0f, 1.0f));
	m_spike4a->SetLocalTransform(spike4a);

	// set spike sprite names
	m_spike1->SetNodeName("m_spike1");
	m_spike2->SetNodeName("m_spike2");
	m_spike3->SetNodeName("m_spike3");
	m_spike4->SetNodeName("m_spike4");
	m_spike1a->SetNodeName("m_spike1a");
	m_spike2a->SetNodeName("m_spike2a");
	m_spike3a->SetNodeName("m_spike3a");
	m_spike4a->SetNodeName("m_spike4a");

	// debug setup
	m_fontDebug = new Font("./bin/font/consolas.ttf", 15);
	m_debug = false;

	// restet player
	Reset();
}
/*****************************************************************************************************************
	Player Constructor with size and mass parameter
******************************************************************************************************************/
Player::Player(float size = 100.0f, float mass = 10.0f)
{
	// set player attributes
	m_playerSprite = new Texture("./bin/textures/player.png");
	m_fontHUD = new Font("./bin/font/consolas.ttf", 25);
	m_mass = 10.0f;
	m_size = 100.0f;
	m_currentSize = m_size;
	m_health = 100;
	m_alive = true;

	// add spikes
	m_spike1 = new Sprite("./bin/textures/tailBig.png");
	AddChild(m_spike1, this);
	m_spike1a = new Sprite("./bin/textures/tailBig.png");
	AddChild(m_spike1a, m_spike1);

	m_spike2 = new Sprite("./bin/textures/tailBig.png", 50.0f, 50.0f, M_PI * 45.0f);
	AddChild(m_spike2, this);
	m_spike2a = new Sprite("./bin/textures/tailBig.png", 50.0f, 50.0f, M_PI * 45.0f);
	AddChild(m_spike2a, m_spike2);

	m_spike3 = new Sprite("./bin/textures/tailBig.png", 50.0f, 50.0f, M_PI * 67.5f);
	AddChild(m_spike3, this);
	m_spike3a = new Sprite("./bin/textures/tailBig.png", 50.0f, 50.0f, M_PI * 67.5f);
	AddChild(m_spike3a, m_spike3);

	m_spike4 = new Sprite("./bin/textures/tailBig.png", 50.0f, 50.0f, M_PI * 22.5f);
	AddChild(m_spike4, this);
	m_spike4a = new Sprite("./bin/textures/tailBig.png", 50.0f, 50.0f, M_PI * 22.5f);
	AddChild(m_spike4a, m_spike4);

	// set local transforms for spikes
	Matrix3 spike1Trans(0);
	spike1Trans.CreateTranslation(Vector3(0.0f, -75.0f, 1.0f));
	m_spike1->SetLocalTransform(spike1Trans);
	Matrix3 spike1a(0);
	spike1a.CreateTranslation(Vector3(0.0f, -25.0f, 1.0f));
	m_spike1a->SetLocalTransform(spike1a);

	Matrix3 spike2(0);
	spike2.CreateTranslation(Vector3(0.0f, 75.0f, 1.0f));
	m_spike2->SetLocalTransform(spike2);
	Matrix3 spike2a(0);
	spike2a.CreateTranslation(Vector3(0.0f, 25.0f, 1.0f));
	m_spike2a->SetLocalTransform(spike2a);

	Matrix3 spike3(0);
	spike3.CreateTranslation(Vector3(-75.0f, 0.0f, 1.0f));
	m_spike3->SetLocalTransform(spike3);
	Matrix3 spike3a(0);
	spike3a.CreateTranslation(Vector3(-25.0f, 0.0f, 1.0f));
	m_spike3a->SetLocalTransform(spike3a);

	Matrix3 spike4(0);
	spike4.CreateTranslation(Vector3(75.0f, 0.0f, 1.0f));
	m_spike4->SetLocalTransform(spike4);
	Matrix3 spike4a(0);
	spike4a.CreateTranslation(Vector3(25.0f, 0.0f, 0.3f));
	m_spike4a->SetLocalTransform(spike4a);

	// set sprite names
	m_spike1->SetNodeName("m_spike1");
	m_spike2->SetNodeName("m_spike2");
	m_spike3->SetNodeName("m_spike3");
	m_spike4->SetNodeName("m_spike4");
	m_spike1a->SetNodeName("m_spike1a");
	m_spike2a->SetNodeName("m_spike2a");
	m_spike3a->SetNodeName("m_spike3a");
	m_spike4a->SetNodeName("m_spike4a");

	// debug setup
	m_fontDebug = new Font("./bin/font/consolas.ttf", 15);
	m_debug = false;
	// restet player
	Reset();
}
/*****************************************************************************************************************
	Player Destructor
******************************************************************************************************************/
Player::~Player()
{
	// spikes destruction handled by Sprite class
	delete m_playerSprite;
	delete m_fontHUD;
	delete m_fontDebug;
}
/*****************************************************************************************************************
	Update Player Object
******************************************************************************************************************/
void Player::Update(float dt)
{
	// if dead don't update anything
	if (!m_alive)
		return;
	
	// get instance of game
	Application2D* app = Application2D::getInstance();

	// reset players rotation
	m_rotation = 0;

	// key press checks for player actions
	//-------------------------------------------------
	// key left 
	if (app->IsKeyDown(GLFW_KEY_LEFT))
	{
		m_rotation += TURN_LEFT;
		m_velocity.m_x -= SPEED;
	}
	//key right
	if (app->IsKeyDown(GLFW_KEY_RIGHT))
	{
		m_rotation += TURN_RIGHT;
		m_velocity.m_x += SPEED;
	}
	// key up
	if (app->IsKeyDown(GLFW_KEY_UP))
	{
		m_velocity.m_y += SPEED;
	}
	// key down
	if (app->IsKeyDown(GLFW_KEY_DOWN))
	{
		m_velocity.m_y += -SPEED;
	}
	// toggle debug
	if (app->IsKeyDown(GLFW_KEY_D))
	{
		if (m_debug)
		{
			m_debug = false;
		}
		else
		{
			m_debug = true;
		}
	}

	// update players spikes
	m_spike1->Update(dt);
	m_spike1a->Update(dt);
	m_spike2->Update(dt);
	m_spike2a->Update(dt);
	m_spike3->Update(dt);
	m_spike3a->Update(dt);
	m_spike4->Update(dt);
	m_spike4a->Update(dt);

	// modify player based on rotation
	Matrix3 mTranspose(0);
	mTranspose.CreateTranslation(m_velocity.m_x * dt, m_velocity.m_y * dt, 1.0f);
	Matrix3 mRotation(0);
	mRotation.setRotateZ(m_rotation * (M_PI/45));

	// rotate player on local axis
	m_local_transform = mTranspose * m_local_transform * mRotation;

	// set postion information for edge detection
	Vector3 position(m_local_transform.m_column3->m_x, m_local_transform.m_column3->m_y, m_local_transform.m_column3->m_z);
	m_position = position;

	// check if player has reached the edge of the game zone
	EdgeDectection();
	
	// set current postion as last position
	m_prevPos = m_position;

}
/*****************************************************************************************************************
	Draw Player Objects 
******************************************************************************************************************/
void Player::Draw(SpriteBatch * spriteBatch)
{
	// Display Players Health
	std::string phealth = std::string("Health ") + std::to_string(m_health);
	spriteBatch->drawText(m_fontHUD, phealth.c_str(), 1100, 700);

	spriteBatch->drawSpriteTransformed3x3(m_playerSprite, (float*)m_global_transform, m_currentSize, m_currentSize);

	// draw spikes
	m_spike1->Draw(spriteBatch);
	m_spike1a->Draw(spriteBatch);
	m_spike2->Draw(spriteBatch);
	m_spike2a->Draw(spriteBatch);
	m_spike3->Draw(spriteBatch);
	m_spike3a->Draw(spriteBatch);
	m_spike4->Draw(spriteBatch);
	m_spike4a->Draw(spriteBatch);

	//*********************************************************************************************************
	// debugging
	if (m_debug)
	{
		// -- DIRECTION OF TURN
		if (m_direction == 3)
		{
			spriteBatch->drawText(m_fontDebug, "Turned Right |", 10, 20);
		}
		else if (m_direction == 4)
		{
			spriteBatch->drawText(m_fontDebug, "Turned Left  |", 10, 20);
		}
		else
		{
			spriteBatch->drawText(m_fontDebug, "Waiting...   |", 10, 20);
		}
		// -- POSITION
		std::string position = "X = " + std::to_string(m_position.m_x) + ", Y = " + std::to_string(m_position.m_y) + "  |";
		spriteBatch->drawText(m_fontDebug, position.c_str(), 200, 20);
		// -- ROTATION
		std::string rotation = "R = " + std::to_string(m_rotation);
		spriteBatch->drawText(m_fontDebug, rotation.c_str(), 600, 20);
		// -- VELOCITY
		std::string velocityY = "Vy = " + std::to_string(m_velocity.m_y);
		spriteBatch->drawText(m_fontDebug, velocityY.c_str(), 800, 20);
		std::string velocityX = "Vx = " + std::to_string(m_velocity.m_x);
		spriteBatch->drawText(m_fontDebug, velocityX.c_str(), 800, 40);

	}
	//**********************************************************************************************************/
}
/*****************************************************************************************************************
	Reset Player
******************************************************************************************************************/
void Player::Reset()
{
	// reset position and rotation
	Matrix3 plyrTrans(0);
	plyrTrans.CreateTranslation(Vector3(PLAYER_START_X, PLAYER_START_Y, 1.0f));
	m_local_transform = plyrTrans;
	m_rotation = 0.0f;

	// reset velocity
	m_velocity.m_x = 0;
	m_velocity.m_y = 0;

	// collision
	m_collided = false;
	m_collisionApplied = false;

	// reset other vars
	m_direction = 0;
	m_currentSize = m_size;
	m_health = PLAYER_HEALTH;
	m_alive = true;

}
/*****************************************************************************************************************
	Reset Velocity
******************************************************************************************************************/
void Player::ResetVelocity()
{
	m_velocity.m_x = 0;
	m_velocity.m_y = 0;
	m_velocity.m_z = 0;
}
/*****************************************************************************************************************
	Apply Collision Action(damage to inflict)
******************************************************************************************************************/
void Player::ApplyCollision(int damage)
{
	if (m_currentSize < (PLAYER_SIZE * 2) && m_currentSize > (PLAYER_SIZE / 2))
	{
		if (m_health > 0)
		{
			m_currentSize += SIZE_PENALTY;
			m_rotation += TURN_LEFT;
			m_health -= damage/10;
		}
		else
		{
			m_alive = false;
			// play plink death sequence
		}

	}
	else if (m_currentSize <= (PLAYER_SIZE / 2))
	{
		if (m_health > 0)
		{
			m_health -= damage/10;
		}
		else
		{
			m_alive = false;
			// play plink death sequence
		}
	}
	else if (m_currentSize >= (PLAYER_SIZE * 2))
	{
		m_alive = false;
		// play pop death sequence
	}
	// bounce player off object
	if (m_velocity.m_x < 0)
	{
		m_velocity.m_x *= -1;
	}
	else
	{
		m_velocity.m_x = -m_velocity.m_x;
	}
	if (m_velocity.m_y < 0)
	{
		m_velocity.m_y *= -1;
	}
	else
	{
		m_velocity.m_y = -m_velocity.m_y;
	}
	m_collisionApplied = true;
}
/*****************************************************************************************************************
	Detect if Player is Out Side of Game Area
******************************************************************************************************************/
void Player::EdgeDectection()
{
	Vector3 bump(2, 2, 0); // bump player off edge so they don't get stuck
	// right/eastern edge check
	if ((m_position.m_x + PLAYER_EDGE) >= SCREEN_W)
	{
		m_position -= bump;
		Bounce(BOUNCE);
	}
	// top/northern edge check
	else if ((m_position.m_y + PLAYER_EDGE) >= SCREEN_H)
	{
		m_position -= bump;
		Bounce(BOUNCE);
	}
	// left/western edge check
	else if ((m_position.m_x - PLAYER_EDGE) <= 0)
	{
		m_position += bump;
		Bounce(BOUNCE);
	}
	// bottom/southern edge check
	else if ((m_position.m_y - PLAYER_EDGE) <= 0)
	{
		m_position += bump;
		Bounce(BOUNCE);
	}
	// if player manages to exist game space, reset
	if (m_position.m_x > SCREEN_W || m_position.m_x < 0 || m_position.m_y > SCREEN_H || m_position.m_y < 0)
	{
		Reset();
	}
}
/*****************************************************************************************************************
	Apply Friction to Player
******************************************************************************************************************/
void Player::SlowDown(int extra)
{
	// moving east/right
	if ((m_velocity.m_x -= m_mass + extra) < 0)
	{
		m_velocity.m_x = 0;
		return;
	}
	// moving west/left
	if ((m_velocity.m_y += m_mass + extra) > 0)
	{
		m_velocity.m_x = 0;
		return;
	}
	// moving north/up
	if ((m_velocity.m_y -= m_mass + extra) < 0)
	{
		m_velocity.m_y = 0;
		return;
	}
	// moving south/down
	if ((m_velocity.m_y += m_mass + extra) > 0)
	{
		m_velocity.m_y = 0;
		return;
	}
}
/*****************************************************************************************************************
	Apply Bounce of a Boundary
******************************************************************************************************************/
void Player::Bounce(int extra)
{
	int x = 0;
	int y = 0;

	// clean up x/y values for location checks
	if (m_position.m_x > HALF_SW && m_position.m_y > HALF_SH)
	{
		x = SCREEN_W - m_position.m_x;
		y = SCREEN_H - m_position.m_y;
	}
	else if (m_position.m_x > HALF_SW && m_position.m_y <= HALF_SH)
	{
		x = SCREEN_W - m_position.m_x;
		y = m_position.m_y;
	}
	else if (m_position.m_x <= HALF_SW && m_position.m_y > HALF_SH)
	{
		x = m_position.m_x;
		y = SCREEN_H - m_position.m_y;
	}
	else
	{
		x = m_position.m_x;
		y = m_position.m_y;
	}
	// if player is closer to the side than top/bottom do these
	if (x <= y)
	{
		if (m_velocity.m_x > 0)
		{
			m_velocity.m_x = -m_velocity.m_x;
			m_velocity.m_x += -(m_mass + extra);
			return;
		}

		if (m_velocity.m_x < 0)
		{
			m_velocity.m_x *= -1;
			m_velocity.m_x += (m_mass + extra);
			return;
		}
	}
	// else do one of these
	if (y <= x)
	{
		if (m_velocity.m_y > 0 && m_velocity.m_y > m_velocity.m_x)
		{
			m_velocity.m_y = -m_velocity.m_y; 
			m_velocity.m_y += -(m_mass + extra);
			return;
		}

		if (m_velocity.m_y < 0 && m_velocity.m_y < m_velocity.m_x)
		{
			m_velocity.m_y *= -1;
			m_velocity.m_y += (m_mass + extra);
			return;
		}
	}
}


