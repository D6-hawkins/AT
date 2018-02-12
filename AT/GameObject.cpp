#include "GameObject.h"
#include "GameData.h"
#include "DrawData.h"
#include "Helper.h"

using namespace DirectX;

GameObject::GameObject()
{
	m_pos = Vector2::Zero;
	m_rot = 0.0f;
	m_scale = Vector2::One;
}