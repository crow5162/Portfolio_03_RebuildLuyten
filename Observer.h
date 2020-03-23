#pragma once
#include "GgaetIp.h"

class Observer abstract 
{
public:
	virtual void OnNotify(MSGTYPE type, string event) = 0;
};

