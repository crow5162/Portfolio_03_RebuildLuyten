#include "stdafx.h"
#include "FadeInAndOut.h"

void FadeInAndOut::Init()
{
	sprite = object->GetComponent<Sprite>();
	if(sprite)
		sprite->SetOpacity(0);
	auto children = object->GetChildren();
	for (auto c : children)
	{
		Sprite* nowSprite = c->GetComponent<Sprite>();
		if (nowSprite)
		{
			childrenSprite.push_back(nowSprite);
			nowSprite->SetOpacity(0);
		}
	}
	startTime = TimeManager::GetInstance()->GetTime();
}

void FadeInAndOut::Update()
{
	if (TimeManager::GetInstance()->GetTime() - startTime < startDelay)
		return;

	if (fadeState == FadeState::In)
		lerpCount += TimeManager::GetInstance()->GetDeltaTime() / duration;

	else if (fadeState == FadeState::Idle && TimeManager::GetInstance()->GetTime() - startTime > delay)
		fadeState = FadeState::Out;

	else if (fadeState == FadeState::Out)
		lerpCount -= TimeManager::GetInstance()->GetDeltaTime() / duration;

	opacity = Lerp_Float(0, 1, lerpCount);
	if(sprite)
		sprite->SetOpacity(opacity);

	for (auto c : childrenSprite)
		c->SetOpacity(opacity);

	if (lerpCount >= 1) //1을 넘어서면 다시 감소해야 함 
	{
		startTime = TimeManager::GetInstance()->GetTime(); //시작 시간 초기화 
		fadeState = FadeState::Idle; //현재 fade state idle로 다시 초기화 
		lerpCount = 0.9999f; //1을 넘어가도 1보다 작게해서 조건문 안들어오게
	}

	if (lerpCount <= 0)
	{
		if (callBackFunc)
			callBackFunc();
		object->RemoveComponent(this);
	}
}