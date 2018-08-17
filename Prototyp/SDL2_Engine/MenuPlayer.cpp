#pragma region project include
#include "MenuPlayer.h"
#include "Game.h"
#include "Input.h"
#include "MainScene.h"
#pragma endregion

#pragma region constructor
// constructor
GMenuPlayer::GMenuPlayer()
{
	// create start text
	m_pStartText = new CText("Start Game", GGame::Get()->m_PArialFont, SRect(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 - 100,
		100, 50), SColor(255, 255, 255));

	// create end text
	m_pEndText = new CText("Exit Game", GGame::Get()->m_PArialFont, SRect(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 100,
		100, 50), SColor(128, 128, 128));
}

// destructor
GMenuPlayer::~GMenuPlayer()
{
	// destroy texts
	delete m_pStartText;
	delete m_pEndText;
}
#pragma endregion

#pragma region public override function
// render every frame
void GMenuPlayer::Update(float _deltaTime)
{
	// get key down to change buttons
	if (CInput::GetKeyDown(SDL_SCANCODE_S) || CInput::GetKeyDown(SDL_SCANCODE_W) ||
		CInput::GetKeyDown(SDL_SCANCODE_DOWN) || CInput::GetKeyDown(SDL_SCANCODE_UP))
	{
		// switch buttons
		m_startActive = !m_startActive;

		// if start active
		if (m_startActive)
		{
			// set color of texts
			m_pStartText->SetColor(SColor(255, 255, 255));
			m_pEndText->SetColor(SColor(128, 128, 128));
		}

		// if end active
		else
		{
			// set color of texts
			m_pEndText->SetColor(SColor(255, 255, 255));
			m_pStartText->SetColor(SColor(128, 128, 128));
		}
	}

	// if key enter pressed
	if (CInput::GetKeyDown(SDL_SCANCODE_RETURN))
	{
		// if start active
		if (m_startActive)
		{
			// switch to main scene
			CEngine::Get()->ChangeScene(new GMainScene());
		}

		// if end active
		else
		{
			// exit engine
			CEngine::Get()->Exit();
		}
	}
}

// render every frame
void GMenuPlayer::Render(CRenderer * _pRenderer)
{
	m_pStartText->Render(_pRenderer);
	m_pEndText->Render(_pRenderer);
}
#pragma endregion