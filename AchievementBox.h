#pragma once
#include "GgaetIp.h"

class AchievementBox : public Script
{
private:
	Sprite* box;
	Sprite* progressBar;
	Sprite* trophy;

	Text* title;
	Text* content;
	Text* ratio;

	pair<wstring, wstring> text;
	int notifyNum;
	int currentNum = 0;

public:
	virtual void Init() override;
	
	void SetString(pair<wstring, wstring> p) { text = p;}
	void SetNotifyNum(int num) { notifyNum = num; }
	void SetProgress();
	float GetProgress() { return currentNum / (float)notifyNum; }
};

