#include "Sprite.h"
#include <DDSTextureLoader.h>
#include "DrawData.h"
#include "GameData.h"
#include "helper.h"
Sprite::Sprite(const wchar_t* _filename, ID3D11Device* _GD) :m_pTextureRV(nullptr)
{
	HRESULT hr = CreateDDSTextureFromFile(_GD, _filename, nullptr, &m_pTextureRV);
	if (hr == S_OK)
	{
		ID3D11Resource *pResource;
		D3D11_TEXTURE2D_DESC Desc;
		m_pTextureRV->GetResource(&pResource);
		((ID3D11Texture2D *)pResource)->GetDesc(&Desc);
	}
	else
	{
		HRESULT hr = CreateDDSTextureFromFile(_GD, L"../AT/sample.dds", nullptr, &m_pTextureRV);
		ID3D11Resource *pResource;
		D3D11_TEXTURE2D_DESC Desc;
		m_pTextureRV->GetResource(&pResource);
		((ID3D11Texture2D *)pResource)->GetDesc(&Desc);
	}

	m_origin = 0.5f*Vector2((float)100, (float)100);//around which rotation and scaing is done

}

Sprite::~Sprite()
{
	if (m_pTextureRV)
	{
		m_pTextureRV->Release();
		m_pTextureRV = nullptr;
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
	_DD->m_Sprites->Draw(m_pTextureRV, m_pos, nullptr, m_col, m_rot, m_origin, m_scale, SpriteEffects_None);
}