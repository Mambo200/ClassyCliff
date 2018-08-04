#pragma region system include
#include <string>
#pragma endregion

#pragma region project include
#include "World.h"
#include "Macro.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "TextureManagement.h"
#include "Texture.h"
#include "Player.h"
#include "MoveEnemy.h"
#include "Background.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

#include <SDL.h>

#pragma region public function
// initialize world
void GWorld::Init()
{	
	// create ground
	GBackground::Ground();

	// prerender background
	for (int i = 0; i < PRERENDER; i++)
	{
		GBackground::GenerateBackgorund(i);
		GBackground::CreateWalls(i, i);
	}

	// string to define world
	string world;
	// S = start point of player
	
	world += "FFFFFSFFFFF\n";

	// width and height of world
	int width = 0, height = 1;

	// name of world texture
	string texName = "World";

	// through world string
	for (int i = 0; i < world.length(); i++)
	{
		// name of world texture
		texName = "World";

		// increase width
		width++;

		// if end of line increase height and reset width
		if (world[i] == '\n')
		{
			height++;
			width = 0;
			continue;
		}

		// create textured object
		CTexturedObject* pObj = new CTexturedObject(
			SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT),
			SVector2(WORLD_BLOCK_WIDTH, WORLD_BLOCK_HEIGHT)
		);

		// set texture name of object
		pObj->SetTextureName(texName.c_str());

		// if texture not exists
		if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
		{
			// create new texture
			CTexture* pTexture = new CTexture("Texture/World/T_WorldSide.png", CEngine::Get()->GetRenderer());

			// add texture to tm
			CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

			// set texture of object
			pObj->SetTexture(pTexture);

			SDL_Delay(500);
		}

		// if texture exists set texture of object
		else
		{
			pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
		}

		// x position of texture in atlas map
		int xPosOfTexture = 0;

		// switch char in world string
		switch (world[i])
		{

		case 'F':
			continue;

		case 'S':
		{
			// create textured object
			GPlayer * pPlayer = new GPlayer(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT), 
				SVector2(PLAYER_WIDTH, PLAYER_HEIGHT)
			);

			// set player values
			pPlayer->SetSpeed(PLAYER_SPEED);
			pPlayer->SetMirror(PLAYER_MIRROR);
			pPlayer->SetColType(ECollisionType::MOVE);
			pPlayer->ActivateGravity();

			// set texture name
			texName = "Player";

			// set texture name of object
			pPlayer->SetTextureName(texName.c_str());

			// if texture not exists
			if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
			{
				// create new texture
				CTexture* pTexture = new CTexture("Texture/Character/Player/Flying_Front/Player_Flying_Front0.png", CEngine::Get()->GetRenderer());

				// add texture to tm
				CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

				// set texture of object
				pPlayer->SetTexture(pTexture);

				SDL_Delay(500);
			}

			// if texture exists set texture of object
			else
			{
				pPlayer->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
			}

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pPlayer);
			break;
		}

		default:
			break;
		}

		if (texName == "Player")
			continue;
		// set source rect of object
		pObj->SetSrcRect(SRect(xPosOfTexture, 0, WORLD_BLOCK_ATLAS_WIDTH, WORLD_BLOCK_ATLAS_HEIGHT));

		// add object to scene list
		CEngine::Get()->GetCM()->AddSceneObject(pObj);
	}

	// check all collision for scene objects
	for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
	{
		if (dynamic_cast<CMoveObject*>(pObj))
			((CMoveObject*)pObj)->CheckCollisionObjects();
	}

	// check all collision for persistant objects
	for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
	{
		if (dynamic_cast<CMoveObject*>(pObj))
			((CMoveObject*)pObj)->CheckCollisionObjects();
	}
}
#pragma endregion