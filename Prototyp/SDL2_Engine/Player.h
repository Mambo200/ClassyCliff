#pragma once

#pragma region project include
#include "MoveObject.h"  
#include "Macro.h"
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
	~GPlayer() {}
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

#pragma region help function
	/// <summary>
	/// set position of helper position
	/// </summary>
	/// <param name="_pos">position to set</param>
	static void SetHelpPosition(SVector2 _pos) { m_helperPosition = _pos; }

	/// <summary>
	/// add position of helper position
	/// </summary>
	/// <param name="_pos">position to add</param>
	void AddHelpPosition(SVector2 _pos) { m_helperPosition = m_helperPosition + _pos; }

	/// <summary>
	/// calculate boostpower
	/// </summary>
	void DirectionBoost(SVector2 _posMouse, SVector2 _posPlayer)
	{
		// reset boost direction
		m_boostDirection = SVector2(0, 0);

		// helper for calculation
		float one_percent = 0.0f;
		float tmp = PLAYER_HEIGHT * 1.5;
		int tmp_x;
		SVector2 correctur_percent_power = SVector2(0, 0);
		bool x_positiv;
		bool y_positiv;
		float boostPower = 0.0f;

		// if mouse is left from player
		if (_posMouse.X <= _posPlayer.X)
			tmp_x = _posPlayer.X - _posMouse.X;

		// if mouse is right from player
		else if (_posMouse.X >= _posPlayer.X)
			tmp_x = _posMouse.X - _posPlayer.X;

		//if mouseposition is too far left from player, set max value for x-achse of mouse
		if (tmp_x < tmp * -1)
			_posMouse.X = tmp * -1;

		//if mouseposition is too far right from player, set max value for x-achse of mouse
		if (tmp_x > tmp)
			_posMouse.X = tmp;

		// calculate 1% of the relative position of mouse for y-achse
		one_percent = tmp / 100;

		// set y of boostDirection in %
		m_boostDirection.Y = ((_posMouse.Y / one_percent) / 100);

		// set x of boostDirection in %
		if (m_boostDirection.X > -0.9999999)
			m_boostDirection.X = (_posMouse.X / one_percent) / 100;
		else if (tmp_x < tmp * -1)
			m_boostDirection.X = -1.0f;

		// make -boost to +boost in correctur_boost_power
		if (m_boostDirection.X <= 0)
		{
			correctur_percent_power.X = m_boostDirection.X * -1;
			x_positiv = false;
		}
		else
		{
			correctur_percent_power.X = m_boostDirection.X;
			x_positiv = true;
		}
		if (m_boostDirection.Y <= 0)
		{
			correctur_percent_power.Y = m_boostDirection.Y * -1;
			y_positiv = false;
		}
		else
		{
			correctur_percent_power.Y = m_boostDirection.Y;
			y_positiv = true;
		}

		// calculate boost power
		boostPower = correctur_percent_power.X + correctur_percent_power.Y;

		// if boost > 100% correctur to 100%
		if (boostPower >= 1)
		{
			if (x_positiv)
				m_boostDirection.X -= (boostPower - 1) / 2;
			else
				m_boostDirection.X += (boostPower - 1) / 2;
			if (y_positiv)
				m_boostDirection.Y -= (boostPower - 1) / 2;
			else
				m_boostDirection.Y += (boostPower - 1) / 2;
		}

		else if (boostPower <= 1)
		{
			if (x_positiv)
				m_boostDirection.X += (boostPower - 1) / 2;
			else
				m_boostDirection.X -= (boostPower - 1) / 2;
			if (y_positiv)
				m_boostDirection.Y += (boostPower - 1) / 2;
			else
				m_boostDirection.Y -= (boostPower - 1) / 2;
		}
	}
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
	/// helper position for calculating the relativ position of mouse to player
	/// </summary>
	static SVector2 m_helperPosition;

	/// <summary>
	/// boost direction
	/// </summary>
	SVector2 m_boostDirection = SVector2(0.0f, 0.0f);
#pragma endregion
};