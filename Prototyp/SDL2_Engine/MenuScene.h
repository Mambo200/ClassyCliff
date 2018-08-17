#pragma once

#pragma region project include
#include "Scene.h"  
#pragma endregion

class CMusic;

/// <summary>
/// menu scene class
/// </summary>
class GMenuScene : public CScene
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	GMenuScene() {}

	/// <summary>
	/// destructor
	/// </summary>
	~GMenuScene() {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// initialize scene
	/// </summary>
	virtual void Init() override;

	/// <summary>
	/// cleaning up scene
	/// </summary>
	virtual void Clean() override;
#pragma endregion

private:
#pragma region private variable
	/// <summary>
	/// background music
	/// </summary>
	CMusic* m_pBackgroundMusic;
#pragma endregion

};