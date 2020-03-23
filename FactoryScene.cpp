#include "stdafx.h"
#include "FactoryScene.h"
#include "Bubble.h"
#include "CraftSpriteAndText.h"
#include "CraftInfo.h"
#include "LinkButton.h"
#include "CraftTimeBar.h"
#include "WorkArea.h"
#include "CraftBox.h"
#include "Inventory.h"
#include "ControlCamera.h"
#include "Mouse.h"
#include "WorkerAnimation.h"
#include "WorkerMove.h"

void FactoryScene::Init()
{
#pragma region UI
	//Time UI
	//Object* time = Object::CreateObject();
	//time->AddComponent<Time>();
	//time->SetIsActive(true);
	//time->SetCameraAffected(false);
	//
	////LuytenTown UI
	//Object* luytenTown = Object::CreateObject();
	//luytenTown->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/LuytenTown.png"));
	//luytenTown->GetTransform()->SetPosition(Convert(41, 23, 245, 53) + (DesignResolution * Vector2(1, -1) / 2));
	//luytenTown->SetCameraAffected(false);
	//
	//
	////Inventory Bag Icon 
	////Object* bag = Object::CreateObject();
	////bag->SetTag("UI");
	////bag->SetName("Inventory");
	////bag->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Inventory_Icon.png"));
	////bag->GetTransform()->SetPosition(Convert(53, 714, 99, 96) + (DesignResolution * Vector2(1, -1) / 2));
	////bag->SetCameraAffected(false);
	//
	//
	////WorkerPanel POP-UP 
	//Object* workerPanel = Object::CreateObject();
	//workerPanel->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/SetPopulation.png"));
	//workerPanel->GetTransform()->SetPosition(Convert(566, 238, 500, 500) + (DesignResolution * Vector2(1, -1) / 2));
	//workerPanel->AddComponent<WorkerPanel>();
	//workerPanel->SetIsActive(false);
	//workerPanel->SetCameraAffected(false);
	//time->GetComponent<Time>()->AddObserver(workerPanel->GetComponent<WorkerPanel>());
	//
	//
	////ShowWorker Total UI
	//Object* totalWorker = Object::CreateObject();
	//totalWorker->AddComponent<BoxCollider>();
	//totalWorker->AddComponent<TotalWorker>();
	//totalWorker->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Town_people.png"));
	//totalWorker->GetTransform()->SetPosition(Convert(360, 23, 314, 52) + (DesignResolution * Vector2(1, -1) / 2));
	//totalWorker->GetComponent<BoxCollider>()->SetSize(Vector2(157, 26));
	//totalWorker->SetCameraAffected(false);
	//
	//
	//Object* showWorker = Object::CreateObject();
	//showWorker->AddComponent<ShowWorker>();
	//showWorker->SetIsActive(false);
	//time->GetComponent<Time>()->AddObserver(showWorker->GetComponent<ShowWorker>());
	//
	//
	//Object* resourceControl = Object::CreateObject();
	//resourceControl->AddComponent<ResourceControl>();
	//time->GetComponent<Time>()->AddObserver(resourceControl->GetComponent<ResourceControl>());
	//
	////Setting Panel
	//
	////Setting Icon                   
	//Object* settingIcon = Object::CreateObject();
	//settingIcon->SetTag("UI");
	//settingIcon->SetName("Setting");
	//settingIcon->AddComponent<BoxCollider>();
	//settingIcon->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Setting_Icon.png"));
	//settingIcon->GetTransform()->SetScale(Vector2(1.65f, 1.65f));
	//settingIcon->GetTransform()->SetPosition(Vector2(DesignResolution.x / 2 - 100, DesignResolution.y / 2 - 70)
	//	+ (DesignResolution * Vector2(1, -1) / 2));
	//settingIcon->AddComponent<SettingIcon>();
	//settingIcon->GetComponent<BoxCollider>()->SetSize(Vector2(100, 100));
	//settingIcon->SetCameraAffected(false);
	//
	//
	//Object* settingPanel = Object::CreateObject();
	//settingPanel->AddComponent<SettingPanel>();
	//settingPanel->GetTransform()->SetDepth(2);
	//settingPanel->SetIsActive(false);
	//
	//
	////<Address Link>
	//totalWorker->GetComponent<TotalWorker>()->SetLinkWithShowWorker(showWorker);
	//workerPanel->GetComponent<WorkerPanel>()->SetLinkWithWorker(totalWorker);
	//showWorker->GetComponent<ShowWorker>()->SetLinkWithWorkerPanel(workerPanel->GetComponent<WorkerPanel>());
	//settingIcon->GetComponent<SettingIcon>()->SetLinkWithSettingPanel(settingPanel);

#pragma endregion
	_mtotalworker = WorkerControlManager::GetInstance()->GetMWorkers();
	
	int num = 0;

	Object* test = Object::CreateObject();
	test->AddComponent<ControlCamera>();
	MapManager::GetInstance()->Load("TileMap_Factory", test);
	//test->GetTransform()->SetDepth(-1);

	for (auto it : _mtotalworker)
	{
		if (it.first != "Wood_Cutter" && it.first != "Water_Collecter")
		{
			Object* facWorker = Object::CreateObject();
			facWorker->SetTag(it.first);

			int b = num % 6;
			string a = to_string(b);

			facWorker->SetName("H" + a);
			facWorker->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/" + facWorker->GetName() + "_Idle_Front.png"));
			facWorker->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.7f, 0.7f));

			if (facWorker->GetTag() == "Carpenter")		facWorker->GetTransform()->SetPosition(Vector2(550, -630));
			if (facWorker->GetTag() == "Miner")			facWorker->GetTransform()->SetPosition(Vector2(750, 250));
			if (facWorker->GetTag() == "Refiner")		facWorker->GetTransform()->SetPosition(Vector2(-750, 275));

			facWorker->AddComponent<Animator>();
			facWorker->AddComponent<WorkerAnimation>();
			facWorker->AddComponent<WorkerMove>();

			//Bubble Set
			Object* facBubble = Object::CreateObject();
			facBubble->AddComponent<Bubble>()->SetLink(facWorker);
			facBubble->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Bubble/" + facWorker->GetTag() + "_Bubble.png"));
			if (facWorker->GetTag() == "Miner") facBubble->GetComponent<Sprite>()->SetSprite(Image::CreateImage
			("Bubble/Brick_Bubble.png"));

			num++;
		}
	}

	auto invenImage = Image::CreateImage("Sprite/UI/Inventory_Icon.png");
	Object* bag = Object::CreateObject();
	bag->SetTag("UI");
	bag->SetName("Inventory");
	bag->SetCameraAffected(false);
	bag->AddComponent<Sprite>()->SetSprite(invenImage);
	bag->GetTransform()->SetPosition(Convert(53, 714, 99, 96) + (DesignResolution / 2 * Vector2(1, -1)));

	Object* inventory = Object::CreateObject();
	auto inven = inventory->AddComponent<Inventory>();
	inventory->SetIsActive(false);
	
	Object* inventoryOnOff = Object::CreateObject();
	inventoryOnOff->SetCameraAffected(false);
	inventoryOnOff->SetName("ASDF");
	inventoryOnOff->AddComponent<BoxCollider>()->SetSize(invenImage->GetContentSize());
	inventoryOnOff->GetTransform()->SetDepth(9999999);
	inventoryOnOff->GetTransform()->SetPosition(Convert(53, 714, 99, 96) + (DesignResolution / 2 * Vector2(1, -1)));
	inventoryOnOff->AddComponent<LinkButton>()->SetLink(inventory);

	for (int i = 0; i < 3; i++)
	{
		Object* workArea = Object::CreateObject();

		if (i == 0)
		{
			workArea->SetTag("Brick");
			workArea->SetName("Miner");
		}
		if (i == 1)
		{
			workArea->SetTag("MetalSheet");
			workArea->SetName("Refiner");
		}
		if (i == 2)
		{
			workArea->SetTag("Plank");
			workArea->SetName("Carpenter");
		}

		if (workArea->GetTag() == "Plank")			workArea->GetTransform()->SetPosition(Vector2(100, -200) + (DesignResolution * Vector2(1, -1) / 2));
		if (workArea->GetTag() == "Brick")			workArea->GetTransform()->SetPosition(Vector2(300, 130) + (DesignResolution * Vector2(1, -1) / 2));
		if (workArea->GetTag() == "MetalSheet")		workArea->GetTransform()->SetPosition(Vector2(-500, 100) + (DesignResolution * Vector2(1, -1) / 2));

		workArea->AddComponent<WorkArea>();
		workArea->AddComponent<BoxCollider>();
		workArea->GetComponent<BoxCollider>()->SetSize(Vector2(150, 150));
		workArea->AddComponent<CraftInfo>();
		workArea->SetCameraAffected(false);

		// productionBox(product)가 infoBox같은 애
		Object* craftBox = Object::CreateObject();
		if (i == 0) craftBox->SetTag("Brick");
		if (i == 1) craftBox->SetTag("MetalSheet");
		if (i == 2) craftBox->SetTag("Plank");
		craftBox->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Material_Synthesis.png"));
		craftBox->GetComponent<Sprite>()->GetTransform()->SetPosition((DesignResolution * Vector2(1, -1) / 2));
		craftBox->AddComponent<BoxCollider>();
		craftBox->AddComponent<CraftBox>();
		craftBox->SetIsActive(false);
		craftBox->SetCameraAffected(false);

		Object* craftTimeBar = Object::CreateObject(craftBox);
		craftTimeBar->AddComponent<CraftTimeBar>();
		craftTimeBar->AddComponent<PolygonDraw>();
		craftTimeBar->SetCameraAffected(false);
		craftTimeBar->SetIsActive(false);
		craftTimeBar->GetComponent<CraftTimeBar>()->SetLink(workArea);

		craftBox->GetComponent<CraftBox>()->SetLink(workArea);
		craftBox->GetComponent<CraftBox>()->SetTimeBarLink(craftTimeBar->GetComponent<CraftTimeBar>());
		workArea->GetComponent<WorkArea>()->SetLink(craftBox);
		workArea->GetComponent<WorkArea>()->SetTimeBarLink(craftTimeBar);

		craftBox->GetComponent<CraftBox>()->SetInvenLink(inven);
		
	}

	//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
}