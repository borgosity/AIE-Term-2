#include "Application2D.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <ctime>
#include "XPathParser.h"

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

// my header files
#include "MtxVec3.h"
#include "Player.h"
#include "Scene.h"
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
	m_player = new Player(PLAYER_SIZE, 20.0f);
	m_player->SetNodeName("m_player");
	m_scene = new Scene();
	m_scene->SetRoot(m_player);
	m_font = new Font("./bin/font/consolas.ttf", 32);
	m_playing = false;
	m_savedGame = false;
	m_gameLoaded = false;

	// create the nasty objects
	//CreateObjects();

	return true;
}

void Application2D::shutdown() {

	DestroyObjects();
	delete m_font;
	delete m_scene;
	delete m_player;
	delete m_spriteBatch;
	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;
	
	// pause game
	if (isKeyPressed(GLFW_KEY_P) && m_playing)
	{
		std::cout << "Pause Game" << std::endl;
		m_pause = true;

	}

	if (m_pause) {
		if (IsKeyDown(GLFW_KEY_ENTER))
		{
			m_pause = false;
			m_playing = true;
			m_savedGame = false;
			m_gameLoaded = false;
		}

		// load saved game
		if (isKeyPressed(GLFW_KEY_L) && !m_playing)
		{
			std::cout << "Load Game" << std::endl;
			LoadGame();
			std::cout << "Game Loaded" << std::endl;
			m_gameLoaded = true;
			m_pause = true;
		}

		// save game state
		if (isKeyPressed(GLFW_KEY_S) && m_playing)
		{
			std::cout << "Save Game" << std::endl;
			SaveGame();
			std::cout << "Game Saved" << std::endl;
			m_savedGame = true;
			m_pause = true;
		}

		// reset player if spaced pressed
		if (isKeyPressed(GLFW_KEY_SPACE))
		{
			m_player->Reset();
			m_pause = false;
			//CreateObjects();
		}

		return true;
	}

	// reset player if spaced pressed
	if (isKeyPressed(GLFW_KEY_SPACE))
	{
		m_player->Reset();
		m_pause = false;
		//CreateObjects();
	}

	// dead checks
	//------------------------------------------------------------
	// check if player is alive
	if (!m_player->IsAlive())
	{
		m_player->Reset();
		//CreateObjects();
	}
	// trawl through the evils objects for the dead and respawn their children
	//ProcessTheDEAD();

	// check for collisions
	// ----------------------------------------------------------------------
	//for (int i = 0; i < m_objNum; ++i)
	//{
	//	if (m_objects[i]->IsColliding(m_player))
	//	{
	//		m_objects[i]->ApplyCollision(m_player);
	//		std::cout << "player colliding" << std::endl;
	//	}
	//	for (int j = i + 1; j < m_objNum; ++j)
	//	{
	//		if (m_objects[i]->IsColliding(m_objects[j]))
	//		{
	//			m_objects[i]->ApplyCollision(m_objects[j]);
	//			std::cout << "objects colliding" << std::endl;
	//		}
	//	}
	//}

	// update player
	m_scene->UpdateTransforms();
	m_player->Update(deltaTime);

	// update objects
	//for (int i = 0; i < m_objNum; ++i)
	//{
	//	m_objects[i]->Update(deltaTime);
	//}

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {
	
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	if (m_pause && !m_playing && !m_gameLoaded)
	{
		m_spriteBatch->drawText(m_font, "Press Enter to Start New Game", (float)HALF_SW - 250, (float)HALF_SH + 28.0f);
		m_spriteBatch->drawText(m_font, "Press L to Load Last Saved Game", (float)HALF_SW - 250, (float)HALF_SH);
		m_spriteBatch->drawText(m_font, "Press P to Pause in Game", (float)HALF_SW - 250, (float)HALF_SH - 28.0f);
		m_spriteBatch->drawText(m_font, "Press ESC to Quit", (float)HALF_SW - 250, (float)HALF_SH - 56.0f);
	}
	else if (m_pause && m_playing && !m_savedGame)
	{
		m_spriteBatch->drawText(m_font, "Press Space to Reset Game", (float)HALF_SW - 250, (float)HALF_SH + 28.0f);
		m_spriteBatch->drawText(m_font, "Press S to Save Game", (float)HALF_SW - 250, (float)HALF_SH);
		m_spriteBatch->drawText(m_font, "Press Enter to Resume", (float)HALF_SW - 250, (float)HALF_SH - 28.0f);
	}
	else if (m_pause && m_savedGame && m_playing)
	{
		m_spriteBatch->drawText(m_font, "Game Saved Successfully!", (float)HALF_SW - 250, (float)HALF_SH + 28.0f);
		m_spriteBatch->drawText(m_font, "Press Enter to Resume", (float)HALF_SW - 250, (float)HALF_SH - 28.0f);
		m_spriteBatch->drawText(m_font, "Press ESC to Quit", (float)HALF_SW - 250, (float)HALF_SH - 56.0f);
	}
	else if (m_pause && m_gameLoaded && !m_playing)
	{
		m_spriteBatch->drawText(m_font, "Game Loaded Successfully!", (float)HALF_SW - 250, (float)HALF_SH + 28.0f);
		m_spriteBatch->drawText(m_font, "Press Enter to Play...", (float)HALF_SW - 250, (float)HALF_SH - 28.0f);
	}
	else
	{
		if (!m_player->IsAlive())
		{
			m_spriteBatch->drawText(m_font, "GAME OVER...!", (float)HALF_SW - 150, (float)HALF_SH);
		}
		else if (m_player->Score() == 100)
		{
			m_spriteBatch->drawText(m_font, "WINNER...!", (float)HALF_SW - 150, (float)HALF_SH);
		}
		// draw player
		m_player->Draw(m_spriteBatch);

		// draw objects
		//for (int i = 0; i < m_objNum; ++i)
		//{
		//	m_objects[i]->Draw(m_spriteBatch);
		//}
	}
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

void Application2D::DestroyObjects()
{
	// objects destroyed auto magically by shared_ptr
}

void Application2D::ProcessTheDEAD()
{
	bool foundDead = true;

	while (foundDead)
	{	
		// check if objects are alive, if not remove them
		for (size_t i = 0; i < m_objects.size(); i++)
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

	for (size_t i = 0; i < m_tempObjs.size(); i++)
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

void Application2D::SaveGame()
{
	std::string savePath = "saves/game_save.xml";
	
	// clear game save
	std::ofstream clearfile;
	clearfile.open(savePath, std::ofstream::out | std::ofstream::trunc);
	clearfile.close();
	// save new game
	std::ofstream output(savePath, std::ofstream::app);
	if (output.is_open())
	{
		output << m_scene->GetRoot()->SaveState().c_str();
	}
	output.close();
}

void Application2D::LoadGame()
{
	float c1x = 0.0f, float c1y = 0.0f, float c1z = 0.0f;
	float c2x = 0.0f, float c2y = 0.0f, float c2z = 0.0f;
	float c3x = 0.0f, float c3y = 0.0f, float c3z = 0.0f;

	m_scene->GetRoot()->SetLocalTransform(c1x, c1y, c1z, c2x, c2y, c2z, c3x, c3y, c3z);

	c1x = 0.0f, c1y = 0.0f, c1z = 0.0f;
	c2x = 0.0f, c2y = 0.0f, c2z = 0.0f;
	c3x = 0.0f, c3y = 0.0f, c3z = 0.0f;

	m_scene->GetRoot()->SetLocalTransform(c1x, c1y, c1z, c2x, c2y, c2z, c3x, c3y, c3z);
}
