#pragma once
#include "GgaetIp.h"
#include <map>
#include <string>

#pragma warning (disable:4996)

using namespace std;

struct tagCraftInfo
{
	map<string, int> material;
	float time;
};


class CraftInfo : public Script
{
public:
	map<string, tagCraftInfo> info;
	virtual void Init() override;

	map<string, tagCraftInfo> GetMCraftInfo() { return info; }
};