#include "stdafx.h"
#include "WorkArea.h"
#include "CraftTimeBar.h"

void WorkArea::Init()
{
	_transform = object->GetTransform();

	_craftBox->SetIsActive(false);
}

void WorkArea::Update()
{
	if (_craftBox->GetIsActive() && InputManager::GetInstance()->GetKeyDown(VK_LBUTTON) &&
		!_craftBox->GetComponent<BoxCollider>()->PtInCollider(InputManager::GetInstance()->GetMouseWorldPosition()) &&
		!object->GetComponent<BoxCollider>()->PtInCollider(InputManager::GetInstance()->GetMouseWorldPosition()))
	{
		_craftBox->SetIsActive(false);
	}

}

void WorkArea::OnMouseDown()
{
	if (WorkerControlManager::GetInstance()->GetMWorkers()[object->GetName()] >= 5)
		_craftBox->SetIsActive(!_craftBox->GetIsActive());
}
