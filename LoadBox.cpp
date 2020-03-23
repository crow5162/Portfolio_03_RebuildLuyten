#include "stdafx.h"
#include "LoadBox.h"
#include "PageButton.h"
#include "LoadButton.h"
#include "TileCheck.h"
#include "BuildingComponent.h"
#include "NewBuilding.h"

void LoadBox::Init()
{
	object->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/NewBuildingPanel2.png"));

	firstPage = Object::CreateObject(object);
	firstPage->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/PoliceStationBox.png"));
	firstPage->SetCameraAffected(false);
	secondPage = Object::CreateObject(object);
	secondPage->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/SchoolBox.png"));
	secondPage->SetIsActive(false);

	//POLICESTATION - TILECHECK 
	auto pCheck = Object::CreateObject();
	auto pCheckCompo =  pCheck->AddComponent<TileCheck>();
	pCheck->AddComponent<BoxCollider>()->SetSize(DesignResolution * 2);
	pCheckCompo->SetLink(map);
	pCheck->GetTransform()->SetDepth(2);
	pCheck->SetIsActive(false);

	//POLICESTATION - BUILDING
	policeStation = Object::CreateObject();
	policeStation->SetTag("PoliceStation");
	policeStation->GetTransform()->SetScale(Vector2(1.5, 1.5));
	policeStation->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/PoliceStation_Color.png"));
	policeStation->GetTransform()->SetPosition(Vector2(-400,-900));
	policeStation->AddComponent<PolygonDraw>();
	policeStation->AddComponent<BoxCollider>();
	policeStation->AddComponent<BuildingComponent>()->SetBuilding(new NewBuilding(policeStation));
	policeStation->SetIsActive(false);

	pCheckCompo->SetLinkToBuilding(policeStation);

	//POLICESTATION - LOADBUTTON 
	pLoadButton = Object::CreateObject(object);
	auto pLoadCompo = pLoadButton->AddComponent<LoadButton>();
	pLoadButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/PoliceStation_Fixed.png"));
	pLoadButton->GetComponent<Sprite>()->SetDepth(30);
	pLoadButton->AddComponent<BoxCollider>();
	//pLoadButton->AddComponent<BoxCollider>()->SetSize(policeStation->GetComponent<BoxCollider>()->GetSize());
	pLoadButton->GetTransform()->SetPosition(Vector2(22,112));
	pLoadButton->GetTransform()->SetDepth(10);
	pLoadButton->SetIsActive(false);

	pLoadCompo->setLinkToMap(map);
	pLoadCompo->setLinkToNewBuilding(policeStation);
	pLoadCompo->setLink(pCheck);

	//POLICESTATION - BADGE 
	pBadge = Object::CreateObject(object);
	pBadge->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/Badge.png"));
	pBadge->GetTransform()->SetPosition(Vector2(100, 40));
	pBadge->SetIsActive(false);


	//FIRESTATION - TILECHECK 
	auto fCheck = Object::CreateObject();
	auto fCheckCompo = fCheck->AddComponent<TileCheck>();
	fCheck->AddComponent<BoxCollider>()->SetSize(Vector2(50*100,50*100));
	fCheckCompo->SetLink(map);
	fCheck->GetTransform()->SetDepth(3);
	fCheck->SetIsActive(false);

	//FIRESTATION - BUILDING
	fireStation = Object::CreateObject();
	fireStation->SetTag("FireStation");
	fireStation->GetTransform()->SetScale(Vector2(1.5, 1.5));
	fireStation->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/FireStation_Color.png"));
	fireStation->GetTransform()->SetPosition(object->GetTransform()->GetPosition() + Vector2(22, 112));
	fireStation->AddComponent<PolygonDraw>();
	fireStation->AddComponent<BoxCollider>();
	fireStation->AddComponent<BuildingComponent>()->SetBuilding(new NewBuilding(fireStation));
	fireStation->SetIsActive(false);

	fCheckCompo->SetLinkToBuilding(fireStation);

	//FIRESTATION - LOADBUTTON 
	fLoadButton = Object::CreateObject(object);
	auto fLoadCompo = fLoadButton->AddComponent<LoadButton>();
	fLoadButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/FireStation_Fixed.png"));
	fLoadButton->GetComponent<Sprite>()->SetDepth(30);
	fLoadButton->AddComponent<BoxCollider>();
	//pLoadButton->AddComponent<BoxCollider>()->SetSize(policeStation->GetComponent<BoxCollider>()->GetSize());
	fLoadButton->GetTransform()->SetPosition(Vector2(17, -114));
	fLoadButton->GetTransform()->SetDepth(30);
	fLoadButton->SetIsActive(false);

	fLoadCompo->setLinkToMap(map);
	fLoadCompo->setLinkToNewBuilding(fireStation);
	fLoadCompo->setLink(fCheck);

	//FIRESTATION - BADGE 
	fBadge = Object::CreateObject(object);
	fBadge->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/Badge.png"));
	fBadge->GetTransform()->SetPosition(Vector2(100, -200));
	fBadge->SetIsActive(false);


	//PAGE BUTTON
	auto pageText = Object::CreateObject(object);
	pageText->GetTransform()->SetPosition(Vector2(195, -247));
	pageNumText = pageText->AddComponent<Text>();
	pageNumText->CreateText(to_wstring(1), L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 20, 400, 40);

	//PAGE BUTTON
	auto buttonUp = Object::CreateObject(object);
	buttonUp->SetTag("PageButton_Up");
	buttonUp->GetTransform()->SetPosition(Vector2(30, -243));
	auto buttonUpSprite = buttonUp->AddComponent<Sprite>();
	buttonUp->AddComponent<BoxCollider>();
	buttonUpSprite->SetSprite(Image::CreateImage("Sprite/Construction/ConstructionPageButton.png"));
	buttonUpSprite->GetTransform()->SetScale(Vector2(0.8, 0.8));
	//buttonUp->AddComponent<PageButton>()->SetLink(this);

	auto buttonDown = Object::CreateObject(object);
	buttonDown->GetTransform()->SetPosition(Vector2(-30, -243));
	buttonDown->SetTag("PageButton_Down");
	auto buttonDownSprite = buttonDown->AddComponent<Sprite>();
	buttonDown->AddComponent<BoxCollider>();
	buttonDownSprite->SetSprite(Image::CreateImage("Sprite/Construction/ConstructionPageButton.png"));
	buttonDownSprite->GetTransform()->SetScale(Vector2(0.8, 0.8));
	buttonDownSprite->GetTransform()->SetRotation(180.0f);
	//buttonDown->AddComponent<PageButton>()->SetLink(this);


}

void LoadBox::Update()
{
	if (((NewBuilding*)(fireStation->GetComponent<BuildingComponent>()->GetBuilding()))->GetFixedPosition())
	{
		fBadge->SetIsActive(true);
		fLoadButton->SetIsActive(false);
		fLoadButton->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/FireStation_Fixed.png"));
	}

	if (((NewBuilding*)(policeStation->GetComponent<BuildingComponent>()->GetBuilding()))->GetFixedPosition())
	{
		pBadge->SetIsActive(true);
		pLoadButton->SetIsActive(false);
		pLoadButton->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/PoliceStation_Fixed.png"));
	}
}

void LoadBox::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::INFORMATION || loadOnce)
		return;

	if (event == "AllowExpansion")
	{
		fLoadButton->SetIsActive(true);
		fLoadButton->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/FireStation_Color.png"));
		fireStation->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/FireStation_Color.png"));
		pLoadButton->SetIsActive(true);
		pLoadButton->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/PoliceStation_Color.png"));
		policeStation->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Construction/PoliceStation_Color.png"));

		loadOnce = true;
	}
}
