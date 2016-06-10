#pragma once
// std lib incudes
#include <random>
#include <math.h>
#include <string>
// dependecy includes
#include <GLFW/glfw3.h>
// basic code includes
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
// my code includes
#include "Application2D.h"
#include "Object.h"
#include "GameDef.h"
#include "Player.h"
#include "Collisions.h"

/*****************************************************************************************************************
	Default Object Constructor
******************************************************************************************************************/
Object::Object()
{
	m_objectSprite = new Texture("./bin/textures/object.png");
	m_fontDebug = new Font("./bin/font/consolas.ttf", 15);
	m_debug = false;
	m_mass = 10.0f;
	m_size = 20.0f;
	m_currentSize = m_size;
	m_alive = true;
	m_spawnNum = OBJECT_SPAWN;
	m_respawnNum = MAX_RESPAWN;
}
/*****************************************************************************************************************
	Object Constructor with Size, Initial Location and Mass Parameters
******************************************************************************************************************/
Object::Object(float size, Vector3 & location, float mass)
{
	m_objectSprite = new Texture("./bin/textures/object.png");
	m_fontDebug = new Font("./bin/font/consolas.ttf", 15);
	m_debug = false;
	m_mass = mass;
	m_position = location;
	m_size = size;
	m_currentSize = m_size;
	m_alive = true;
	m_spawnNum = OBJECT_SPAWN;
	m_respawnNum = MAX_RESPAWN;
}
/*****************************************************************************************************************
	Object Destructor
******************************************************************************************************************/
Object::~Object()
{
	delete m_objectSprite;
	delete m_fontDebug;
}
/*****************************************************************************************************************
	Update Object
******************************************************************************************************************/
void Object::Update(float dt)
{
	Application2D* app = Application2D::getInstance();

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

	// check if Object has reached the edge of the game zone
	//EdgeDectection();
	
	// set current postion as last position
	//m_prevPos = m_position;

	Matrix3 m(0);
	m.setRotateZ(m_rotation);// *(M_PI / 2));
	Vector3 v = m * m_velocity;
	m_position += v * dt;
}
/*****************************************************************************************************************
	Draw Objects
******************************************************************************************************************/
void Object::Draw(SpriteBatch * batch)
{
	Matrix3 transpose(0);
	transpose.CreateTranslation(Vector3(m_position.m_x, m_position.m_y, 0));
	Matrix3 rotation(0);
	rotation.setRotateZ(m_rotation);// *(M_PI / 2));
	Matrix3 translation = transpose;
	 
	//translation = transpose * rotation;
	batch->drawSpriteTransformed3x3(m_objectSprite, (float*)translation, m_currentSize, m_currentSize);

	//*********************************************************************************************************
	// debugging
	if (m_debug)
	{
		// -- POSITION
		std::string position = "X = " + std::to_string(m_position.m_x) + ", Y = " + std::to_string(m_position.m_y) + "  |";
		batch->drawText(m_fontDebug, position.c_str(), 5, 50);
		// -- ROTATION
		std::string rotation = "R = " + std::to_string(m_rotation);
		batch->drawText(m_fontDebug, rotation.c_str(), 5, 40);
		// -- VELOCITY
		std::string velocity = "V = " + std::to_string(m_velocity.m_y);
		batch->drawText(m_fontDebug, velocity.c_str(), 5, 30);
	}
	//**********************************************************************************************************/
}
/*****************************************************************************************************************
	Reset Object
******************************************************************************************************************/
void Object::Reset()
{
	m_position.m_x = HALF_SW - 20;
	m_position.m_y = HALF_SH - 20;
	m_velocity.m_x = 0;
	m_velocity.m_y = 0;
	m_rotation = 0.0;
	m_direction = 0;
	m_alive = true;
	m_spawnNum = OBJECT_SPAWN;
	m_respawnNum = MAX_RESPAWN;
}
/*****************************************************************************************************************
	Reset Velocity
******************************************************************************************************************/
void Object::ResetVelocity()
{
	m_velocity.m_x = 0;
	m_velocity.m_y = 0;
	m_velocity.m_z = 0;
}
/*****************************************************************************************************************
	Is Object Coliding With Other Objects(shared_ptr)
******************************************************************************************************************/
bool Object::IsColliding(std::shared_ptr<Object> object)
{
	// sum of both radius
	float radSum = (m_currentSize/2) + (object->m_currentSize/2);

	// vector sum of object position minus player position
	Vector3 vecSum = m_position;
	vecSum -= object->GetPosition();

	// vector magnitude of vector sum
	float vecMag = vecSum.magnitude();

	// return true if colliding and false if they aren't
	return ((vecMag * vecMag) <= (radSum * radSum));
}
/*****************************************************************************************************************
	Is Object Coliding With Other Objects(Object*)
******************************************************************************************************************/
bool Object::IsColliding(Object * object)
{
	// sum of both radius
	float radSum = (m_currentSize/2) + (object->m_currentSize/2);
	
	// vector sum of object position minus player position
	Vector3 vecSum = m_position;
	vecSum -= object->GetPosition();

	// vector magnitude of vector sum
	float vecMag = vecSum.magnitude();

	// return true if colliding and false if they aren't
	return ((vecMag * vecMag) <= (radSum * radSum));
}
/*****************************************************************************************************************
	Is Object Coliding With A  Certain Postion(Vector3*)
******************************************************************************************************************/
bool Object::IsColliding(Vector3 * position)
{
	return false;
}
/*****************************************************************************************************************
	Is Object Coliding With The Player(Player*)
******************************************************************************************************************/
bool Object::IsColliding(Player * player)
{
	// sum of both radius
	float radSum = (m_currentSize/2) + (player->GetSize()/2);
	
	// vector sum of object position minus player position
	Vector3 vecSum = player->GetPosition();
	vecSum -= m_position;

	// vector magnitude of vector sum
	float vecMag = vecSum.magnitude();

	// return true if colliding and false if they aren't
	return ((vecMag * vecMag) <= (radSum * radSum));

}
/*****************************************************************************************************************
	Apply Collision With Other Objects(shared_ptr)
******************************************************************************************************************/
void Object::ApplyCollision(std::shared_ptr<Object> object)
{
	// apply results of collision
	if (m_currentSize < (OBJECT_SIZE * 2) && m_currentSize > (OBJECT_SIZE / 2))
	{
		m_currentSize += SIZE_PENALTY;
		m_rotation += TURN_RIGHT;
	}
	else if (m_currentSize <= (OBJECT_SIZE / 2))
	{
		m_alive = false;
		// play plink death sequence
	}

}
/*****************************************************************************************************************
	Apply Collision With Player(Player*)
******************************************************************************************************************/
void Object::ApplyCollision(Player * player)
{
	// if object is the smae size or smaller than player then reduce in size
	if (m_currentSize <= player->GetSize())
	{
		m_currentSize += SIZE_PENALTY;
	}
	// else if object is bigger then it can increase in size
	else if (m_currentSize < (OBJECT_SIZE * 2) || m_currentSize > (OBJECT_SIZE / 2))
	{
		m_currentSize += SIZE_BONUS;
	}
	// else if object is bigger than double it originl size it pops, or if it is to small it dies as well
	else if (m_currentSize >= (OBJECT_SIZE * 2) || m_currentSize < (OBJECT_SIZE / 2))
	{
		m_alive = false;
		// play pop death sequence
	}
	player->ApplyCollision((int)m_currentSize);
	// apply collsion response
	//Vector3 normal(((m_position.m_x + m_currentSize / 2) - (m_position.m_x - m_currentSize / 2)),
	//			   ((m_position.m_x + m_currentSize / 2) - (m_position.m_x - m_currentSize / 2)),
	//				1.0f);
	////Vector3 normal = m_position;
	////normal.normalise();
	//Vector3 reflection = GetReflection(player->Velocity(), normal);
	//m_position = reflection;
}
/*****************************************************************************************************************
	Detect if Object is Out Side of Game Area
******************************************************************************************************************/
void Object::EdgeDectection()
{
	Vector3 bump(2, 2, 0); // bump Object off edge so they don't get stuck
	// right/eastern edge check
	if ((m_position.m_x + PLAYER_EDGE) >= SCREEN_W)
	{
		if (m_xPlus == 1 && m_yPlus == 1)
		{
			m_rotation += TURN_LEFT * 2;// *(float)M_PI;
			m_direction = 4;
		}
		else if (m_xPlus == 1 && m_yPlus == 0)
		{
			m_rotation += TURN_RIGHT * 2;
			m_direction = 3;
		}
 		else
		{
			m_rotation += TURN_RIGHT;
			m_direction = 3;	
		}
		m_position -= bump;
		Bounce(BOUNCE);
	}
	// top/northern edge check
	else if ((m_position.m_y + PLAYER_EDGE) >= SCREEN_H)
	{
		if (m_xPlus == 1 && m_yPlus == 1)
		{
			m_rotation += TURN_RIGHT * 2;// *(float)M_PI;
			m_direction = 3;
		}
		else if (m_xPlus == 0 && m_yPlus == 1)
		{
			m_rotation += TURN_LEFT * 2;
			m_direction = 4;
		}
		else
		{
			m_rotation += TURN_LEFT;
			m_direction = 4;
			
		}
		m_position -= bump;
		Bounce(BOUNCE);
	}
	// left/western edge check
	else if ((m_position.m_x - PLAYER_EDGE) <= 0)
	{
		if (m_xPlus == 0 && m_yPlus == 0)
		{
			m_rotation += TURN_LEFT * 2;// *(float)M_PI;
			m_direction = 4;
		}
		else if (m_xPlus == 0 && m_yPlus == 1)
		{
			m_rotation += TURN_RIGHT * 2;
			m_direction = 3;
		}
		else
		{
			m_rotation += TURN_RIGHT;
			m_direction = 3;
		}
		m_position += bump;
		Bounce(BOUNCE);
	}
	// bottom/southern edge check
	else if ((m_position.m_y - PLAYER_EDGE) <= 0)
	{
		if (m_xPlus == 0 && m_yPlus == 0)
		{
			m_rotation += TURN_RIGHT * 2;// *(float)M_PI;
			m_direction = 3;
		}
		else if (m_xPlus == 1 && m_yPlus == 0)
		{
			m_rotation += TURN_LEFT * 2;
			m_direction = 4;
		}
		else
		{
			m_rotation += TURN_LEFT;
			m_direction = 4;
		}
		m_position += bump;
		Bounce(BOUNCE);
	}

	if (m_position.m_x > SCREEN_W || m_position.m_x < 0 || m_position.m_y > SCREEN_H || m_position.m_y < 0)
	{
		Reset();
	}
}
/*****************************************************************************************************************
	Apply Friction to Object
******************************************************************************************************************/
void Object::SlowDown(int extra)
{
	if ((m_velocity.m_y -= m_mass + extra) < 0)
	{
		m_velocity.m_y = 0;
	}
}
/*****************************************************************************************************************
	Apply Bounce of an Object
******************************************************************************************************************/
void Object::Bounce(int extra)
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

