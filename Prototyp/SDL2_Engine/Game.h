#pragma once

#pragma region forward decleration
class CFont;
#pragma endregion

/// <summary>
/// core game class for game logic
/// </summary>
class GGame
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	GGame() {}

	/// <summary>
	/// destructor
	/// </summary>
	~GGame() { Clean(); }
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get game
	/// </summary>
	/// <returns>game</returns>
	inline static GGame* Get()
	{
		// create game if not exists
		static GGame* pGame = new GGame();

		// return game
		return pGame;
	}
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize game
	/// </summary>
	void Init();

	/// <summary>
	/// clean game
	/// </summary>
	void Clean();
#pragma endregion

#pragma region public variable
	/// <summary>
	/// base arial font
	/// </summary>
	CFont* m_PArialFont = nullptr;
#pragma endregion
};