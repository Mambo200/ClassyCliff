#include <iostream>	///TODO: DELETE
#include <string>	///TODO: DELETE

#pragma region project include
#include "Player.h"
#include "Input.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "TextureManagement.h"
#include "Texture.h"
#include "Physic.h"
#include "Renderer.h"
#include "Bullet.h"
#include "Time.h"	///TODO: DELETE
#pragma endregion

#pragma region public override function
// update every frame
void GPlayer::Update(float _deltaTime)
{
	//// start game
	//if (CInput::GetMouseDown(SDL_BUTTON_LEFT))
	//	start = true;
	//
	//// if game started
	//if (start)
	//{
		// movement left
		if (CInput::GetKey(SDL_SCANCODE_A))
		{
			// set movement, forward and mirror
			m_movement.X = -1.0f;
			m_mirror.X = 1.0f;
			m_forward.X = -1.0f;
		}

		// movement right
		else if (CInput::GetKey(SDL_SCANCODE_D))
		{
			// set movemenet, forward and mirror
			m_movement.X = 1.0f;
			m_mirror.X = 0.0f;
			m_forward.X = 1.0f;
		}

		// no movement left or right
		else
			m_movement.X = 0.0f;

		// if key space is pressed this frame and jump not active and grounded
		if (CInput::GetMouseDown(SDL_BUTTON_LEFT) && !m_jump && m_grounded)
		{
			// set jump enable, gravity false and set jump time
			m_jump = true;
			m_jumpTime = PLAYER_JUMP_TIME;
			m_gravity = false;

			// TODO

			// spawn bullet
			GBullet* pBullet = new GBullet(m_position, m_forward);
			pBullet->AddPosition(SVector2(m_forward.X * PLAYER_WIDTH + 1, 48.0f));  //m_forward.X muss noch geändert werden

			// set texture name of object
			pBullet->SetTextureName("Bullet");

			// if texture not exists
			if (CEngine::Get()->GetTM()->GetTexture("Bullet") == nullptr)
			{
				// create new texture
				CTexture* pTexture = new CTexture("Texture/Bullet/T_Bullet.png", CEngine::Get()->GetRenderer());

				// add texture to tm
				CEngine::Get()->GetTM()->AddTexture("Bullet", pTexture);

				// set texture of object
				pBullet->SetTexture(pTexture);
			}

			// if texture exists set texture of object
			else
			{
				pBullet->SetTexture(CEngine::Get()->GetTM()->GetTexture("Bullet"));
			}

			// add to list
			CEngine::Get()->GetCM()->AddPersistantObject(pBullet);
		}

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

			// moveable default true
			bool moveable = true;

			// next position
			SVector2 nextPos = m_position;
			nextPos.Y -= PLAYER_JUMP_FORCE * _deltaTime;

			// next rect
			SRect nextRect = m_rect;
			nextRect.x = nextPos.X;
			nextRect.y = nextPos.Y;

			// through all collision objects
			for (CObject* pObj : m_pCollisionObjects)
			{
				// if current object is self continue
				if ((CMoveObject*)pObj && pObj == this)
					continue;

				// if collision type none
				if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
					continue;

				// set moveable by checking collision
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

				// if not moveable cancel collision check
				if (!moveable)
					break;
			}

			// if still moveable set y position
			if (moveable)
			{
				m_position.Y -= PLAYER_JUMP_FORCE * _deltaTime;
				m_rect.y = m_position.Y;
			}
		}
	//}

	if (!saved)
	{
		savedXPos = m_position.X + PLAYER_WIDTH / 2;
		saved = true;
	}

	// set position of camera
	CEngine::Get()->GetRenderer()->SetCamera(
		SVector2(savedXPos, m_position.Y - PLAYER_HEIGHT)
	);

	/// <summary>
	/// TODO: DELETE
	/// </summary>
	// print player position
	std::string s = "Position Y: ";
	s += std::to_string(m_position.Y);
	LOG_ERROR("", s.c_str());
}

// render every frame
void GPlayer::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}
#pragma endregion