#include "stdafx.h"
#include "ControlCamera.h"
#include <WinUser.h>

void ControlCamera::Init()
{
	transform = CameraManager::GetInstance()->GetRenderCamera()->GetTransform();

}

void ControlCamera::Update()
{
	Zoom();

	transform->SetScale(Vector2(_scale,_scale));

	Vector2 nowPosition = InputManager::GetInstance()->GetMousePosition();
	if (InputManager::GetInstance()->GetKeyDown(VK_RBUTTON))
		_prevPosition = InputManager::GetInstance()->GetMousePosition();

	if (!InputManager::GetInstance()->GetKey(VK_RBUTTON))
		return;

	transform->Translate((nowPosition - _prevPosition) * Vector2(1, -1));
	_prevPosition = nowPosition;
	
}

void ControlCamera::Zoom()
{
	_delta = InputManager::GetInstance()->GetWheelDelta();

	if (!_delta)
		return;
	if (_scale + _delta * _scaleSpeed < 0.1 ||
		_scale + _delta * _scaleSpeed > 2.5)
		return;

	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	_scale += _delta* _scaleSpeed;	
}
