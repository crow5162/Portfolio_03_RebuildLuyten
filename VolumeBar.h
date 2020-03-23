#pragma once
#include "GgaetIp.h"

 

class VolumeBar : public Script
{
private:

	float _soundVolume; //���� 
	
	float _mouseX; 
	float _mouseY; 

	float _startVolumeBarPosX; 
	float _maxVolumeBarPosX;
	float _topVolumeBarLength; 
	
	Object* _settingPanel;

	//volume Bar�� PolyDraw
	//�������� ��� ����. �� ���������� �̾��ش�. 
	//��������, ������ ���� -> �� �� ���� �յ��� ���ͷ� ��Ƶδ� ��
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

