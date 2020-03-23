#include "stdafx.h"
#include "FixButton.h"
#include "Building.h"
#include "BuildingComponent.h"
#include "ConstructionTimeBar.h"
#include "DefaultBuilding.h"
#include "Inventory.h"
#include "InfoBox.h"

void FixButton::OnMouseDown()
{
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/        _neededResources = object->GetParent()->GetComponent<InfoBox>()->GetMValidResources();
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/        for (auto it : _neededResources)
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/ {
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/           if (InventoryData::GetInstance()->GetCount()[it.first] < it.second)
            /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/              return;
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/
    }

    if (((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->GetHouseState() != HOUSE_RUINED)
        return;

    ((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->SetHouseState(HOUSE_UNDER_CONSTRUCTION);

    ((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->GetConstructionTimeBar()->SetIsActive(true);
    ((DefaultBuilding*)_building->GetComponent<BuildingComponent>()->GetBuilding())->GetConstructionTimeBar()
        ->GetComponent<ConstructionTimeBar>()->SetStartTime(TimeManager::GetInstance()->GetTime());

    for (auto it : _neededResources)
    {
        object->GetParent()->GetComponent<InfoBox>()->GetMValidResources()[it.first] -= it.second;
    }

}