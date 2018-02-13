#ifndef GAME_H_
#define GAME_H_
#include <Windows.h>
#include <list>
#include <dinput.h>
#include "Effects.h"
#include "CommonStates.h"
#include "SpriteBatch.h"
#include "SpriteFont.h"

using namespace DirectX;
using std::list;
using std::unique_ptr;
class GameObject;
struct DrawData;
struct GameData;
class Sprite;
class PlatformGenerator;
class Game
{
public:
	Game(ID3D11Device* _pd3dDevice, HWND _hWnd, HINSTANCE _hInstance);
	virtual ~Game() {};
	bool Tick();
	void Draw(ID3D11DeviceContext* _pd3dImmediateConext);
private:
	DWORD m_playTime;
	list <GameObject*> m_gameObjects;


	bool Input();
	void PlayTick();
	IDirectInput8* m_DirectInput;
	IDirectInputDevice8* m_Keyboard;
	IDirectInputDevice8* m_Mouse;
	unsigned char m_keyboardState[256];
	unsigned char m_prevKeyboardState[256];
	DIMOUSESTATE m_mouseState;
	HWND m_hWND;
	GameData* m_GD;
	DrawData* m_DD;
	Sprite* m_sprite;
	PlatformGenerator* platGen;
};


#endif // !GAME_H_
