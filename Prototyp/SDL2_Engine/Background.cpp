#pragma region system includes
#include <string>  
#include <SDL.h>
#pragma endregion

#pragma region project includes
#include "Background.h"
#include "MoveObject.h"
#include "Engine.h"
#include "Vector2.h"
#include "Engine.h"
#include "TextureManagement.h"
#include "Texture.h"
#include "ContentManagement.h"
#include "Object.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

void GBackground::Update(float _deltaTime)
{
	LoadTexture1(1);
}

void GBackground::GenerateBackgorund(int _world)
{
	LoadTexture4(_world);
	LoadTexture3(_world);
	LoadTexture2(_world);
	LoadTexture1(_world);
}

void GBackground::CreateWalls(int _world, int _position)
{
	LoadLeftWall(_world, _position);
	LoadRightWall(_world, _position);
}

/// <summary>
/// Create Background 1
/// </summary>
void GBackground::LoadTexture1(int _world)
{
	// name of world texture
	string texName = "Background1";

	// width and height of world
	int width = 0, height = START_POITION;

	// create textured object
	CTexturedObject* pObj = new CTexturedObject(
		SVector2((PLAYER_WIDTH / 2) - 10, height - (SCREEN_HEIGHT * _world)),
		SVector2(SCREEN_WIDTH, SCREEN_HEIGHT)
	);
	// set texture name of object
	pObj->SetTextureName(texName.c_str());

	// if texture not exists
	if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
	{
		// create new texture
		CTexture* pTexture = new CTexture("Texture/Background/Colision_False/BackgroundColor.png", CEngine::Get()->GetRenderer());

		// add texture to tm
		CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

		// set texture of object
		pObj->SetTexture(pTexture);

		SDL_Delay(500);
	}

	// if texture exists set texture of object
	else
	{

		//// mirror every second texture
		//if (_world % 2)
		//	pObj->SetMirror(SVector2(0, 1));

		pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
	}

	// add object to background list
	CEngine::Get()->GetCM()->AddBackground1Object(pObj);
}


void GBackground::LoadTexture2(int _world)
{
	// name of world texture
	string texName = "Background2";

	// width and height of world
	int width = 0, height = START_POITION;

	// create textured object
	CTexturedObject* pObj = new CTexturedObject(
		SVector2((PLAYER_WIDTH / 2) - 10, height - (SCREEN_HEIGHT * _world)),
		SVector2(SCREEN_WIDTH, SCREEN_HEIGHT)
	);

	// set texture name of object
	pObj->SetTextureName(texName.c_str());

	// if texture not exists
	if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
	{
		// create new texture
		CTexture* pTexture = new CTexture("Texture/Background/Colision_False/Cliff4.png", CEngine::Get()->GetRenderer());

		// add texture to tm
		CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

		// set texture of object
		pObj->SetTexture(pTexture);

		SDL_Delay(500);
	}

	// if texture exists set texture of object
	else
	{
		//// mirror every second texture
		//if (_world % 2)
		//	pObj->SetMirror(SVector2(0, 1));

		pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
	}

	// add object to background list
	CEngine::Get()->GetCM()->AddBackground2Object(pObj);
}

void GBackground::LoadTexture3(int _world)
{
	// name of world texture
	string texName = "Background3";

	// width and height of world
	int width = 0, height = START_POITION;

	// create textured object
	CTexturedObject* pObj = new CTexturedObject(
		SVector2((PLAYER_WIDTH / 2) - 10, height - (SCREEN_HEIGHT * _world)),
		SVector2(SCREEN_WIDTH, SCREEN_HEIGHT)
	);

	// set texture name of object
	pObj->SetTextureName(texName.c_str());

	// if texture not exists
	if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
	{
		// create new texture
		CTexture* pTexture = new CTexture("Texture/Background/Colision_False/Cliff3.png", CEngine::Get()->GetRenderer());

		// add texture to tm
		CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

		// set texture of object
		pObj->SetTexture(pTexture);

		SDL_Delay(500);
	}

	// if texture exists set texture of object
	else
	{
		//// mirror every second texture
		//if (_world % 2)
		//	pObj->SetMirror(SVector2(0, 1));

		pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
	}

	// add object to background list
	CEngine::Get()->GetCM()->AddBackground3Object(pObj);
}

void GBackground::LoadTexture4(int _world)
{
	// name of world texture
	string texName = "Background4";

	// width and height of world
	int width = 0, height = START_POITION;

	// create textured object
	CTexturedObject* pObj = new CTexturedObject(
		SVector2((PLAYER_WIDTH / 2) - 10, height - (SCREEN_HEIGHT * _world)),
		SVector2(SCREEN_WIDTH, SCREEN_HEIGHT)
	);

	// set texture name of object
	pObj->SetTextureName(texName.c_str());

	// if texture not exists
	if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
	{
		// create new texture
		CTexture* pTexture = new CTexture("Texture/Background/Colision_False/Cliff2.png", CEngine::Get()->GetRenderer());

		// add texture to tm
		CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

		// set texture of object
		pObj->SetTexture(pTexture);

		SDL_Delay(500);
	}

	// if texture exists set texture of object
	else
	{
		//// mirror every second texture
		//if (_world % 2)
		//	pObj->SetMirror(SVector2(0, 1));

		pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
	}

	// add object to background list
	CEngine::Get()->GetCM()->AddBackground4Object(pObj);
}

void GBackground::LoadLeftWall(int _world, int _position)
{
	// 1 to 5 chance a branch appears
	if (rand() % 3 == 0)
	{
		// name of branch texture
		string texName = "BranchLeft";

		// width and height of world
		int width = 0, height = START_POITION;

		// create textured object
		CTexturedObject* pObj = new CTexturedObject(
			SVector2(-25 + _world, -(SCREEN_HEIGHT * _position)),
			SVector2(PLAYER_HEIGHT * 2, PLAYER_WIDTH * 3)
		);



		// set texture name of object
		pObj->SetTextureName(texName.c_str());

		pObj->SetColType(ECollisionType::WALL);

		// if texture not exists
		if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
		{
			// create new texture
			CTexture* pTexture = new CTexture("Texture/Character/Enemy/Static_Obstacle/Branch1.png", CEngine::Get()->GetRenderer());

			// add texture to tm
			CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

			// set texture of object
			pObj->SetTexture(pTexture);
		}

		// if texture exists set texture of object
		else
		{
			//// mirror every second texture
			//if (_world % 2)
			//	pObj->SetMirror(SVector2(0, 1));

			pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
		}

		// add object to scene list
		CEngine::Get()->GetCM()->AddSceneObject(pObj);
	}

		// name of world texture
		string texName = "LeftWall";

		// width and height of world
		int width = 0, height = START_POITION;

		// create textured object
		CTexturedObject* pObj = new CTexturedObject(
			SVector2(-50 + _world,  -(SCREEN_HEIGHT * _position)),
			SVector2(SCREEN_WIDTH / 3, SCREEN_HEIGHT)
		);

		// set texture name of object
		pObj->SetTextureName(texName.c_str());

		pObj->SetColType(ECollisionType::WALL);

		// if texture not exists
		if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
		{
			// create new texture
			CTexture* pTexture = new CTexture("Texture/Background/Colision_True/Left_Wall.png", CEngine::Get()->GetRenderer());

			// add texture to tm
			CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

			// set texture of object
			pObj->SetTexture(pTexture);

			SDL_Delay(500);
		}

		// if texture exists set texture of object
		else
		{
			//// mirror every second texture
			//if (_world % 2)
			//	pObj->SetMirror(SVector2(0, 1));

			pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
		}

		// add object to scene list
		CEngine::Get()->GetCM()->AddSceneObject(pObj);
}

void GBackground::LoadRightWall(int _world, int _position)
{
	// 1 to 10 chance a branch appears
	if (rand() % 3 == 0)
	{
		// name of branch texture
		string texName = "BranchRight";

		// width and height of world
		int width = 0, height = START_POITION;

		// create textured object
		CTexturedObject* pObj = new CTexturedObject(
			SVector2((SCREEN_WIDTH - (PLAYER_HEIGHT * 2 - WORLD_BLOCK_WIDTH + _world)), -(SCREEN_HEIGHT * _position) + (SCREEN_HEIGHT/2)),
			SVector2(PLAYER_HEIGHT*2 , PLAYER_WIDTH * 2)
		);



		// set texture name of object
		pObj->SetTextureName(texName.c_str());

		pObj->SetColType(ECollisionType::WALL);

		// if texture not exists
		if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
		{
			// create new texture
			CTexture* pTexture = new CTexture("Texture/Character/Enemy/Static_Obstacle/Branch2.png", CEngine::Get()->GetRenderer());

			// add texture to tm
			CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

			// set texture of object
			pObj->SetTexture(pTexture);
		}

		// if texture exists set texture of object
		else
		{
			//// mirror every second texture
			//if (_world % 2)
			//	pObj->SetMirror(SVector2(0, 1));

			pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
		}

		// add object to scene list
		CEngine::Get()->GetCM()->AddSceneObject(pObj);
	}

	// name of world texture
	string texName = "RightWall";

	// width and height of world
	int width = 0, height = START_POITION;

	// create textured object
	CTexturedObject* pObj = new CTexturedObject(
		SVector2((SCREEN_WIDTH - (136 - WORLD_BLOCK_WIDTH + _world)), -(SCREEN_HEIGHT * _position)),
		SVector2(SCREEN_WIDTH / 3, SCREEN_HEIGHT)
	);



	// set texture name of object
	pObj->SetTextureName(texName.c_str());

	pObj->SetColType(ECollisionType::WALL);

	// if texture not exists
	if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
	{
		// create new texture
		CTexture* pTexture = new CTexture("Texture/Background/Colision_True/Right_Wall.png", CEngine::Get()->GetRenderer());

		// add texture to tm
		CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

		// set texture of object
		pObj->SetTexture(pTexture);

		SDL_Delay(500);
	}

	// if texture exists set texture of object
	else
	{
		//// mirror every second texture
		//if (_world % 2)
		//	pObj->SetMirror(SVector2(0, 1));

		pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
	}

	// add object to scene list
	CEngine::Get()->GetCM()->AddSceneObject(pObj);

}

void GBackground::Ground()
{
	// name of world texture
	string texName = "Ground";

	// width and height of world
	int width = 0, height = START_POITION;

	// create textured object
	CTexturedObject* pObj = new CTexturedObject(
		SVector2(-270, -80),
		SVector2(SCREEN_WIDTH * 2, SCREEN_HEIGHT / 3)
	);



	// set texture name of object
	pObj->SetTextureName(texName.c_str());

	pObj->SetColType(ECollisionType::WALL);

	// if texture not exists
	if (CEngine::Get()->GetTM()->GetTexture(texName) == nullptr)
	{
		// create new texture
		CTexture* pTexture = new CTexture("Texture/Background/Colision_True/Ground.png", CEngine::Get()->GetRenderer());

		// add texture to tm
		CEngine::Get()->GetTM()->AddTexture(texName, pTexture);

		// set texture of object
		pObj->SetTexture(pTexture);

		SDL_Delay(500);
	}

	// if texture exists set texture of object
	else
	{
		//// mirror every second texture
		//if (_world % 2)
		//	pObj->SetMirror(SVector2(0, 1));

		pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
	}

	// add object to scene list
	CEngine::Get()->GetCM()->AddBackground4Object(pObj);
}

