#pragma once
#include "GgaetIp.h"
class InventoryData
{
private:
	map<string, Text*> text;
	map<string, int> items;
public:
	static InventoryData* GetInstance();

	map<string, Text*>& GetText() { return text; }
	map<string, int>& GetCount() { return items; }
};

