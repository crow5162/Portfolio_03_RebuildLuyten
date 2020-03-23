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
	
	//어떤 Work Area를 클릭했는가 에 따라서 1차 재료를 감소시키고 CraftTimeBar 진행시키고 조합상태로 변합니다.
	//2차재료의 종류에 따라서 나누었습니다.
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