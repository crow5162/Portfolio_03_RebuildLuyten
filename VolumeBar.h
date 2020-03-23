#pragma once
#include "GgaetIp.h"

 

class VolumeBar : public Script
{
private:

	float _soundVolume; //볼륨 
	
	float _mouseX; 
	float _mouseY; 

	float _startVolumeBarPosX; 
	float _maxVolumeBarPosX;
	float _topVolumeBarLength; 
	
	Object* _settingPanel;

	//volume Bar용 PolyDraw
	//꼭지점을 담는 벡터. 이 꼭지점들을 이어준다. 
	//시작지점, 끝지점 설정 -> 이 두 점을 잇도록 벡터로 담아두는 것
	vector<Vector2> _topPolygonPos;
	vector<Vector2> _bottomPolygonPos;

	Object* _polyDrawTop;
	Object* _polyDrawBottom;
	Object* _volumeControlButton; 

	/*PolygonDraw* _polyDrawTop;
	PolygonDraw* _polyDrawBottom; */

	Color _topColor;
	Color _bottomColor;

	bool _isClicked;

public: 

	virtual void Init() override; 
	virtual void Update() override; 
	virtual void OnMouseDown() override;
	virtual void OnMouseUp() override;

	//Link
	void SetLinkWithSettingPanel(Object* ob) { _settingPanel = ob; }
	//Getter
	float GetSoundVolume() { return _soundVolume; }
};

