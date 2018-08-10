#pragma region project include
#include "MenuScene.h"  
#include "MenuPlayer.h"
#include "Engine.h"
#include "ContentManagement.h"
#pragma endregion

#pragma region public override function
// initialize scene
void GMenuScene::Init()
{
	// create menu player
	GMenuPlayer* pPlayer = new GMenuPlayer();

	// add fps text to list
	CEngine::Get()->GetCM()->AddSceneObject(pPlayer);
}

// cleaning up scene
void GMenuScene::Clean()
{
	// remove player
	CEngine::Get()->GetCM()->RemoveObject(
		CEngine::Get()->GetCM()->GetSceneObjects().front()
	);
}
#pragma endregion