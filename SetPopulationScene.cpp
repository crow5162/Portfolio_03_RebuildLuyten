#include "stdafx.h"
#include "SetPopulationScene.h"
#include "WorkerPanel.h"


void SetPopulationScene::Init()
{

	this->SetTag("SetPopulationScene");

	ApplicationManager::GetInstance()->SetResolution(1600, 900, false);

	Object* setPopulationScene = Object::CreateObject();
	setPopulationScene->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/SetPopulation.png"));
	setPopulationScene->GetTransform()->SetPosition(Vector2(0, 0) + (DesignResolution * Vector2(1, -1) / 2));
	setPopulationScene->AddComponent<WorkerPanel>(); 
	setPopulationScene->SetCameraAffected(false); 

}
