#ifndef SPRITE_H_
#define SPRITE_H_
#include "GameObject.h"
#include <D3D11.h>
class Sprite : public GameObject
{
public:
	Sprite(const wchar_t* _filename, ID3D11Device* _GD);
	virtual ~Sprite();

	virtual void Tick(GameData* _GD);
	virtual void Draw(DrawData* _DD);
	ID3D11ShaderResourceView* getView() { return m_pTextureRV; };
protected:
	ID3D11ShaderResourceView* m_pTextureRV;


};


#endif