#include "stdafx.h"
#include "Mouse.h"

void Mouse::Init()
{
	object->AddComponent<Sprite>();
	object->AddComponent<Sound>();
	
	_transform = object->GetTransform();
	_sprite = object->GetComponent<Sprite>();
	_sound = object->GetComponent<Sound>();
	
	_sprite->SetSprite(Image::CreateImage("Sprite/Mouse_Basic.png"));
	_sprite->GetTransform()->SetScale(Vector2(0.5f, 0.5f));
	auto click = AudioClip::CreateSound("Sound/SE/Click.wav");
	_sound->SetSound(click);
	_sprite->SetDepth(100);


	//_sprite->SetDepth((int)ZORDER::MOUSE);


	_transform->SetAnchorPoint(Vector2(0,1));

}

void Mouse::Update()
{
	_transform->SetPosition((InputManager::GetInstance()->GetMouseWorldPosition() - DesignResolution/2) * Vector2(1,-1));

	ClickMotionAndSound();
}

void Mouse::ClickMotionAndSound()
{

	if (InputManager::GetInstance()->GetKeyDown(VK_LBUTTON))
	{
		_sound->Play();
	}

	if (InputManager::GetInstance()->GetKey(VK_LBUTTON))
	{
		_sprite->SetSprite(Image::CreateImage("Sprite/Mouse_Clicked.png"));
	}
	else
		_sprite->SetSprite(Image::CreateImage("Sprite/Mouse_Basic.png"));
}