#include "stdafx.h"
#include "CraftBox.h"
#include "CraftInfo.h"
#include "CraftSpriteAndText.h"
#include "CraftButton.h"
#include "CraftTimeBar.h"
#include "CraftResult.h"
#include "Inventory.h"

void CraftBox::Init()
{
	_transform = object->GetTransform();
	_sprite = object->GetComponent<Sprite>();
	_text = object->GetComponent<Text>();

	_mCraftResources = _workArea->GetComponent<CraftInfo>()->GetMCraftInfo()[_workArea->GetTag()].material;
	_craftTime = _workArea->GetComponent<CraftInfo>()->GetMCraftInfo()[_workArea->GetTag()].time;

	for (_miCraftResources = _mCraftResources.begin(); _miCraftResources != _mCraftResources.end(); _miCraftResources++)
	{
		if (_miCraftResources->second == 0) continue;

		_mValidCraftResources.insert(pair<string, int>(_miCraftResources->first, _miCraftResources->second));
	}

	int i = 0;

	for (auto it : _mValidCraftResources)
	{
		Object* craftSpriteAndText = Object::CreateObject(object);
		craftSpriteAndText->SetTag(it.first);
		craftSpriteAndText->AddComponent<CraftSpriteAndText>();
		craftSpriteAndText->GetComponent<CraftSpriteAndText>()->SetResourceName(it.first);
		craftSpriteAndText->GetComponent<CraftSpriteAndText>()->
			SetMaterialSpriteStartPos(Vector2(-125 + i * 120, 10));

		craftSpriteAndText->GetComponent<CraftSpriteAndText>()->
			SetMaterialTextStartPos(Vector2(-90 + i * 118, -53));
		craftSpriteAndText->GetComponent<CraftSpriteAndText>()->SetLink(this);
		craftSpriteAndText->SetCameraAffected(false);

		i++;
	}

	Object* craftbutton = Object::CreateObject(object);
	craftbutton->AddComponent<CraftButton>();
	craftbutton->AddComponent<BoxCollider>();
	craftbutton->GetComponent<CraftButton>()->SetLink(_workArea);
	craftbutton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Craft_Button.png"));
	craftbutton->GetTransform()->SetPosition(Vector2(-800, 395) + (DesignResolution * Vector2(1, -1) / 2));
	craftbutton->GetComponent<CraftButton>()->SetinvenLink(_inven);
	craftbutton->SetCameraAffected(false);

	_craftResult = Object::CreateObject(object);
	_craftResult->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/" + object->GetTag() + ".png"));
	_craftResult->GetComponent<Sprite>()->GetTransform()->SetPosition(Vector2(120, 10) + (DesignResolution * Vector2(1, -1) / 2));
	_craftResult->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.7f, 0.7f));
	_craftResult->GetComponent<Sprite>()->SetOpacity(0.3f);
	_craftResult->AddComponent<CraftResult>();
	_craftResult->GetComponent<CraftResult>()->Setlink(_timeBar);
	_craftResult->GetComponent<CraftResult>()->SetInventoryLink(_inven);
	_craftResult->SetCameraAffected(false);

	_currentSecondMaterial = Object::CreateObject(object);
	_currentSecondMaterial->AddComponent<Text>();
	_currentSecondMaterial->GetTransform()->SetPosition(Vector2(12, -58));
	_currentSecondMaterial->SetCameraAffected(false);

	_currentFirstMaterial = Object::CreateObject(object);
	_currentFirstMaterial->AddComponent<Text>();
	_currentFirstMaterial->GetTransform()->SetPosition(Vector2(-108, -58));
	_currentFirstMaterial->SetCameraAffected(false);
}

void CraftBox::Update()
{
	if (_timeBar->GetIsDone() && _timeBar->GetCraftState() == INTERVAL)
		_craftResult->GetComponent<Sprite>()->SetOpacity(1.f);
	else
		_craftResult->GetComponent<Sprite>()->SetOpacity(0.3f);

#pragma region CurrentItem

	if (object->GetTag() == "MetalSheet")
	{
		string a = to_string(_inven->GetInventory()["Stone"]);
		wstring b;
		b.assign(a.begin(), a.end());

		string c = to_string(_inven->GetInventory()["Ore"]);
		wstring d;
		d.assign(c.begin(), c.end());

		if (_inven->GetInventory()["Stone"] < 50)
			_currentSecondMaterial->GetComponent<Text>()->SetColor({ 1,0,0,1 }, 0, 100);
		if (_inven->GetInventory()["Ore"] < 50)

			_currentFirstMaterial->GetComponent<Text>()->SetColor({ 1,0,0,1 }, 0, 100);
		_currentSecondMaterial->GetComponent<Text>()->CreateText(b, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 10, 50, 100);
		_currentFirstMaterial->GetComponent<Text>()->CreateText(d, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 10, 50, 100);

	}
	if (object->GetTag() == "Plank")
	{
		string e = to_string(_inven->GetInventory()["Wood"]);
		wstring f;
		f.assign(e.begin(), e.end());

		string g = to_string(_inven->GetInventory()["Dirt"]);
		wstring h;
		h.assign(g.begin(), g.end());
		_currentSecondMaterial->GetComponent<Text>()->CreateText(f, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 10, 50, 100);
		_currentFirstMaterial->GetComponent<Text>()->CreateText(h, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 10, 50, 100);

		if (_inven->GetInventory()["Wood"] < 50)
			_currentSecondMaterial->GetComponent<Text>()->SetColor({ 1,0,0,1 }, 0, 100);
		if (_inven->GetInventory()["Dirt"] < 50)
			_currentFirstMaterial->GetComponent<Text>()->SetColor({ 1,0,0,1 }, 0, 100);
	}
	if (object->GetTag() == "Brick")
	{
		string h = to_string(_inven->GetInventory()["Water"]);
		wstring i;
		i.assign(h.begin(), h.end());

		string j = to_string(_inven->GetInventory()["Dirt"]);
		wstring k;
		k.assign(j.begin(), j.end());

		_currentSecondMaterial->GetComponent<Text>()->CreateText(i, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 10, 50, 100);
		_currentFirstMaterial->GetComponent<Text>()->CreateText(k, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 10, 50, 100);
		if (_inven->GetInventory()["Water"] < 50)
			_currentSecondMaterial->GetComponent<Text>()->SetColor({ 1,0,0,1 }, 0, 100);
		if (_inven->GetInventory()["Dirt"] < 50)
			_currentFirstMaterial->GetComponent<Text>()->SetColor({ 1,0,0,1 }, 0, 100);
	}

#pragma endregion 

}

