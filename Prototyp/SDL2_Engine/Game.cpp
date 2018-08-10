#pragma region project include
#include "Game.h"
#include "Engine.h"
#include "MenuScene.h"
#include "Font.h"
#pragma endregion

#pragma region public function
// initialize game
void GGame::Init()
{
	// create base arial font
	m_PArialFont = new CFont("Font/F_Arial.ttf", 50);

	// create new main scene
	CEngine::Get()->ChangeScene(new GMenuScene());
}

// clean game
void GGame::Clean()
{
	// delete arial font
	delete m_PArialFont;
}
#pragma endregion