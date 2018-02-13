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

	m_origin = 0.5f*Vector2((float)100, (float)100);
	m_col = Color(1, 1, 1);
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

}



void Sprite::Draw(DrawData* _DD)
{
	_DD->m_Sprites->Draw(m_pTextureRV, m_pos, nullptr, m_col, m_rot, m_origin, m_scale, SpriteEffects_None);
}