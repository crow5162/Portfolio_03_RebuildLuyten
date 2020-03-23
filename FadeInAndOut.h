#pragma once
#include "GgaetIp.h"

enum class FadeState
{
	In,
	Idle,
	Out
};

class FadeInAndOut : public Script
{
private:
	float opacity;
	float startDelay;
	float delay;
	float duration;
	function<void()> callBackFunc = nullptr;

	FadeState fadeState;

	Sprite* sprite;
	vector<Sprite*> childrenSprite;

	float startTime;
	float lerpCount;
public:
	virtual void Init() override;
	virtual void Update() override;

	void SetDelay(float delay) { this->delay = delay; } //메인 화면 지속 시간
	void SetStartDelay(float startDelay) { this->startDelay = startDelay; } 
	void SetDuration(float duration) { this->duration = duration; } //Fade In/out 시간

	// ??? 
	void SetCallBackFunc(function<void()> func) { callBackFunc = func; }
};

