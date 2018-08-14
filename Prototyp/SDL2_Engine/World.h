#pragma once

/// <summary>
/// world class
/// </summary>
class GWorld
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	GWorld() {}
	
	/// <summary>
	/// destructor
	/// </summary>
	~GWorld() {}
#pragma endregion

#pragma region public function
	/// <summary>
	/// initialize world
	/// </summary>
	void Init();

	
	void FlyAnimationRight();
	void FlyAnimationLeft();
	void FallAnimationRight();
	void FallAnimationLeft();
#pragma endregion
};