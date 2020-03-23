#include "stdafx.h"
#include "InventoryData.h"

InventoryData* InventoryData::GetInstance()
{
	static InventoryData* instance = new InventoryData;
	return instance;
}
