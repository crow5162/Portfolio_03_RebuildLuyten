#pragma once
#include "GgaetIp.h"
#include <any>

class Logo;

class MoveBackground : public Script
{
private:
	float time;
	float endTime;
	float opacity = 1;
	float startTime;
	Vector2 speed;
	vector<Sprite*> childrenSprite;
	Logo* logo;
public:
	virtual void Init() override;
	virtual void Update() override;

	void SetTime(float time);
	void SetSpeed(Vector2 direction);
	void SetEndTime(float endTime) { this->endTime = endTime; }
	void SetLogo(Logo* logo) { this->logo = logo; }
};

