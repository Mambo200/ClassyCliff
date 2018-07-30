#pragma region project include
#include "Input.h"  
#pragma endregion

// static variable has to be initialized
#pragma region variable
bool CInput::m_keyIsDown[];
bool CInput::m_keyWasDown[];
bool CInput::m_buttonIsDown[];
bool CInput::m_buttonWasDown[];
#pragma endregion

#pragma region public function
// handle sdl event
void CInput::ParseEvent(SDL_Event _event)
{
	// if key is in range set key is down to event type
	if (_event.key.keysym.scancode < 256)
		m_keyIsDown[_event.key.keysym.scancode] = _event.type == SDL_KEYDOWN;
	if (_event.button.button < 5)
		m_buttonIsDown[_event.button.button] = _event.type == SDL_MOUSEBUTTONDOWN;
}

// refresh state
void CInput::RefreshState()
{
	// set last frame keys to current
	for (int i = 0; i < 256; i++)
		m_keyWasDown[i] = m_keyIsDown[i];
	for (int i = 0; i < 5; i++)
		m_buttonWasDown[i] = m_buttonIsDown[i];
}

// key is pressed
bool CInput::GetKey(SDL_Scancode _key)
{
	return m_keyIsDown[_key];
}

// key is pressed in current frame
bool CInput::GetKeyDown(SDL_Scancode _key)
{
	return m_keyIsDown[_key] && !m_keyWasDown[_key];
}

// key was released in current frame
bool CInput::GetKeyUp(SDL_Scancode _key)
{
	return !m_keyIsDown[_key] && m_keyWasDown[_key];
}


// mouse button is pressed
bool CInput::GetMouse(int _button)
{
	return m_buttonIsDown[_button];
}

// mouse button is pressed in current frame
bool CInput::GetMouseDown(int _button)
{
	return m_buttonIsDown[_button] && !m_buttonWasDown[_button];
}

// mouse button was released in current frame
bool CInput::GetMouseUp(int _button)
{
	return !m_buttonIsDown[_button] && m_buttonWasDown[_button];
}
#pragma endregion