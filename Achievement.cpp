#include "stdafx.h"
#include "Achievement.h"
#include "AchievementBox.h"
#include "PageButton.h"
void Achievement::Init()
{
	//업적 관리 
	aList.push_back(aInfo{ L"수리의 귀재", L"마을의 건물을 4 채 수리하세요." , 4 });
	aList.push_back(aInfo{ L"수리의 대가", L"마을의 건물을 8 채 수리하세요.", 1 });
	aList.push_back(aInfo{ L"재료는 모든 것의 시작", L"재료를 300개 모으세요.",300 });
	aList.push_back(aInfo{ L"한 단계 더 높게", L"2차 가공에 도전하세요." ,1 });
	aList.push_back(aInfo{ L"더 큰 마을으로", L"인구가 50명으로 늘어났습니다.",50});

	maxPageNum = aList.size() / 4;

	for (int i = 0; i < aList.size(); i++)
	{
		auto newAchievement = Object::CreateObject(object);
		newAchievement->GetTransform()->SetPosition(Vector2(0, 125 - (i%4) * 90));
		newAchievement->SetCameraAffected(false);
		auto boxcompo = newAchievement->AddComponent<AchievementBox>();
		boxcompo->SetString(make_pair(aList[i].title,aList[i].content));
		boxcompo->SetNotifyNum(aList[i].notifyNum);
		aBox.push_back(newAchievement);
	}

	auto pageText = Object::CreateObject(object);
	pageText->SetCameraAffected(false);
	pageText->GetTransform()->SetPosition(Vector2(195, -207));
	pageNumText = pageText->AddComponent<Text>();
	pageNumText->CreateText(to_wstring(1), L"맑은 고딕", L"ko-KR", { 1,1,1,1 }, 20, 400, 40);

	//PAGE BUTTON
	auto buttonUp = Object::CreateObject(object);
	buttonUp->SetCameraAffected(false);
	buttonUp->SetTag("PageButton_Up");
	buttonUp->GetTransform()->SetPosition(Vector2(30, -203));
	auto buttonUpSprite = buttonUp->AddComponent<Sprite>();
	buttonUp->AddComponent<BoxCollider>();
	buttonUpSprite->SetSprite(Image::CreateImage("Sprite/UI/Button_Plus_Icon.png"));
	buttonUpSprite->GetTransform()->SetRotation(270.0f);
	buttonUpSprite->GetTransform()->SetScale(Vector2(0.8, 0.8));
	buttonUp->AddComponent<PageButton>()->SetLink(this);

	auto buttonDown = Object::CreateObject(object);
	buttonDown->SetCameraAffected(false);

	buttonDown->GetTransform()->SetPosition(Vector2(-30, -203));
	buttonDown->SetTag("PageButton_Down");
	auto buttonDownSprite = buttonDown->AddComponent<Sprite>();
	buttonDown->AddComponent<BoxCollider>();
	buttonDownSprite->SetSprite(Image::CreateImage("Sprite/UI/Button_Plus_Icon.png"));
	buttonDownSprite->GetTransform()->SetScale(Vector2(0.8, 0.8));
	buttonDownSprite->GetTransform()->SetRotation(90.0f);
	buttonDown->AddComponent<PageButton>()->SetLink(this);

	SetPageNum(1);
}


void Achievement::OnNotify(MSGTYPE type, string event)
{
	if (type != MSGTYPE::INFORMATION)
		return;

	for (int i = 0; i < aList.size(); i++)
		if (aList[i].title == string_to_wstring(event))
		{
			aBox[i]->GetComponent<AchievementBox>()->SetProgress();
			if (aBox[i]->GetComponent<AchievementBox>()->GetProgress() != 0)
				Notify(MSGTYPE::TUTORIAL, "Achievement");

			if (aBox[1]->GetComponent<AchievementBox>()->GetProgress())
				Notify(MSGTYPE::INFORMATION, "AllowExpansion");
			
		}

}

