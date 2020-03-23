#pragma once
#include "GgaetIp.h"
#include "Observer.h"


class WorkerPanelUiSet;

class WorkerPanel : public Script, public Observer
{
private:
	
	map<string, int> _mForSettingWorker; 

	int _totalPopulationForSet = 0; 

	Object* _totalWorker; 
	Object* _workerNum;
	Object* _buttonDown;
	Object* _buttonUp;
	Object* _jobSprite; 
	Object* _settingDoneButton; 

	vector<Object*> _vWorkerNum;

public: 
	virtual void Init();
	virtual void Update();

	void ControlOnOff(bool onoff); //WorkerPanel on/off ÇÔ¼ö
	void ContolPopulationNum(int num, string job); 
	virtual void OnNotify(MSGTYPE type, string event) override;
	
public:
	//GETTER & SETTER
	map<string, int> GetMForSettingWorker() { return _mForSettingWorker; }
	vector<Object*> GetVWorkerNum() { return _vWorkerNum; }
	int GetTotalPopulationNum() { return _totalPopulationForSet;  }
	void SetLinkWithWorker(Object* control) { _totalWorker = control; }
	//vector<Object*> GetWorkerNum() { return _vWorkerNum; }
	/*void Tokenize(const string& str, vector<string>& tokens,
					const string& delimiters = " ");*/

};

