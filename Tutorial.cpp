#include "stdafx.h"
#include "Tutorial.h"

void Tutorial::Init()
{
	//튜토리얼 내용 관리 
	tagTutorialInfo achievement;
	achievement.name = "Achievement";
	achievement.position = Vector2(500, 300);
	achievement.spriteRoute = "Sprite/Tutorial/Tutorial_Achievement.png";
	vTutorialInfo.push_back(achievement);

	tagTutorialInfo construction;
	construction.name = "Construction";
	construction.spriteRoute = "Sprite/Tutorial/Tutorial_Achievement.png";
	construction.position = Vector2::zero;
	vTutorialInfo.push_back(construction);

	tagTutorialInfo time;
	time.name = "Time";
	time.spriteRoute = "Sprite/Tutorial/Tutorial_Time.png";
	time.position = Vector2::zero;
	vTutorialInfo.push_back(time);

	for (int i = 0; i < vTutorialInfo.size(); i++)
	{
		auto tutorialBox = Object::CreateObject();
		tutorialBox->SetName(vTutorialInfo[i].name);
		tutorialBox->GetTransform()->SetPosition(vTutorialInfo[i].position);
		tutorialBox->GetTransform()->SetScale(Vector2(0.7, 0.7));
		auto spriteCompo = tutorialBox->AddComponent<Sprite>();
		spriteCompo->SetSprite(Image::CreateImage(vTutorialInfo[i].spriteRoute));
		spriteCompo->SetOpacity(0.f);
		vTutorialBox.push_back(make_pair(tutorialBox, vTutorialInfo[i]));
	}
}

void Tutorial::Update()
{
	FadeOut();
}


void Tutorial::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::TUTORIAL)
		return;

	for (int i = 0; i < vTutorialBox.size(); i++)
	{
		if (vTutorialBox[i].first->GetName() != event || vTutorialBox[i].second.isNotified)
			return;

		vTutorialBox[i].second.alphaTime = TimeManager::GetInstance()->GetTime();
		vTutorialBox[i].second.isNotified = true;
		vTutorialBox[i].first->GetComponent<Sprite>()->SetOpacity(1.f);
	}
}

void Tutorial::FadeOut()
{
	for (int i = 0; i < vTutorialBox.size(); i++)
	{
		auto spriteCompo = vTutorialBox[i].first->GetComponent<Sprite>();

		if (!vTutorialBox[i].second.isNotified || !spriteCompo->GetOpacity() ||
			TimeManager::GetInstance()->GetTime() - vTutorialBox[i].second.alphaTime < 1)
			return;


		spriteCompo->SetOpacity(spriteCompo->GetOpacity() - 0.01f);

	}
}
