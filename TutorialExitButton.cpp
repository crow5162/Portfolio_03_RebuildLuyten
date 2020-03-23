#include "stdafx.h"
#include "TutorialExitButton.h"
#include "TutorialScene.h"
#include "SetPopulationScene.h"


void TutorialExitButton::OnMouseDown()
{
	SceneManager::GetInstance()->PopScene(); 
}
