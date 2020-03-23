#pragma once
#include "GgaetIp.h"
#include "InventoryData.h"
class Inventory : public Script
{
private:
	map<string, int>& items = InventoryData::GetInstance()->GetCount();
	Sprite* sprite;
	Vector2 prevPosition;
	map<string, Text*>& text = InventoryData::GetInstance()->GetText();
public:
	virtual void Init() override;
	virtual void Update() override;
	void AddItem(string itemName, int count) { items[itemName] += count; }
	void DelItem(string itemName, int count) { items[itemName] -= count; }
	int GetItemCount(string itemName) { return items[itemName]; }

	map<string, int> GetInventory() { return items; }
};

