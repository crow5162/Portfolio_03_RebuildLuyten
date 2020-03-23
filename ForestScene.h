#pragma once
#include "GgaetIp.h"

class ForestScene : public Scene
{
private:
	map <string, int> _mtotalworker;
public:
	virtual void Init() override;

	Vector2 Convert(int left, int top, int width, int height)
	{
		Vector2 temp;
		temp.x = left + width / 2 - DesignResolution.x / 2;
		temp.y = (-1) * (top + height / 2 - DesignResolution.y / 2);

		return temp;
	}
};

