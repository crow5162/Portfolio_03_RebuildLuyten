#pragma once
#include "GgaetIp.h"

class Mouse : public Script
{
private:
	Transform* _transform;
	Sprite* _sprite;
	Sound* _sound;

public:
	virtual void Init();
	virtual void Update();

	void ClickMotionAndSound();
};