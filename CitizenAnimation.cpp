#include "stdafx.h"
#include "CitizenAnimation.h"

void CitizenAnimation::Init()
{
	auto animator = object->GetComponent<Animator>();

	Animation moveLeftRight;
	moveLeftRight.SetFrameCount(Vector2(4, 1));
	moveLeftRight.SetRepeat(true);
	moveLeftRight.SetImage(Image::CreateImage("Sprite/" + object->GetTag() + "_Move_Left.png"));
	moveLeftRight.SetTime(0.07f);
	animator->AddAnimation("Citizen_MoveLeftRight", moveLeftRight);

	Animation moveUp;
	moveUp.SetFrameCount(Vector2(4, 1));
	moveUp.SetRepeat(true);
	moveUp.SetImage(Image::CreateImage("Sprite/" + object->GetTag() + "_Move_Front.png"));
	moveUp.SetTime(0.07f);
	animator->AddAnimation("Citizen_MoveUp", moveUp);

	Animation moveDown;
	moveDown.SetFrameCount(Vector2(4, 1));
	moveDown.SetRepeat(true);
	moveDown.SetImage(Image::CreateImage("Sprite/" + object->GetTag() + "_Move_Back.png"));
	moveDown.SetTime(0.07f);
	animator->AddAnimation("Citizen_MoveDown", moveDown);

	animator->AddParameter<int>("Move");

	auto leftRightToUp = animator->MakeTransition("Citizen_MoveLeftRight", "Citizen_MoveUp");
	leftRightToUp->SetCondition("Move", 3, ConditionType::Equal);

	auto UpToLeftRight = animator->MakeTransition("Citizen_MoveUp", "Citizen_MoveLeftRight");
	UpToLeftRight->SetCondition("Move", 0, ConditionType::Equal);

	auto leftRightToDown = animator->MakeTransition("Citizen_MoveLeftRight", "Citizen_MoveDown");
	leftRightToDown->SetCondition("Move", 1, ConditionType::Equal);

	auto downToLeftRight = animator->MakeTransition("Citizen_MoveDown", "Citizen_MoveLeftRight");
	downToLeftRight->SetCondition("Move", 0, ConditionType::Equal);

	auto upToDown = animator->MakeTransition("Citizen_MoveUp", "Citizen_MoveDown");
	upToDown->SetCondition("Move", 1, ConditionType::Equal);

	auto downToUp = animator->MakeTransition("Citizen_MoveDown", "Citizen_MoveUp");
	downToUp->SetCondition("Move", 3, ConditionType::Equal);

}
