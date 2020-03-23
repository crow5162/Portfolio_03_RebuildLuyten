#pragma once
#include "GgaetIp.h"
#include "Observer.h"

struct tagTutorialInfo
{
	string name;
	Vector2 position;
	string spriteRoute;
	bool isNotified = false;
	float alphaTime = 0;
};

class Tutorial : public Script, public Observer
{
private:
	vector<tagTutorialInfo> vTutorialInfo;
	vector<pair<Object*, tagTutorialInfo>> vTutorialBox;

public:
	virtual void Init() ;
	virtual void Update();
	virtual void OnNotify(MSGTYPE type, string event);

	void FadeOut();
};

