#include "stdafx.h"
#include "Subject.h"
#include "Observer.h"


void Subject::AddObserver(Observer* observer)
{
	observers.push_back(observer);
}


void Subject::RemoveObserver(Observer* observer)
{
	for (int i = 0; i < observers.size(); i++)
	{
		if (observers[i] != observer)
			continue;

		observers.erase(observers.begin() + i);
		break;
	}
}


void Subject::Notify(MSGTYPE type, string event)
{
	for (int i = 0; i < observers.size(); i++)
	{
		observers[i]->OnNotify(type, event);
	}
}


//
//void Subject::Notify(TIMETYPE type)
//{
//	for (int i = 0; i < observers.size(); i++)
//	{
//		observers[i]->OnNotify(type);
//	}
//}
