#pragma once

#pragma region project include
#include "MoveObject.h"
#include "Macro.h"
#include "Sound.h"
#pragma endregion

/// <summary>
/// bullet class
/// </summary>
class GBullet : public CMoveObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_position">position</param>
	/// <param name="_direction">direction</param>
	GBullet(SVector2 _position, SVector2 _direction) : CMoveObject(_position)
	{
		m_movement = _direction;
		m_speed = BULLET_SPEED;
		m_colType = ECollisionType::MOVE;
		m_rect.w = BULLET_SIZE_X;
		m_rect.h = BULLET_SIZE_Y;
		m_pTag = "Bullet";
		m_pLifetime = LIFETIME_OF_BULLET;
	}

	/// <summary>
	/// destructor
	/// </summary>
	~GBullet() {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override
	{
		CMoveObject::Update(_deltaTime);
	}

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	void Render(CRenderer* _pRenderer) override
	{
		CMoveObject::Render(_pRenderer);
	}
#pragma endregion

	void PlaySound() { m_pSound->Play(); }
};