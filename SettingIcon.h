#pragma once
#include "GgaetIp.h"
#include "Script.h"


class SettingIcon :public Script
{
private:

	Sprite* _sprite; 
	Object* _settingPanel; 


public:
	virtual void Init();
	virtual void Update();

	virtual void OnMouseDown() override;
	virtual void OnMouseUp() override;

	void SetLinkWithSettingPanel(Object* panel) { _settingPanel = panel; }
};

