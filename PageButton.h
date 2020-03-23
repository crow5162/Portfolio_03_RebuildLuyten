#pragma once
#include "GgaetIp.h"
#include "Achievement.h"

class PageButton: public Script
{
private:
	Achievement* linked;
public:
	void SetLink(Achievement* achievement) { linked = achievement; }
	void OnMouseDown() override;
	void OnMouseUp() override;
};

