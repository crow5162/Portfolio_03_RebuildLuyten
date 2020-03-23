#include "stdafx.h"
#include "WcDoneButton.h"
#include "WorkerPanel.h"

void WcDoneButton::Init()
{
}

void WcDoneButton::Update()
{
}

void WcDoneButton::OnMouseDown()
{
	WorkerControlManager::GetInstance()->SetPopulation(_workerPanel->GetMForSettingWorker());
	_workerPanel->ControlOnOff(false);
}
