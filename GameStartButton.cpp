#include "stdafx.h"
#include "GameStartButton.h"
#include "TutorialScene.h"
#include "SetPopulationScene.h"

void GameStartButton::Init()
{
	sprite = object->GetComponent<Sprite>();
}

void GameStartButton::OnMouseDown()
{
	if (sprite->GetOpacity() >= 1)
	{
		SceneManager::GetInstance()->PushScene(new SetPopulationScene);
		SceneManager::GetInstance()->PushScene(new TutorialScene);
	}	
}
