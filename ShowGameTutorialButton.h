#pragma once
#include "GgaetIp.h"

class ShowGameTutorialButton : public Script
{
private:
	Sprite* _sprite; 
	Transform* _transform; 
	Collider* collider; 

public:

	virtual void Init();
	
	virtual void OnMouseDown() override;
	virtual void OnMouseUp() override;
};

