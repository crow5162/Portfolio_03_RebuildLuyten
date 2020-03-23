#pragma once
#include "GgaetIp.h"
#include <time.h>

enum class MOVESET
{
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_UP,
	MOVE_DOWN,
	IDLE_FRONT,
	IDLE_LEFT,
	IDLE_RIGHT,
	IDLE_BACK
};

class WorkerMove : public Script
{
private:
	Transform* _transform;
	Animator* _animator;
	Sprite* _sprite;

	MOVESET _moveSet = MOVESET::IDLE_FRONT;

	int _count;

	int _rand;
	int _timeRand;

	Vector2 _startPoint;

	bool _isChange;

public:
	virtual void Init() override;
	virtual void Update() override;

	void MovePattern();
	void MoveRangeSet();

	MOVESET GetWorkerState() { return _moveSet; }

};

