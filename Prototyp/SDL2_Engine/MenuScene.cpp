#pragma region project include
#include "MenuScene.h"  
#include "MenuPlayer.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Music.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMenuScene::Init()
{
	// create menu player
	GMenuPlayer* pPlayer = new GMenuPlayer();

	// add fps text to list
	CEngine::Get()->GetCM()->AddSceneObject(pPlayer);

	// create background music
	// Copyright Halcyonic Falcon X
	m_pBackgroundMusic = new CMusic(GetAssetPath("Audio/S_Background_MenuScene.mp3", 4).c_str()); // Changed Music

	// play music
	m_pBackgroundMusic->Play(true);
}

// cleaning up scene
void GMenuScene::Clean()
{
	// delete music
	delete m_pBackgroundMusic;

	// remove player
	CEngine::Get()->GetCM()->RemoveObject(
		CEngine::Get()->GetCM()->GetSceneObjects().front()
	);
}
#pragma endregion