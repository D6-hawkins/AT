#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <d3d11_1.h>
#include "SimpleMath.h"
#include <string>

using namespace DirectX;
using namespace SimpleMath;
using namespace std;

struct GameData;
struct DrawData;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject() {};

	virtual void Tick(GameData* _GD) = 0;
	virtual void Draw(DrawData* _DD) = 0;

	//setters
	void SetPos(Vector2 _pos) { m_pos = _pos; };
	void setRot(float _rot) { m_rot = _rot; };
	void setScale(Vector2 _scale) { m_scale = _scale; };
	void setOrigin(Vector2 _origin) { m_origin = _origin; };
protected:
	Vector2 m_pos;
	float m_rot;
	Vector2 m_scale;
	Vector2 m_origin;
	Color m_col;
};

#endif // !GAME_OBJECT_H_
