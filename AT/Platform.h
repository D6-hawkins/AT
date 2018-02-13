#pragma once
#include "Sprite.h"

class Platform : public Sprite
{
public:
	Platform(const wchar_t* filename, ID3D11Device* _GD) : Sprite(filename, _GD) {};
	virtual ~Platform() {};
	virtual void Tick(GameData* _GD);
private:
	//ID3D11Device* _GD;
	//const wchar_t* _filename;
};
