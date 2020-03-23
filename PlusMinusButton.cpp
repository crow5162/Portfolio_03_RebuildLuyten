#include "stdafx.h"
#include "PlusMinusButton.h"
#include "WorkerPanel.h"


void PlusMinusButton::Init()
{
	_sprite = object->GetComponent<Sprite>(); 
	collider = object->GetComponent<Collider>();
}

void PlusMinusButton::Update()
{
	if(InputManager::GetInstance()->GetKeyUp(VK_LBUTTON))
		_sprite->GetTransform()->SetScale(Vector2(1.f, 1.f));
}

void PlusMinusButton::OnMouseDown()
{
	if (_sprite)
	{
		_sprite->GetTransform()->SetScale(Vector2(0.9f, 0.9f));
	}

		if (object->GetTag() == "Button_Plus")
		{
			if (_workerPanel->GetTotalPopulationNum() >= TOTALPOPULATION) return;

			string b = object->GetName();
			_workerPanel->ContolPopulationNum(1, object->GetName());
		}
		else if (object->GetTag() == "Button_Minus")
		{
			if (_workerPanel->GetTotalPopulationNum() <= 0
				&& _workerPanel->GetMForSettingWorker()[object->GetName()] == 0) return;

			_workerPanel->ContolPopulationNum(-1, object->GetName());
		}
	
}
