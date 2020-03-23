#pragma once
#include "Script.h"

 
class SettingPanel : public Script
{
private: 
	Sprite* _sprite;
	Object* _tutorialButton; 

public: 

	virtual void Init();
	virtual void Update();

	virtual void OnMouseDown() override;
};

