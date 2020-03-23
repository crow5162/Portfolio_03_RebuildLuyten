#pragma once
#include "GgaetIp.h"

class CraftTimeBar;
class WorkArea;
class Inventory;

class CraftBox : public Script
{
private:
	Object* _workArea;

	// �ڽ� ��ü ����
	Transform* _transform;
	Physics* _physics;
	Sprite* _sprite;
	BoxCollider* _boxCollider;
	Inventory* _inven;

	CraftTimeBar* _timeBar;

	Object* _craftResult;
	Object* _currentFirstMaterial;
	Object* _currentSecondMaterial;

	// �ڽ��� �ؽ�Ʈ ����
	Object* _infoText;
	Text* _text;
	map<string, int> _mCraftResources;
	map<string, int>::iterator _miCraftResources;
	map<string, int> _mValidCraftResources;
	int _craftTime;


public:
	virtual void Init() override;
	virtual void Update() override;

	map<string, int> GetmCraftResources() { return _mCraftResources; }
	map<string, int> GetmValidCraftResources() { return _mValidCraftResources; }

	virtual void SetTimeBarLink(CraftTimeBar* c) { _timeBar = c; }

	void SetLink(Object* ob) { _workArea = ob; }
	void SetInvenLink(Inventory* inven) { _inven = inven; }

	float GetCraftTime() { return _craftTime; }
};