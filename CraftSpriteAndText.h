#pragma once
#include "GgaetIp.h"

class CraftBox;
class CraftSpriteAndText : public Script
{
private:
	CraftBox* _craftBox;
	Sprite* _sprite;
	Transform* _transform;

	string _resourceName;

	Vector2 _setSpritePos;
	Vector2 _setTextPos;

	map<string, int> _mCraftInfo;


public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void SetLink(CraftBox* c) { _craftBox = c; }

	void SetResourceName(string s) { _resourceName = s; }

	virtual void SetMaterialSpriteStartPos(Vector2 pos) { _setSpritePos = pos; }
	virtual void SetMaterialTextStartPos(Vector2 pos) { _setTextPos = pos; }
};