#pragma once
#include "GgaetIp.h"

class CraftTimeBar;
class Inventory;

class CraftResult : public Script
{
private:
	CraftTimeBar* _timeBar;
	Inventory* _inven;
	Object* _resultCount;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void OnMouseDown();

	void Setlink(CraftTimeBar* c) { _timeBar = c; }
	void SetInventoryLink(Inventory* i) { _inven = i; }
};