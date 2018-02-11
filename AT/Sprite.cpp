#include "Sprite.h"
#include "DDSTextureLoader.h"
#include "DrawData.h"
#include "GameData.h"
#include "helper.h"

Sprite::Sprite(string _fileName, ID3D11Device* _GD) :tex(nullptr)
{
	string fullfilename =
#if DEBUG
		"../Debug/"
#else
		"../Release/"
#endif
		+ _fileName + ".dds";
	HRESULT hr = CreateDDSTextureFromFile(_GD, Helper::charToWChar(fullfilename.c_str()), nullptr, &tex);

	//this nasty thing is required to find out the size of this image!
	ID3D11Resource *pResource;
	D3D11_TEXTURE2D_DESC Desc;
	tex->GetResource(&pResource);
	((ID3D11Texture2D *)pResource)->GetDesc(&Desc);

	m_origin = 0.5f*Vector2((float)Desc.Width, (float)Desc.Height);//around which rotation and scaing is done

}

Sprite::~Sprite()
{
	if (tex)
	{
		tex->Release();
		tex = nullptr;
	}
}

void Sprite::Tick(GameData* _GD)
{
	//spins!
	m_rot += _GD->m_dt;
}



void Sprite::Draw(DrawData* _DD)
{
	//nullptr can be changed to a RECT* to define what area of this image to grab
	//you can also add an extra value at the end to define layer depth
	//right click and "Go to Defintion/Declaration" to see other version of this in DXTK
	_DD->m_Sprites->Draw(tex, m_pos, nullptr, m_col, m_rot, m_origin, m_scale, SpriteEffects_None);
}