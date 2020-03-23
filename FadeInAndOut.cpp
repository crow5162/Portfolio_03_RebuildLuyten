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

	if (lerpCount >= 1) //1�� �Ѿ�� �ٽ� �����ؾ� �� 
	{
		startTime = TimeManager::GetInstance()->GetTime(); //���� �ð� �ʱ�ȭ 
		fadeState = FadeState::Idle; //���� fade state idle�� �ٽ� �ʱ�ȭ 
		lerpCount = 0.9999f; //1�� �Ѿ�� 1���� �۰��ؼ� ���ǹ� �ȵ�����
	}

	if (lerpCount <= 0)
	{
		if (callBackFunc)
			callBackFunc();
		object->RemoveComponent(this);
	}
}