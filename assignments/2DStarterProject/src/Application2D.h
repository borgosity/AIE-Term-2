#pragma once
#include <vector>
#include <memory>

#include "BaseApplication.h"
#include "GameDef.h"

class SpriteBatch;
class Texture;
class Font;
class Player;
class Wall;
class Object;
class Scene;

class Application2D : public BaseApplication {
public:
	static Application2D* getInstance();

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

	bool IsKeyDown(int key) { return BaseApplication::isKeyPressed(key); }

	// evil object functions
	void CreateObjects();			// creates the evil objects
	void DestroyObjects();			// deletes the evil objects
	void ProcessTheDEAD();				// checks the army of evil objects for the dead
	void SpawnObjects(std::shared_ptr<Object> object, int spawnCount);

	// save game
	void SaveGame();
	void LoadGame();

protected:

	SpriteBatch*	m_spriteBatch;
	Font*			m_font;
	Scene*			m_scene;
		
	// player memeber variables
	Player*			m_player;
	Texture*		m_ptexture;
	
	// evil objects members variables
	Object*			m_object;
	Texture*		m_otexture;
	int				m_objNum;
	std::vector<std::shared_ptr<Object>>	m_objects;  // vector of Object shared pointers
	std::vector<int> m_theDead;							// vector of positions of the dead in the Object vector
	std::vector<std::shared_ptr<Object>>	m_tempObjs; // vector to hold the new spawns, whilst the dead are cleaned up
	
	// wall realted member variables
	Wall*			m_wall;
	Texture*		m_wtexture;
	std::vector<std::shared_ptr<Wall>>	m_walls;

	// gaem variables
	bool m_pause;
	bool m_save;
	bool m_newGame;
	bool m_savedGame;
	bool m_gameLoaded;
	bool m_playing;


private:
	static Application2D* m_pInstance;
};