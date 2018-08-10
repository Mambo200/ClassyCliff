#pragma region system include
#include <cstdlib>
#pragma endregion

#pragma region project include
#include "MoveEnemy.h"  
#include "Macro.h"
#pragma endregion

#pragma region public override function
// update every frame
void GMoveEnemy::Update(float _deltaTime)
{
	// update parent
	CMoveObject::Update(_deltaTime);
}

// render every frame
void GMoveEnemy::Render(CRenderer * _pRenderer)
{
	// render parent
	CMoveObject::Render(_pRenderer);
}
#pragma endregion

#pragma region public function
// initialize enemy
void GMoveEnemy::Init()
{
	// set gravity and speed
	m_gravity = true;
	m_speed = MOVE_ENEMY_SPEED;

	// set rect
	m_rect.w = MOVE_ENEMY_WIDTH;
	m_rect.h = MOVE_ENEMY_HEIGHT;

	// random movement x
	if (rand() % 2)
		m_movement.X = 1.0f;
	else
		m_movement.X = -1.0f;

	// set collision type
	m_colType = ECollisionType::MOVE;

	// set tag
	m_pTag = ENEMY_TAG;
}
#pragma endregion