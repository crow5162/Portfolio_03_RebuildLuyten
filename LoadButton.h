#pragma once
#include "GgaetIp.h"

class TileCheck;
class TileMap;

class LoadButton : public Script
{
private:
	vector<Object*> vTotal;
	Object* newBuilding;
	Object* map;
	Object* checkObj;
	TileCheck* check;

	bool isClicked = false;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void OnMouseDown() override;

	Object* GetNewBuilding() { return newBuilding; }

	void setLink(Object* check) { this->checkObj = check; }
	void setLinkToMap(Object* map) { this->map = map; }
	void setLinkToNewBuilding(Object* building) { this->newBuilding = building; }

};

