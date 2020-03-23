#include "stdafx.h"
#include "ConfirmButton.h"
#include "LotExpansion.h"


void ConfirmButton::OnMouseDown()
{
	object->GetTransform()->SetScale(Vector2(0.9,0.9));
}

void ConfirmButton::OnMouseUp()
{
	//인벤토리 처리 
	object->GetTransform()->SetScale(Vector2(1, 1));
	window->SetIsActive(false);
	expansion->AllowExpansion();
}
