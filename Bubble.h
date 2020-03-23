#pragma once
#include "GgaetIp.h"

class Bubble : public Script
{
private:
	Sprite* _sprite;
	Transform* _transform;
	Object* _worker;

	float _time;

public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void SetLink(Object* worker) { _worker = worker; }
	virtual void OpacityCount();
};