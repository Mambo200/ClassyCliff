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
#include "Background.h"
#pragma endregion

#pragma region static variable
SVector2 GPlayer::m_helperPosition = SVector2(0, 0);
#pragma endregion

#pragma region public override function
// update every frame
void GPlayer::Update(float _deltaTime)
{

	// creating world while playing
	for (CObject* pObj : CEngine::Get()->GetCM()->GetBackground2Object())
		pObj->SetPosition(pObj->GetPosition() + SVector2(0, 100));

	//LOG_ERROR((int)CEngine::Get()->GetRenderer()->GetCamera().Y % (SCREEN_HEIGHT * (m_backGround - 2)), m_backGround)
	LOG_ERROR(CEngine::Get()->GetTime()->GetFPS(), m_afterFifty);
		if (((int)CEngine::Get()->GetRenderer()->GetCamera().Y % (SCREEN_HEIGHT * (m_afterFifty - 2))) <= 0 &&
			((int)CEngine::Get()->GetRenderer()->GetCamera().Y % (SCREEN_HEIGHT * (m_afterFifty - 2))) >= -100)
		{
			GBackground::GenerateBackgorund(m_afterFifty);
			GBackground::CreateWalls(m_backGround, m_afterFifty);
			if (m_backGround < 50)
				m_backGround++;
			m_afterFifty++;
			//CEngine::Get()->GetCM()->MoveBackground2Object();
		}

	// start game
	if (CInput::GetMouseDown(SDL_BUTTON_LEFT))
		start = true;

	// get mouseposition on screen
	int m1 = (int)m_position.X;
	int m2 = (int)m_position.Y;
	SDL_GetMouseState(&m1, &m2);
	m1 -= SCREEN_WIDTH / 2;
	m2 -= SCREEN_HEIGHT - (PLAYER_HEIGHT * 2);
	if (m2 < (PLAYER_HEIGHT * 1.5f) * -1)
		m2 = (PLAYER_HEIGHT * 1.5f) * -1;
	else if (m2 > (PLAYER_HEIGHT * 1.5f))
			 m2 = (PLAYER_HEIGHT * 1.5f);
	if (m1 < (PLAYER_HEIGHT * 1.5f) * -1)
		m1 = (PLAYER_HEIGHT * 1.5f) * -1;
	else if (m1 > (PLAYER_HEIGHT * 1.5f))
			 m1 = (PLAYER_HEIGHT * 1.5f);
	DirectionBoost(SVector2(m1, m2), m_helperPosition);

	// if cursor right of player
	if (m1 < m_helperPosition.X)
	{
		m_forward.X = -1.0f;
		m_mirror.X = 1.0f;
	}

	// if cursor left of player
	if (m1 > m_helperPosition.X)
	{
		m_forward.X = 1.0f;
		m_mirror.X = 0.0f;
	}
	
	if (CInput::GetMouseDown(SDL_BUTTON_RIGHT))
	{
		// spawn bullet
		GBullet* pBullet = new GBullet(m_position, m_forward);
		pBullet->AddPosition(SVector2(m_boostDirection.X * PLAYER_WIDTH + 1, m_boostDirection.Y * PLAYER_HEIGHT + 1));

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

	// if game started
	if (start)
	{
		// if cursor right of player
		if (m1 < m_helperPosition.X)
		{
			m_forward.X = -1.0f;
			m_mirror.X = 1.0f;
		}

		// if cursor left of player
		if (m1 > m_helperPosition.X)
		{
			m_forward.X = 1.0f;
			m_mirror.X = 0.0f;
		}
		
		// if player is moveable
		//if (moveable)
		//{
			// movement left
			if (CInput::GetMouseDown(SDL_BUTTON_LEFT) && m1 > m_helperPosition.X)
			{
				// set movement, forward and mirror
				m_movement.X = -1.0f;
				AddHelpPosition(SVector2(m_movement.X, 0));

				// set jump enable, gravity false and set jump time
				m_fallTime = 0.001f;
				m_jump = true;
				m_jumpTime = PLAYER_JUMP_TIME;
				m_shotTime = PLAYER_JUMP_TIME - PLAYER_JUMP_TIME / 5;
				m_gravity = false;

				// spawn bullet
				GBullet* pBullet = new GBullet(m_position, m_forward);
				pBullet->AddPosition(SVector2(m_boostDirection.X * PLAYER_WIDTH + 1, m_boostDirection.Y * 48.0f + 1));

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

			// movement right
			else if (CInput::GetMouseDown(SDL_BUTTON_LEFT) && m1 < m_helperPosition.X)
			{
				// set movement, forward and mirror
				m_movement.X = 1.0f;
				AddHelpPosition(SVector2(m_movement.X, 0));

				// set jump enable, gravity false and set jump time
				m_fallTime = 0.001f;
				m_jump = true;
				m_jumpTime = PLAYER_JUMP_TIME;
				m_shotTime = PLAYER_JUMP_TIME - PLAYER_JUMP_TIME / 5;
				m_gravity = false;

				// TODO

				// spawn bullet
				GBullet* pBullet = new GBullet(m_position, m_forward);
				pBullet->AddPosition(SVector2(m_boostDirection.X * PLAYER_WIDTH + 1, m_boostDirection.Y * 48.0f + 1));  //m_forward.X muss noch geändert werder
													
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

			// no movement left or right
			else if (m_jumpTime <= 0.01f)
				m_movement.X = 0.0f;
			
			// update parent
			CMoveObject::Update(_deltaTime);

			// if jump enabled
			if (m_jump)

			{
				// decrease jump time
				m_jumpTime -= _deltaTime;
				m_shotTime -= _deltaTime;

				// if jump time under 0
				if (m_jumpTime <= 0.0f)
				{
					// deactivate jump and activate gravity
					m_jump = false;
					m_gravity = true;
				}

				// next position
				SVector2 nextPos = m_position;
				nextPos.X += m_movement.X;
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
	}

	if (!saved)
	{
		savedXPos = m_position.X + PLAYER_WIDTH / 2;
		saved = true;
	}

	// set position of camera
	CEngine::Get()->GetRenderer()->SetCamera(
		SVector2(savedXPos, m_position.Y - PLAYER_HEIGHT * 2.4)
	);

	/// <summary>
	/// TODO: DELETE
	/// </summary>
	// print player position
	std::string s = "Position Y: ";
	s += std::to_string(m1) + " " + std::to_string(m2) + "\n";
	s += std::to_string(m_boostDirection.X) + " " + std::to_string(m_boostDirection.Y) + "\n";
	s += std::to_string(Y_POSITION_OF_PLAYER);
	//LOG_ERROR("", s.c_str());

}

// render every frame
void GPlayer::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}
#pragma endregion