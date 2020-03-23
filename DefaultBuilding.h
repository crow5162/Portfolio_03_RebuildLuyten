#pragma once
#include "Building.h"

enum HOUSESTATE
{
    HOUSE_RUINED,
    HOUSE_UNDER_CONSTRUCTION,
    HOUSE_FIXED
};

class InfoBox;
class ConstructionTimeBar;

class DefaultBuilding : public Building
{
private:
    Object* _constructionTimeBar;
    Object* _infoBox;
    InfoBox* _infoBoxComponent;
    HOUSESTATE _houseState;
    bool _houseClicked = false;

public:

    DefaultBuilding(Object* obj) : Building::Building(obj) {};

    virtual void Init() override;
    virtual void Update() override;
    virtual void OnMouseDown() override;

    Object* GetConstructionTimeBar() { return _constructionTimeBar; }

    HOUSESTATE GetHouseState() { return _houseState; }
    void SetHouseState(HOUSESTATE state) { _houseState = state; }

    bool GetIfHouseClicked() { return _houseClicked; }
    void SetIfHouseClicked(bool trueOrFalse) { _houseClicked = trueOrFalse; }

    void SetLink(Object* ob) { _infoBox = ob; }
    void SetTimeBarLink(Object* bar) { _constructionTimeBar = bar; }


};
