#include "stdafx.h"
#include "Inventory.h"

void Inventory::Init()
{
	//items = InventoryData::GetInstance()->GetCount();
	//text = InventoryData::GetInstance()->GetText();

	sprite = object->AddComponent<Sprite>();
	object->SetCameraAffected(false);
	sprite->SetSprite(Image::CreateImage("Sprite/UI/Inventory.png"));
	object->GetTransform()->SetDepth(100000);

	object->GetTransform()->SetPosition(Vector2(-525,-114) + (DesignResolution*Vector2(1,-1)/2));

	object->AddComponent<BoxCollider>();
	//MetalSheet,LongMetalSheet,Brick,BigMetalSheet,BigPlank,LongPlank,Plank,Dirt,Ore,Stone,Wood,Water

	items["MetalSheet"] = 0;
	Object* metalSheetText = Object::CreateObject(object);
	Text* metalSheetComponent = metalSheetText->AddComponent<Text>();
	metalSheetComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	metalSheetComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	metalSheetText->SetCameraAffected(false);
	metalSheetText->GetTransform()->SetPosition(Vector2(-40,159));
	//metalSheetText->GetTransform()->SetDepth(9999);
	text["MetalSheet"] = metalSheetComponent;

	items["LongMetalSheet"] = 0;
	Object* longMetalSheetText = Object::CreateObject(object);
	Text* longMetalSheetComponent = longMetalSheetText->AddComponent<Text>();
	longMetalSheetComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	longMetalSheetComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	longMetalSheetText->SetCameraAffected(false);
	longMetalSheetText->GetTransform()->SetPosition(Vector2(124, 159));
	text["LongMetalSheet"] = longMetalSheetComponent;

	items["Brick"] = 0;
	Object* brickText = Object::CreateObject(object);
	Text* brickComponent = brickText->AddComponent<Text>();
	brickComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	brickComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	brickText->SetCameraAffected(false);
	brickText->GetTransform()->SetPosition(Vector2(206, 159));
	text["Brick"] = brickComponent;

	items["BigMetalSheet"] = 0;
	Object* bigMetalSheetText = Object::CreateObject(object);
	Text* bigMetalComponent = bigMetalSheetText->AddComponent<Text>();
	bigMetalComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	bigMetalComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	bigMetalSheetText->SetCameraAffected(false);
	bigMetalSheetText->GetTransform()->SetPosition(Vector2(40, -6));
	text["BigMetalSheet"] = bigMetalComponent;

	items["BigPlank"] = 0;
	Object* bigPlankText = Object::CreateObject(object);
	Text* bigPlankComponent = bigPlankText->AddComponent<Text>();
	bigPlankComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	bigPlankComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	bigPlankText->SetCameraAffected(false);
	bigPlankText->GetTransform()->SetPosition(Vector2(204,-6));
	text["BigPlank"] = bigPlankComponent;

	items["LongPlank"] = 0;
	Object* longPlankText = Object::CreateObject(object);
	Text* longPlankComponent = longPlankText->AddComponent<Text>();
	longPlankComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	longPlankComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	longPlankText->SetCameraAffected(false);
	longPlankText->GetTransform()->SetPosition(Vector2(40, -90));
	text["LongPlank"] = longPlankComponent;

	items["Plank"] = 0;
	Object* plankText = Object::CreateObject(object);
	Text* plankComponent = plankText->AddComponent<Text>();
	plankComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	plankComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	plankText->SetCameraAffected(false);
	plankText->GetTransform()->SetPosition(Vector2(124, -90));
	text["Plank"] = plankComponent;

	items["Dirt"] = 0;
	Object* dirtText = Object::CreateObject(object);
	Text* dirtComponent = dirtText->AddComponent<Text>();
	dirtComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	dirtComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	dirtText->SetCameraAffected(false);
	dirtText->GetTransform()->SetPosition(Vector2(204, -89));
	text["Dirt"] = dirtComponent;

	items["Ore"] = 0;
	Object* oreText = Object::CreateObject(object);
	Text* oreComponent = oreText->AddComponent<Text>();
	oreComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	oreComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	oreText->SetCameraAffected(false);
	oreText->GetTransform()->SetPosition(Vector2(-40, -169));
	text["Ore"] = oreComponent;

	items["Stone"] = 0;
	Object* stoneText = Object::CreateObject(object);
	Text* stoneComponent = stoneText->AddComponent<Text>();
	stoneComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	stoneComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	stoneText->SetCameraAffected(false);
	stoneText->GetTransform()->SetPosition(Vector2(40, -169));
	text["Stone"] = stoneComponent;

	items["Wood"] = 0;
	Object* woodText = Object::CreateObject(object);
	Text* woodComponent = woodText->AddComponent<Text>();
	woodComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	woodComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	woodText->SetCameraAffected(false);
	woodText->GetTransform()->SetPosition(Vector2(123, -169));
	text["Wood"] = woodComponent;

	items["Water"] = 0;
	Object* waterText = Object::CreateObject(object);
	Text* waterComponent = waterText->AddComponent<Text>();
	waterComponent->CreateText(L"0", L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 16, 100, 40);
	waterComponent->SetAnchorPoint(AnchorPoint::RightCenter);
	waterText->SetCameraAffected(false);
	waterText->GetTransform()->SetPosition(Vector2(204, -168));
	text["Water"] = waterComponent;
}

void Inventory::Update()
{	
	auto itr2 = items.begin();
	for (auto itr = text.begin(); itr != text.end(); itr++, itr2++)
	{
		(*itr).second->ChangeText(to_wstring((*itr2).second));
		(*itr).second->SetAnchorPoint(AnchorPoint::RightCenter);
	}
}