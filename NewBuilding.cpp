#include "stdafx.h"
#include "NewBuilding.h"

void NewBuilding::Init()
{
	Building::Init();
	if (buildingType == SPECIAL)
		return;

	buildingType = NEW;
	_sprite = _thisObj->GetComponent<Sprite>();
	_sprite->SetSprite(Image::CreateImage("Sprite/Construction/" + _thisObj->GetTag() + "_Fixed.png"));
}

void NewBuilding::Update()
{
	Building::Update();
}


