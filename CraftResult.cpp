#include "stdafx.h"
#include "CraftResult.h"
#include "CraftTimeBar.h"
#include "Inventory.h"

void CraftResult::Init()
{
	object->AddComponent<BoxCollider>();
	object->GetComponent<BoxCollider>()->SetSize(Vector2(50, 50));
	object->GetTransform()->SetPosition(Vector2(120, 10));

	_resultCount = Object::CreateObject(object);
	_resultCount->AddComponent<Text>();
	_resultCount->GetComponent<Text>()->CreateText(L"20", L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 25, 50, 100);
	_resultCount->GetTransform()->SetPosition(Vector2(35, -60));
	_resultCount->SetCameraAffected(false);
}

void CraftResult::Update()
{
	if (_timeBar->GetIsDone())
	{
		_resultCount->GetComponent<Text>()->CreateText(L"20", L"Vivaldi", L"ko-KR", { 0,1,1,1 }, 25, 50, 100);
	}
	else
	{
		_resultCount->GetComponent<Text>()->CreateText(L"20", L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 25, 50, 100);
	}
}

void CraftResult::OnMouseDown()
{
	if (_timeBar->GetIsDone())
	{
		//타임바의 제작이 완료되었을때 클릭했을시, Interval 상태로 돌려주고
		//해당 Area 의 Tag에 따라서 2차재료 Inventory에 Add 시켜준다.

		_timeBar->SetCraftState(INTERVAL);
		_timeBar->SetIsDone(false);
		object->GetComponent<Sprite>()->SetOpacity(0.3f);

		if (object->GetParent()->GetTag() == "MetalSheet")	  
			_inven->AddItem("MetalSheet", 20);
		if (object->GetParent()->GetTag() == "Brick")		 
			_inven->AddItem("Brick", 20);
		if (object->GetParent()->GetTag() == "Plank")		  
			_inven->AddItem("Plank", 20);
	}
}