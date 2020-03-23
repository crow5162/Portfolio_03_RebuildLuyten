#pragma once
#include "GgaetIp.h"
#include "Observer.h"
#include <atlconv.h>

class NotificationBox: public Script, public Observer
{
private:

	float alphaTime = 0.f;
	Sprite* sprite;
	Text* text;
	float textOpacity = 0.f;
	bool isNotified = false;

public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void OnNotify(MSGTYPE type, string event) override;
	void FadeOut();


	void SetTextOpacity(float alpha);
	float GetTextOpacity() { return textOpacity; }

	wstring string_to_wstring(string str)
	{
		USES_CONVERSION;
		return std::wstring(A2W(str.c_str()));
	}

};

