#include "stdafx.h"
#include "DefaultBuilding.h"
#include "InfoBox.h"
#include "ConstructionTimeBar.h"

void DefaultBuilding::Init()
{
    Building::Init();
    buildingType = DEFAULT;
    _sprite = _thisObj->GetComponent<Sprite>();
    _sprite->SetSprite(Image::CreateImage("Sprite/" + _thisObj->GetTag() + "_Ruined.png"));

    _polydraw = _thisObj->GetComponent<PolygonDraw>();
    _polygonPos.push_back(Vector2(-110, -25));
    _polygonPos.push_back(Vector2(110, -25));
    _polydraw->SetVertices(_polygonPos);
    _polydraw->SetStrokeWidth(250.f);
    _polydraw->SetColor(Color{ 1.0f,1.0f,1.0f,0.0f });

    _infoBoxComponent = _infoBox->GetComponent<InfoBox>();

    _houseState = HOUSE_RUINED;
    _infoBox->SetIsActive(false);
}

void DefaultBuilding::Update()
{
     /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/        if (!_thisObj->GetComponent<BoxCollider>()->GetOnMouse()
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/ && InputManager::GetInstance()->GetKey(VK_LBUTTON)
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/ && !_infoBox->GetComponent<BoxCollider>()->GetOnMouse())
    {
        _houseClicked = false;
    }

    if (_houseState == HOUSE_UNDER_CONSTRUCTION)
    {
        _infoBox->SetIsActive(false);
    }

    if (_houseState == HOUSE_RUINED)
    {
        if (_thisObj->GetComponent<BoxCollider>()->GetOnMouse())
        {
            _polydraw->SetColor(Color{ 1.0f,1.0f,1.0f,0.05f });
        }
        else
        {
            if (_houseClicked) return;

            _polydraw->SetColor(Color{ 1.0f,1.0f,1.0f,0.0f });
        }
    }
    else
    {
        _polydraw->SetColor(Color{ 1.0f,1.0f,1.0f,0.0f });
    }

    if (!_houseClicked)
    {
        if (_thisObj->GetComponent<BoxCollider>()->GetOnMouse())
        {
            if (_houseState == HOUSE_RUINED)
                _infoBox->SetIsActive(true);
            else
                _infoBox->SetIsActive(false);
        }
        else
        {
            if (_houseState == HOUSE_RUINED)
                _infoBox->SetIsActive(false);
        }
    }
    else
    {
        if (_houseState == HOUSE_RUINED)
            _infoBox->SetIsActive(true);
        else
            _infoBox->SetIsActive(false);
    }
}

void DefaultBuilding::OnMouseDown()
{
    _houseClicked = true;
}