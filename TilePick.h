#pragma once
#include "GgaetIp.h"

class TileMap;

class TilePick : public Script
{
private:
	TileMap* map;
	vector<Object*> vTotal;
public:
	virtual void Init() override;
	virtual void OnMouseDown() override;
	

	void SetLink(TileMap* tileMap) { map = tileMap; }
};

