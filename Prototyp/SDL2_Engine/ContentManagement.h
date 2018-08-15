#pragma once

#pragma region system include
#include <list>
#pragma endregion

#pragma region forward decleration
class CRenderer;
class CObject;
class CMoveObject;
#pragma endregion

#pragma region using
using namespace std;
#pragma endregion

/// <summary>
/// content management system
/// </summary>
class CContentManagement
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CContentManagement() {}

	/// <summary>
	/// destructor
	/// </summary>
	~CContentManagement();
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// add object to background list
	/// </summary>
	/// <param name="_pObject">object to add</param>
	inline void AddBackgroundObject(CObject* _pObject) { AddObject(_pObject, m_pBackgroundObjects); }

	/// <summary>
	/// get background object list
	/// </summary>
	/// <returns>list of all background object</returns>
	inline list<CObject*> GetBackgroundObjects() { return m_pBackgroundObjects; }

	/// <summary>
	/// add object to scene list
	/// </summary>
	/// <param name="_pObject">object to add</param>
	inline void AddSceneObject(CObject* _pObject) { AddObject(_pObject, m_pSceneObjects); }

	/// <summary>
	/// get scene objects list
	/// </summary>
	/// <returns>list of all scene object</returns>
	inline list<CObject*> GetSceneObjects() { return m_pSceneObjects; }

	/// <summary>
	/// add object to persitant list
	/// </summary>
	/// <param name="_pObject">object to add</param>
	inline void AddPersistantObject(CObject* _pObject) { AddObject(_pObject, m_pPersistantObjects); }

	/// <summary>
	/// get persistant objects list
	/// </summary>
	/// <returns>list of all persistant object</returns>
	inline list<CObject*> GetPersistantObjects() { return m_pPersistantObjects; }

	/// <summary>
	/// add object to ui list
	/// </summary>
	/// <param name="_pObject">object to add</param>
	inline void AddUIObject(CObject* _pObject) { AddObject(_pObject, m_pUIObjects); }

	/// <summary>
	/// get ui objects list
	/// </summary>
	/// <returns>list of all ui object</returns>
	inline list<CObject*> GetUIObjects() { return m_pUIObjects; }

	/// <summary>
	/// add object to background list
	/// </summary>
	/// <param name="_pObject">object to add</param>
	inline void AddWallObject(CObject* _pObject) { AddObject(_pObject, m_pWallObjects); }

	/// <summary>
	/// get background object list
	/// </summary>
	/// <returns>list of all background object</returns>
	inline list<CObject*> GetWallObjects() { return m_pWallObjects; }

	/// <summary>
	/// add object to background list
	/// </summary>
	/// <param name="_pObject">object to add</param>
	inline void AddBrancheObject(CObject* _pObject) { AddObject(_pObject, m_pBrancheObjects); }

	/// <summary>
	/// get background object list
	/// </summary>
	/// <returns>list of all background object</returns>
	inline list<CObject*> GetBrancheObjects() { return m_pBrancheObjects; }

	inline void AddBackground1Object(CObject* _pObject) { AddObject(_pObject, m_pBackground1); }
	inline list<CObject*> GetBackground1Object() { return m_pBackground1; }

	inline void AddBackground2Object(CObject* _pObject) { AddObject(_pObject, m_pBackground2); }
	inline list<CObject*> GetBackground2Object() { return m_pBackground2; }
	//inline void MoveBackground2Object();

	inline void AddBackground3Object(CObject* _pObject) { AddObject(_pObject, m_pBackground3); }
	inline list<CObject*> GetBackground3Object() { return m_pBackground3; }

	inline void AddBackground4Object(CObject* _pObject) { AddObject(_pObject, m_pBackground4); }
	inline list<CObject*> GetBackground4Object() { return m_pBackground4; }

#pragma endregion

#pragma region public function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime);

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	void Render(CRenderer* _pRenderer);

	/// <summary>
	/// remove object
	/// </summary>
	/// <param name="_pObj">object to remove</param>
	void RemoveObject(CObject* _pObj);

	/// <summary>
	/// clean all scene objects
	/// </summary>
	void CleanScene();

	/// <summary>
	/// clean all ui objects
	/// </summary>
	void CleanUI();

	/// <summary>
	/// clean all persistant objects
	/// </summary>
	void CleanPersistantObjects();

	/// <summary>
	/// clean all background objects
	/// </summary>
	void CleanBackgroundObjects();

	/// <summary>
	/// sort list for layering
	/// </summary>
	/// <param name="_pList">list to sort</param>
	void SortList(list<CObject*> &_pList);
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// background list
	/// </summary>
	list<CObject*> m_pBackgroundObjects;

	/// <summary>
	/// scene / world objects
	/// </summary>
	list<CObject*> m_pSceneObjects;

	/// <summary>
	/// persistant object
	/// </summary>
	list<CObject*> m_pPersistantObjects;

	/// <summary>
	/// ui / screen object
	/// </summary>
	list<CObject*> m_pUIObjects;

	/// <summary>
	/// objects to remove
	/// </summary>
	list<CObject*> m_pRemoveObjects;

	/// <summary>
	/// list of all moveable objects exept background
	/// </summary>
	list<CMoveObject*> m_pMoveObjects;

	/// <summary>
	/// list of all background 1 objects
	/// </summary>
	list<CObject*> m_pBackground1;

	/// <summary>
	/// list of all background 2 objects
	/// </summary>
	list<CObject*> m_pBackground2;

	/// <summary>
	/// list of all background 3 objects
	/// </summary>
	list<CObject*> m_pBackground3;

	/// <summary>
	/// list of all background 4 objects
	/// </summary>
	list<CObject*> m_pBackground4;

	/// <summary>
	/// list of all Wall objects
	/// </summary>
	list<CObject*> m_pWallObjects;

	/// <summary>
	/// list of all Branch objects
	/// </summary>
	list<CObject*> m_pBrancheObjects;
#pragma endregion

#pragma region private function
	/// <summary>
	/// add object to list
	/// </summary>
	/// <param name="_pObj">object</param>
	/// <param name="_pList">list to add to</param>
	void AddObject(CObject* _pObj, list<CObject*> &_pList);
#pragma endregion

#pragma region private primitive variable
	/// <summary>
	/// time to check collision for move objects
	/// </summary>
	float m_collisionTimer;
#pragma endregion
};