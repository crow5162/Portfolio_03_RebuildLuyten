#include "stdafx.h"
#include "LinkButton.h"

void LinkButton::Init()
{
	object->AddComponent<BoxCollider>();
}

void LinkButton::Update()
{
	if (linked->GetIsActive() && InputManager::GetInstance()->GetKeyDown(VK_LBUTTON) &&
		!linked->GetComponent<BoxCollider>()->PtInCollider(InputManager::GetInstance()->GetMouseWorldPosition())&&
		!object->GetComponent<BoxCollider>()->PtInCollider(InputManager::GetInstance()->GetMouseWorldPosition()))
	{
		linked->SetIsActive(false);
	}
}

void LinkButton::OnMouseDown()
{
	linked->SetIsActive(!linked->GetIsActive());
}
