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

protected:

	SpriteBatch*	m_spriteBatch;
	Font*			m_font;

	Texture*		m_ptexture;
	Texture*		m_otexture;
	Texture*		m_wtexture;
	
	Player*			m_player;
	Object*			m_object;
	Wall*			m_wall;

	std::vector<std::shared_ptr<Object>>	m_objects;
	std::vector<std::shared_ptr<Wall>>	m_walls;


private:
	static Application2D* m_pInstance;
};