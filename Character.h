#pragma once
#include "GgaetIp.h"
#include "TileMap.h"

//#define TILENUM_X 11
//#define TILENUM_Y 11

//#define TILEWIDTH 128
//#define TILEHEIGHT 32


//실시간 ASTAR 테스트 캐릭터 
class Character: public Script
{
private:
	//map 정보
	Object* map;
	TileMap* tileMap;
	vector<Object*> vTotal;

	Vector2 index = { 7,7 };
public:

	virtual void Init() override;
	virtual void Update() override;


	void KeyControl();

	void SetLink(Object* tileMap) { this->map = tileMap; }
	Vector2 GetIndex() { return index; }
}; 

