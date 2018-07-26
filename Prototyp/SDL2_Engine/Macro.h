#pragma once

#pragma region value macro
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 840
#define PLAYER_SPEED 500.0f
#define PLAYER_JUMP_FORCE 500.0f
#define PLAYER_JUMP_TIME 0.50f
#define PLAYER_WIDTH  51 //68
#define PLAYER_HEIGHT 69 //92
#define PLAYER_MIRROR SVector2(1.0f, 0.0f)
#define WORLD_BLOCK_ATLAS_WIDTH 26
#define WORLD_BLOCK_ATLAS_HEIGHT 26
#define WORLD_BLOCK_WIDTH 40
#define WORLD_BLOCK_HEIGHT 40
#define GRAVITY_VALUE 9.81f
#pragma endregion

#pragma region function macro
#define LOG_ERROR(TEXT, ERROR)		\
	std::cout << TEXT;				\
	std::cout << " Error: ";		\
	std::cout << ERROR;				\
	std::cout << std::endl;

#define EASY_OUTPUT(TEXT) std::cout << TEXT << std::endl;
#pragma endregion