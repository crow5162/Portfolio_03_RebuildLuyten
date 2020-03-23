#include "stdafx.h"
#include "ShowWorker.h"
#include "WorkerPanel.h"

void ShowWorker::Init()
{
	_isNight = false;
	
	object->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/ShowWorkerSprite/PeopleUI.png"));
	object->GetTransform()->SetDepth(100);
	object->GetTransform()->SetPosition(Vector2(-440, -80) + (DesignResolution * Vector2(1, -1) / 2));
	object->SetCameraAffected(false);
	object->GetComponent<Sprite>()->GetTransform()->SetAnchorPoint(Vector2(0, 0));
	//map<string,int> check = WorkerControlManager::GetInstance()->GetMWorkers();

	for (int i = 0; i < _workerPanel->GetVWorkerNum().size(); i++)
	{
		_showWorkerSprite = Object::CreateObject(object);
		_showWorkerSprite->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/ShowWorkerSprite/"
															+_workerPanel->GetVWorkerNum()[i]->GetName() + ".png"));
		_showWorkerSprite->GetTransform()->SetPosition(Vector2(93, 120 + i * 75));
		_showWorkerSprite->GetComponent<Sprite>()->SetCameraAffected(false);


		_showWorkerText = Object::CreateObject(object); 
		_showWorkerText->AddComponent<Text>()->
		CreateText(to_wstring(WorkerControlManager::GetInstance()->GetMWorkers()[_workerPanel->GetVWorkerNum()[i]->GetName()]), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 30, 100, 40);
		_showWorkerText->GetTransform()->SetPosition(Vector2(300, 120 + i * 75));
		_showWorkerText->SetCameraAffected(false);
		_vWorkerNumList.push_back(_showWorkerText);
		_vWorkerAmount.push_back(WorkerControlManager::GetInstance()->GetMWorkers()[_workerPanel->GetVWorkerNum()[i]->GetName()]);
	}

	_inHouseWorkerText = Object::CreateObject(object);
	_inHouseWorkerText->AddComponent<Text>();
	_inHouseWorkerText->GetComponent<Text>()->CreateText(to_wstring(_totalHouseWorker), L"HYHeadLine-Medium", L"ko-KR", { 1,1,1,1 }, 30, 100, 40);
	_inHouseWorkerText->GetTransform()->SetPosition(Vector2(300, 45));
	_inHouseWorkerText->GetComponent<Text>()->SetCameraAffected(false); 
}

void ShowWorker::Update()
{
	cout << _isNight;

	//인부들 int값만 담아놓은 vector
	for (int i = 0; i < _vWorkerAmount.size(); i++)
	{
		_vWorkerAmount[i] = WorkerControlManager::GetInstance()->GetMWorkers()[_workerPanel->GetVWorkerNum()[i]->GetName()];
	}

	if (!_isNight) //낮일 때만 WorkerPanel 값 받아올 수 있도록
	{
		_inHouseWorkerText->GetComponent<Text>()->ChangeText(to_wstring(0));

		//설정한 worker 숫자 노출 
		for (int i = 0; i < _vWorkerNumList.size(); i++)
		{
			_vWorkerNumList[i]->GetComponent<Text>()->ChangeText(to_wstring(WorkerControlManager::GetInstance()->GetMWorkers()[_workerPanel->GetVWorkerNum()[i]->GetName()]));
		}
	}
	else if(_isNight) //밤일 때 
	{
		//전체 인부 집으로 돌아가는 설정 -> 잘들어옴
		_totalHouseWorker = _vWorkerAmount[0] + _vWorkerAmount[1] + _vWorkerAmount[2] + _vWorkerAmount[3] + _vWorkerAmount[4];
		_inHouseWorkerText->GetComponent<Text>()->ChangeText(to_wstring(_totalHouseWorker));

		//설정한 worker 숫자 0으로 --> Inhouse
		for (int i = 0; i < _vWorkerNumList.size(); i++)
		{
			_vWorkerNumList[i]->GetComponent<Text>()->ChangeText(to_wstring(0));
		}
	}
}

void ShowWorker::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::TIME) return;

	if (event == "isNight") //밤일 때
	{
		_isNight = true; 
	}
	else if (event == "isDay") //낮일 때 
	{
		_isNight = false; //두번째 날 아침은 신호가 안들어옴
	}
}

