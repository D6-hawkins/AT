#include "PlatformGenerator.h"
#include "Platform.h"
#include <random>
PlatformGenerator::PlatformGenerator(const wchar_t* filename, int platform, ID3D11Device* _GD)
{
	PlatfileName = filename;
	_GameData = _GD;
	Generate(platform);
}

void PlatformGenerator::Tick(GameData * _GD)
{
	for (int i = 0; i != platVec.size(); i++)
	{
		platVec[i]->Tick(_GD);
	}
}

void PlatformGenerator::Draw(DrawData * _DD)
{
	for (int i = 0; i != platVec.size(); i++)
	{
		platVec[i]->Draw(_DD);
	}
}

void PlatformGenerator::Generate(int platforms)
{
	newPlat = new Platform(PlatfileName, _GameData);
	int x = rand() % 500 + 20;
	int y = rand() % 500 + 20;
	Vector2 pos = Vector2(x, y);
	newPlat->SetPos(pos);
	platVec.push_back(newPlat);
	for (int i = 0; i != platforms; i++)
	{
		newPlat = new Platform(PlatfileName, _GameData);
		int x = 0;
		int y = 0;
		int randDirection = rand() % 4 + 1;
		int C = 0;
		if (i != 0)
		{
			C = i-1;
		}
		ID3D11Resource *pResource;
		D3D11_TEXTURE2D_DESC Desc;
		platVec[C]->getView()->GetResource(&pResource);
		((ID3D11Texture2D *)pResource)->GetDesc(&Desc);
		switch (randDirection)
		{
			case 1: //North
				y = platVec[C]->GetPos().y + platVec[C]->GetScale().y + Desc.Height;
				x = platVec[C]->GetPos().x;
				break;
			case 2: //South
				y = platVec[C]->GetPos().y - platVec[C]->GetScale().y + Desc.Height;
				x = platVec[C]->GetPos().x;
				break;
			case 3: //East
				y = platVec[C]->GetPos().y ;
				x = platVec[C]->GetPos().x +platVec[C]->GetScale().x + Desc.Width;
				break;
			case 4: //West
				y = platVec[C]->GetPos().y ;
				x = platVec[C]->GetPos().x - -platVec[C]->GetScale().x + Desc.Width;
				break;

		}
		//if (x <= 20)
		//	x = 20;
		//if (x >= 1000)
		//	x = 1000;
		//if (y <= 20)
		//	y = 20;
		//if (y >= 1000)
		//	y = 1000;
		//int x = rand() % 1000 + 20;
		//int y = rand() % 1000 + 20;
		Vector2 pos = Vector2(x, y);
		newPlat->SetPos(pos);
		platVec.push_back(newPlat);
	}
}
