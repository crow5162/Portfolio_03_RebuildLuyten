#include "stdafx.h"
#include "ConstructionTimeBar.h"
#include "BuildingInfo.h"
#include "BuildingManager.h"
#include "BuildingComponent.h"
#include "DefaultBuilding.h"

void ConstructionTimeBar::Init()
{
    _startPosX = _building->GetTransform()->GetPosition().x - 100;
    _maxPosX = _building->GetTransform()->GetPosition().x + 100;
    object->GetTransform()->SetPosition(Vector2(object->GetTransform()->GetPosition().x, _building->GetTransform()->GetPosition().y + 115));

    _infoTime = _building->GetComponent<BuildingInfo>()->GetBuildingInfo()[_building->GetTag()].time;

    _polydraw = object->GetComponent<PolygonDraw>();

    _polygonPos.push_back(Vector2(_startPosX, 0));
    _polygonPos.push_back(Vector2(_startPosX, 0));
    _polydraw->SetVertices(_polygonPos);
    _polydraw->SetStrokeWidth(5.f);

    _color.a = 0.6f;
    _color.r = 0.2f;
    _color.g = 0.8f;
    _color.b = 0.4f;

    _polydraw->SetColor(_color);
}

void ConstructionTimeBar::Update()
{
    if (((DefaultBuilding*)(_building->GetComponent<BuildingComponent>()->GetBuilding()))->GetHouseState() == HOUSE_UNDER_CONSTRUCTION)
    {
        _polydraw->SetVertices(_polygonPos);

        if (_polygonPos[1].x < _maxPosX)
            _polygonPos[1].x = (200.0 * (TimeManager::GetInstance()->GetTime() - _startTime)) / _infoTime + _startPosX;
        else
        {
            _polygonPos[1].x = _maxPosX;
            ((DefaultBuilding*)(_building->GetComponent<BuildingComponent>()->GetBuilding()))->SetHouseState(HOUSE_FIXED);
            _building->GetComponent<Sprite>()->SetSprite(Image::CreateImage("Sprite/" + _building->GetTag() + "_Fixed.png"));

            //매니저 처리 
            BuildingManager* manager = _building->GetComponent<BuildingComponent>()->GetBuilding()->GetManager();
            manager->SetFixedNum(manager->GetFixedNum() + 1);
        }
    }

    if (((DefaultBuilding*)(_building->GetComponent<BuildingComponent>()->GetBuilding()))->GetHouseState() == HOUSE_FIXED)
    {
        _color.a = 0.f;
        _polydraw->SetColor(_color);
    }
}