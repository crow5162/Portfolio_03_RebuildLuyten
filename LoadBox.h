#pragma once
#include "GgaetIp.h"
#include "Observer.h"

class LoadBox : public Script, public Observer
{
private:
	Object* map;

	//Building
	Object* school;
	Object* policeStation;
	Object* fireStation;

	//load Button
	Object* sLoadButton;
	Object* pLoadButton;
	Object* fLoadButton;

	//Badge
	Object* sBadge;
	Object* pBadge;
	Object* fBadge;


	Object* firstPage;
	Object* secondPage;

	Text* pageNumText;

	bool loadOnce = false;
public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void OnNotify(MSGTYPE type, string event);
	void SetLinkToMap(Object* map) { this->map = map; }

};

