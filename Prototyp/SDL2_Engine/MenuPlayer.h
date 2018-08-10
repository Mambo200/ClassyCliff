#pragma once

#pragma region project include
#include "Object.h"
#include "Text.h"
#pragma endregion

/// <summary>
/// menu player class
/// </summary>
class GMenuPlayer : public CObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	GMenuPlayer();

	/// <summary>
	/// destructor
	/// </summary>
	~GMenuPlayer();
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	void Render(CRenderer* _pRenderer) override;
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// start text is active
	/// </summary>
	bool m_startActive = true;
#pragma endregion

#pragma region private variable
	/// <summary>
	/// start text
	/// </summary>
	CText* m_pStartText;

	/// <summary>
	/// end text
	/// </summary>
	CText* m_pEndText;
#pragma endregion
};