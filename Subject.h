#pragma once
#include "GgaetIp.h"
#include "Observer.h"

class Subject
{
private:
	vector<Observer*> observers;
public:
	void AddObserver(Observer* observer);
	void RemoveObserver(Observer* observer);
	void Notify(MSGTYPE type, string event);
};

