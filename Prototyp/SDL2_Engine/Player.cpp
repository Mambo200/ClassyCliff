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
#include "Sound.h"
#include "Animation.h"
#include "MenuScene.h"
#include "Helper.h"
#include "Score.h"
#pragma endregion

int GPlayer::m_currentScore = 0;
int GPlayer::m_highScore = 0;

#pragma region public override function
// update every frame
void GPlayer::Update(float _deltaTime)
{
	// last position of player
	SVector2 lastPosition;

	// reset pointer of background-objects
	CObject* bGround1_1 = nullptr;
	CObject* bGround2_1 = nullptr;
	CObject* bGround3_1 = nullptr;
	CObject* bGround4_1 = nullptr;

	// get first object of the list of background-objects
	bGround1_1 = CEngine::Get()->GetCM()->GetBackground1Object().front();
	bGround2_1 = CEngine::Get()->GetCM()->GetBackground2Object().front();
	bGround3_1 = CEngine::Get()->GetCM()->GetBackground3Object().front();
	bGround4_1 = CEngine::Get()->GetCM()->GetBackground4Object().front();
	// differenz
	float diff = 0;

	// if lastPostion zero, get current position of player
	if (lastPosition.Y == 0)
		lastPosition = GetPosition();

	// if debug mode is active
	if (DEBUG_ON)
		moveable = true;

	// set standing animation
	if (!start)
	{
		m_pCurrentAnim = m_pIdleAnim;
	}

	// start game
	if (CInput::GetMouseDown(SDL_BUTTON_LEFT) && start == false)
		start = true;

	// get mouseposition on screen
	int m1;
	int m2;
	SDL_GetMouseState(&m1, &m2);

	m1 = m1 - (m_rect.x - (CEngine::Get()->GetRenderer()->GetCamera().X - SCREEN_WIDTH / 2)+ m_rect.w / 2);
	m2 = m2 - (m_rect.y  - (CEngine::Get()->GetRenderer()->GetCamera().Y - SCREEN_HEIGHT / 2)+ m_rect.h / 2);

	SVector2 s2 = SVector2(m1, m2);

	if (s2.magnitude() > PLAYER_HEIGHT * 1.5f)
	{
		s2 = s2.normalize() * PLAYER_HEIGHT * 1.5f;
	}

	// if cursor right of player
	if (m1 < 0)
	{
		m_forward.X = -1.0f;
		m_mirror.X = 1.0f;
	}

	// if cursor left of player
	if (m1 > 0)
	{
		m_forward.X = 1.0f;
		m_mirror.X = 0.0f;
	}

	// if game started
	if (start)
	{

		if (((int)CEngine::Get()->GetRenderer()->GetCamera().Y % (SCREEN_HEIGHT * (m_afterFifty - 2))) <= 0 &&
			((int)CEngine::Get()->GetRenderer()->GetCamera().Y % (SCREEN_HEIGHT * (m_afterFifty - 2))) >= -100)
		{
			GBackground::CreateWalls(m_backGround, m_afterFifty);
			if (m_backGround < 50)
				m_backGround++;
			m_afterFifty++;
			//CEngine::Get()->GetCM()->MoveBackground2Object();
		}

		float c = CEngine::Get()->GetRenderer()->GetCamera().Y;
		float o1 = bGround1_1->GetPosition().Y;
		float o2 = bGround2_1->GetPosition().Y;
		float o3 = bGround3_1->GetPosition().Y;
		float o4 = bGround4_1->GetPosition().Y;

		//LOG_ERROR("Position of Object:", o2);
		//LOG_ERROR("Position of Camera:", c);

		if (c - SCREEN_HEIGHT < o1)
		{
			GBackground::LoadBackground1(o1);
		}

		if (c - SCREEN_HEIGHT < o2)
		{
			GBackground::LoadBackground2(o2);
		}

		if (c - SCREEN_HEIGHT < o3)
		{
			GBackground::LoadBackground3(o3);
		}

		if (c - SCREEN_HEIGHT < o4)
		{
			GBackground::LoadBackground4(o4);
		}

		// if player is moveable
		if (moveable)
		{
			// movement left
			if (CInput::GetMouseDown(SDL_BUTTON_LEFT) && m1 > 0)
			{
				// calculate boost direction
				DirectionBoost(s2);

				// calculate angle
				double angle = atan2((double)m_boostDirection.X, (double)m_boostDirection.Y) * 180 / M_PI;

				// set jump enable, gravity false and set jump time
				m_fallTime = 0.001f;
				m_jump = true;
				m_jumpTime = PLAYER_JUMP_TIME;
				m_shotTime = PLAYER_JUMP_TIME - PLAYER_JUMP_TIME / 5;
				m_gravity = false;

				// spawn bullet
				GBullet* pBullet = new GBullet(m_position, m_boostDirection);
				pBullet->AddPosition(SVector2((m_boostDirection.X * (PLAYER_WIDTH)) + 30, (m_boostDirection.Y * 100) + 50));

				// set texture name of object
				pBullet->SetTextureName("Bullet");

				// set forward of object
				m_forward = m_boostDirection;

				// if texture not exists
				if (CEngine::Get()->GetTM()->GetTexture("Bullet") == nullptr)
				{
					// create new texture
					CTexture* pTexture = new CTexture("Texture/Character/Player/Rocket/Rocket.png", CEngine::Get()->GetRenderer());

					// add texture to tm
					CEngine::Get()->GetTM()->AddTexture("Bullet", pTexture);

					// set texture of object
					pBullet->SetTexture(pTexture);
					pBullet->SetAngle(-angle + 90);

					// create shot sound
					CSound* pSound = new CSound(GetAssetPath("Audio/S_Shot.wav", 4).c_str());

					// set shot sound of player
					pBullet->SetSound(pSound);
					pBullet->PlaySound();
				}

				// if texture exists set texture of object
				else
				{
					pBullet->SetTexture(CEngine::Get()->GetTM()->GetTexture("Bullet"));
					pBullet->SetAngle(-angle + 90);

					// create shot sound
					CSound* pSound = new CSound(GetAssetPath("Audio/S_Shot.wav", 4).c_str());

					// set shot sound of player
					pBullet->SetSound(pSound);
					pBullet->PlaySound();
				}

				// add to list
				CEngine::Get()->GetCM()->AddPersistantObject(pBullet);
			}

			// movement right
			else if (CInput::GetMouseDown(SDL_BUTTON_LEFT) && m1 < 0)
			{
				// calculate boost direction
				DirectionBoost(s2);

				// calculate angle
				double angle = atan2((double)m_boostDirection.X, (double)m_boostDirection.Y) * 180 / M_PI;

				// set jump enable, gravity false and set jump time
				m_fallTime = 0.001f;
				m_jump = true;
				m_jumpTime = PLAYER_JUMP_TIME;
				m_shotTime = PLAYER_JUMP_TIME - PLAYER_JUMP_TIME / 5;
				m_gravity = false;

				// spawn bullet
				GBullet* pBullet = new GBullet(m_position, m_boostDirection);
				pBullet->AddPosition(SVector2((m_boostDirection.X * (PLAYER_WIDTH)) + 30, (m_boostDirection.Y * 100) + 50)); 
													
				// set texture name of object
				pBullet->SetTextureName("Bullet");

				// set forward of object
				m_forward = m_boostDirection;

				// if texture not exists
				if (CEngine::Get()->GetTM()->GetTexture("Bullet") == nullptr)
				{
					// create new texture
					CTexture* pTexture = new CTexture("Texture/Bullet/Rakete.png", CEngine::Get()->GetRenderer());

					// add texture to tm
					CEngine::Get()->GetTM()->AddTexture("Bullet", pTexture);

					// set texture of object
					pBullet->SetTexture(pTexture);
					pBullet->SetAngle(-angle + 90);

					// create shot sound
					CSound* pSound = new CSound(GetAssetPath("Audio/S_Shot.wav", 4).c_str());

					// set shot sound of player
					pBullet->SetSound(pSound);
					pBullet->PlaySound();
				}

				// if texture exists set texture of object
				else
				{
					pBullet->SetTexture(CEngine::Get()->GetTM()->GetTexture("Bullet"));
					pBullet->SetAngle(-angle + 90);

					// create shot sound
					CSound* pSound = new CSound(GetAssetPath("Audio/S_Shot.wav", 4).c_str());

					// set shot sound of player
					pBullet->SetSound(pSound);
					pBullet->PlaySound();
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
				float tmp_x = m_boostDirection.X * PLAYER_JUMP_FORCE * _deltaTime;
				nextPos.X -= tmp_x;
				float tmp_y = m_boostDirection.Y * PLAYER_JUMP_FORCE * _deltaTime;
				nextPos.Y -= tmp_y;

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
					if (((CTexturedObject*)pObj)->GetTag() == "Bullet")
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
					m_position.X -= tmp_x;
					m_position.Y -= tmp_y;
					m_rect.x = m_position.X;
					m_rect.y = m_position.Y;
				}
			}
		}
		
		if (CEngine::Get()->GetCM()->GetBackground2Object().size() >= 4)
		{
			bGround2_1 = CEngine::Get()->GetCM()->GetBackground2Object().back();
			CEngine::Get()->GetCM()->RemoveObject(bGround2_1);
		}
		
		if (CEngine::Get()->GetCM()->GetBackground3Object().size() >= 4)
		{
			bGround3_1 = CEngine::Get()->GetCM()->GetBackground3Object().back();
			CEngine::Get()->GetCM()->RemoveObject(bGround3_1);
		}
		
		if (CEngine::Get()->GetCM()->GetBackground4Object().size() >= 4)
		{
			bGround4_1 = CEngine::Get()->GetCM()->GetBackground4Object().back();
			CEngine::Get()->GetCM()->RemoveObject(bGround4_1);
		}

	}

	if (m_pCurrentAnim)
	{
		// update animation
		m_pCurrentAnim->Update(_deltaTime);

		// set source from animation
		m_srcRect = SRect(
			m_pCurrentAnim->GetCurrentTexturePosition().X,
			m_pCurrentAnim->GetCurrentTexturePosition().Y,
			m_pCurrentAnim->GetSize().X,
			m_pCurrentAnim->GetSize().Y
		);
	}

	if (!saved)
	{
		savedXPos = m_position.X + PLAYER_WIDTH / 2;
		saved = true;
	}

	// set position of camera
	CEngine::Get()->GetRenderer()->SetCamera(
		SVector2(savedXPos, m_position.Y - PLAYER_HEIGHT)
	);

	//LOG_ERROR("m1", m1);

	// set animation
	// player can control
	if (moveable)
	{
		// mouse is on the right side of the player
		if (m1 >= 0)
		{
			// player is falling
			if (m_gravity)
				m_pCurrentAnim = m_pFallAnimRight;

			// player is rising
			else
				m_pCurrentAnim = m_pFlyAnimRight;
		}

		// mouse is on the left side of the player
		else
		{
			// player is falling
			if (m_gravity)
				m_pCurrentAnim = m_pFallAnimLeft;

			// player is rising
			else
				m_pCurrentAnim = m_pFlyAnimLeft;
		}
	}

	// player collided with object
	else
	{
		m_mirror = SVector2();
		m_pCurrentAnim = m_pDeathAnim;
		CEngine::Get()->ChangeScene(new GMenuScene());
	}
	// if player is lower than allowed
	if (m_position.Y >= -400)
		moveable = false;

	// if debug mode is active
	if (DEBUG_ON)
		moveable = true;

	// calculate differenz between last position and current position of Player
	diff = lastPosition.Y - GetPosition().Y;

	// move backgrounds
	for (CObject* pObj : CEngine::Get()->GetCM()->GetBackground1Object())
	{
		pObj->AddPosition(SVector2(0, (diff / 1.125f) * -1));
	}

	for (CObject* pObj : CEngine::Get()->GetCM()->GetBackground2Object())
	{
		pObj->AddPosition(SVector2(0, (diff / 1.25f) * -1));
	}

	for (CObject* pObj : CEngine::Get()->GetCM()->GetBackground3Object())
	{
		pObj->AddPosition(SVector2(0, (diff / 1.5f) * -1));
	}

	for (CObject* pObj : CEngine::Get()->GetCM()->GetBackground4Object())
	{
		pObj->AddPosition(SVector2(0, (diff / 2) * -1));
	}

	// get current position of Player
	lastPosition = GetPosition();

	// print player position
	std::string s = "Position: ";
	s += std::to_string(s2.X) + " " + std::to_string(s2.Y) + "\n";
	s += std::to_string(m_boostDirection.X) + " " + std::to_string(m_boostDirection.Y) + "\n";
	//LOG_ERROR("", s.c_str());
	//LOG_ERROR("Player.Y", m_position.Y);
	LOG_ERROR("high score", m_maxYCoordinate);

	// save high score
	if ((((-(m_position.Y)) + START_POITION) > m_maxYCoordinate) || start == false)
	{
		m_maxYCoordinate = (-(m_position.Y)) - 500;
		m_currentScore = m_maxYCoordinate / 50;
	}

	// death if position lower then player position
	if (diff <= -25)
		moveable = false;

	// save score
	if ((m_currentScore > GScore::GetScoreFromFile()))
	{
		GScore::SetScoreToFile(m_currentScore);
	}

}
// render every frame
void GPlayer::Render(CRenderer * _pRenderer)
{
	CMoveObject::Render(_pRenderer);
}
#pragma endregion

#pragma region public function
// initialize player and score
void GPlayer::Init()
{
	// create fall animation (left)
	m_pFallAnimLeft = new CAnimation
	(
		SVector2(),
		SVector2(PLAYER_SRC_RECT_WIDTH, PLAYER_SRC_RECT_HEIGHT),
		3
	);
	m_pFallAnimLeft->SetAnimationTime(0.5f);
	
	// create fall animation (right)
	m_pFallAnimRight = new CAnimation
	(
		SVector2(0.0f, PLAYER_SRC_RECT_HEIGHT),
		SVector2(PLAYER_SRC_RECT_WIDTH, PLAYER_SRC_RECT_HEIGHT),
		3
	);
	m_pFallAnimRight->SetAnimationTime(0.5f);

	// create fly animation (left)
	m_pFlyAnimLeft = new CAnimation
	(
		SVector2(0.0f, PLAYER_SRC_RECT_HEIGHT * 2),
		SVector2(PLAYER_SRC_RECT_WIDTH, PLAYER_SRC_RECT_HEIGHT),
		3
	);
	m_pFlyAnimLeft->SetAnimationTime(0.5f);

	// create fly animation (right)
	m_pFlyAnimRight = new CAnimation
	(
		SVector2(0.0f, PLAYER_SRC_RECT_HEIGHT * 3),
		SVector2(PLAYER_SRC_RECT_WIDTH, PLAYER_SRC_RECT_HEIGHT),
		3
	);
	m_pFlyAnimRight->SetAnimationTime(0.5f);

	// create idle animation
	m_pIdleAnim = new CAnimation
	(
		SVector2(0.0f, PLAYER_SRC_RECT_HEIGHT * 4),
		SVector2(PLAYER_SRC_RECT_WIDTH, PLAYER_SRC_RECT_HEIGHT),
		3
	);
	m_pIdleAnim->SetAnimationTime(0.5f);

	// create death animation
	m_pDeathAnim = new CAnimation
	(
		SVector2(0.0f, PLAYER_SRC_RECT_HEIGHT * 5),
		SVector2(PLAYER_SRC_RECT_HEIGHT, PLAYER_SRC_RECT_WIDTH),
		1
	);
	m_pDeathAnim->SetAnimationTime(0.5f);
}
#pragma endregion
