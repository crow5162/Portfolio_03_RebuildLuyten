#include "stdafx.h"
#include "Bubble.h"

void Bubble::Init()
{
	_transform = object->GetTransform();
	_sprite = object->GetComponent<Sprite>();
	
	_time = TimeManager::GetInstance()->GetTime();
}

void Bubble::Update()
{
	_sprite->GetTransform()->SetPosition(Vector2(_worker->GetTransform()->GetPosition().x, 
		_worker->GetTransform()->GetPosition().y + 50));

	OpacityCount();
}

void Bubble::OpacityCount()
{
	if (TimeManager::GetInstance()->GetTime() - _time > 1)
	{
		_sprite->SetOpacity(0.4);
	}
	if (TimeManager::GetInstance()->GetTime() - _time > 2)
	{
		_sprite->SetOpacity(1);
		_time = TimeManager::GetInstance()->GetTime();
	}
}
