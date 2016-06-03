#include "Application2D.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> origin/master
#include <vector>
#include <memory>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

// my header files
#include "MtxVec3.h"
#include "Player.h"
#include "Object.h"
#include "Wall.h"


Application2D* Application2D::m_pInstance = nullptr;

Application2D* Application2D::getInstance()
{
	return m_pInstance;
}

Application2D::Application2D() 
{
	if (m_pInstance == nullptr)
		m_pInstance = this;
}

Application2D::~Application2D() 
{	

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", 1280, 720);

	m_spriteBatch = new SpriteBatch();

	m_font = new Font("./bin/font/consolas.ttf", 32);

	// textures
	//m_ptexture = new Texture("./bin/textures/player.png");
	//m_otexture = new Texture("./bin/textures/player.png");
	//m_wtexture = new Texture("./bin/textures/object.png");

	// world objects
<<<<<<< HEAD
	m_player = new Player(PLAYER_SIZE, 20.0f);
	//m_object = new Object();
	//m_object->SetPosition(Vector3(40, 40, 0));

	// create the nasty objects
	CreateObjects();
=======
	m_player = new Player();
	//m_object = new Object();
	//m_object->SetPosition(Vector3(40, 40, 0));

	for (int i = 0; i < OBJECT_COUNT; i++)
	{
		m_objects.push_back(std::make_shared<Object>(10, Vector3(1, 0, 0)));
		m_objects[i]->SetPosition(Vector3((float)(rand() % SCREEN_W),
										  (float)(rand() % SCREEN_H),
										  1.0f));
	}
>>>>>>> origin/master

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_spriteBatch;

	// player deletes
	//delete m_ptexture;
	delete m_player;
	// object deletes
	//delete m_otexture;
	delete m_object;

	// wall deletes
	//delete m_wtexture;
	//delete m_wall;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	// reset player if spaced pressed
	if (isKeyPressed(GLFW_KEY_SPACE))
	{
<<<<<<< HEAD
		m_player->Reset();
		CreateObjects();
	}

	// dead checks
	//------------------------------------------------------------
	// check if player is alive
	if (!m_player->IsAlive())
	{
		m_player->Reset();
		CreateObjects();
	}
	// trawl through the evils objects for the dead and respawn their children
	ProcessTheDEAD();

	// check for collisions
	// ----------------------------------------------------------------------
	for (int i = 0; i < m_objNum; ++i)
	{
		if (m_objects[i]->IsColliding(m_player))
		{
			m_objects[i]->ApplyCollision(m_player);
			std::cout << "player colliding" << std::endl;
		}
		for (int j = i + 1; j < m_objNum; ++j)
		{
			if (m_objects[i]->IsColliding(m_objects[j]))
			{
				m_objects[i]->ApplyCollision(m_objects[j]);
				std::cout << "objects colliding" << std::endl;
=======
		m_player->Reset();
		for (int i = 0; i < OBJECT_COUNT; ++i)
		{
			m_objects[i]->SetPosition(Vector3((float)(rand() % SCREEN_W), 
											 (float)(rand() % SCREEN_H), 
											 1.0f));
			//m_objects[i].SetVelocity(Vector3(rand() % 1000 - 500.f, rand() % 1000 - 500.f, 0));
		}
	}

	// check for collisions
	for (int i = 0; i < OBJECT_COUNT; ++i)
	{
		for (int j = i + 1; j < OBJECT_COUNT; ++j)
		{
			if (m_objects[i].IsColliding(&m_objects[j]))
			{
				m_objects[i].ApplyCollision(&m_objects[j]);
>>>>>>> origin/master
			}
		}
	}

	// update player
	m_player->Update(deltaTime);
	//m_object->Update(deltaTime);

	// update objects
<<<<<<< HEAD
	for (int i = 0; i < m_objNum; ++i)
=======
	for (int i = 0; i < OBJECT_COUNT; ++i)
>>>>>>> origin/master
	{
		m_objects[i]->Update(deltaTime);
	}

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {
	
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	// some game checks here
	//*******************************
	// is game paused?
	// is player dead?
	// is game finished?

	// draw player
	m_player->Draw(m_spriteBatch);

	// draw objects
<<<<<<< HEAD
	for (int i = 0; i < m_objNum; ++i)
=======
	for (int i = 0; i < OBJECT_COUNT; ++i)
>>>>>>> origin/master
	{
		m_objects[i]->Draw(m_spriteBatch);
	}



	//m_spriteBatch->drawSprite(m_texture, 200, 200, 100, 100);

	//m_spriteBatch->drawLine(300, 300, 600, 400, 10, 1);

	//m_spriteBatch->setSpriteColor(1, 0, 0, 1);
	//m_spriteBatch->drawSprite(m_wtexture, 400, 400, 100, 100, 3.14159f * 0.25f);

	//m_spriteBatch->setSpriteColor(0, 1, 1, 1);
	//m_spriteBatch->drawText(m_font, "OMG BBQ!", 200, 400);
	//m_spriteBatch->drawText(m_font, "Yeaaahhhhh", 200, 300);

	// done drawing sprites
	m_spriteBatch->end();	
}

void Application2D::CreateObjects()
{
	// Set number of objects
	m_objNum = OBJECT_COUNT;

	for (int i = 0; i < m_objNum; i++)
	{
		// push new object on to the vector, with a random location on the screen
		m_objects.push_back(std::make_shared<Object>(OBJECT_SIZE, Vector3((float)(rand() % SCREEN_W), (float)(rand() % SCREEN_H), 1.0f), 20.0f));
	}

}

void Application2D::ProcessTheDEAD()
{
	bool foundDead = true;

	while (foundDead)
	{	
		// check if objects are alive, if not remove them
		for (int i = 0; i < m_objects.size(); i++)
		{
			if (!m_objects[i]->IsAlive())
			{
				// spawn evil twins
				SpawnObjects(m_objects[i], m_objects[i]->RespawnCount());
				m_objects.erase(m_objects.begin() + i);
				m_objNum--;
				foundDead = true;
				break;
			}
			else
			{
				foundDead = false;
			}
		}

	}

	for (int i = 0; i < m_tempObjs.size(); i++)
	{
		// decrease spwan reproductability
		m_tempObjs[i]->DecreaseSpawns();
		m_objects.push_back(m_tempObjs[i]);
		// increase total known number of objects
		m_objNum++;
	}
	// empty the nursery
	m_tempObjs.clear();
}

void Application2D::SpawnObjects(std::shared_ptr<Object> object, int spawnCount)
{
	// get the current size of the dieing object and increase it for the spawn
	float size = (object->GetSize() + 5);
	
	if ( spawnCount > 0)
	{
		for (int i = 0; i < spawnCount; i++)
		{
			// push new spawn to the nursery vector, with a random location close to where their parent was
			m_tempObjs.push_back(std::make_shared<Object>(size, Vector3((float)(rand() % (int)object->GetPosition().m_x),
																		(float)(rand() % (int)object->GetPosition().m_y),
																		1.0f)
																		, 20.0f));
		}
	}

}
