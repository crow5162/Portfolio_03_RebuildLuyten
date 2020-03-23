#include "stdafx.h"
#include "LogoAndTitleScene.h"
#include "GameScene.h"
#include "FadeInAndOut.h"
#include "SetPopulationScene.h"
#include "MapManager.h"
#include "MoveBackground.h"
#include "Logo.h"

void LogoAndTitleScene::Init()
{
	ApplicationManager::GetInstance()->SetResolution(1600, 900, false);
	CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->SetScale(Vector2(1.2f,1.2f));

	Object* ezLogo = Object::CreateObject();
	ezLogo->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/EZlogoScene.png"));
	auto ezLogoComponent = ezLogo->AddComponent<FadeInAndOut>();
	ezLogoComponent->SetStartDelay(1.f);
	ezLogoComponent->SetDuration(2.f);
	ezLogoComponent->SetDelay(1.2f);
	ezLogoComponent->SetCallBackFunc([&]()
		{
			Object* logo = Object::CreateObject();
			logo->AddComponent<Logo>();

			Object* city = Object::CreateObject();
			city->GetTransform()->SetPosition(Vector2(-300, 1500));
			city->GetTransform()->SetScale(Vector2(1.f, 1.f));
			auto cityMove = city->AddComponent<MoveBackground>();
			cityMove->SetSpeed(Vector2(-100, -300));
			cityMove->SetEndTime(5.5f);
			cityMove->SetLogo(logo->GetComponent<Logo>());
			MapManager::GetInstance()->Load("CityMap", city);
			auto cityFade = city->AddComponent<FadeInAndOut>();
			cityFade->SetDuration(0.01f);
			cityFade->SetStartDelay(2.1f);
			cityFade->SetDelay(99999999999.f);

			Object* forest = Object::CreateObject();
			MapManager::GetInstance()->Load("TileMap_Forest", forest);
			auto forestMove = forest->AddComponent<MoveBackground>();
			forestMove->SetSpeed(Vector2(-90, 0));
			auto forestFade = forest->AddComponent<FadeInAndOut>();
			forestFade->SetDuration(2.f);
			forestFade->SetDelay(0.8f);
			//forestMove->SetTime(4.f);
		});


	//게임 스타트 버튼을 따로 만들어? 
	//logoScene->SetCallBackFunc([&]() //mainGameTitle이 끝났을 때 특정 함수 실행시키고 싶으면 람다로 불러오기 
	//{
	//	//인구 조정 씬으로 씬 전환
	//	SceneManager::GetInstance()->PushScene(new SetPopulationScene());
	//});
	
	//맵 불러오는 법
	//MapManager::GetInstance()->Load("ForestMap");

}