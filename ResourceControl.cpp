#include "stdafx.h"
#include "ResourceControl.h"
#include "InventoryData.h"

//1차 자원 정보 저장하는 클래스 

void ResourceControl::Init()
{

	_startTime = TimeManager::GetInstance()->GetTime(); 

	_mResourceSave.clear(); 
	
	_mResourceSave.insert(make_pair("Stone", 0));
	_mResourceSave.insert(make_pair("Dirt", 0));
	_mResourceSave.insert(make_pair("Water", 0));
	_mResourceSave.insert(make_pair("Ore", 0));
	_mResourceSave.insert(make_pair("Wood", 0));

	//Wood_Cutter --> 숫자 받아와서 = 목재 아이템 * 3분에 2개씩 
	//Miner --> 숫자 받아와서 = 원석, 석재, 흙 아이템 * 3분에 2개씩 
	//Water_Collecter --> 숫자 받아와서 = 물 아이템 * 3분에 2개씩 
}


void ResourceControl::Update()
{
	if (isDayToProduce) //낮 동안일 때 
	{
		//_producingnStartTime = 실행 시간 구하기
		_producingnStartTime = TimeManager::GetInstance()->GetTime() - _startTime;
		if (_producingnStartTime >= PRODUCTIONTIME) // 5초일 때 한 번만 실행되게
		{
			MakeResource();
			_startTime = TimeManager::GetInstance()->GetTime(); //시간 다시 초기화
		}
	}
}


void ResourceControl::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::TIME) return;

	if (event == "isDay") //낮일 때 자원 생산하도록
	{
		isDayToProduce = true;
	}
}

void ResourceControl::MakeResource()
{
	//_mResourceSave["Stone", "Dirt", "Ore" ] += WorkerControlManager::GetInstance()->GetMWorkers()["Miner"] * 2;
	InventoryData::GetInstance()->GetCount()["Ore"] += WorkerControlManager::GetInstance()->GetMWorkers()["Miner"] * 20;
	InventoryData::GetInstance()->GetCount()["Dirt"] += WorkerControlManager::GetInstance()->GetMWorkers()["Miner"] * 20;
	InventoryData::GetInstance()->GetCount()["Stone"] += WorkerControlManager::GetInstance()->GetMWorkers()["Miner"] * 20;
	InventoryData::GetInstance()->GetCount()["Water"] += WorkerControlManager::GetInstance()->GetMWorkers()["Water_Collecter"] *20;
	InventoryData::GetInstance()->GetCount()["Wood"] += WorkerControlManager::GetInstance()->GetMWorkers()["Wood_Cutter"] * 20;

//#pragma region 자원 확인용 cout 출력
//		cout << "돌 자원 : " << _mResourceSave["Stone"] << endl;
//		cout << "흙 자원 : " << _mResourceSave["Dirt"] << endl;
//		cout << "물 자원 : " << _mResourceSave["Water"] << endl;
//		cout << "광석 자원 : " << _mResourceSave["Ore"] << endl;
//		cout << "나무 자원 : " << _mResourceSave["Wood"] << endl;
//		cout << "======================" << endl;
//#pragma endregion
}