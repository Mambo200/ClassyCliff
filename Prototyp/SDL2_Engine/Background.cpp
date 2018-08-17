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
#include "Renderer.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

void GBackground::GenerateBackgorund(int _world)
{
	LoadBackground4(_world);
	LoadBackground3(_world);
	LoadBackground2(_world);
	LoadBackground1(_world);
}

void GBackground::CreateWalls(int _world, int _position)
{
	LoadLeftWall(_world, _position);
	LoadRightWall(_world, _position);

	// delete useless Objects from backgroundlists
	if (CEngine::Get()->GetCM()->GetWallObjects().size() >= 4)
		CEngine::Get()->GetCM()->RemoveObject(CEngine::Get()->GetCM()->GetWallObjects().back());

	// delete useless Objects from backgroundlists
	if (CEngine::Get()->GetCM()->GetBrancheObjects().size() >= 4)
		CEngine::Get()->GetCM()->RemoveObject(CEngine::Get()->GetCM()->GetBrancheObjects().back());

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
			SVector2((-5 - (SCREEN_WIDTH / 2)) + _world, -(SCREEN_HEIGHT * _position)),
			SVector2(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 4)
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

		// set Tag of Object
		pObj->SetTag(texName.c_str());

		// add object to scene list
		CEngine::Get()->GetCM()->AddBrancheObject(pObj);
	}

		// name of world texture
		string texName = "LeftWall";

		// width and height of world
		int width = 0, height = START_POITION;

		// create textured object
		CTexturedObject* pObj = new CTexturedObject(
			SVector2((-25 - (SCREEN_WIDTH / 2)) + _world,  -(SCREEN_HEIGHT * _position)),
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

		// set Tag of Object
		pObj->SetTag(texName.c_str());

		// add object to scene list
		CEngine::Get()->GetCM()->AddWallObject(pObj);
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
			SVector2(((SCREEN_WIDTH / 6) + 65) - _world, -(SCREEN_HEIGHT * _position) + (SCREEN_HEIGHT/2)),
			SVector2(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 4)
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

		// set Tag of Object
		pObj->SetTag(texName.c_str());

		// add object to scene list
		CEngine::Get()->GetCM()->AddBrancheObject(pObj);
	}

	// name of world texture
	string texName = "RightWall";

	// width and height of world
	int width = 0, height = START_POITION;

	// create textured object
	CTexturedObject* pObj = new CTexturedObject(
		SVector2(((SCREEN_WIDTH / 6) + 80) - _world, -(SCREEN_HEIGHT * _position)),
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

	// set Tag of Object
	pObj->SetTag(texName.c_str());

	// add object to scene list
	CEngine::Get()->GetCM()->AddWallObject(pObj);

}

void GBackground::Ground()
{
	// name of world texture
	string texName = "Ground";

	// width and height of world
	int width = 0, height = START_POITION;

	// create textured object
	CTexturedObject* pObj = new CTexturedObject(
		SVector2(-SCREEN_WIDTH / 2, START_POITION*0.9f), // 25 - (SCREEN_WIDTH / 2)
		SVector2(SCREEN_WIDTH, SCREEN_HEIGHT / 2)
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


#pragma region Spawnalgorithmus
// handle the first backgroundlist
void GBackground::LoadBackground1(int _pos)
{
	string texName = "Background1";

	CTexturedObject* pObj = new CTexturedObject(
		SVector2(25 - (SCREEN_WIDTH / 2), (int)_pos - (SCREEN_HEIGHT)),
		SVector2(SCREEN_WIDTH, SCREEN_HEIGHT));

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
		pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
	}

	// add object to background list
	CEngine::Get()->GetCM()->AddBackground1Object(pObj);

	// delete useless Objects from backgroundlists
	if (CEngine::Get()->GetCM()->GetBackground1Object().size() >= 4)
		CEngine::Get()->GetCM()->RemoveObject(CEngine::Get()->GetCM()->GetBackground1Object().back());
}

// handle second backgroundlist
void GBackground::LoadBackground2(int _pos)
{
	string texName = "Background2";

	CTexturedObject* pObj = new CTexturedObject(
		SVector2(25 - (SCREEN_WIDTH / 2), (int)_pos - (SCREEN_HEIGHT)),
		SVector2(SCREEN_WIDTH, SCREEN_HEIGHT));

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
		pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
	}

	// add object to background list
	CEngine::Get()->GetCM()->AddBackground2Object(pObj);

	// delete useless Objects from backgroundlists
	if (CEngine::Get()->GetCM()->GetBackground2Object().size() >= 4)
		CEngine::Get()->GetCM()->RemoveObject(CEngine::Get()->GetCM()->GetBackground2Object().back());
}

// handle third backgroundlist
void GBackground::LoadBackground3(int _pos)
{
	string texName = "Background3";

	CTexturedObject* pObj = new CTexturedObject(
		SVector2(25 - (SCREEN_WIDTH / 2), (int)_pos - (SCREEN_HEIGHT)),
		SVector2(SCREEN_WIDTH, SCREEN_HEIGHT));

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
		pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
	}

	// add object to background list
	CEngine::Get()->GetCM()->AddBackground3Object(pObj);

	// delete useless Objects from backgroundlists
	if (CEngine::Get()->GetCM()->GetBackground3Object().size() >= 4)
		CEngine::Get()->GetCM()->RemoveObject(CEngine::Get()->GetCM()->GetBackground3Object().back());
}

// handle fourth backgroundlist
void GBackground::LoadBackground4(int _pos)
{
	string texName = "Background4";

	CTexturedObject* pObj = new CTexturedObject(
		SVector2(25 - (SCREEN_WIDTH / 2), (int)_pos - (SCREEN_HEIGHT)),
		SVector2(SCREEN_WIDTH, SCREEN_HEIGHT));

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
		pObj->SetTexture(CEngine::Get()->GetTM()->GetTexture(texName));
	}

	// add object to background list
	CEngine::Get()->GetCM()->AddBackground4Object(pObj);

	// delete useless Objects from backgroundlists
	if (CEngine::Get()->GetCM()->GetBackground4Object().size() >= 4)
		CEngine::Get()->GetCM()->RemoveObject(CEngine::Get()->GetCM()->GetBackground4Object().back());
}
#pragma endregion