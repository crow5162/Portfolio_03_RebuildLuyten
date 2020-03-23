#include "stdafx.h"
#include "ForestScene.h"
#include "WorkerAnimation.h"
#include "WorkerMove.h"
#include "Bubble.h"
#include "Mouse.h"
#include "ControlCamera.h"
#include "MapManager.h"

#include "PlusMinusButton.h"
#include "TotalWorker.h"
#include "ShowWorker.h"
#include "WorkerPanel.h"
#include "Time.h"
#include "SettingPanel.h"
#include "SettingIcon.h"
#include "ResourceControl.h"
#include "VolumeBar.h" 

void ForestScene::Init()
{
#pragma region UI
	//Time UI
	Object* time = Object::CreateObject();
	time->AddComponent<Time>();
	time->SetIsActive(true);
	time->SetCameraAffected(false);

	//LuytenTown UI
	Object* luytenTown = Object::CreateObject();
	luytenTown->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/LuytenTown.png"));
	luytenTown->GetTransform()->SetPosition(Convert(41, 23, 245, 53) + (DesignResolution * Vector2(1, -1) / 2));
	luytenTown->SetCameraAffected(false);


	//Inventory Bag Icon 
	Object* bag = Object::CreateObject();
	bag->SetTag("UI");
	bag->SetName("Inventory");
	bag->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Inventory_Icon.png"));
	bag->GetTransform()->SetPosition(Convert(53, 714, 99, 96) + (DesignResolution * Vector2(1, -1) / 2));
	bag->SetCameraAffected(false);


	//WorkerPanel POP-UP 
	Object* workerPanel = Object::CreateObject();
	workerPanel->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/SetPopulation.png"));
	workerPanel->GetTransform()->SetPosition(Convert(566, 238, 500, 500) + (DesignResolution * Vector2(1, -1) / 2));
	workerPanel->AddComponent<WorkerPanel>();
	workerPanel->SetIsActive(false);
	workerPanel->SetCameraAffected(false);
	time->GetComponent<Time>()->AddObserver(workerPanel->GetComponent<WorkerPanel>());


	//ShowWorker Total UI
	Object* totalWorker = Object::CreateObject();
	totalWorker->AddComponent<BoxCollider>();
	totalWorker->AddComponent<TotalWorker>();
	totalWorker->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Town_people.png"));
	totalWorker->GetTransform()->SetPosition(Convert(360, 23, 314, 52) + (DesignResolution * Vector2(1, -1) / 2));
	totalWorker->GetComponent<BoxCollider>()->SetSize(Vector2(157, 26));
	totalWorker->SetCameraAffected(false);


	Object* showWorker = Object::CreateObject();
	showWorker->AddComponent<ShowWorker>();
	showWorker->SetIsActive(false);
	time->GetComponent<Time>()->AddObserver(showWorker->GetComponent<ShowWorker>());


	Object* resourceControl = Object::CreateObject();
	resourceControl->AddComponent<ResourceControl>();
	time->GetComponent<Time>()->AddObserver(resourceControl->GetComponent<ResourceControl>());

	//Setting Panel

	//Setting Icon                   
	Object* settingIcon = Object::CreateObject();
	settingIcon->SetTag("UI");
	settingIcon->SetName("Setting");
	settingIcon->AddComponent<BoxCollider>();
	settingIcon->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Setting_Icon.png"));
	settingIcon->GetTransform()->SetScale(Vector2(1.65f, 1.65f));
	settingIcon->GetTransform()->SetPosition(Vector2(DesignResolution.x / 2 - 100, DesignResolution.y / 2 - 70)
		+ (DesignResolution * Vector2(1, -1) / 2));
	settingIcon->AddComponent<SettingIcon>();
	settingIcon->GetComponent<BoxCollider>()->SetSize(Vector2(100, 100));
	settingIcon->SetCameraAffected(false);


	Object* settingPanel = Object::CreateObject();
	settingPanel->AddComponent<SettingPanel>();
	settingPanel->GetTransform()->SetDepth(2);
	settingPanel->SetIsActive(false);


	//<Address Link>
	totalWorker->GetComponent<TotalWorker>()->SetLinkWithShowWorker(showWorker);
	workerPanel->GetComponent<WorkerPanel>()->SetLinkWithWorker(totalWorker);
	showWorker->GetComponent<ShowWorker>()->SetLinkWithWorkerPanel(workerPanel->GetComponent<WorkerPanel>());
	settingIcon->GetComponent<SettingIcon>()->SetLinkWithSettingPanel(settingPanel);
#pragma endregion
	//ShowCursor(false);
	//
	//Object* mouse = Object::CreateObject();
	//mouse->SetTag("Mouse");
	//mouse->AddComponent<Mouse>();
	//ShowCursor(false);

	//Object* background = Object::CreateObject();
	//background->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Forest_Test.png"));
	//background->GetTransform()->SetScale(Vector2(0.8f, 0.8f));

	_mtotalworker = WorkerControlManager::GetInstance()->GetMWorkers();


	int num = 0;

	Object* test = Object::CreateObject();
	test->AddComponent<ControlCamera>();
	MapManager::GetInstance()->Load("TileMap_Forest", test);
	test->GetTransform()->SetDepth(-999);

	//_mtotal 의 현재 배치된 각직업의 인구수를 불러오고, 최대 4명까지 맵에 배치시킵니다.
	for (auto it : _mtotalworker)
	{
		for (int j = 0; j < it.second / 10; j++)
		{
			if (it.first != "Carpenter" && it.first != "Refiner")
				//숲 맵에서는 2차재료 직업군 불러오지말기.
			{
				Object* worker = Object::CreateObject();
				worker->SetTag(it.first);

				int b = num % 6;
				string a = to_string(b);

				worker->SetName("H" + a);
				worker->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/" + worker->GetName() + "_Idle_Front.png"));
				worker->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.7f, 0.7f));

				if (worker->GetTag() == "Miner")			
					worker->GetTransform()->SetPosition(Vector2(720 + num * 35, -1300));
				if (worker->GetTag() == "Wood_Cutter")		
					worker->GetTransform()->SetPosition(Vector2(-225 - num * 35, -80));
				if (worker->GetTag() == "Water_Collecter")	
					worker->GetTransform()->SetPosition(Vector2(-400 + num * 50, -925 - num * 30));

				
					worker->AddComponent<Animator>();
					worker->AddComponent<WorkerMove>();
					worker->AddComponent<WorkerAnimation>();
				

				//worker->SetCameraAffected(false);

				//직업에 맞는 자원의 말풍선을 출력합니다.
				Object* bubble = Object::CreateObject();
				bubble->AddComponent<Bubble>();
				bubble->GetComponent<Bubble>()->SetLink(worker);
				bubble->AddComponent<Sprite>();
				bubble->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Bubble/" + worker->GetTag() + "_Bubble.png"));

				num++;
			}
		}
	}
}
