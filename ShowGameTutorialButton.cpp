#include "stdafx.h"
#include "ShowGameTutorialButton.h"
#include "TutorialScene.h"

void ShowGameTutorialButton::Init()
{
	_sprite = object->GetComponent<Sprite>();
	collider = object->GetComponent<Collider>();
}

void ShowGameTutorialButton::OnMouseDown()
{
	_sprite->GetTransform()->SetScale(Vector2(0.97f, 0.97f)); 
	SceneManager::GetInstance()->PushScene(new TutorialScene);
}

void ShowGameTutorialButton::OnMouseUp()
{
	_sprite->GetTransform()->SetScale(Vector2(1.f, 1.f));
}
