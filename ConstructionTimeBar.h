#pragma once
#include "GgaetIp.h"

class ConstructionTimeBar :	public Script
{
private:
	Object* _building;

	float _startTime;
	float _infoTime;

	float _startPosX;
	float _maxPosX;

	float _barLength = 200;

	bool _decreaseResource = false;
	

	// TimeBar¿ë PolyDraw
	vector<Vector2> _polygonPos;
	PolygonDraw* _polydraw;
	Color _color;

public:
	virtual void Init();
	virtual void Update();

	void SetStartTime(float time) { _startTime = time; }

	void SetLink(Object* b) { _building = b; }
};