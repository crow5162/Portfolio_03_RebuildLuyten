#include "stdafx.h"
#include "Logo.h"
#include "FadeInAndOut.h"
#include "GameStartButton.h"

void Logo::Play()
{
	Object* logo = Object::CreateObject();
	logo->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/EZGameName.png"));
	logo->AddComponent<BoxCollider>();
	auto logoPhysics = logo->AddComponent<Physics>();
	logoPhysics->SetRestitution(0.3f);
	logoPhysics->SetGravityScale(1.f);
	auto logoTransform = logo->GetTransform();
	logoTransform->SetScale(Vector2(0.7f, 0.7f));
	logoTransform->SetPosition(Vector2(0, 700));
	logo->GetTransform()->SetDepth(99999999);

	Object* dummyGround = Object::CreateObject();
	dummyGround->GetTransform()->SetPosition(Vector2(0, -100));
	dummyGround->AddComponent<BoxCollider>()->SetSize(Vector2(DesignResolution.x, 50));


	Object* subTitle = Object::CreateObject();
	subTitle->GetTransform()->SetScale(Vector2(0.7f, 0.7f));
	subTitle->GetTransform()->SetPosition(Vector2(0, -100));
	auto subTitleSprite = subTitle->AddComponent<Sprite>();
	subTitleSprite->SetSprite(Image::CreateImage("Sprite/UI/EZGameSubTitle.png"));
	subTitle->GetTransform()->SetDepth(999999999);
	auto subTitleFadeIn = subTitle->AddComponent<FadeInAndOut>();
	subTitleFadeIn->SetStartDelay(3.f);
	subTitleFadeIn->SetDuration(1.5f);
	subTitleFadeIn->SetDelay(9.f);


	Object* gameStartButton = Object::CreateObject();
	gameStartButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/GameStartButton.png"));
	gameStartButton->GetTransform()->SetPosition(Vector2(0, -220));
	gameStartButton->GetTransform()->SetScale(Vector2(0.8f, 0.8f));
	gameStartButton->AddComponent<BoxCollider>();
	gameStartButton->AddComponent<GameStartButton>();
	auto buttonFadeIn = gameStartButton->AddComponent<FadeInAndOut>();
	buttonFadeIn->SetStartDelay(5.f);
	buttonFadeIn->SetDuration(1.5f);
	buttonFadeIn->SetDelay(9.f);
}
