#include "Game.h"
#include "DrawData.h"
#include "GameData.h"
#include <Windows.h>
#include "Sprite.h"
#include <time.h>
Game::Game(ID3D11Device * _pd3dDevice, HWND _hWnd, HINSTANCE _hInstance)
{
	//SpriteBatch
	ID3D11DeviceContext* pd3dImmediateContext;
	_pd3dDevice->GetImmediateContext(&pd3dImmediateContext);
	m_DD = new DrawData();
	m_DD->m_Sprites.reset(new SpriteBatch(pd3dImmediateContext));
	m_DD->m_Font.reset(new SpriteFont(_pd3dDevice, L"..\\Assets\\italic.spritefont"));

	//m_hWND = _hWnd;
	//m_Keyboard = nullptr;
	//m_DirectInput = nullptr;

	//HRESULT hr = DirectInput8Create(_hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_DirectInput, NULL);
	//hr = m_DirectInput->CreateDevice(GUID_SysKeyboard, &m_Keyboard, NULL);
	//hr = m_Keyboard->SetDataFormat(&c_dfDIKeyboard);
	//hr = m_Keyboard->SetCooperativeLevel(m_hWND, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	//hr = m_DirectInput->CreateDevice(GUID_SysMouse, &m_Mouse, NULL);
	//hr = m_Mouse->SetDataFormat(&c_dfDIMouse);
	//hr = m_Mouse->SetCooperativeLevel(m_hWND, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	srand((UINT)time(NULL));
	//create GameData struct and populate its pointers
	m_GD = new GameData;
	m_GD->m_keyboardState = m_keyboardState;
	m_GD->m_prevKeyboardState = m_prevKeyboardState;
	m_GD->m_GS = GS_PLAY;
	m_GD->m_mouseState = &m_mouseState;

	RECT rc;
	GetClientRect(_hWnd, &rc);
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;
	float AR = (float)width / (float)height;

	m_sprite = new Sprite(L"../AT/gengar.dds", _pd3dDevice);
	m_sprite->SetPos(200.0f * Vector2::One);
	m_gameObjects.push_back(m_sprite);
}

bool Game::Tick()
{

	/*Input();


	if (m_keyboardState[DIK_ESCAPE] & 0x80)
	{
		return false;
	}*/

	//calculate frame time-step dt for passing down to game objects
	DWORD currentTime = GetTickCount();
	m_GD->m_dt = min((float)(currentTime - m_playTime) / 1000.0f, 0.1f);
	m_playTime = currentTime;

	switch (m_GD->m_GS)
	{
	case GS_GAME_OVER:
		break;
	case GS_PLAY:
		PlayTick();
		break;
	}


	return true;
}

void Game::Draw(ID3D11DeviceContext * _pd3dImmediateConext)
{
	m_DD->m_Sprites->Begin();
	for (list<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end(); it++)
	{
		(*it)->Draw(m_DD);
	}
	m_DD->m_Sprites->End();
}

bool Game::Input()
{
	memcpy(m_prevKeyboardState, m_keyboardState, sizeof(unsigned char) * 256);

	//clear out previous state
	ZeroMemory(&m_keyboardState, sizeof(unsigned char) * 256);
	ZeroMemory(&m_mouseState, sizeof(DIMOUSESTATE));

	// Read the keyboard device.
	HRESULT hr = m_Keyboard->GetDeviceState(sizeof(m_keyboardState), (LPVOID)&m_keyboardState);
	if (FAILED(hr))
	{
		// If the keyboard lost focus or was not acquired then try to get control back.
		if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
		{
			m_Keyboard->Acquire();
		}
		else
		{
			return false;
		}
	}

	// Read the Mouse device.
	hr = m_Mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouseState);
	if (FAILED(hr))
	{
		// If the Mouse lost focus or was not acquired then try to get control back.
		if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
		{
			m_Mouse->Acquire();
		}
		else
		{
			return false;
		}
	}

	return true;
}

void Game::PlayTick()
{
}

