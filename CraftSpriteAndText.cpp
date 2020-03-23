#include "stdafx.h"
#include "CraftSpriteAndText.h"
#include "WorkArea.h"
#include "CraftBox.h"

void CraftSpriteAndText::Init()
{

	_mCraftInfo = _craftBox->GetmValidCraftResources();

	Object* materialSprite = Object::CreateObject(object->GetParent());
	materialSprite->AddComponent<Sprite>();
	materialSprite->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/" + _resourceName + ".png"));
	materialSprite->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.6f, 0.6f));
	materialSprite->GetComponent<Sprite>()->GetTransform()->SetPosition(_setSpritePos);
	materialSprite->SetCameraAffected(false);

	string a = to_string(_mCraftInfo[_resourceName]);
	wstring b;
	b.assign(a.begin(), a.end());

	Object* materialText = Object::CreateObject(object->GetParent());
	materialText->AddComponent<Text>();
	materialText->GetComponent<Text>()->CreateText(L"/"+b, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 15, 50, 100);
	materialText->GetComponent<Text>()->GetTransform()->SetPosition(_setTextPos);
	materialText->SetCameraAffected(false);
}

void CraftSpriteAndText::Update()
{
}
