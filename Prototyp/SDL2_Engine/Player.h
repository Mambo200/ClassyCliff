#pragma once

#pragma region project include
#include "MoveObject.h"  
#include "Macro.h"
#pragma endregion

#pragma region forward declaration
class CSound;
class CAnimation;
#pragma endregion

/// <summary>
/// player class
/// </summary>
class GPlayer :	public CMoveObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	GPlayer(SVector2 _pos) : CMoveObject(_pos) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	GPlayer(SVector2 _pos, SVector2 _size) : CMoveObject(_pos, _size) {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	/// <param name="_size">width and height of rect</param>
	/// <param name="_pRenderer">renderer</param>
	/// <param name="_pFileName">file path name (relative)</param>
	GPlayer(SVector2 _pos, SVector2 _size, CRenderer* _pRenderer,
		const char* _pFileName) : CMoveObject(_pos, _size, _pRenderer, _pFileName) {}

	/// <summary>
	/// destructor
	/// </summary>
	~GPlayer() 
	{
		// delete animation
		delete m_pFlyAnim;
		delete m_pDeathAnim;
	}
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
	/// <param name="_pRenderer"></param>
	void Render(CRenderer* _pRenderer) override;
#pragma endregion

	/// <summary>
	/// calculate boostpower
	/// </summary>
	/// <param name="_pos">position of mouse</param>
	/// <param name="_pos">position of m_helperPosition</param>
	void DirectionBoost(SVector2 _posMouse)
	{
		// reset boost direction
		m_boostDirection = SVector2(0, 0);

		// helper for calculation
		float one_percent = 0.0f;
		float tmp = PLAYER_HEIGHT * 1.5;
		SVector2 correctur_percent_power = SVector2(0, 0);
		bool x_positiv;
		bool y_positiv;
		float boostPower = 0.0f;

		// calculate 1% of the relative position of mouse for y-achse
		one_percent = tmp / 100;

		// set y of boostDirection in %
		m_boostDirection.Y = ((_posMouse.Y / one_percent) / 100);

		// set x of boostDirection in %
		if (m_boostDirection.X > -0.9999999)
			m_boostDirection.X = (_posMouse.X / one_percent) / 100;
		else if (_posMouse.X < tmp * -1)
			m_boostDirection.X = -1.0f;

		// calculate boost power
		boostPower = correctur_percent_power.X + correctur_percent_power.Y;
	}

	// get direction of boost
	SVector2 GetBoostDirection() { return m_boostDirection; }
#pragma endregion

#pragma region public inline function

	/// <summary>
	/// initialize player
	/// </summary>
	void Init();
#pragma endregion


private:
#pragma region private primitive variable
	/// <summary>
	/// is jump active
	/// </summary>
	bool m_jump;

	/// <summary>
	/// time till jump ends
	/// </summary>
	float m_jumpTime;

	/// <summary>
	/// save first x position of camera
	/// </summary>
	float savedXPos;

	/// <summary>
	/// time since Player can shot again
	/// </summary>
	float m_shotTime = 0.0f;

	/// <summary>
	/// x position of camera saved
	/// </summary>
	bool saved = false;

	/// <summary>
	/// game start
	/// </summary>
	bool start = false;

	/// <summary>
	/// boost direction
	/// </summary>
	SVector2 m_boostDirection = SVector2(0.0f, 0.0f);

	int m_backGround = PRERENDER;
	int m_afterFifty = PRERENDER;

#pragma region private variable
	/// <summary>
	/// shot sound
	/// </summary>
	CSound* m_pShotSound;

	/// <summary>
	/// current animation
	/// </summary>
	CAnimation* m_pCurrentAnim;

	/// <summary>
	/// fly animation
	/// </summary>
	CAnimation* m_pFlyAnim;
	
	/// <summary>
	/// death animation
	/// </summary>
	CAnimation* m_pDeathAnim;
#pragma endregion

#pragma endregion
};