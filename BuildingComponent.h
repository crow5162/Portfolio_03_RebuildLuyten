#pragma once
#include "GgaetIp.h"
#include "Building.h"
class BuildingComponent : public Script
{
private:
	Building* building;
public:
	BuildingComponent() {}
	BuildingComponent(Building* thisObj) : building(thisObj) {}

	void SetBuilding(Building* building);
	Building* GetBuilding() { return building; }

	virtual void Init() override;
	virtual void Update() override;

	virtual void OnMouseDown() override;

};

