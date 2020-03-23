#pragma once
#include "Script.h"
#include <atlconv.h>
#include "Subject.h"

class Time : public Script, public Subject
{
private: 
	float _dayStartTime;
	float _nightStartTime;
	float _dayEndTime;
	int _realTime = 0; 
	int _gameTime = 0;
	int _gameStartTime =0; 
	
	Object* _timeUI; 
	Object* _hourText; //시간
	Object* _minuteText; //분 
	Object* _dateText; //n일차//요일
	Object* _dayText; //요일

	Object* _dayNightSprite;
	Object* _nightSky; //밤하늘 
	string _dayOfWeek;

	bool _isDay;

public:
	virtual void Init() override;
	virtual void Update() override;
	void GameTimeSet(); 
	
	Vector2 Convert(int left, int top, int width, int height)
	{
		Vector2 temp;
		temp.x = left + width / 2 - DesignResolution.x / 2;
		temp.y = (-1) * (top + height / 2 - DesignResolution.y / 2);

		return temp;
	}
	
	wstring string_to_wstring(string str)
	{
		USES_CONVERSION;
		return std::wstring(A2W(str.c_str()));
	}

};

