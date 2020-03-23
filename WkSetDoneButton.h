#pragma once
#include "Script.h"


class WorkerPanel;

class WkSetDoneButton : public Script
{
private: 
	Transform* _transform;
	WorkerPanel* _workerPanel;
	Collider* collider;

public:
	virtual void OnMouseDown();

	void SetLinkWithWC(WorkerPanel* wc) { _workerPanel = wc; }
};

