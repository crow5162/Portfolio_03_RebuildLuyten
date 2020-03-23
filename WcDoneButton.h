#pragma once
#include "Script.h"

class WorkerPanel;
class WcDoneButton : public Script
{
private: 
	Transform* _transform;
	WorkerPanel* _workerPanel;
	Collider* collider;

public:
	virtual void Init() override;
	virtual void Update() override;

	virtual void OnMouseDown();

	void SetLinkWithWC(WorkerPanel* wc) { _workerPanel = wc; }
};

