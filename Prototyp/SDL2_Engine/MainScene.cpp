// Changes by Tobias Stroedicke
#pragma region project include
#include "MainScene.h"
#include "World.h"
#include "ContentManagement.h"
#include "Helper.h"
#include "Music.h"
#include "Game.h"
#include "TextFPS.h"
#include "TextScore.h"
#include "TextHighScore.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMainScene::Init()
{
	// create world
	m_pWorld = new GWorld();
	m_pWorld->Init();

	// create score text
	GTextScore* pScore = new GTextScore("Score: 0", GGame::Get()->m_PArialFont, SRect(SCREEN_WIDTH / 2 - 100, 100, 200, 50));

	// add score text to ui list
	CEngine::Get()->GetCM()->AddUIObject(pScore);

#pragma region Tobias Stroedicke
	// create high score text
	GTextHighScore* pHighScore = new GTextHighScore("Highscore = 0", GGame::Get()->m_PArialFont, SRect(SCREEN_WIDTH / 2 - 150, 0, 300, 50));

	// add high score to ui list
	CEngine::Get()->GetCM()->AddUIObject(pHighScore);

	// create background music
	// Copyright Halcyonic Falcon X
	m_pBackgroundMusic = new CMusic(GetAssetPath("Audio/S_Background_MainScene.mp3", 4).c_str());
#pragma endregion

	// play music
	m_pBackgroundMusic->Play(true);
}

// cleaning up scene
void GMainScene::Clean()
{
	// delete world
	delete m_pWorld;

	// delete music
	delete m_pBackgroundMusic;

	// clean all objects
	CEngine::Get()->GetCM()->CleanScene();
	CEngine::Get()->GetCM()->CleanUI();
	CEngine::Get()->GetCM()->CleanPersistantObjects();
	CEngine::Get()->GetCM()->CleanBackgroundObjects(); // Tobias Stroedicke
}
#pragma endregion