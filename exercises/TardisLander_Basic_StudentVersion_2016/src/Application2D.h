#pragma once

#include "BaseApplication.h"

class SpriteBatch;
class Texture;
class Font;
class Player;

class Application2D : public BaseApplication {
private:
	static Application2D* m_pInstance;

public:
	static Application2D* getInstance();

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual bool update(float deltaTime);
	virtual void draw();

	bool IsKeyDown(int key) {return BaseApplication::isKeyPressed(key);}

protected:

	SpriteBatch*	m_spriteBatch;
	Font*			m_font;
	
	Player* m_pPlayer;

	bool m_bPause;
};