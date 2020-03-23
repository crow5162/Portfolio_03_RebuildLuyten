#include "stdafx.h"
#include "SettingIcon.h"
#include "SettingPanel.h"



void SettingIcon::Init()
{
	_sprite = object->GetComponent<Sprite>(); 
}


void SettingIcon::Update()
{

}


void SettingIcon::OnMouseDown()
{
	_sprite->GetTransform()->SetScale(Vector2(1.58f, 1.58f));
	_settingPanel->SetIsActive(!_settingPanel->GetIsActive());
}

void SettingIcon::OnMouseUp()
{
	_sprite->GetTransform()->SetScale(Vector2(1.65f, 1.65f));
}
