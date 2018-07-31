#pragma region project include
#include "MoveObject.h"
#include "Engine.h"
#include "ContentManagement.h"
#include "Physic.h"
#include "Renderer.h"
#include "Macro.h" ///TODO DELETE
#pragma endregion

#pragma region public override function
// update every frame
void CMoveObject::Update(float _deltaTime)
{
	// next position
	SVector2 nextPos = m_position + m_movement * m_speed * _deltaTime;

	// next rect
	SRect nextRect = m_rect;
	nextRect.x = nextPos.X;
	nextRect.y = nextPos.Y;

	// through all scene objects
	for (CObject* pObj : CEngine::Get()->GetCM()->GetSceneObjects())
	{
		// if current object is self continue
		if ((CMoveObject*)pObj && pObj == this)
			continue;

		// if collision type none
		if (((CTexturedObject*)pObj)->GetColType() == ECollisionType::NONE)
			continue;

		// set moveable by checking collision
		moveable = !(CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()));

		// if not moveable cancel collision check
		if (!moveable)
			break;
	}
	// throught all falling objects
	if (moveable)
	{
		for (CObject* pObj : CEngine::Get()->GetCM()->GetFallingObjects())
		{
			// if current object is self continue
			if ((CMoveObject*)pObj && pObj == this)
				continue;

			// if object is near Sceenspace set moveableObject true
			if (((CMoveObject*)pObj)->GetPosition().Y >= (CEngine::Get()->GetRenderer()->GetCamera().Y) - SCREEN_HEIGHT /*- 50*/)
			{
				SVector2 tmp = ((CMoveObject*)pObj)->GetPosition();
				float tmp2 = CEngine::Get()->GetRenderer()->GetCamera().Y;
				pObj->SetMoveableObject(true);
			}

			// set moveable by checking collision
			moveable = !(CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()));

			// if not moveable cancel collision check
			if (!moveable)
				break;

			//// if object out of Screen add to RemoveList
			//if (((CMoveObject*)pObj)->GetPosition().Y >= (CEngine::Get()->GetRenderer()->GetCamera().Y) + SCREEN_HEIGHT + 50)
			//	CEngine::Get()->GetCM()->RemoveObject(pObj);
		}
	}

	// if moveable
	if (moveable)
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
			moveable = !(CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect()));

			// if not moveable cancel collision check
			if (!moveable)
				break;
		}
	}

	// if moveable
	if (moveable)
	{
		// add position by movement * speed
		m_position = nextPos;

		// set position of rect
		m_rect.x = m_position.X;
		m_rect.y = m_position.Y;
	}

	// if no gravity return
	if (!m_gravity)
		return;

	// set next rect down
	nextRect = m_rect;

	// set y value
	nextRect.y += GRAVITY_VALUE * m_fallTime * m_fallTime + 1;

	// through all scene objects
	if (moveable)
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
			moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

			// if not moveable cancel collision check
			if (!moveable)
				break;
		}

		// if moveable
		if (moveable)
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
				moveable = !CPhysic::RectRectCollision(nextRect, ((CTexturedObject*)pObj)->GetRect());

				// if not moveable cancel collision check
				if (!moveable)
					break;
			}
		}
	}
/*
	// if not moveable return
	if (!moveable)
		return;

	// add position by movement * speed
	m_position = nextPos;

	// set position of rect
	m_rect.x = m_position.X;
	m_rect.y = m_position.Y;
*/
// if still moveable set y position
	if (moveable)
	{
		m_position.Y += GRAVITY_VALUE * m_fallTime * m_fallTime;
		m_rect.y = m_position.Y;
		m_grounded = false;
		m_fallTime += _deltaTime;
	}

	// gravity active and not moveable
	else
	{
		m_fallTime = 0.001f;
		m_grounded = true;
	}
}

// render every frame
void CMoveObject::Render(CRenderer * _pRenderer)
{
	CTexturedObject::Render(_pRenderer);
}
#pragma endregion