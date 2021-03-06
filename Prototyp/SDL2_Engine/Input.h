#pragma once
// Changes by Tobias Stroedicke & Marcel Lueke

#pragma region system include
#include <SDL.h>
#pragma endregion

/// <summary>
/// input handling class
/// </summary>
class CInput
{
public:
#pragma region public function

	/// <summary>
	/// handle sdl events
	/// </summary>
	/// <param name="_event"></param>
	static void ParseEvent(SDL_Event _event);

	/// <summary>
	/// refresh current state
	/// </summary>
	static void RefreshState();

	/// <summary>
	/// key is pressed
	/// </summary>
	/// <param name="_key">key scancode</param>
	/// <returns>if key is pressed</returns>
	static bool GetKey(SDL_Scancode _key);

	/// <summary>
	/// key is pressed in current frame
	/// </summary>
	/// <param name="_key">key scancode</param>
	/// <returns>if key is pressed this frame</returns>
	static bool GetKeyDown(SDL_Scancode _key);

	/// <summary>
	/// key is released in current frame
	/// </summary>
	/// <param name="_key">key scancode</param>
	/// <returns>if key is released this frame</returns>
	static bool GetKeyUp(SDL_Scancode _key);

#pragma region Tobias Stroedicke & Marcel Lueke
	/// <summary>
	/// mouse button is pressed
	/// </summary>
	/// <param name="_key">mouse button event</param>
	/// <returns>if mouse button is pressed</returns>
	static bool GetMouse(int _button);

	/// <summary>
	/// mouse button is pressed in current frame
	/// </summary>
	/// <param name="_key">mouse button event</param>
	/// <returns>if mouse button is pressed this frame</returns>
	static bool GetMouseDown(int _button);

	/// <summary>
	/// mouse button is released in current frame
	/// </summary>
	/// <param name="_key">mouse button event</param>
	/// <returns>if mouse button is released this frame</returns>
	static bool GetMouseUp(int _button);
#pragma endregion
#pragma endregion

private:
#pragma region private primitive variable
	/// <summary>
	/// key down this frame
	/// </summary>
	static bool m_keyIsDown[256];

	/// <summary>
	/// key down last frame
	/// </summary>
	static bool m_keyWasDown[256];

#pragma region Tobias Stroedicke & Marcel Lueke
	/// <summary>
	/// mousebutton down this frame
	/// </summary>
	static bool m_buttonIsDown[5];

	/// <summary>
	/// mousebutton down last frame
	/// </summary>
	static bool m_buttonWasDown[5];
#pragma endregion
#pragma endregion
};