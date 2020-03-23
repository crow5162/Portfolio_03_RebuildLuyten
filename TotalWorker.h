#pragma once
#include "Script.h"

class TotalWorker : public Script
{
private: 

	Object* _control; 
	Object* _totalWorkerSprite; 
	Object* _totalWorkerText; 

	Object* _showWorker;

	Sprite* _sprite;

	int _totalNum; 

public: 

	virtual void Init();
	virtual void Update();

	Vector2 Convert(int left, int top, int width, int height)
	{
		Vector2 temp;
		temp.x = left + width / 2 - DesignResolution.x / 2;
		temp.y = (-1) * (top + height / 2 - DesignResolution.y / 2);

		return temp;
	}

	void SetLinkWithShowWorker(Object* showWorker) { _showWorker = showWorker; }
	
	virtual void OnMouseDown() override;
	virtual void OnMouseUp() override;
};

