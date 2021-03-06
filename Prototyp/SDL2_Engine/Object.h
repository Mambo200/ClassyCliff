#pragma once

#pragma region project include
#include "Vector2.h"
#pragma endregion

#pragma region forward decleration
class CRenderer;
class CSound;
#pragma endregion

/// <summary>
/// base object class
/// </summary>
class CObject
{
public:
#pragma region constructor
	/// <summary>
	/// constructor
	/// </summary>
	CObject() {}

	/// <summary>
	/// constructor
	/// </summary>
	/// <param name="_pos">position of object</param>
	CObject(SVector2 _pos) : m_position(_pos) {}
#pragma endregion

#pragma region public inline function
	/// <summary>
	/// get position
	/// </summary>
	/// <returns>position</returns>
	inline SVector2 GetPosition() { return m_position; }

	/// <summary>
	/// set position
	/// </summary>
	/// <param name="_pos">position to set</param>
	inline void SetPosition(SVector2 _pos) { m_position = _pos; }

	/// <summary>
	/// add position
	/// </summary>
	/// <param name="_pos">position to add</param>
	inline void AddPosition(SVector2 _pos) { m_position = m_position + _pos; }

	/// <summary>
	/// get tag of object
	/// </summary>
	/// <returns>tag</returns>
	inline const char* GetTag() { return m_pTag; }

	/// <summary>
	/// set tag of object
	/// </summary>
	/// <param name="_pTag">tag to set</param>
	inline void SetTag(const char* _pTag) { m_pTag = _pTag; }

	/// <summary>
	/// set state of animation of object
	/// </summary>
	/// <param name="_bo">bool to set</param>
	inline void SetAnimated(bool _bo) { animated = _bo; }

	/// <summary>
	/// get state of animation of object
	/// </summary>
	/// <returns></returns>
	inline bool GetAnimated() { return animated; }

	/// <summary>
	/// set count of frames for animation of object
	/// </summary>
	/// <param name="_in">number of frames</param>
	inline void SetAnimatedFrames(int _in) { animated_frames = _in; }

	/// <summary>
	/// get count of frames for animation of object
	/// </summary>
	/// <returns></returns>
	inline int GetAnimatedFrames() { return animated_frames; }

	/// <summary>
	/// get layer
	/// </summary>
	/// <returns>layer</returns>
	inline int GetLayer() { return m_layer; }

	/// <summary>
	/// set layer
	/// </summary>
	/// <param name="_layer">layer to set</param>
	inline void SetLayer(int _layer) { m_layer = _layer; }

	/// <summary>
	/// set shot sound
	/// </summary>
	/// <param name="_pSound">sound to set</param>
	inline void SetSound(CSound* _pSound) { m_pSound = _pSound; }
#pragma endregion

#pragma region public function
	/// <summary>
	/// update every frame
	/// </summary>
	/// <param name="_deltaTime">time since last frame</param>
	virtual void Update(float _deltaTime) = 0;

	/// <summary>
	/// render every frame
	/// </summary>
	/// <param name="_pRenderer">renderer</param>
	virtual void Render(CRenderer* _pRenderer) = 0;
#pragma endregion

protected:
#pragma region protected variable
	/// <summary>
	/// position of object
	/// </summary>
	SVector2 m_position;

	/// <summary>
	/// angle of object
	/// </summary>
	float m_angle;

	/// <summary>
	/// tag of object
	/// </summary>
	const char* m_pTag;

	/// <summary>
	/// lifetime of object
	/// </summary>
	float m_pLifetime = 0.0f;

	/// <summary>
	/// has this object an animation
	/// </summary>
	bool animated = false;

	/// <summary>
	/// count of frames of animated object
	/// </summary>
	int animated_frames = 0;

	/// <summary>
	/// layer to render
	/// </summary>
	int m_layer;

	/// <summary>
	/// sound of object
	/// </summary>
	CSound* m_pSound;
#pragma endregion
};