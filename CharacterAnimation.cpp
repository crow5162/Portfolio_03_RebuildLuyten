#include "stdafx.h"
#include "CharacterAnimation.h"

void CharacterAnimation::Init()
{
	auto animator = object->GetComponent<Animator>();

	
	//1. 필요한 프레임이미지(애니메이션) ADD

	Animation idle;
	//프레임 갯수 (X,Y)
	idle.SetFrameCount(Vector2(2, 1));
	//반복 여부 
	idle.SetRepeat(true);
	idle.SetImage(Image::CreateImage("Sprite/ErikIdle.png"));
	//프레임 돌리는 속도 (1에 가까워질 수록 빠르다)
	idle.SetTime(0.1f);
	animator->AddAnimation("Erik_Idle", idle); 

	Animation jump;
	jump.SetFrameCount(Vector2(4, 1));
	jump.SetRepeat(false);
	jump.SetImage(Image::CreateImage("Sprite/ErikJump.png"));
	jump.SetTime(0.2f);
	animator->AddAnimation("Erik_Jump", jump);

	Animation run;
	run.SetFrameCount(Vector2(8, 1));
	run.SetRepeat(true);
	run.SetImage(Image::CreateImage("Sprite/ErikRun.png"));
	run.SetTime(0.1f);
	animator->AddAnimation("Erik_Run", run);

	//2. 다른 프레임이미지로 전환 조건 만들기 
	//   인자값으로 int,bool,float이 있음.
	animator->AddParameter<int>("Run");
	animator->AddParameter<bool>("Jump");


	//(1). INT를 인자값으로 쓰는 예


	//IDLE에서 RUN으로 가는 트랜지션 
	//RUN 조건이 0과 다를때 전환
	auto itor = animator->MakeTransition("Erik_Idle", "Erik_Run");
	itor->SetCondition("Run", 0,ConditionType::NotEqual);

	//RUN에서 IDLE로 가는 트랜지션
	//RUN 조건이 0과 같을때 전환
	//밑의 예와는 달리 이런식으로 조건을 줘서 오른쪽,왼쪽 같이 눌러도 IDLE 상태 유지. 
	auto rtoi = animator->MakeTransition("Erik_Run", "Erik_Idle");
	rtoi->SetCondition("Run", 0,ConditionType::Equal);

	//(2) BOOL을 인자값으로 쓰는 예

	//IDLE에서 점프로 가는 트랜지션 
	//JUMP 조건이 true일때 
	auto itoj = animator->MakeTransition("Erik_Idle", "Erik_Jump");
	itoj->SetCondition("Jump", true);

	//점프에서 IDLE로 가는 트랜지션
	//JUMP 조건이 false일때 
	auto jtoi = animator->MakeTransition("Erik_Jump", "Erik_Idle");
	jtoi->SetCondition("Jump", false);


}