#pragma once
#include "Object.h"

class BuildingManager;

enum BUILDINGTYPE
{
    DEFAULT,
    NEW,
    ROAD,
    SPECIAL
};

class Building abstract
{
protected:
    Object* _thisObj;

    Transform* _transform;
    Sprite* _sprite;
    PolygonDraw* _polydraw;
    BuildingManager* _buildingManager;

    vector<Vector2> _polygonPos;

    BUILDINGTYPE buildingType = DEFAULT;
    bool _houseClicked;

public:
    Building(Object* obj);

    virtual void Init();
    virtual void Update();

    virtual void OnMouseDown();


    BUILDINGTYPE GetBuildingType() { return buildingType; }


    void SetLinkWithManager(BuildingManager* manager) { _buildingManager = manager; }
    BuildingManager* GetManager() { return _buildingManager; }
};