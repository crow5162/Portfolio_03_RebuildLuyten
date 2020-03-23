#include "stdafx.h"
#include "GameScene.h"

//Eunsol
#include "PlusMinusButton.h"
#include "TotalWorker.h"
#include "ShowWorker.h"
#include "WorkerPanel.h"
#include "Time.h"
#include "SettingPanel.h"
#include "SettingIcon.h"
#include "ResourceControl.h"
#include "VolumeBar.h" 

//Hyolim and Haeun
#include "AStar.h"
#include "ControlCamera.h"
#include "Character.h"
#include "TileMap.h"
#include "TilePick.h"

#include "BuildingManager.h"
#include "Building.h"

#include "Mouse.h"

#include "LinkButton.h"
#include "NotificationBox.h"
#include "Achievement.h"

#include "LoadButton.h"
#include "TileCheck.h"
#include "BuildingComponent.h"
#include "NewBuilding.h"

#include "RandomMove.h"
#include "CitizenAnimation.h"
#include "CitizenTalk.h"
#include "Tutorial.h"

#include "LotExpansion.h"
#include "Inventory.h"
#include "LoadBox.h"

#include <time.h>

void GameScene::Init()
{
	//ShowCursor(false);

	//Object* mouse = Object::CreateObject();
	//mouse->SetTag("Mouse");
	//mouse->AddComponent<Mouse>();
	//ShowCursor(false);


#pragma region EUNSOL

	//BackGround
	//Object* backGround = Object::CreateObject();
	//backGround->SetTag("BackGround");
	//backGround->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/Test_background.png"));

	//Time UI
	Object* time = Object::CreateObject();
	time->AddComponent<Time>();
	time->SetIsActive(true);
	time->SetCameraAffected(false);
	time->GetTransform()->SetDepth(100);

	//LuytenTown UI
	Object* luytenTown = Object::CreateObject();
	luytenTown->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/LuytenTown.png"));
	luytenTown->GetTransform()->SetPosition(Convert(41, 23, 245, 53) + (DesignResolution * Vector2(1, -1) / 2));
	luytenTown->SetCameraAffected(false);
	luytenTown->GetTransform()->SetDepth(100);


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
	totalWorker->GetTransform()->SetDepth(100);


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
	settingIcon->GetTransform()->SetDepth(100);


	Object* settingPanel = Object::CreateObject();
	settingPanel->AddComponent<SettingPanel>();
	settingPanel->GetTransform()->SetDepth(2);
	settingPanel->SetIsActive(false);
	settingPanel->SetCameraAffected(false);


	//<Address Link>
	totalWorker->GetComponent<TotalWorker>()->SetLinkWithShowWorker(showWorker);
	workerPanel->GetComponent<WorkerPanel>()->SetLinkWithWorker(totalWorker);
	showWorker->GetComponent<ShowWorker>()->SetLinkWithWorkerPanel(workerPanel->GetComponent<WorkerPanel>());
	settingIcon->GetComponent<SettingIcon>()->SetLinkWithSettingPanel(settingPanel);
#pragma endregion

#pragma region HYOLIM

	
	auto tileMap = Object::CreateObject();
	tileMap->AddComponent<ControlCamera>();
	tileMap->AddComponent<TileMap>();

	auto invenImage = Image::CreateImage("Sprite/UI/Inventory_Icon.png");
	//인벤토리 
	Object* inventory = Object::CreateObject();
	inventory->AddComponent<Inventory>();
	inventory->SetIsActive(false);

	//Inventory Bag Icon 
	Object* bag = Object::CreateObject();
	bag->SetTag("UI");
	bag->SetName("Inventory");
	bag->AddComponent<Sprite>()->SetSprite(invenImage);
	bag->GetTransform()->SetPosition(Convert(53, 714, 99, 96) + (DesignResolution * Vector2(1, -1) / 2));
	bag->SetCameraAffected(false);

	Object* inventoryOnOff = Object::CreateObject();
	inventoryOnOff->SetCameraAffected(false);
	inventoryOnOff->GetTransform()->SetPosition(Convert(53, 714, 99, 96) + (DesignResolution * Vector2(1, -1) / 2));
	inventoryOnOff->AddComponent<BoxCollider>()->SetSize(invenImage->GetContentSize());
	inventoryOnOff->GetTransform()->SetDepth(999999999);
	inventoryOnOff->AddComponent<LinkButton>()->SetLink(inventory);

	MapManager::GetInstance()->SetInventoryLink(inventory->GetComponent<Inventory>());

	//부지 확장 테스트

	//auto lotExpansion = Object::CreateObject();
	////lotExpansion->GetTransform()->SetPosition(Vector2(0, -1000));
	//auto expansionCompo = lotExpansion->AddComponent<LotExpansion>();
	//auto lotExpansionColliderCompo = lotExpansion->AddComponent<BoxCollider>();
	//lotExpansionColliderCompo->SetSize(Vector2(50*80,50*80));
	//expansionCompo->SetLinkToMap(tileMap);
	//expansionCompo->SetLinkToInventory(inventory->GetComponent<Inventory>());

	//도시 에이스타 테스트 

	for (int i = 0; i < 5; i++)
	{
		int random = rand() % 6;
		auto citizen = Object::CreateObject();
		citizen->SetTag("H" + to_string(random));
		citizen->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/H" + to_string(random)+"_Move_Front.png"));
		//citizen->GetTransform()->SetScale(Vector2(0.5, 0.5));
		citizen->AddComponent<Animator>();
		citizen->AddComponent<RandomMove>()->SetLinkToMap(tileMap);
		citizen->AddComponent<CitizenAnimation>();
		citizen->GetTransform()->SetDepth(100);

		auto citizentalk = Object::CreateObject();
		citizentalk->GetTransform()->SetPosition(citizen->GetTransform()->GetPosition());
		citizentalk->SetTag("H" + to_string(random));
		citizentalk->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/H" +to_string(random)+"_Idle_Front.png"));
		//citizentalk->GetTransform()->SetScale(Vector2(0.5, 0.5));

		citizentalk->GetComponent<Sprite>()->SetOpacity(0.f);
		citizentalk->AddComponent<BoxCollider>();
		citizentalk->AddComponent<CitizenTalk>()->SetLinkToCitizen(citizen);
		citizentalk->GetTransform()->SetDepth(100);
	}


		/*auto check = Object::CreateObject();
		check->GetTransform()->SetDepth(2);
		auto checkcompo = check->AddComponent<TileCheck>();
		check->AddComponent<BoxCollider>()->SetSize(Vector2(50*100,50*100));
		checkcompo->SetLink(tileMap);

		auto newBuildingTest = Object::CreateObject();
		newBuildingTest->SetTag("House_A");
		newBuildingTest->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/test.png"));
		newBuildingTest->GetComponent<Sprite>()->SetDepth(1);

		newBuildingTest->AddComponent<PolygonDraw>();
		newBuildingTest->AddComponent<BoxCollider>()->SetSize(Vector2(100,110));
		newBuildingTest->AddComponent<BuildingComponent>()->SetBuilding(new NewBuilding(newBuildingTest));
		newBuildingTest->SetIsActive(false);

		checkcompo->SetLinkToBuilding(newBuildingTest);*/


	//건물 생성 체크
	auto constructionButton = Object::CreateObject();
	constructionButton->GetTransform()->SetPosition(Vector2(-698, -207) +(DesignResolution * Vector2(1, -1) / 2));
	constructionButton->AddComponent<BoxCollider>();
	constructionButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/BuildingConstructionIcon.png"));
	constructionButton->GetTransform()->SetDepth(3);
	constructionButton->SetCameraAffected(false);

	auto loadBox = Object::CreateObject();
	loadBox->GetTransform()->SetPosition(Vector2(-477, -118) + (DesignResolution * Vector2(1, -1) / 2));
	loadBox->AddComponent<BoxCollider>();
	loadBox->AddComponent<LoadBox>();
	constructionButton->AddComponent<LinkButton>()->SetLink(loadBox);
	loadBox->SetIsActive(false);
	loadBox->GetTransform()->SetDepth(4);
	loadBox->GetComponent<LoadBox>()->SetLinkToMap(tileMap);
	loadBox->SetCameraAffected(false);


	//엄적 테스트

	auto achievementLinkButton = Object::CreateObject();
	achievementLinkButton->GetTransform()->SetPosition(Vector2(DesignResolution.x / 2 - 100, DesignResolution.y / 2 - 170));
	achievementLinkButton->GetTransform()->Translate(Vector2(DesignResolution * Vector2(1, -1) / 2));
	auto aSprite = achievementLinkButton->AddComponent<Sprite>();
	aSprite->SetSprite(Image::CreateImage("Sprite/Achievement/AchievementButton.png"));
	aSprite->SetDepth((int)ZORDER::UI);
	aSprite->SetCameraAffected(false);

	auto achievement = Object::CreateObject();
	achievement->GetTransform()->SetPosition(Vector2(500, 200)+(DesignResolution * Vector2(1, -1) / 2));
	auto acompo = achievement->AddComponent<Achievement>();
	auto asprite = achievement->AddComponent<Sprite>();
	asprite->SetSprite(Image::CreateImage("Sprite/Achievement/AchievementUI.png"));
	asprite->SetDepth((int)ZORDER::UI);
	achievement->AddComponent<BoxCollider>();
	achievement->SetIsActive(false);
	achievement->SetCameraAffected(false);

	achievementLinkButton->AddComponent<LinkButton>()->SetLink(achievement);

	auto notificationBox = Object::CreateObject();
	auto ncompo = notificationBox->AddComponent<NotificationBox>();

	auto buildingManager = Object::CreateObject();
	auto manager = buildingManager->AddComponent<BuildingManager>();
	manager->AddObserver(ncompo);
	manager->AddObserver(acompo);
	acompo->AddObserver(loadBox->GetComponent<LoadBox>()); 
	time->GetComponent<Time>()->AddObserver(manager);

	MapManager::GetInstance()->Load("CityMap", manager);

	auto tutorial = Object::CreateObject();
	tutorial->AddComponent<Tutorial>();
	acompo->AddObserver(tutorial->GetComponent<Tutorial>());



#pragma endregion
}
