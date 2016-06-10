// std library includes
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <ctime>
// dependency includes
#include <GLFW/glfw3.h>
#include "yaml-cpp\yaml.h"
// basic code includes
#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
// my code inlcudes
#include "Application2D.h"
#include "MtxVec3.h"
#include "Player.h"
#include "Scene.h"
#include "Object.h"
#include "Wall.h"


/*****************************************************************************************************************
	Returns an instance of the current game for objects to work with
******************************************************************************************************************/
Application2D* Application2D::m_pInstance = nullptr;

Application2D* Application2D::getInstance()
{
	return m_pInstance;
}
/*****************************************************************************************************************
    Default Constructor
******************************************************************************************************************/
Application2D::Application2D() 
{
	if (m_pInstance == nullptr)
		m_pInstance = this;
}
/*****************************************************************************************************************
   Destructor
******************************************************************************************************************/
Application2D::~Application2D() 
{	
	// nothing to destroy
}
/*****************************************************************************************************************
	Startup - sets up initial Game state
******************************************************************************************************************/
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
	CreateObjects();

	return true;
}
/*****************************************************************************************************************
	Shutdown detructs game objects
******************************************************************************************************************/
void Application2D::shutdown() {

	DestroyObjects();
	delete m_font;
	delete m_scene;
	delete m_player;
	delete m_spriteBatch;
	destroyWindow();
}
/*****************************************************************************************************************
	Update - updates game objects between frames
******************************************************************************************************************/
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
	// possible keypress actions whilst game is paused
	if (m_pause) {
		// enter keypress, resumes and starts
		//---------------------------------------------------
		if (IsKeyDown(GLFW_KEY_ENTER))
		{
			m_pause = false;
			m_playing = true;
			m_savedGame = false;
			m_gameLoaded = false;
		}
		// load saved game
		//---------------------------------------------------
		if (isKeyPressed(GLFW_KEY_L))
		{
			std::cout << "Load Game" << std::endl;
			LoadGame();
			std::cout << "Game Loaded" << std::endl;
			m_gameLoaded = true;
			m_pause = true;
		}
		// save game state
		//---------------------------------------------------
		if (isKeyPressed(GLFW_KEY_S) && m_playing)
		{
			std::cout << "Save Game" << std::endl;
			SaveGame();
			std::cout << "Game Saved" << std::endl;
			m_savedGame = true;
			m_pause = true;
		}
		// reset player if spaced pressed
		//---------------------------------------------------
		if (isKeyPressed(GLFW_KEY_SPACE))
		{
			m_player->Reset();
			m_pause = false;
			CreateObjects();
		}

		return true;
	}

	// reset player if spaced pressed
	if (isKeyPressed(GLFW_KEY_SPACE))
	{
		m_player->Reset();
		m_pause = false;
		DestroyObjects();
		CreateObjects();
		return true;
	}

	// dead checks
	//------------------------------------------------------------
	// check if player is alive
	if (!m_player->IsAlive())
	{
		m_player->Reset();
		DestroyObjects();
		CreateObjects();
		return true;
	}
	// trawl through the evils objects for the dead and respawn their children
	ProcessTheDEAD();

	// check for collisions
	// ----------------------------------------------------------------------
	for (int i = 0; i < m_objNum; ++i)
	{
		bool colliding = m_objects[i]->IsColliding(m_player);
		bool collided = m_player->Collided();
		bool collisionApplied = m_player->CollisionApplied();
		
		// check if objects are colliding with the player
		if (colliding && !collided && !collisionApplied)
		{
			m_player->Collided(true);
			std::cout << "player colliding" << std::endl;
		}
		else if (!colliding && collided && !collisionApplied)
		{
			m_objects[i]->ApplyCollision(m_player);
			std::cout << "appply collision to player" << std::endl;
			m_player->Collided(false);
		}
		else if (!colliding && !collided && collisionApplied)
		{
			m_player->CollisionApplied(false);
		}

		// chekc if objects are colliding with other objects
		for (int j = i + 1; j < m_objNum; ++j)
		{
			if (m_objects[i]->IsColliding(m_objects[j]))
			{
				m_objects[i]->ApplyCollision(m_objects[j]);
				std::cout << "objects colliding" << std::endl;
			}
		}
	}

	// update player
	m_scene->UpdateTransforms();
	m_player->Update(deltaTime);

	// update objects
	for (int i = 0; i < m_objNum; ++i)
	{
		m_objects[i]->Update(deltaTime);
	}

	// the applciation closes if we return false
	return true;
}
/*****************************************************************************************************************
	Draw game objects 
******************************************************************************************************************/
void Application2D::draw() {
	
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();

	// paused game screens
	//-------------------------------------------------------------------------------------------------------------------
	// Initial startup screen
	if (m_pause && !m_playing && !m_gameLoaded)
	{
		m_spriteBatch->drawText(m_font, "Press Enter to Start New Game", (float)HALF_SW - 250, (float)HALF_SH + 28.0f);
		m_spriteBatch->drawText(m_font, "Press L to Load Last Saved Game", (float)HALF_SW - 250, (float)HALF_SH);
		m_spriteBatch->drawText(m_font, "Press P to Pause in Game", (float)HALF_SW - 250, (float)HALF_SH - 28.0f);
		m_spriteBatch->drawText(m_font, "Press ESC to Quit", (float)HALF_SW - 250, (float)HALF_SH - 56.0f);
	}
	//-------------------------------------------------------------------------------------------------------------------
	// In game - paused screen
	else if (m_pause && m_playing && !m_savedGame && !m_gameLoaded)
	{
		m_spriteBatch->drawText(m_font, "Press Space to Reset Game", (float)HALF_SW - 250, (float)HALF_SH + 28.0f);
		m_spriteBatch->drawText(m_font, "Press L to Load Last Saved Game", (float)HALF_SW - 250, (float)HALF_SH);
		m_spriteBatch->drawText(m_font, "Press S to Save Game", (float)HALF_SW - 250, (float)HALF_SH - 28.0f);
		m_spriteBatch->drawText(m_font, "Press Enter to Resume", (float)HALF_SW - 250, (float)HALF_SH - 56.0f);
	}
	//-------------------------------------------------------------------------------------------------------------------
	// In game - game saved confirmation
	else if (m_pause && m_savedGame && m_playing)
	{
		m_spriteBatch->drawText(m_font, "Game Saved Successfully!", (float)HALF_SW - 250, (float)HALF_SH + 28.0f);
		m_spriteBatch->drawText(m_font, "Press Enter to Resume", (float)HALF_SW - 250, (float)HALF_SH - 28.0f);
		m_spriteBatch->drawText(m_font, "Press ESC to Quit", (float)HALF_SW - 250, (float)HALF_SH - 56.0f);
	}
	//-------------------------------------------------------------------------------------------------------------------
	// In game - game loaded confirmation
	else if (m_pause && m_gameLoaded)
	{
		m_spriteBatch->drawText(m_font, "Game Loaded Successfully!", (float)HALF_SW - 250, (float)HALF_SH + 28.0f);
		m_spriteBatch->drawText(m_font, "Press Enter to Play...", (float)HALF_SW - 250, (float)HALF_SH - 28.0f);
	}
	//-------------------------------------------------------------------------------------------------------------------
	// non paused game states
	else
	{
		// if player is dead
		if (!m_player->IsAlive())
		{
			m_spriteBatch->drawText(m_font, "GAME OVER...!", (float)HALF_SW - 150, (float)HALF_SH);
		}
		// if player score has reached 100
		else if (m_player->Score() == 100)
		{
			m_spriteBatch->drawText(m_font, "WINNER...!", (float)HALF_SW - 150, (float)HALF_SH);
		}
		// draw player
		m_player->Draw(m_spriteBatch);

		// draw objects
		for (int i = 0; i < m_objNum; ++i)
		{
			m_objects[i]->Draw(m_spriteBatch);
		}
	}
	// done drawing sprites
	m_spriteBatch->end();	
}
/*****************************************************************************************************************

******************************************************************************************************************/
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
/*****************************************************************************************************************
	Destroy Objects
******************************************************************************************************************/
void Application2D::DestroyObjects()
{
	m_objects.clear();
}
/*****************************************************************************************************************
	Trawls through the objects looking for the dead and spwans their children
******************************************************************************************************************/
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
	// go through the list of the deads spwans and reduce the number they can spawn
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
/*****************************************************************************************************************
	Spawn the children of the object that just died
******************************************************************************************************************/
void Application2D::SpawnObjects(std::shared_ptr<Object> object, int spawnCount)
{
	// get the current size of the dieing object and increase it for the spawn
	float size = (object->GetSize() + 5);
	
	if (m_objects.size() < OBJECT_MAX_COUNT)
	{
		if ( spawnCount > 0)
		{
			for (int i = 0; i < spawnCount; i++)
			{
				// push new spawn to the nursery vector, with a random location close to where their parent was
				m_tempObjs.push_back(std::make_shared<Object>(size, Vector3((float)(rand() % ((int)object->GetPosition().m_x + 1)),
																			(float)(rand() % ((int)object->GetPosition().m_y + 1)),
																			1.0f)
																			, 20.0f));
			}
		}
	}
	else
	{
		// reached max objects
	}

}
/*****************************************************************************************************************
	Save Players Current State, clears last save
******************************************************************************************************************/
void Application2D::SaveGame()
{
	// clear game save
	std::ofstream clearfile;
	clearfile.open(SAVE_PATH, std::ofstream::out | std::ofstream::trunc);
	clearfile.close();

	// save new game
	std::ofstream output(SAVE_PATH, std::ofstream::app);
	// open save file
	if (output.is_open())
	{
		// save root node state
		output << m_scene->GetRoot()->SaveStateYAML();
		// check if root node has children
		if (!m_scene->GetRoot()->GetChildren().empty())
		{
			// iterate thorugh child node list and save state
			for (std::list<SceneNode*>::const_iterator i = m_scene->GetRoot()->GetChildren().begin(), 
													   i_end = m_scene->GetRoot()->GetChildren().end(); 
													   i != i_end; i++)
			{
				output << (*i)->SaveStateYAML();
			}
		}
	}
	output.close();
}
/*****************************************************************************************************************
	Load Players Last Saved Game
******************************************************************************************************************/
void Application2D::LoadGame()
{
	// set up root node transform names
	std::string LT = m_scene->GetRoot()->GetNodeName() + std::string("LT");
	std::string GT = m_scene->GetRoot()->GetNodeName() + std::string("GT");
	
	// set yaml node file location
	YAML::Node gameSave = YAML::LoadFile(SAVE_PATH);

	// load root node local transform
	m_scene->GetRoot()->SetLocalTransform(gameSave[LT][0].as<float>(),
										  gameSave[LT][1].as<float>(),
										  gameSave[LT][2].as<float>(),
										  gameSave[LT][3].as<float>(),
										  gameSave[LT][4].as<float>(),
										  gameSave[LT][5].as<float>(),
										  gameSave[LT][6].as<float>(),
										  gameSave[LT][7].as<float>(),
										  gameSave[LT][8].as<float>());
	// load root node global transform
	m_scene->GetRoot()->SetGlobalTransform(gameSave[GT][0].as<float>(),
										   gameSave[GT][1].as<float>(),
										   gameSave[GT][2].as<float>(),
										   gameSave[GT][3].as<float>(),
										   gameSave[GT][4].as<float>(),
										   gameSave[GT][5].as<float>(),
										   gameSave[GT][6].as<float>(),
										   gameSave[GT][7].as<float>(),
										   gameSave[GT][8].as<float>());

	// check if root node has children
	if (!m_scene->GetRoot()->GetChildren().empty())
	{
		// iterate through child snene nodes and update transforms
		for (std::list<SceneNode*>::const_iterator i = m_scene->GetRoot()->GetChildren().begin(),
			i_end = m_scene->GetRoot()->GetChildren().end();
			i != i_end; i++)
		{
			std::string CLT = (*i)->GetNodeName() + std::string("LT");
			std::string CGT = (*i)->GetNodeName() + std::string("GT");

			// set child local transform
			(*i)->SetLocalTransform(gameSave[CLT][0].as<float>(),
									gameSave[CLT][1].as<float>(),
									gameSave[CLT][2].as<float>(),
									gameSave[CLT][3].as<float>(),
									gameSave[CLT][4].as<float>(),
									gameSave[CLT][5].as<float>(),
									gameSave[CLT][6].as<float>(),
									gameSave[CLT][7].as<float>(),
									gameSave[CLT][8].as<float>());
			// set child global transform
			(*i)->SetGlobalTransform(gameSave[CGT][0].as<float>(),
									 gameSave[CGT][1].as<float>(),
									 gameSave[CGT][2].as<float>(),
									 gameSave[CGT][3].as<float>(),
									 gameSave[CGT][4].as<float>(),
									 gameSave[CGT][5].as<float>(),
									 gameSave[CGT][6].as<float>(),
									 gameSave[CGT][7].as<float>(),
									 gameSave[CGT][8].as<float>());
		}
	}
}
