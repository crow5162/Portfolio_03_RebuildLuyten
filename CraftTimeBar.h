#pragma once
#include "GgaetIp.h"

enum CRAFTSTATE
{
	CRAFTING,
	INTERVAL
};

class CraftTimeBar : public Script
{
private:
	Object* _workArea;

	CRAFTSTATE _craftState;

	float _startTime;
	float _infoTime;

	float _startPosX, _startPosY;
	float _maxPosX;

	float _barLength = 150;

	bool _isDone = false;

	
	vector<Vector2> _polygonPos;  


	PolygonDraw* _polydraw;
	Color _color;

public:
	virtual void Init();
	virtual void Update();

	void SetStartTime(float time) { _startTime = time; }

	void SetLink(Object* b) { _workArea	= b; }

	bool GetIsDone()			{ return _isDone; }
	void SetIsDone(bool tf)		{ _isDone = tf; }

	void SetCraftState(CRAFTSTATE c) { _craftState = c; }
	CRAFTSTATE GetCraftState() { return _craftState; }
};

