#pragma once

#pragma region project include
#include "Macro.h"
#pragma endregion

#pragma region forward decleration
class SDL_Window;
class SDL_Surface;
class CRenderer;
class CScene;
class CContentManagement;
class CTime;
class CTextureManagement;
class GPlayer;
#pragma endregion

/// <summary>
/// core engine class
/// </summary>
class CEngine
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CEngine();

	/// <summary>
	/// destructor
	/// </summary>
	~CEngine();
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get engine
	/// </summary>
	/// <returns>engine</returns>
	inline static CEngine* Get()
	{
		// create engine if not exists
		static CEngine* pEngine = new CEngine();

		// return engine
		return pEngine;
	}

	/// <summary>
	/// exit engine
	/// </summary>
	inline void Exit() { m_isRunning = false; }

	/// <summary>
	/// get sdl surface
	/// </summary>
	/// <returns>sdl surface</returns>
	inline SDL_Surface* GetSDLSurface() { return m_pSurface; }

	/// <summary>
	/// get renderer
	/// </summary>
	/// <returns>renderer</returns>
	inline CRenderer* GetRenderer() { return m_pRenderer; }

	/// <summary>
	/// get content management system
	/// </summary>
	/// <returns>content management</returns>
	inline CContentManagement* GetCM() { return m_pCM; }

	/// <summary>
	/// get texture management system
	/// </summary>
	/// <returns>texture management</returns>
	inline CTextureManagement* GetTM() { return m_pTM; }

	/// <summary>
	/// get time class
	/// </summary>
	/// <returns>time class</returns>
	inline CTime* GetTime() { return m_pTime; }

	/// <summary>
	/// get player class
	/// </summary>
	/// <returns>player class</returns>
	inline GPlayer* GetScore() { return m_pScore; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize engine
	/// </summary>
	/// <returns>if initialize successful</returns>
	bool Init();

	/// <summary>
	/// load images
	/// </summary>
	/// <returns>if images loaded successfully</returns>
	bool Load();

	/// <summary>
	/// running program
	/// </summary>
	void Run();

	/// <summary>
	/// clean up engine
	/// </summary>
	void Clean();

	/// <summary>
	/// change active scene
	/// </summary>
	/// <param name="_pScene">new scene</param>
	void ChangeScene(CScene* _pScene);
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// if engine is running
	/// </summary>
	bool m_isRunning;
#pragma endregion

#pragma region private variable
	/// <summary>
	/// window to render to
	/// </summary>
	SDL_Window* m_pWindow;

	/// <summary>
	///  surface from window
	/// </summary>
	SDL_Surface* m_pSurface;

	/// <summary>
	/// renderer to render images
	/// </summary>
	CRenderer* m_pRenderer;

	/// <summary>
	/// content management system
	/// </summary>
	CContentManagement* m_pCM;

	/// <summary>
	/// texture management system
	/// </summary>
	CTextureManagement* m_pTM;

	/// <summary>
	/// active scene
	/// </summary>
	CScene* m_pScene;

	/// <summary>
	/// time
	/// </summary>
	CTime* m_pTime;

	/// <summary>
	/// score
	/// </summary>
	GPlayer* m_pScore;
#pragma enregion

#pragma region private function
	/// <summary>
	/// update every frame
	/// </summary>
	void Update();

	/// <summary>
	/// render every frame
	/// </summary>
	void Render();
#pragma endregion
};