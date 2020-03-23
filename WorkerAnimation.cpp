#include "stdafx.h"
#include "WorkerAnimation.h"

void WorkerAnimation::Init()
{
	auto animator = object->GetComponent<Animator>();
	_sprite = object->GetComponent<Sprite>();

#pragma region AddAnimation
	//=========================================== MoveAnimation
	Animation leftMove;
	leftMove.SetFrameCount(Vector2(4, 1));
	leftMove.SetRepeat(true);
	leftMove.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Move_Left.png"));
	leftMove.SetTime(0.1f);
	animator->AddAnimation("Worker_LRMove", leftMove);

	Animation upMove;
	upMove.SetFrameCount(Vector2(4, 1));
	upMove.SetRepeat(true);
	upMove.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Move_Back.png"));
	upMove.SetTime(0.1f);
	animator->AddAnimation("Worker_UpMove", upMove);

	Animation downMove;
	downMove.SetFrameCount(Vector2(4, 1));
	downMove.SetRepeat(true);
	downMove.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Move_Front.png"));
	downMove.SetTime(0.1f);
	animator->AddAnimation("Worker_DownMove", downMove);

	//=========================================== Idle Animation
	Animation frontIdle;
	frontIdle.SetFrameCount(Vector2(1, 1));
	frontIdle.SetRepeat(false);
	frontIdle.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Idle_Front.png"));
	frontIdle.SetTime(0.1f);
	animator->AddAnimation("Worker_Idle_Front", frontIdle);

	Animation leftIdle;
	leftIdle.SetFrameCount(Vector2(1, 1));
	leftIdle.SetRepeat(false);
	leftIdle.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Idle_Left.png"));
	leftIdle.SetTime(0.1f);
	animator->AddAnimation("Worker_Idle_Left", leftIdle);

	Animation backIdle;
	backIdle.SetFrameCount(Vector2(1, 1));
	backIdle.SetRepeat(false);
	backIdle.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Idle_Back.png"));
	backIdle.SetTime(0.1f);
	animator->AddAnimation("Worker_Idle_Back", backIdle);

	Animation rightIdle;
	rightIdle.SetFrameCount(Vector2(1, 1));
	rightIdle.SetRepeat(false);
	rightIdle.SetImage(Image::CreateImage("Sprite/" + object->GetName() + "_Idle_Right.png"));
	rightIdle.SetTime(0.1f);
	animator->AddAnimation("Worker_Idle_Right", rightIdle);
#pragma endregion

#pragma region Transition

	animator->AddParameter<int>("Move");

	// Left, Right Move Trans
	auto m2u = animator->MakeTransition("Worker_LRMove", "Worker_UpMove");
	m2u->SetCondition("Move", 0, ConditionType::Greater);
	auto m2d = animator->MakeTransition("Worker_LRMove", "Worker_DownMove");
	m2d->SetCondition("Move", 0, ConditionType::Less);
	auto m2i = animator->MakeTransition("Worker_LRMove", "Worker_Idle_Front");
	m2i->SetCondition("Move", 3, ConditionType::Equal);
	auto m2li = animator->MakeTransition("Worker_LRMove", "Worker_Idle_Left");
	m2li->SetCondition("Move", 2, ConditionType::Equal);
	auto m2di = animator->MakeTransition("Worker_LRMove", "Worker_Idle_Back");
	m2di->SetCondition("Move", 4, ConditionType::Equal);

	// Down Move Trans
	auto d2m = animator->MakeTransition("Worker_DownMove", "Worker_LRMove");
	d2m->SetCondition("Move", 0, ConditionType::Equal);
	auto d2u = animator->MakeTransition("Worker_DownMove", "Worker_UpMove");
	d2u->SetCondition("Move", 0, ConditionType::Greater);
	auto d2i = animator->MakeTransition("Worker_DownMove", "Worker_Idle_Front");
	d2i->SetCondition("Move", 3, ConditionType::Equal);
	auto d2li = animator->MakeTransition("Worker_DownMove", "Worker_Idle_Left");
	d2li->SetCondition("Move", 2, ConditionType::Equal);
	auto d2di = animator->MakeTransition("Worker_DownMove", "Worker_Idle_Back");
	d2di->SetCondition("Move", 4, ConditionType::Equal);

	// Up Move Trans
	auto u2d = animator->MakeTransition("Worker_UpMove", "Worker_DownMove");
	u2d->SetCondition("Move", 0, ConditionType::Less);
	auto u2i = animator->MakeTransition("Worker_UpMove", "Worker_Idle_Front");
	u2i->SetCondition("Move", 3, ConditionType::Equal);
	auto u2m = animator->MakeTransition("Worker_UpMove", "Worker_LRMove");
	u2m->SetCondition("Move", 0, ConditionType::Equal);
	auto u2li = animator->MakeTransition("Worker_UpMove", "Worker_Idle_Left");
	u2li->SetCondition("Move", 2, ConditionType::Equal);
	auto u2di = animator->MakeTransition("Worker_UpMove", "Worker_Idle_Back");
	u2di->SetCondition("Move", 4, ConditionType::Equal);

	// Front Idle Trans
	auto i2m = animator->MakeTransition("Worker_Idle_Front", "Worker_LRMove");
	i2m->SetCondition("Move", 0, ConditionType::Equal);
	auto i2u = animator->MakeTransition("Worker_Idle_Front", "Worker_UpMove");
	i2u->SetCondition("Move", -1, ConditionType::Equal);
	auto i2d = animator->MakeTransition("Worker_Idle_Front", "Worker_DownMove");
	i2d->SetCondition("Move", 1, ConditionType::Equal);
	auto i2li = animator->MakeTransition("Worker_Idle_Front", "Worker_Idle_Left");
	i2li->SetCondition("Move", 2, ConditionType::Equal);
	auto i2di = animator->MakeTransition("Worker_Idle_Front", "Worker_Idle_Back");
	i2di->SetCondition("Move", 4, ConditionType::Equal);

	// Left, Right Idle Trans
	auto li2m = animator->MakeTransition("Worker_Idle_Left", "Worker_LRMove");
	li2m->SetCondition("Move", 0, ConditionType::Equal);
	auto li2i = animator->MakeTransition("Worker_Idle_Left", "Worker_Idle_Front");
	li2i->SetCondition("Move", 3, ConditionType::Equal);
	auto li2u = animator->MakeTransition("Worker_Idle_Left", "Worker_UpMove");
	li2u->SetCondition("Move", -1, ConditionType::Equal);
	auto li2d = animator->MakeTransition("Worker_Idle_Left", "Worker_DownMove");
	li2d->SetCondition("Move", 1, ConditionType::Equal);
	auto li2di = animator->MakeTransition("Worker_Idle_Left", "Worker_Idle_Back");
	li2di->SetCondition("Move", 4, ConditionType::Equal);

	// Back Idle Trans
	auto di2i = animator->MakeTransition("Worker_Idle_Back", "Worker_Idle_Front");
	di2i->SetCondition("Move", 3, ConditionType::Equal);
	auto di2m = animator->MakeTransition("Worker_Idle_Back", "Worker_LRMove");
	di2m->SetCondition("Move", 0, ConditionType::Equal);
	auto di2u = animator->MakeTransition("Worker_Idle_Back", "Worker_UpMove");
	di2u->SetCondition("Move", -1, ConditionType::Equal);
	auto di2d = animator->MakeTransition("Worker_Idle_Back", "Worker_DownMove");
	di2d->SetCondition("Move", 1, ConditionType::Equal);
	auto di2li = animator->MakeTransition("Worker_Idle_Back", "Worker_Idle_Left");
	di2li->SetCondition("Move", 2, ConditionType::Equal);


#pragma endregion 

}


