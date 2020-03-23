#pragma once
#include "GgaetIp.h"

class ControlCamera : public Script
{
private:

	Transform* transform;

	float _lerpCount = 0;
	float _moveTime = 5;

	float _delta; 
	float _scaleSpeed = 0.2f;
	float _scale = 1;


	Vector2 _position;
	Vector2 _prevPosition;

public:
	virtual void Init()		override;
	virtual void Update()	override;

	//ZOOM
	virtual void Zoom();


	void SetScaleSpeed(float speed) { _scaleSpeed = speed; }
};

