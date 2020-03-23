#pragma once
#include "GgaetIp.h"

class Inventory;

class LotExpansion: public Script
{
private:
	Object* map;
	vector<Object*> vTotal;
	vector<Object*> vExpansion;
	vector<Object*> vInfo;

	vector<Object*> vUndiscovered;

	Text* dimensionText;
	Vector2 dimension;
	Vector2 startIndex;
	Vector2 maxIndex;	

	Object* confirmationWindow;
	Text* confirmationText;

	Inventory* inventory;

	int testDirt;
	int testStone;

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void OnMouseDown() override;
	virtual void OnMouseUp() override;

	void DrawExpansion();
	bool CostCheck();
	void SetLinkToMap(Object* map) { this->map = map; }
	void SetLinkToInventory(Inventory* inventory) { this->inventory = inventory; }

	void AllowExpansion();
	
	Vector2 GetDimension() { return dimension; }
};

