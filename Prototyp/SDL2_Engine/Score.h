#pragma once

class GScore
{
public:
	GScore();
	~GScore();

#pragma region public function
	/// <summary>
	/// set Score
	/// </summary>
	/// <param name="_score"></param>
	void SetScore(int _score) { m_score += _score; }

	/// <summary>
	/// get Score
	/// </summary>
	/// <returns>Score</returns>
	int GetScore() { return m_score; }
#pragma endregion

private:
#pragma region private variable
	int m_score = 0;
#pragma endregion
};
