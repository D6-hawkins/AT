#include "Sprite.h"
#include <vector>
#include "GameObject.h"
class Platform;
class PlatformGenerator : public GameObject
{
public:
	PlatformGenerator(const wchar_t* filename, int platform, ID3D11Device* _GD);
	virtual ~PlatformGenerator() {};
	virtual void Tick(GameData* _GD);
	virtual void Draw(DrawData* _DD);
private:
	void Generate(int platforms);
	std::vector<Platform*> platVec;
	const wchar_t* PlatfileName;
	Platform* newPlat;
	ID3D11Device* _GameData;
	int prevDirection = 0;
};