#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"

#include "MtxVec3.h"
#include "Player.h"


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

	m_ptexture = new Texture("./bin/textures/player.png");

	m_font = new Font("./bin/font/consolas.ttf", 32);

	m_player = new Player();

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_ptexture;
	delete m_spriteBatch;
	delete m_player;

	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	m_player->Update(deltaTime);

	// reset player if spaced pressed
	if (isKeyPressed(GLFW_KEY_SPACE))
		m_player->Reset();

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

	m_player->Draw(m_spriteBatch);




	//m_spriteBatch->drawSprite(m_texture, 200, 200, 100, 100);

	//m_spriteBatch->drawLine(300, 300, 600, 400, 10, 1);

	//m_spriteBatch->setSpriteColor(1, 0, 0, 1);
	//m_spriteBatch->drawSprite(m_texture, 400, 400, 100, 100, 3.14159f * 0.25f);

	//m_spriteBatch->setSpriteColor(0, 1, 1, 1);
	//m_spriteBatch->drawText(m_font, "OMG BBQ!", 200, 400);
	//m_spriteBatch->drawText(m_font, "Yeaaahhhhh", 200, 300);

	// done drawing sprites
	m_spriteBatch->end();	
}
