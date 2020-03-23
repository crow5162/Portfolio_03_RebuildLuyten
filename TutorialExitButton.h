#pragma once
#include "Script.h"


class TutorialExitButton : public Script
{
private: 
	Object* _tutorialScene; 

	float _realTime;


public:
	virtual void OnMouseDown();

	void SetLinkWithTutorialScene(Object* ob) { _tutorialScene = ob; }

};

