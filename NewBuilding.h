#pragma once
#include "Building.h"
#include "Observer.h"
class NewBuilding: public Building
{
private:
	bool _fixedPosition = false;
	Sprite* lighted;

public:
	NewBuilding(Object* obj) : Building::Building(obj) {};
	virtual void Init() override;
	virtual void Update() override;
		 
	bool GetFixedPosition() { return _fixedPosition; }
	void SetFixedPosition(bool fixedPosition) { _fixedPosition = fixedPosition; }

};

