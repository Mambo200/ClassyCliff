#pragma once

#pragma region project include
#include "Helper.h"
#pragma endregion

/// <summary>
/// score class
/// </summary>
class GScore
{
public:
#pragma region public function
	/// <summary>
	/// set Score
	/// </summary>
	/// <param name="_score"></param>
	static void SetScoreToFile(int _score);

	/// <summary>
	/// get Score
	/// </summary>
	/// <returns>Score</returns>
	static int GetScoreFromFile();
#pragma endregion

private:
#pragma region private variable
	static int m_score;
#pragma endregion
};