#include <iostream>	///TODO: DELETE
#include <string>	///TODO: DELETE
#include <list>

#pragma region project include
#include "Player.h"
#include "Input.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Physic.h"
#include "Renderer.h"
#include "World.h"
#include "MoveObject.h"
#include "Bullet.h"
#include "Engine.h"
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

#pragma region public override function
// update every frame
void GPlayer::Update(float _deltaTime)
{
#pragma region Changed
	// start game
	if (CInput::GetMouseDown(SDL_BUTTON_LEFT))
		start = true;

	// if game started
	if (start)
	{
		if (!collided)
			collided = !GetMoveable();

		for each (CObject* Obj in CEngine::Get()->GetCM()->GetFallingObjects())
		{
			if (Obj->GetMoveableObject() == true)
			{
				Obj->AddPosition(SVector2(0, Obj->GetFalltime() * OBJECT_FALL_FORCE));
				Obj->SetFalltime(_deltaTime);
			}
		}

		// player collides
		if (!collided)
		{
			//m_movement.Y = -0.5f * _deltaTime * 50;
#pragma endregion


		// movement left
			if (CInput::GetKey(SDL_SCANCODE_A) || CInput::GetKey(SDL_SCANCODE_LEFT))
			{
				// set movement and mirror
				m_movement.X = -1.0f * _deltaTime * 50;
				m_mirror.X = 1.0f;
			}

			// movement right
			else if (CInput::GetKey(SDL_SCANCODE_D) || CInput::GetKey(SDL_SCANCODE_RIGHT))
			{
				// set movemenet and mirror
				m_movement.X = 1.0f * _deltaTime * 50;
				m_mirror.X = 0.0f;
			}
			// no movement left or right
			else
				m_movement.X = 0.0f;

			

			// delete bullets
			LOG_ERROR(bulletTimeOnScreen[0], bulletTimeOnScreen[1]);
			LOG_ERROR(whichBulletShot[0], whichBulletShot[1]);

			
			
			// bullet disaperas
				if (CheckArraySize() <= 1 && whichBulletShot[0])
				{
					CEngine::Get()->GetCM()->RemoveBullet();
					whichBulletShot[0] = false;
				}
				else if ((CheckArraySize() == 2 || CheckArraySize() == 0) && whichBulletShot[1])
				{
					CEngine::Get()->GetCM()->RemoveBullet();
					whichBulletShot[1] = false;
				}
			//!CEngine::Get()->GetCM()->GetBulletObjects().empty())




			// if left mouse button is pressed this frame
			if (CInput::GetMouseDown(SDL_BUTTON_LEFT) && !shot)
			{
				// set jump enable, gravity false and set jump time
				m_jump = true;
				m_jumpTime = PLAYER_JUMP_TIME;
				m_gravity = false;
				ResetfallTime();

				AddTime();
				SetShootTime();

				// create bullet
				CTexturedObject* bullet = new CTexturedObject(
					SVector2(m_position.X + PLAYER_WIDTH / 2, m_position.Y),
					SVector2(5, 17),
					CEngine::Get()->GetRenderer(),
					"Texture/Bullet/T_Bullet.png"

				);

				shot = true;

				// add object to persistant list
				CEngine::Get()->GetCM()->AddBulletObject(bullet);
			}
			//else if {bulletTimeOnScreen }


		// update parent
			CMoveObject::Update(_deltaTime);

			// if jump enabled
			if (m_jump)
			{
				// decrease jump time
				m_jumpTime -= _deltaTime;

				// if jump time under 0
				if (m_jumpTime <= 0.0f)
				{
					// deactivate jump and activate gravity
					m_jump = false;
					m_gravity = true;
				}



				// next position
				nextPos = m_position;
				nextPos.Y -= PLAYER_JUMP_FORCE * _deltaTime;

				// next rect
				SRect nextRect = m_rect;
				nextRect.x = nextPos.X;
				nextRect.y = nextPos.Y;

				// through all scene objects
				if (GetMoveable())
				{
					for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
					{
						// if current object is self continue
						if ((CMoveObject*)pObj && pObj == this)
							continue;

						// if collision type none
						if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
							continue;

						// set moveable by checking collision
						SetMoveable(!CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()));

						// if not moveable cancel collision check
						if (!GetMoveable())
							break;
					}

					// if moveable
					if (GetMoveable())
					{
						// through all persistant objects
						for (CObject* pObj : CEngine::Get()->GetCM()->GetPersistantObjects())
						{
							// if current object is self continue
							if ((CMoveObject*)pObj && pObj == this)
								continue;

							// if collision type none
							if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
								continue;

							// set moveable by checking collision
							SetMoveable(!CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()));



							// if not moveable cancel collision check
							if (!GetMoveable())
								break;
						}
					}
				}
				// if still moveable set y position
				if (GetMoveable())
				{
					m_position.Y -= PLAYER_JUMP_FORCE * _deltaTime;
					m_rect.y = m_position.Y;
				}
			}
			LowerShootTime(_deltaTime);
			LowerBulletTime(_deltaTime);

			//LOG_ERROR(bulletTimeOnScreen[0], bulletTimeOnScreen[1])

			//EASY_OUTPUT(shootTime);

		}
		else	// changed
		{
			EASY_OUTPUT("Verloren");	// changed
			m_movement = SVector2(0, 0);
		}

#pragma region Changed

#pragma endregion


		/*
		/// <summary>
		/// TODO: DELETE
		/// </summary>
		// print player position
		std::string s = "Player position: X: ";
		s += std::to_string(m_position.X);
		s += ", Y: ";
		s += std::to_string(m_position.Y);
		LOG_ERROR("", s.c_str());
		*/
	}

	// save position X Camera at Startpoint
	if (!saved)
	{
		savedXPos = m_position.X + PLAYER_WIDTH / 2;
		saved = true;
	}

	// set position of camera
	CEngine::Get()->GetRenderer()->SetCamera(
		SVector2(savedXPos, m_position.Y - PLAYER_HEIGHT * 2) // Changed xPosition
	);

}

// render every frame
void GPlayer::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}

// add time too array
void GPlayer::AddTime()
{
	if (CheckArraySize() <= 1)
		bulletTimeOnScreen[0] = BULLET_TIME_TO_DISAPPEAR;
	else if (CheckArraySize() == 2)
		bulletTimeOnScreen[1] = BULLET_TIME_TO_DISAPPEAR;
}
void GPlayer::RemoveTime(list<float>& _pList)
{
	_pList.pop_back();
}
short GPlayer::CheckArraySize()
{
	if (bulletTimeOnScreen[0] == 0 && bulletTimeOnScreen[1] == 0)
		return 0;
	else if (bulletTimeOnScreen[0] == 0)
		return 1;
	else if (bulletTimeOnScreen[1] == 0)
		return 2;
	else
		return 3;
}

void GPlayer::LowerShootTime(float _deltatime)
{
	if (shootTime < _deltatime)
	{
		shootTime = 0;
		shot = false;
	}
	else if (shootTime == 0)
		return;
	else
		shootTime -= _deltatime;
}

/// <summary>
/// lowers bullet time
/// </summary>
void GPlayer::LowerBulletTime(float _deltaTime)
{
	if (bulletTimeOnScreen[0] != 0)
	{
		if (bulletTimeOnScreen[0] <= _deltaTime)
			bulletTimeOnScreen[0] = 0;
		else
		{
			bulletTimeOnScreen[0] -= _deltaTime;
			whichBulletShot[0] = true;
		}
	}

	if (bulletTimeOnScreen[1] != 0)
	{
		if (bulletTimeOnScreen[1] <= _deltaTime)
			bulletTimeOnScreen[1] = 0;
		else
		{
			bulletTimeOnScreen[1] -= _deltaTime;
			whichBulletShot[1] = true;
		}
	}
}
#pragma endregion