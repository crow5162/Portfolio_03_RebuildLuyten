#include "stdafx.h"
#include "TotalWorker.h"
#include "ShowWorker.h"

void TotalWorker::Init()
{
	_sprite = object->GetComponent<Sprite>();

	_totalWorkerText = Object::CreateObject();
	_totalWorkerText->AddComponent<Text>();
	_totalWorkerText->GetComponent<Text>()->CreateText(to_wstring(TOTALPOPULATION),
		L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 30, 100, 40);
	_totalWorkerText->GetComponent<Text>()->GetTransform()->SetPosition(Vector2(-150, 400) + (DesignResolution * Vector2(1, -1) / 2));
	_totalWorkerText->GetComponent<Text>()->SetCameraAffected(false); 
	_totalWorkerText->GetTransform()->SetDepth(300);
}


void TotalWorker::Update()
{
	_totalWorkerText->GetComponent<Text>()->ChangeText(to_wstring(TOTALPOPULATION));
}


void TotalWorker::OnMouseDown()
{
	if (_sprite)
	{
		_sprite->GetTransform()->SetScale(Vector2(0.97f, 0.97f));
	}

	_showWorker->SetIsActive(!_showWorker->GetIsActive());
}

void TotalWorker::OnMouseUp()
{
	_sprite->GetTransform()->SetScale(Vector2(1.f, 1.f));
}

