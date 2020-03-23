#include "stdafx.h"
#include "BuildingComponent.h"

void BuildingComponent::SetBuilding(Building* building)
{
	this->building = building;
}

void BuildingComponent::Init()
{
	building->Init();
}

void BuildingComponent::Update()
{
	building->Update();
}

void BuildingComponent::OnMouseDown()
{
	building->OnMouseDown();
}

