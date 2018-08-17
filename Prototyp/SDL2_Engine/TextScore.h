#pragma once

#pragma region project include
#include "Text.h"
#include "Player.h"
#pragma endregion

class GTextScore : public CText
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pText">text value</param>
	/// <param name="_pFont">font</param>
	/// <param name="_rect">rect</param>
	/// <param name="_color">color</param>
	GTextScore(const char* _pText, CFont* _pFont, SRect _rect = SRect(), SColor _color = SColor())
		: CText(_pText, _pFont, _rect, _color) {}

	/// <summary>
	/// destructor
	/// </summary>
	~GTextScore() {}
#pragma endregion

#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override
	{
		// text to show
		string text = "Score: ";

		// append fps value
		text.append(to_string(GPlayer::GetCurrentScore()));

		// random color
		SColor color = SColor(
			0,
			0,
			0,
			0
		);
		// set color
		SetColor(color);

		// set text
		SetText(text.c_str());
	}

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	void Render(CRenderer* _pRenderer) override { CText::Render(_pRenderer); }
#pragma endregion

};