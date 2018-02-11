#ifndef DRAW_DATA_H_
#define DRAW_DATA_H_

#include "SpriteBatch.h"
#include "SpriteFont.h"

using namespace DirectX;
using namespace std;


struct DrawData
{
	unique_ptr<SpriteBatch> m_Sprites;
	unique_ptr<SpriteFont> m_Font;


};

#endif