#include "stdafx.h"
#include "AchievementBox.h"

void AchievementBox::Init()
{
	box = object->AddComponent<Sprite>();
	box->SetSprite(Image::CreateImage("Sprite/Achievement/AchievementBox.png"));
	box->GetTransform()->SetScaleY(0.95);
	
	auto bar = Object::CreateObject(object);
	progressBar = bar->AddComponent<Sprite>();
	progressBar->SetSprite(Image::CreateImage("Sprite/Achievement/ProgressBar.png"));
	progressBar->GetTransform()->SetScaleX(0.f);
	bar->GetTransform()->SetPosition(Vector2(-67, -24));
	progressBar->GetTransform()->SetAnchorPoint(Vector2(0, 0.5));
	progressBar->SetCameraAffected(false);

	auto titleText = Object::CreateObject(object);
	title = titleText->AddComponent<Text>();
	title->GetTransform()->SetPosition(Vector2(16, 20));
	title->CreateText(text.first, L"¸¼Àº °íµñ", L"ko-KR", { 0,0,0,1}, 18, 400, 40);
	title->SetAnchorPoint(AnchorPoint::Center);
	title->SetDepth((int)ZORDER::UI);
	title->SetCameraAffected(false);

	auto contentText = Object::CreateObject(object);
	content = contentText->AddComponent<Text>();
	content->GetTransform()->SetPosition(Vector2(16, 0));
	content->CreateText(text.second, L"¸¼Àº °íµñ", L"ko-KR", { 0,0,0,1 }, 13, 400, 40);
	content->SetAnchorPoint(AnchorPoint::Center);
	content->SetCameraAffected(false);

	auto ratioText = Object::CreateObject(object);
	ratio = ratioText->AddComponent<Text>();
	ratio->GetTransform()->SetPosition(Vector2(16, -23));
	ratio->CreateText(to_wstring(currentNum)+L"/"+to_wstring(notifyNum), L"¸¼Àº °íµñ", L"ko-KR", { 1,1,1,1 }, 14, 400, 40);
	ratio->SetAnchorPoint(AnchorPoint::Center);
	ratio->SetDepth((int)ZORDER::UI + 100);
	ratio->SetCameraAffected(false);


	auto trophyobj = Object::CreateObject(object);
	trophy = trophyobj->AddComponent<Sprite>();
	trophy->SetSprite(Image::CreateImage("Sprite/Achievement/trophy_gold.png"));
	trophyobj->GetTransform()->SetPosition(Vector2(-105, 0));
	trophy->SetOpacity(0.1f);
	trophy->SetCameraAffected(false);


}

void AchievementBox::SetProgress()
{
	if (trophy->GetOpacity() == 1.0f)
		return;
	currentNum++;
	if (notifyNum == currentNum)
		trophy->SetOpacity(1.f);
	progressBar->GetTransform()->SetScaleX((float)currentNum / (float)notifyNum);
	ratio->ChangeText(to_wstring(currentNum) + L"/" + to_wstring(notifyNum));
	ratio->SetAnchorPoint(AnchorPoint::Center);
}
