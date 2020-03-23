#pragma once
#include "GgaetIp.h"
#include <time.h>
#include "WorkerMove.h"

class WorkerMove;

class WorkerAnimation : public Script
{
private:
	int _rand;
	Sprite* _sprite;
	WorkerMove* _worker;
public:

	virtual void Init();

	void SetWorker(WorkerMove* m) { _worker = m; }
};

