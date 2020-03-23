#include "stdafx.h"
#include "MoveBackground.h"
#include "Logo.h"

void MoveBackground::Init()
{
	auto children = object->GetChildren();
	for (auto c : children)
	{
		Sprite* nowSprite = c->GetComponent<Sprite>();
		if (nowSprite)
			childrenSprite.push_back(nowSprite);
	}
	startTime = TimeManager::GetInstance()->GetTime();
}

void MoveBackground::Update()
{
	if (time)
	{
		opacity -= TimeManager::GetInstance()->GetDeltaTime() / time;
		for (auto c : childrenSprite)
			c->SetOpacity(opacity);
	}

	if (!endTime)
	{
		object->GetTransform()->Translate(speed * TimeManager::GetInstance()->GetDeltaTime());
		return;
	}

	object->GetTransform()->Translate(speed * TimeManager::GetInstance()->GetDeltaTime());
	if (TimeManager::GetInstance()->GetTime() - startTime > endTime)
	{
		logo->Play();
		object->RemoveComponent(this);
	}
}

void MoveBackground::SetTime(float time)
{
	this->time = time;
}

void MoveBackground::SetSpeed(Vector2 speed)
{
	this->speed = speed;
}
