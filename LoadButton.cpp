#include "stdafx.h"
#include "LoadButton.h"
#include "TileCheck.h"
#include "TileMap.h"
#include "NewBuilding.h"
#include "BuildingComponent.h"

void LoadButton::Init()
{
	vTotal = map->GetComponent<TileMap>()->GetVTotal();
	check = checkObj->GetComponent<TileCheck>();
	newBuilding->GetComponent<Sprite>()->SetOpacity(0.5f);
}

void LoadButton::Update()
{
	if (!isClicked || ((NewBuilding*)(newBuilding->GetComponent<BuildingComponent>()->GetBuilding()))->GetFixedPosition())
		return;

	newBuilding->GetTransform()->SetPosition(vTotal[check->GetMouseIndex().y + check->GetMouseIndex().x * TILENUM_Y]->GetTransform()->GetPosition() - Vector2(TILEWIDTH/2, - TILEHEIGHT/2));
}

void LoadButton::OnMouseDown()
{

	isClicked = true;
	newBuilding->SetIsActive(true);
	map->GetComponent<TileMap>()->SetTileView(true);
	checkObj->SetIsActive(true);

	////Å¸ÀÏºä Á¦¾î 
	//if (isClicked)
	//	map->SetIsActive(true);
	//else
	//	map->SetIsActive(false);

}


