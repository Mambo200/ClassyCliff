#pragma once

#pragma region value macro
#define DEBUG_ON true
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 720
#define LAYER_COUNT 10
#define PLAYER_SPEED 500.0f
#define PLAYER_JUMP_FORCE 375.0f
#define PLAYER_JUMP_TIME 0.75f
#define START_POITION -500
#define PLAYER_WIDTH 252 / 5
#define PLAYER_HEIGHT 512 / 5
#define PLAYER_SRC_RECT_WIDTH 36
#define PLAYER_SRC_RECT_HEIGHT 46
#define BACKGROUND_HEIGHT 1920
#define PRERENDER 3
#define PLAYER_MIRROR SVector2(1.0f, 0.0f)
#define WORLD_BLOCK_ATLAS_WIDTH 26
#define WORLD_BLOCK_ATLAS_HEIGHT 26
#define WORLD_BLOCK_WIDTH 48
#define WORLD_BLOCK_HEIGHT 48
#define MOVE_ENEMY_WIDTH 32
#define MOVE_ENEMY_HEIGHT 32
#define MOVE_ENEMY_SPEED 125.0f
#define BULLET_SIZE_X 25.0f
#define BULLET_SIZE_Y 18.0f
#define BULLET_WIDTH 241
#define BULLET_HEIGHT 123
#define BULLET_SPEED 250.0f
#define GRAVITY_VALUE 9.81f
#define COLLISION_DISTANCE 640.0f
#define COLLISION_CHECK_TIMER 0.1f
#define LIFETIME_OF_BULLET 1.0f
#define Y_POSITION_OF_PLAYER SCREEN_HEIGHT - 2 * PLAYER_HEIGHT
#define BULLET_TAG "Bullet"
#define ENEMY_TAG "Enemy"
#pragma endregion

#pragma region function macro
#define LOG_ERROR(TEXT, ERROR)		\
	std::cout << TEXT;				\
	std::cout << " Error: ";		\
	std::cout << ERROR;				\
	std::cout << std::endl;
#pragma endregion