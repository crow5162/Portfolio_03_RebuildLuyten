#pragma once
#include "GgaetIp.h"
#include "Subject.h"

class BuildingManager :	public Script, public Subject, public Observer
{
private:
	vector<Object*> _vHouses;
	int _fixedHouseNum = 0;
	
public:
	virtual void Init();

	vector<Object*> GetVHouses() { return _vHouses; }
	int GetFixedNum() { return _fixedHouseNum;}
	void SetFixedNum(int num);

	vector<Object*> GetHouses() { return _vHouses; }

	virtual void OnNotify(MSGTYPE type, string event);
};