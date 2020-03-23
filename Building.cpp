#include "stdafx.h"
#include "Building.h"


Building::Building(Object* obj)
{
	_thisObj = obj;
}

void Building::Init()
{
	vector<Vector2> _polygonPos;

	_polydraw = _thisObj->GetComponent<PolygonDraw>();
	_polygonPos.push_back(Vector2(-110, -25));
	_polygonPos.push_back(Vector2(110, -25));
	_polydraw->SetVertices(_polygonPos);
	_polydraw->SetStrokeWidth(250.f);
	_polydraw->SetColor(Color{ 100.f,100.f,100.f,0.f });
}

void Building::Update()
{


	/*if (_thisObj->GetComponent<BoxCollider>()->GetOnMouse())
	{
		_polydraw->SetColor(Color{ 100.0f,100.f,100.f,0.1f });
	}
	else
	{
		if (_houseClicked) return;
		_polydraw->SetColor(Color{ 100.f,100.f,100.f,0.f });
	}*/

}

void Building::OnMouseDown()
{
	_houseClicked = true;
}
                                                                                               
