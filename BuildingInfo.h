#pragma once
#include "GgaetIp.h"
#include <map>
#include <string>

#pragma warning (disable:4996)

using namespace std;

struct tagBuildingInfo
{
	map<string, int> material;
	float time;
};


class BuildingInfo : public Script
{
public:
	map<string, tagBuildingInfo> info;
	virtual void Init() override;

	map<string, tagBuildingInfo> GetBuildingInfo() { return info; }
};