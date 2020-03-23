#pragma once
#include "GgaetIp.h"
#include "AStar.h"
#include "TileMap.h"

#define SPEED 2

class RandomMove : public Script
{
private:
	Object* map;
	vector<Object*> vTotal;
	AStar* star;

	Transform* transform;
	Animator* animator;

	Vector2 currentIndex;
	Vector2 nextIndex;
	Vector2 targetIndex;

	bool arrived = true;
	bool stop = false;

	vector<Vector2> pos;
	Object* target;
	Object* current;
	float angle;
public:
	virtual void Init() override;
	virtual void Update() override;
	void Move();

	void SetLinkToMap(Object* map) { this->map = map; }
	void SetDirection();
	
	//test
	void SetTarget();
	float GetAngle(Vector2 startPos, Vector2 endPos)
	{
		float x = startPos.x - endPos.x;
		float y = startPos.y - endPos.y;
		float angle = -atan2f(y, x);

		return angle;
	}
};

