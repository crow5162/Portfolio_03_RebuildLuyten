#include "stdafx.h"
#include "CraftButton.h"
#include "CraftTimeBar.h"
#include "WorkArea.h"
#include "Inventory.h"

void CraftButton::Init()
{
	
}

void CraftButton::Update()
{

}

void CraftButton::OnMouseDown()
{
	object->GetTransform()->SetScale(Vector2(0.8f, 0.8f));

	if (_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetIsActive() ||
		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetComponent<CraftTimeBar>()->GetIsDone() == true) return;
	
	//� Work Area�� Ŭ���ߴ°� �� ���� 1�� ��Ḧ ���ҽ�Ű�� CraftTimeBar �����Ű�� ���ջ��·� ���մϴ�.
	//2������� ������ ���� ���������ϴ�.
	if (object->GetParent()->GetTag() == "MetalSheet" 
		&& _inven->GetInventory()["Stone"] >= 50
		&& _inven->GetInventory()["Ore"] >= 50)
	{
		_inven->DelItem("Stone", 50);
		_inven->DelItem("Ore", 50);

		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->SetIsActive(true);

		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetComponent<CraftTimeBar>()->
			SetStartTime(TimeManager::GetInstance()->GetTime());

		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetComponent<CraftTimeBar>()->SetCraftState(CRAFTING);
	}
	if (object->GetParent()->GetTag() == "Brick" 
		&& _inven->GetInventory()["Dirt"] >= 50
		&& _inven->GetInventory()["Water"] >= 50)
	{
		_inven->DelItem("Dirt", 50);
		_inven->DelItem("Water", 50);

		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->SetIsActive(true);

		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetComponent<CraftTimeBar>()->
			SetStartTime(TimeManager::GetInstance()->GetTime());

		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetComponent<CraftTimeBar>()->SetCraftState(CRAFTING);
	}
	if (object->GetParent()->GetTag() == "Plank" 
		&& _inven->GetInventory()["Wood"] >= 50
		&& _inven->GetInventory()["Dirt"] >= 50)
	{
		_inven->DelItem("Wood", 50);
		_inven->DelItem("Dirt", 50);
		
		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->SetIsActive(true);

		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetComponent<CraftTimeBar>()->
			SetStartTime(TimeManager::GetInstance()->GetTime());

		_workArea->GetComponent<WorkArea>()->GetCraftTimeBar()->GetComponent<CraftTimeBar>()->SetCraftState(CRAFTING);
	}
}

void CraftButton::OnMouseUp()
{
	object->GetTransform()->SetScale(Vector2(1, 1));
}