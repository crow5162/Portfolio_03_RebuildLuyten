#pragma once
#include "Script.h"
class GameStartButton : public Script
{
private:
	Transform* _transform;
	Collider* collider;
	Sprite* sprite;
public:
	virtual void Init();
	virtual void OnMouseDown();
};

