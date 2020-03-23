#pragma once
#include "Script.h"
#include "House.h"
#include "PlayerChoice.h"
#include "FallingItem.h"


class PlayerGame : public Script
{
private:
	House* _house;
	PlayerChoice* _choice; 
	FallingItem* _item; 


	bool _isGameStart; 
	bool _isSame; 

public:
	virtual void Init();
	virtual void Update();
	
	void SetIcon();
	void ChooseItem(); 
	void Result(); 
};

