#pragma once

#include <random>
#include <math.h>
#include <string>

#include <GLFW/glfw3.h>

#include "Application2D.h"
#include "Object.h"
#include "GameDef.h"
#include "Player.h"

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"



#define M_PI       3.14159265358979323846   // pi


Object::Object()
{
	m_objectSprite = new Texture("./bin/textures/object.png");
	m_fontDebug = new Font("./bin/font/consolas.ttf", 15);
	m_debug = false;
<<<<<<< HEAD
	m_mass = 10.0f;
	m_size = 20.0f;
	m_currentSize = m_size;
	m_alive = true;
	m_spawnNum = OBJECT_SPAWN;
	m_respawnNum = MAX_RESPAWN;
	//Reset();
}

Object::Object(float size, Vector3 & location, float mass)
=======
	m_mass = 10;
	//Reset();
}

Object::Object(int size, Vector3 & location, float mass)
>>>>>>> origin/master
{
	m_objectSprite = new Texture("./bin/textures/object.png");
	m_fontDebug = new Font("./bin/font/consolas.ttf", 15);
	m_debug = false;
	m_mass = mass;
	m_position = location;
	m_size = size;
<<<<<<< HEAD
	m_currentSize = m_size;
	m_alive = true;
	m_spawnNum = OBJECT_SPAWN;
	m_respawnNum = MAX_RESPAWN;
=======
>>>>>>> origin/master
	//Reset();
}


Object::~Object()
{
	delete m_objectSprite;
	delete m_fontDebug;
}

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

	// check Objects movement and set flags
	//DirectionCheck();

	// check if Object has reached the edge of the game zone
	//EdgeDectection();
	
	// set current postion as last position
	//m_prevPos = m_position;

<<<<<<< HEAD
	Matrix3 m(0);
	m.setRotateZ(m_rotation);// *(M_PI / 2));
	Vector3 v = m * m_velocity;
	m_position += v * dt;
=======
	//MoveObject(m_direction);
	//Matrix3 m(0);
	//m.setRotateZ(m_rotation);// *(M_PI / 2));
	//Vector3 v = m * m_velocity;
	//m_position += v * dt;

>>>>>>> origin/master
}

void Object::Draw(SpriteBatch * batch)
{
	//Matrix3 transpose(0);
	//transpose.CreateTranslation(Vector3(m_position.m_x, m_position.m_y, 0));
	//Matrix3 rotation(0);
	//rotation.setRotateZ(m_rotation);// *(M_PI / 2));
	//Matrix3 translation = transpose;
	
	//***************************************
	// rotate around 0/0 world cordinates
	//translation = rotation * transpose;
	//batch->drawSpriteTransformed3x3(m_ObjectSprite, (float*)translation, 100, 100);
	
	//*************************************** 
	//translation = transpose * rotation;
<<<<<<< HEAD
	batch->drawSpriteTransformed3x3(m_objectSprite, (float*)translation, m_currentSize, m_currentSize);

	//batch->drawSprite(m_objectSprite, m_position.m_x, m_position.m_y, m_size, m_size, 3.14159f * 0.25f);
=======
	//batch->drawSpriteTransformed3x3(m_ObjectSprite, (float*)translation, 100, 100);

	batch->drawSprite(m_objectSprite, m_position.m_x, m_position.m_y, 100, 100, 3.14159f * 0.25f);
>>>>>>> origin/master

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

void Object::SetPosition(Vector3 position)
{
	m_position = position;
}

void Object::SetVelocity(Vector3 velocity)
{
	m_velocity = velocity;
}

void Object::SetPosition(Vector3 position)
{
	m_position = position;
}

void Object::SetVelocity(Vector3 velocity)
{
	m_velocity = velocity;
}

void Object::ResetVelocity()
{
	m_velocity.m_x = 0;
	m_velocity.m_y = 0;
	m_velocity.m_z = 0;
}

<<<<<<< HEAD
void Object::DecreaseSpawns(int spawnNum)
{
	m_spawnNum -= spawnNum;
}

=======
>>>>>>> origin/master
Vector3 Object::GetPosition()
{
	return m_position;
}

<<<<<<< HEAD
const float Object::GetSize()
{
	return m_currentSize;
}

bool Object::IsAlive()
{
	return m_alive;
}

const int Object::RespawnCount()
{
	return m_respawnNum;
}

bool Object::IsColliding(std::shared_ptr<Object> object)
{
	float radSum = (m_currentSize/2) + (object->m_currentSize/2);

	Vector3 vecSum = m_position;
	vecSum -= object->GetPosition();

	float vecMag = vecSum.magnitude();

	return ((vecMag * vecMag) <= (radSum * radSum));
}

bool Object::IsColliding(Object * object)
{
	float radSum = (m_currentSize/2) + (object->m_currentSize/2);
	
	Vector3 vecSum = m_position;
	vecSum -= object->GetPosition();

	float vecMag = vecSum.magnitude();

	return ((vecMag * vecMag) <= (radSum * radSum));
}

bool Object::IsColliding(Vector3 * position)
{
	return false;
}

bool Object::IsColliding(Player * player)
{
	float radSum = (m_currentSize/2) + (player->GetSize()/2);

	Vector3 vecSum = player->GetPosition();
	vecSum -= m_position;

	float vecMag = vecSum.magnitude();

	return ((vecMag * vecMag) <= (radSum * radSum));

}

void Object::ApplyCollision(std::shared_ptr<Object> object)
{
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

void Object::ApplyCollision(Player * player)
{
	if (m_currentSize < (OBJECT_SIZE * 2) && m_currentSize > (OBJECT_SIZE / 2))
	{
		m_currentSize += SIZE_BONUS;
	}
	else if (m_currentSize >= (OBJECT_SIZE * 2))
	{
		m_alive = false;
		// play pop death sequence
	}
	player->ApplyCollision((int)m_currentSize);
=======
bool Object::IsColliding(Object * object)
{
	float radSum = m_size + object->m_size;
	
	Vector3 magSum = m_position - object->GetPosition();
	if (magSum.magnitude() < (radSum * radSum))
	{

	}
>>>>>>> origin/master
}

int Object::RandomDir()
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 8);
	int tempDir = distribution(generator);

	return tempDir;
}

void Object::DirectionCheck()
{
	// check current x position agianst previous x position and set flag
	if (m_position.m_x > m_prevPos.m_x)
	{
		m_xPlus = 1;
	}
	else if (m_position.m_x < m_prevPos.m_x)
	{
		m_xPlus = 0;
	}
	else
	{
		m_xPlus = -1;
	}
	// check current y position agianst previous y position and set flag
	if (m_position.m_y > m_prevPos.m_y)
	{
		m_yPlus = 1;
	}
	else if (m_position.m_y < m_prevPos.m_y)
	{
		m_yPlus = 0;
	}
	else
	{
		m_yPlus = -1;
	}
}

void Object::EdgeDectection()
{
	//m_rotation = 0;
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

void Object::SlowDown(int extra)
{
	if ((m_velocity.m_y -= m_mass + extra) < 0)
	{
		m_velocity.m_y = 0;
	}
}

void Object::Bounce(int extra)
{
	m_velocity.m_y += m_mass + extra;
}

