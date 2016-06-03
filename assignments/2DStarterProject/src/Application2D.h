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
	void ProcessTheDEAD();				// checks the army of evil objects for the dead
	void SpawnObjects(std::shared_ptr<Object> object, int spawnCount);

protected:

	SpriteBatch*	m_spriteBatch;
	Font*			m_font;
<<<<<<< HEAD
		
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
=======

	Texture*		m_ptexture;
	Texture*		m_otexture;
	Texture*		m_wtexture;
	
	Player*			m_player;
	Object*			m_object;
	Wall*			m_wall;

	std::vector<std::shared_ptr<Object>>	m_objects;
>>>>>>> origin/master
	std::vector<std::shared_ptr<Wall>>	m_walls;


private:
	static Application2D* m_pInstance;
};