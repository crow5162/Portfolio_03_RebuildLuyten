#pragma once
#include "GgaetIp.h"

class CraftBox;
class WorkArea : public Script
{
private:
	Object* _craftBox;
	Object* _craftTimeBar;

	CraftBox* _craftBoxComponent;
	Transform* _transform;



public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void OnMouseDown() override;

	Transform* GetHouseTransform() { return _transform; }
	Object* GetCraftTimeBar() { return _craftTimeBar; }

	void SetLink(Object* ob) { _craftBox = ob; }
	void SetTimeBarLink(Object* bar) { _craftTimeBar = bar; }

	//void SetLinkTo(Object* obj) { linked = obj; }

};