#pragma once
#include "GgaetIp.h"


class WorkerControlManager
{
private:
	WorkerControlManager(); //생성자 --> 어느 누구도 이 클래스를 생성할 수 없게 된다. 
	//map으로 string, num 엮어서 값 저장하게 설정 
	map<string, int> _mWorkers;
	map<string, int> ::iterator _miWorkers;

	int _totalPopulation =0;


public:

	static WorkerControlManager* GetInstance(); //어디에서든 이 instance 를 가져올 수 있음 전역적으로 접근 가능


	map<string, int> GetMWorkers() { return _mWorkers; }
	map<string, int>::iterator GetMiWorkers() { return _miWorkers; }
	int GetTotalPopulation() { return _totalPopulation; }

	void SetPopulation(map<string, int> _map);
	//void SetPopulation(string job, int num); //버튼 눌렀을 때 인구 숫자 up 

	void SetTotalPopulation(int num) { _totalPopulation = num; }

	void Init() {}
	void Update() {}
};

