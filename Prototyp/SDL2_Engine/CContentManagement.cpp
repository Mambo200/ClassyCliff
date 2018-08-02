#pragma region project include
#include "ContentManagement.h"
#include "MoveObject.h"
#include "Macro.h"
#include "Background.h"
#pragma endregion

#pragma region constructor
// destructor
CContentManagement::~CContentManagement()
{
	// as long as there is a object in list delete first element
	while (m_pBackground1.size() > 0)
		m_pBackground1.pop_front();

	// as long as there is a object in list delete first element
	while (m_pBackground2.size() > 0)
		m_pBackground1.pop_front();

	// as long as there is a object in list delete first element
	while (m_pBackground3.size() > 0)
		m_pBackground1.pop_front();

	// as long as there is a object in list delete first element
	while (m_pBackground4.size() > 0)
		m_pBackground1.pop_front();

	// as long as there is a object in list delete first element
	while (m_pSceneObjects.size() > 0)
		m_pSceneObjects.pop_front();

	// as long as there is a object in list delete first element
	while (m_pPersistantObjects.size() > 0)
		m_pPersistantObjects.pop_front();

	// as long as there is a object in list delete first element
	while (m_pUIObjects.size() > 0)
		m_pUIObjects.pop_front();

	while (m_pBackgroundObjects.size() > 0)
		m_pBackgroundObjects.pop_front();
}
#pragma endregion

#pragma region public function
//inline void CContentManagement::MoveBackground2Object()
//{
//	for (CObject* pObj : m_pBackground2)
//		pObj->SetPosition(pObj->GetPosition() + SVector2(0, 1));
//}
// update every frame
void CContentManagement::Update(float _deltaTime)
{
	//update every background object
	for (CObject* pObj : m_pBackground1)
		pObj->Update(_deltaTime);
		
	// update every scene object
	for each (CObject* pObj in m_pSceneObjects)
		pObj->Update(_deltaTime);

	// update every persistant object
	for (CObject* pObj : m_pPersistantObjects)
		pObj->Update(_deltaTime);

	// update every ui object
	for (CObject* pObj : m_pUIObjects)
		pObj->Update(_deltaTime);



	// remove object in remove list
	while (m_pRemoveObjects.size() > 0)
	{
		// get first object in remove list
		CObject* pObj = m_pRemoveObjects.front();

		// remove pointer from background list
		m_pBackgroundObjects.remove(pObj);

		// remove pointer from scene list
		m_pSceneObjects.remove(pObj);

		// remove pointer from persistant list
		m_pPersistantObjects.remove(pObj);

		// remove pointer from ui list
		m_pUIObjects.remove(pObj);

		// remove pointer from move list
		if((CMoveObject*)pObj)
			m_pMoveObjects.remove((CMoveObject*)pObj);

		// delete first object in list
		m_pRemoveObjects.pop_front();
	}

	// decrease collision check timer
	m_collisionTimer -= _deltaTime;

	// if collision timer under 0
	if (m_collisionTimer <= 0.0f && m_pMoveObjects.size() > 0)
	{
		// check collision of first move object
		m_pMoveObjects.front()->CheckCollisionObjects();

		// save reference of first move object
		CMoveObject* pObj = m_pMoveObjects.front();

		// remove object from list
		m_pMoveObjects.remove(pObj);

		// add object at end of list
		m_pMoveObjects.push_back(pObj);

		// reset
		m_collisionTimer = COLLISION_CHECK_TIMER / m_pMoveObjects.size();
	}
}

// render every frame
void CContentManagement::Render(CRenderer * _pRenderer)
{
	// render every background1 object
	for (CObject* pObj : m_pBackground1)
		pObj->Render(_pRenderer);

	// render every background1 object
	for (CObject* pObj : m_pBackground2)
		pObj->Render(_pRenderer);

	// render every background1 object
	for (CObject* pObj : m_pBackground3)
		pObj->Render(_pRenderer);

	// render every background1 object
	for (CObject* pObj : m_pBackground4)
		pObj->Render(_pRenderer);

	// render every scene object
	for each (CObject* pObj in m_pSceneObjects)
		pObj->Render(_pRenderer);

	// render every persistant object
	for (CObject* pObj : m_pPersistantObjects)
		pObj->Render(_pRenderer);

	// render every ui object
	for (CObject* pObj : m_pUIObjects)
		pObj->Render(_pRenderer);
}

// remove object
void CContentManagement::RemoveObject(CObject * _pObj)
{
	// add object to remove list
	m_pRemoveObjects.push_front(_pObj);
}

void CContentManagement::SortList(list<CObject*>& _pList)
{

}

#pragma endregion

#pragma region private function
// add object to list
void CContentManagement::AddObject(CObject * _pObj, list<CObject*>& _pList)
{
	// add object to list
	_pList.push_front(_pObj);

	// if object is a moveable object add to list
	if (dynamic_cast<CMoveObject*>(_pObj))
		m_pMoveObjects.push_front((CMoveObject*)_pObj);

	// sort list
	SortList(_pList);
}
#pragma endregion