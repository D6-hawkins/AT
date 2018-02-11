#ifndef GAME_DATA_H_
#define GAME_DATA_H_

#include <dinput.h>
#include "GameState.h"

//using namespace DirectX;

struct GameData
{
	float m_dt;
	GameState m_GS;

	//Input
	unsigned char* m_keyboardState;
	unsigned char* m_prevKeyboardState;
	DIMOUSESTATE* m_mouseState;



};


#endif // !GAME_DATA_H_
