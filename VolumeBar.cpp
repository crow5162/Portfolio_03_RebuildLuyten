#include "stdafx.h"
#include "VolumeBar.h"
#include "SettingPanel.h"

void VolumeBar::Init()
{
	_soundVolume = 1.0f;

	//볼륨바 길이 = 100 픽셀 
	_startVolumeBarPosX = - 70;
	_maxVolumeBarPosX =  + 70;

	//볼륨바 전체 길이 
	_topVolumeBarLength = _maxVolumeBarPosX - _startVolumeBarPosX; 

	_topPolygonPos.push_back(Vector2(_startVolumeBarPosX, 0));
	_topPolygonPos.push_back(Vector2(_maxVolumeBarPosX, 0));

	_bottomPolygonPos.push_back(Vector2(_startVolumeBarPosX, 0));
	_bottomPolygonPos.push_back(Vector2(_maxVolumeBarPosX, 0));

	_polyDrawBottom = Object::CreateObject(object);
	_polyDrawBottom->AddComponent<PolygonDraw>();
	_polyDrawBottom->GetComponent<PolygonDraw>()->SetVertices(_bottomPolygonPos);
	_polyDrawBottom->GetComponent<PolygonDraw>()->SetStrokeWidth(7.f);
	_polyDrawBottom->SetCameraAffected(false);


	_polyDrawTop = Object::CreateObject(object);
	_polyDrawTop->AddComponent<PolygonDraw>();
	_polyDrawTop->GetComponent<PolygonDraw>()->SetVertices(_topPolygonPos);
	_polyDrawTop->GetComponent<PolygonDraw>()->SetStrokeWidth(7.f);
	_polyDrawTop->AddComponent<BoxCollider>();
	_polyDrawTop->SetCameraAffected(false);

	_topColor = { 0, 0, 0, 1 }; //검은색 
	_bottomColor = { 0.5, 0.5, 0.5, 1 }; //회색

	_polyDrawTop->GetComponent<PolygonDraw>()->SetColor(_topColor);
	_polyDrawBottom->GetComponent<PolygonDraw>()->SetColor(_bottomColor);

	//볼륨조절버튼
	_volumeControlButton = Object::CreateObject(object);
	_volumeControlButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/volumeControlButton.png"));
	_volumeControlButton->GetTransform()->SetScale(Vector2(0.32, 0.32)); 
	_volumeControlButton->SetCameraAffected(false);

	//볼륨조절버튼 생성 위치를 _polyDrawTop 끝 지점으로 설정 
	_volumeControlButton->GetTransform()->SetPosition(Vector2(_topPolygonPos[1].x-7, 1.59));
}

void VolumeBar::Update()
{	
	//체크가 되어있고 아직 충돌 중인 상태라면 계속 실행하기 
	if (_isClicked && object->GetComponent<BoxCollider>()->GetOnMouse())
	{
		_polyDrawTop->GetComponent<PolygonDraw>()->SetVertices(_topPolygonPos);
		_polyDrawBottom->GetComponent<PolygonDraw>()->SetVertices(_bottomPolygonPos);

		//마우스 좌표 계산
		auto mousePosition = InputManager::GetInstance()->GetMouseWorldPosition();
		Vector3 mousePosition_V3 = Vector3(mousePosition.x, mousePosition.y, 1);
		Vector3 mouseWorldPosition = Matrix3x3::Mul(mousePosition_V3, CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetLocalToWorldMatrix().GetInverseMatrix());

		_mouseX = mouseWorldPosition.x;
		_mouseY = (-1) * mouseWorldPosition.y;
		
		_topPolygonPos[1].x = _mouseX - object->GetParent()->GetTransform()->GetPosition().x;
	
		//예외처리(top볼륨바가 bottom최대 길이 못넘어가게 설정)
		//Clamp(최소값, 최대값, 기준값) = 기준값이 최소값일때 최소값 반환, 최대값일 때 최대값 반환해서 예외처리 가능
		_topPolygonPos[1].x = Clamp(_topPolygonPos[0].x, _bottomPolygonPos[1].x, _topPolygonPos[1].x);

		//cout << "_topPolygonPos" << _topPolygonPos[1].x << endl;
		//cout << "_bottomPolygonPos" << _bottomPolygonPos[1].x << endl;

		//_soundVolume = 볼륨바 현재 길이(마우스 좌표 기준) / 탑 볼륨바 전체 길이
		_soundVolume = (_topPolygonPos[1].x- _topPolygonPos[0].x) / _topVolumeBarLength;

		cout << "볼륨바 현재 길이" << _topPolygonPos[1].x - _topPolygonPos[0].x << endl;
		cout << "_topVolumeBarLength" << _topVolumeBarLength << endl;
		cout << "_soundVolume" << _soundVolume << endl;
		_volumeControlButton->GetTransform()->SetPosition(Vector2(_topPolygonPos[1].x, 0));
	}
}


void VolumeBar::OnMouseDown()
{
	_isClicked = true;
}


void VolumeBar::OnMouseUp()
{
	_isClicked = false;
}


#pragma region 안쓰는 코드
//_polyDrawTop->GetComponent<PolygonDraw>()->SetVertices(_topPolygonPos);
	//_polyDrawBotton->GetComponent<PolygonDraw>()->SetVertices(_bottomPolygonPos);

	////마우스 좌표 계산
	//auto mousePosition = InputManager::GetInstance()->GetMouseWorldPosition();
	//Vector3 mousePosition_V3 = Vector3(mousePosition.x, mousePosition.y, 1);
	//Vector3 mouseWorldPosition = Matrix3x3::Mul(mousePosition_V3, CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetLocalToWorldMatrix().GetInverseMatrix());

	//_mouseX = mouseWorldPosition.x;
	//_mouseY = (-1) * mouseWorldPosition.y;

	////a = 마우스 좌표에 따라 업데이트되는 볼륨바 길이
	//if (_topPolygonPos[1].x < _maxVolumeBarPosX) //포지션이 최대보다 커지면 안되니까 
	//{
	//	_topPolygonPos[1].x = (_mouseX - _topPolygonPos[0].x) / _topVolumeBarLength;
	//	cout << _topPolygonPos[1].x; 
	//}
	// 
	////_soundVolume = (a) / 탑 볼륨바 전체 길이
	//_soundVolume = _topPolygonPos[1].x / _topVolumeBarLength; 
#pragma endregion