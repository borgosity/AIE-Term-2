#include "Application2D.h"
#include <GLFW/glfw3.h>

#include "SpriteBatch.h"
#include "Texture.h"
#include "Font.h"
#include "Player.h"
#include "GameDefs.h"

Application2D* Application2D::m_pInstance = nullptr;

Application2D* Application2D::getInstance()
{
	return m_pInstance;
}

Application2D::Application2D() {
	if (m_pInstance == nullptr)
		m_pInstance = this;
}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	createWindow("A.I. Project", SCREEN_WIDTH, SCREEN_HEIGHT);

	m_spriteBatch = new SpriteBatch();
	
	m_font = new Font("./bin/font/consolas.ttf", 32);

	m_pPlayer = new Player();

	m_bPause = true;

	return true;
}

void Application2D::shutdown() {

	delete m_font;
	delete m_spriteBatch;
	delete m_pPlayer;
	destroyWindow();
}

bool Application2D::update(float deltaTime) {
	
	// close the application if the window closes or we press escape
	if (hasWindowClosed() || isKeyPressed(GLFW_KEY_ESCAPE))
		return false;

	// pause only used at start of the game, can't be toggled during game
	if (m_bPause) {
		if (IsKeyDown(GLFW_KEY_ENTER))
			m_bPause = false;
		return true;
	}

	if (m_pPlayer->IsDead() == false && m_pPlayer->HasLanded() == false) {
		m_pPlayer->Update(deltaTime);
	}

	if (IsKeyDown(GLFW_KEY_SPACE))
		m_pPlayer->Reset();

	// the applciation closes if we return false
	return true;
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_spriteBatch->begin();
	
	if (m_bPause) {
		m_spriteBatch->drawText(m_font, "Press Enter to Start", HALF_SCRW - 200, HALF_SCRH);
	}
	else
	{
		if (m_pPlayer->IsDead()) {
			m_spriteBatch->drawText(m_font, "Game Over... You Suck", HALF_SCRW - 200, HALF_SCRH);
		}
		else if (m_pPlayer->HasLanded()) {
			m_spriteBatch->drawText(m_font, "Winner!!!!!1", HALF_SCRW - 200, HALF_SCRH);
		}

		m_pPlayer->Draw(m_spriteBatch);

		m_spriteBatch->drawLine(0, GROUND_Y, SCREEN_WIDTH, GROUND_Y);
	}

	// done drawing sprites
	m_spriteBatch->end();	
}