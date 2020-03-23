#include "stdafx.h"
#include "WorkerMove.h"

void WorkerMove::Init()
{
	_transform = object->GetTransform();
	_animator = object->GetComponent<Animator>();
	_sprite = object->GetComponent<Sprite>();
	_count = TimeManager::GetInstance()->GetTime();

	_startPoint = _transform->GetPosition();

	_rand = rand() % 8;
	_timeRand = rand() % 4;
	srand(time(NULL));

	_moveSet = (MOVESET)_rand;
}

void WorkerMove::Update()
{

	//1초마다 MoveSet Random Setting
	if (TimeManager::GetInstance()->GetTime() - _count > 2)
	{
		_rand = rand() % 8;
		_moveSet = (MOVESET)_rand;

		if (_moveSet == MOVESET::IDLE_FRONT || _moveSet == MOVESET::IDLE_LEFT || _moveSet == MOVESET::IDLE_RIGHT
			|| _moveSet == MOVESET::IDLE_BACK)
			_count = TimeManager::GetInstance()->GetTime() + 10;

		else if (_moveSet != MOVESET::IDLE_FRONT)
			_count = TimeManager::GetInstance()->GetTime();
	}

	MovePattern();
	MoveRangeSet();
}

void WorkerMove::MovePattern()
{
	int moveDirection = 0;

	if (_moveSet == MOVESET::MOVE_LEFT)
	{
		_sprite->SetFlip(false);
		_transform->Translate(Vector2(-2, 0));
		moveDirection = 0;
	}
	else if (_moveSet == MOVESET::MOVE_RIGHT)
	{
		_sprite->SetFlip(true);
		_transform->Translate(Vector2(2, 0));
		moveDirection = 0;
	}
	else if (_moveSet == MOVESET::MOVE_UP)
	{
		_transform->Translate(Vector2(0, -2));
		moveDirection -= 1;
	}
	else if (_moveSet == MOVESET::MOVE_DOWN)
	{
		_transform->Translate(Vector2(0, 2));
		moveDirection += 1;
	}
	else if (_moveSet == MOVESET::IDLE_FRONT)
	{
		moveDirection += 3;
	}
	else if (_moveSet == MOVESET::IDLE_LEFT)
	{
		_sprite->SetFlip(false);
		moveDirection = 2;
	}
	else if (_moveSet == MOVESET::IDLE_RIGHT)
	{
		_sprite->SetFlip(true);
		moveDirection = 2;
	}
	else if (_moveSet == MOVESET::IDLE_BACK)
	{
		moveDirection = 4;
	}

	_animator->SetParameter("Move", moveDirection);
}

void WorkerMove::MoveRangeSet()
{
	Vector2 temp = _startPoint - object->GetTransform()->GetPosition();
	float distance = temp.Magnitude();

	//distance 벗어나려고 하면 받고있던 State의 반대방향 State를 주어서 돌아가게 하였다.
	if (distance >= 50 && !_isChange)
	{
		if (_moveSet == MOVESET::MOVE_LEFT)			_moveSet = MOVESET::MOVE_RIGHT;
		else if (_moveSet == MOVESET::MOVE_RIGHT)	_moveSet = MOVESET::MOVE_LEFT;
		else if (_moveSet == MOVESET::MOVE_UP)		_moveSet = MOVESET::MOVE_DOWN;
		else if (_moveSet == MOVESET::MOVE_DOWN)	_moveSet = MOVESET::MOVE_UP;

		//끼임현상있어서 bool
		_isChange = true;
	}
	else if (distance < 50 && _isChange) _isChange = false;

}
