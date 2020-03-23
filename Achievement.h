#pragma once
#include "GgaetIp.h"
#include "Observer.h"
#include "Subject.h"
#include <atlconv.h>

struct aInfo
{
	wstring title;
	wstring content;
	int notifyNum;
};

class Achievement: public Script, public Observer, public Subject
{
private:
	vector<Object*> aBox;
	vector<aInfo> aList;

	int maxPageNum;
	int pageNum = 0;
	Text* pageNumText;

public :
	virtual void Init() override;
	virtual void OnNotify(MSGTYPE type, string event) override;

	wstring string_to_wstring(string str)
	{
		USES_CONVERSION;
		return std::wstring(A2W(str.c_str()));
	}

	int GetPageNum() { return pageNum; }
	int GetMaxPageNum() { return maxPageNum; }
	void SetPageNum(int pageNum) 
	{ 
		this->pageNum = pageNum; 
		pageNumText->ChangeText(to_wstring(pageNum));
		for (int i = 0; i < aBox.size(); i++)
		{
			if (i / 4 +1 == pageNum)
				aBox[i]->SetIsActive(true);
			else
				aBox[i]->SetIsActive(false);
		}

	}
};

