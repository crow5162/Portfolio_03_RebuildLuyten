#include "stdafx.h"
#include "TutorialScene.h"
#include "TutorialExitButton.h"


void TutorialScene::Init()
{
	CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->SetScale(Vector2(1,1));
	this->SetTag("TutorialScene");

	ApplicationManager::GetInstance()->SetResolution(1600, 900, false);

	Object* gameTutorialImage = Object::CreateObject(); 
	gameTutorialImage->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/GameInstruction.png"));
	gameTutorialImage->GetComponent<Sprite>()->SetCameraAffected(false); 
	gameTutorialImage->GetTransform()->SetPosition(Vector2(-6,20) + (DesignResolution * Vector2(1, -1) / 2));
	gameTutorialImage->SetCameraAffected(false);

	// GameTutorial Exit Buttom
	Object* exitButton = Object::CreateObject();
	exitButton->AddComponent<TutorialExitButton>();
	exitButton->AddComponent<BoxCollider>();
	exitButton->GetComponent<BoxCollider>()->SetSize(Vector2(20, 20));
	exitButton->GetTransform()->SetPosition(Vector2(710,355));
	exitButton->GetComponent<TutorialExitButton>()->SetLinkWithTutorialScene(this);
 
}
