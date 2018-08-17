#pragma once

#pragma region project include
#include "Text.h"
#include "Player.h"
#include "Score.h"
#pragma endregion

class GTextHighScore : public CText
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
	GTextHighScore(const char* _pText, CFont* _pFont, SRect _rect = SRect(), SColor _color = SColor())
	: CText(_pText, _pFont, _rect, _color) {}

	/// <summary>
	/// destructor
	/// </summary>
	~GTextHighScore() {}
#pragma endregion


#pragma region public override function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	void Update(float _deltaTime) override
	{
		// text to show
		string text = "HighScore: ";

		// append highscore value
		text.append(to_string(GScore::GetScoreFromFile()));

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