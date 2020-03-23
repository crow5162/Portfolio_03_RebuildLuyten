#include "stdafx.h"
#include "NotificationBox.h"

void NotificationBox::Init()
{
	object->GetTransform()->SetPosition(Vector2(0,200));
	object->SetCameraAffected(false);
	object->GetTransform()->Translate(Vector2(DesignResolution * Vector2(1, -1) / 2));
	sprite = object->AddComponent<Sprite>();
	sprite->SetOpacity(0.f);
	sprite->SetSprite(Image::CreateImage("Sprite/Achievement/NotificationBox.png"));
	sprite->GetTransform()->SetScale(Vector2(0.5, 0.5));
	sprite->SetDepth((int)ZORDER::UI);

	//좌표때문에 현 OBJ의 CHILD로 등록 
	auto textChild = Object::CreateObject(object);
	text = textChild->AddComponent<Text>();
	text->CreateText(L"", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,0 }, 30, 400, 40);
	text->GetTransform()->SetPosition(text->GetTransform()->GetPosition() + Vector2(-60, -2));
	text->SetAnchorPoint(AnchorPoint::LeftCenter);
	text->SetDepth((int)ZORDER::UI);
	text->SetCameraAffected(false);
}

void NotificationBox::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::NOTIFICATION)
		return;

	sprite->SetOpacity(1.f);
	text->ChangeText(string_to_wstring(event));
	SetTextOpacity(1.f);
	alphaTime = TimeManager::GetInstance()->GetTime();
	isNotified = true;
}

void NotificationBox::Update()
{
	//두개가 동시에 들어올때 예외 상황처리 해줘야 할듯 
	FadeOut();
}

void NotificationBox::FadeOut()
{
	if (!isNotified || TimeManager::GetInstance()->GetTime() - alphaTime < 1)
		return;

	sprite->SetOpacity(sprite->GetOpacity() - 0.01f);
	SetTextOpacity(GetTextOpacity() - 0.01f);

	if (!sprite->GetOpacity())
		isNotified = true;
	
}

void NotificationBox::SetTextOpacity(float alpha)
{
	text->SetColor(Color{ 1,1,1,alpha }, 0, 400);
	textOpacity = alpha;
}

