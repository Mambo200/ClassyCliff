#pragma region system include
#include <string>
#pragma endregion

#pragma region project include
#include "World.h"
#include "Macro.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Player.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

#pragma region public function
// initialize world
void GWorld::Init()
{
	// string to define world
	string world;

	// add lines to world string
	// string 100x20
	// 1 block is 64 x 64 pixel
	// screen has 20 (width) and 12 (height) blocks
	// X = dirt (outside)
	// 0 = black (free, background)
	// W = way (walk on)
	// L = lava (death)
	// S = start point of player
	
	/*world += "XXXXXX0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXXXX\n";
	world += "XXXXXX0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXXXX\n";
	world += "XXXXXX0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXXXX\n";
	world += "XXXXXX0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXXXX\n";
	world += "XXXXXX0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXXXX\n";
	world += "XXXXXX0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXXXX\n";
	world += "XXXXXX0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXXXX\n";
	world += "XXXXXX0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXXXX\n";
	world += "XXXXXX0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXXXX\n";
	world += "XXXXXX0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000XXXXXX\n";
	world += "XXXXXX0000000000000000000000000000000000000000WWW0000000000WWWWWW00000000000000000000000000000XXXXXX\n";
	world += "XXXXXX00000000000000000000WWWW00000000000000000000000000000000000000000000000000000000000WWWWWXXXXXX\n";
	world += "XXXXXX000000000000000000000000000000000000000000000WWWWWW00000000000000000000000000WWWWWWWXXXXXXXXXX\n";
	world += "XXXXXX0000000000WWWWWWWW000000000000000000000WWWWWWWXXXXWWWW0000000000000000WWWWWWWWXXXXXXXXXXXXXXXX\n";
	world += "XXXXXX00S000WWWWWXXXXXXWWWWWWWWLLWWWLLWWWWWWWWXXXXXXXXXXXXXWWWWWWWLWWWLLWWWWWXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";*/
	
	world += "XXWWWWWWWWWXX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XXLL0000000XX\n";
	world += "XXLL0000000XX\n";
	world += "XXLL0000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX0000LL000XX\n";
	world += "XX0000LL000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX00LLLL000XX\n";
	world += "XX00LLLL000XX\n";
	world += "XX00LLLL000XX\n";
	world += "XX00LLLL000XX\n";
	world += "XX00000000LXX\n";
	world += "XX00000000LXX\n";
	world += "XX00000000LXX\n";
	world += "XX00000000LXX\n";
	world += "XX00000000LXX\n";
	world += "XX0000000LLXX\n";
	world += "XX0000000LLXX\n";
	world += "XXLL00000LLXX\n";
	world += "XXLL00000LLXX\n";
	world += "XXLL0000000XX\n";
	world += "XX0000000LLXX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XXLLL000000XX\n";
	world += "XXLLL000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX0000LLLLLXX\n";
	world += "XX0000LLLLLXX\n";
	world += "XX0000LLLLLXX\n";
	world += "XX00000000LXX\n";
	world += "XX00000000LXX\n";
	world += "XX00000000LXX\n";
	world += "XX000000000XX\n";
	world += "XX00LL00000XX\n";
	world += "XX00LL00000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000LLLXX\n";
	world += "XX000000LLLXX\n";
	world += "XX000000LLLXX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX000000000XX\n";
	world += "XX0000S0000XX\n";
	world += "XXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXX\n";
	world += "XXXXXXXXXXXXX";

	// width and height of world
	int width = 0, height = 1;

	// through world string
	for (int i = 0; i < world.length(); i++)
	{
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
			SVector2(WORLD_BLOCK_WIDTH, WORLD_BLOCK_HEIGHT),
			CEngine::Get()->GetRenderer(),
			"Texture/World/T_WorldSide.png"
		);

		// x position of texture in atlas map
		int xPosOfTexture = 0;

		// switch char in world string
		switch (world[i])
		{
		// if dirt set position of texture in atlas map
		case 'X':
		{
			xPosOfTexture = WORLD_BLOCK_ATLAS_WIDTH;

			// set collision type to wall
			pObj->SetColType(ECollisionType::WALL);
			break;
		}

		// if way set position of texture in atlas map
		case 'W':
		{
			xPosOfTexture = 2 * WORLD_BLOCK_ATLAS_WIDTH;
			
			// set collision type to wall
			pObj->SetColType(ECollisionType::WALL);
			break;
		}

		// if lava set position of texture in atlas map
		case 'L':
		{
			xPosOfTexture = 3 * WORLD_BLOCK_ATLAS_WIDTH;
			
			// set collision type to wall
			pObj->SetColType(ECollisionType::WALL);
			break;
		}

		case 'S':
		{
			// create textured object
			GPlayer * pPlayer = new GPlayer(
				SVector2((width - 1) * WORLD_BLOCK_WIDTH, (height - 1) * WORLD_BLOCK_HEIGHT - PLAYER_HEIGHT), 
				SVector2(PLAYER_WIDTH, PLAYER_HEIGHT),
				CEngine::Get()->GetRenderer(), 
				"Texture/Character/Player/T_Samus_Idle.png");

			// set player values
			pPlayer->SetSpeed(PLAYER_SPEED);
			pPlayer->SetMirror(PLAYER_MIRROR);
			pPlayer->SetColType(ECollisionType::MOVE);

			// add player to persistant list
			CEngine::Get()->GetCM()->AddPersistantObject(pPlayer);
			break;
		}

		default:
			break;
		}

		// set source rect of object
		pObj->SetSrcRect(SRect(xPosOfTexture, 0, WORLD_BLOCK_ATLAS_WIDTH, WORLD_BLOCK_ATLAS_HEIGHT));

		// add object to scene list
		CEngine::Get()->GetCM()->AddSceneObject(pObj);
	}
}
#pragma endregion