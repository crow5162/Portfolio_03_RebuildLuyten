#include "stdafx.h"
#include "PlayerGame.h"




void PlayerGame::Init()
{
	//nowScene에서 클릭했을 때 Zoom In이 되면 게임을 시작하게끔 카메라 가져오기
	if (_house->GetInPutKey() == true)
	{
		_isGameStart = true;
	}

	if (_house->GetInPutKey() == false)
	{
		_isGameStart = false;
	}
}

void PlayerGame::Update()
{
	if (_isGameStart == true)
	{
		//아이콘이 등장하는 시간차를 두게 타이머를 줄까요? 
		//fallingItem(); 

	}

	//플레이 중이면 bool값을 입력 --> bool값의 기준은 //nowScene에서 클릭했을 때 Zoom In인 경우 
	//{
		//fallingItem -->아이템 떨어지는 클래스 불러오기 bulletFire(); 
		//SetIcon(); 

		//ChooseItem(); --> 플레이어가 아이템 선택하기 
		//ChooseItem(); --> 플레이어 아이템과 falling item의 순서를 비교


		//순서 같을 경우 
	
	//--> 다시 falling Item(); 
	//}

	//플레이 중이 아닐 때 --> 벡터와 비교했을 때 잘못된 선택을 하면 게임 종료 --> zoom out
}



void PlayerGame::SetIcon()
{
	//버튼의 투명도를 조절해서 setopacity 


	//Air->GetTransform()->SetPosition(Vector2(50, -70));
	//Air->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Air.png"));
	//Air->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.2f, 0.2f));

	//Water->GetTransform()->SetPosition(Vector2(-10, -150));
	//Water->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Water.png"));
	//Water->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.2f, 0.2f));

	//Wood->GetTransform()->SetPosition(Vector2(110, -150));
	//Wood->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/Wood.png"));
	//Wood->GetComponent<Sprite>()->GetTransform()->SetScale(Vector2(0.2f, 0.2f));

}


void PlayerGame::ChooseItem()
{
}

void PlayerGame::Result()
{
}
