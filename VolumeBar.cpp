#include "stdafx.h"
#include "VolumeBar.h"
#include "SettingPanel.h"

void VolumeBar::Init()
{
	_soundVolume = 1.0f;

	//������ ���� = 100 �ȼ� 
	_startVolumeBarPosX = - 70;
	_maxVolumeBarPosX =  + 70;

	//������ ��ü ���� 
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

	_topColor = { 0, 0, 0, 1 }; //������ 
	_bottomColor = { 0.5, 0.5, 0.5, 1 }; //ȸ��

	_polyDrawTop->GetComponent<PolygonDraw>()->SetColor(_topColor);
	_polyDrawBottom->GetComponent<PolygonDraw>()->SetColor(_bottomColor);

	//����������ư
	_volumeControlButton = Object::CreateObject(object);
	_volumeControlButton->AddComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/UI/volumeControlButton.png"));
	_volumeControlButton->GetTransform()->SetScale(Vector2(0.32, 0.32)); 
	_volumeControlButton->SetCameraAffected(false);

	//����������ư ���� ��ġ�� _polyDrawTop �� �������� ���� 
	_volumeControlButton->GetTransform()->SetPosition(Vector2(_topPolygonPos[1].x-7, 1.59));
}

void VolumeBar::Update()
{	
	//üũ�� �Ǿ��ְ� ���� �浹 ���� ���¶�� ��� �����ϱ� 
	if (_isClicked && object->GetComponent<BoxCollider>()->GetOnMouse())
	{
		_polyDrawTop->GetComponent<PolygonDraw>()->SetVertices(_topPolygonPos);
		_polyDrawBottom->GetComponent<PolygonDraw>()->SetVertices(_bottomPolygonPos);

		//���콺 ��ǥ ���
		auto mousePosition = InputManager::GetInstance()->GetMouseWorldPosition();
		Vector3 mousePosition_V3 = Vector3(mousePosition.x, mousePosition.y, 1);
		Vector3 mouseWorldPosition = Matrix3x3::Mul(mousePosition_V3, CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetLocalToWorldMatrix().GetInverseMatrix());

		_mouseX = mouseWorldPosition.x;
		_mouseY = (-1) * mouseWorldPosition.y;
		
		_topPolygonPos[1].x = _mouseX - object->GetParent()->GetTransform()->GetPosition().x;
	
		//����ó��(top�����ٰ� bottom�ִ� ���� ���Ѿ�� ����)
		//Clamp(�ּҰ�, �ִ밪, ���ذ�) = ���ذ��� �ּҰ��϶� �ּҰ� ��ȯ, �ִ밪�� �� �ִ밪 ��ȯ�ؼ� ����ó�� ����
		_topPolygonPos[1].x = Clamp(_topPolygonPos[0].x, _bottomPolygonPos[1].x, _topPolygonPos[1].x);

		//cout << "_topPolygonPos" << _topPolygonPos[1].x << endl;
		//cout << "_bottomPolygonPos" << _bottomPolygonPos[1].x << endl;

		//_soundVolume = ������ ���� ����(���콺 ��ǥ ����) / ž ������ ��ü ����
		_soundVolume = (_topPolygonPos[1].x- _topPolygonPos[0].x) / _topVolumeBarLength;

		cout << "������ ���� ����" << _topPolygonPos[1].x - _topPolygonPos[0].x << endl;
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


#pragma region �Ⱦ��� �ڵ�
//_polyDrawTop->GetComponent<PolygonDraw>()->SetVertices(_topPolygonPos);
	//_polyDrawBotton->GetComponent<PolygonDraw>()->SetVertices(_bottomPolygonPos);

	////���콺 ��ǥ ���
	//auto mousePosition = InputManager::GetInstance()->GetMouseWorldPosition();
	//Vector3 mousePosition_V3 = Vector3(mousePosition.x, mousePosition.y, 1);
	//Vector3 mouseWorldPosition = Matrix3x3::Mul(mousePosition_V3, CameraManager::GetInstance()->GetRenderCamera()->GetTransform()->GetLocalToWorldMatrix().GetInverseMatrix());

	//_mouseX = mouseWorldPosition.x;
	//_mouseY = (-1) * mouseWorldPosition.y;

	////a = ���콺 ��ǥ�� ���� ������Ʈ�Ǵ� ������ ����
	//if (_topPolygonPos[1].x < _maxVolumeBarPosX) //�������� �ִ뺸�� Ŀ���� �ȵǴϱ� 
	//{
	//	_topPolygonPos[1].x = (_mouseX - _topPolygonPos[0].x) / _topVolumeBarLength;
	//	cout << _topPolygonPos[1].x; 
	//}
	// 
	////_soundVolume = (a) / ž ������ ��ü ����
	//_soundVolume = _topPolygonPos[1].x / _topVolumeBarLength; 
#pragma endregion