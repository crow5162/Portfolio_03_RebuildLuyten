#include "stdafx.h"
#include "TileMap.h"
#include "TilePick.h"

void TileMap::Init()
{
	//vector<Vector2> pos;

	//ISOMETRIC
	//pos.push_back(Vector2(TILEWIDTH / 2, 0));
	//pos.push_back(Vector2(0, TILEHEIGHT / 2));
	//pos.push_back(Vector2(-TILEWIDTH / 2, 0));
	//pos.push_back(Vector2(0, -TILEHEIGHT / 2));
	//
	//for (int i = 0; i < TILENUM_X; i++)
	//{
	//	for (int j = 0; j < TILENUM_Y; j++)
	//	{
	//		Object* normalTile = Object::CreateObject();
	//		normalTile->GetTransform()->SetPosition(Vector2(i * TILEWIDTH / 2 - j * TILEWIDTH / 2, TILEHEIGHT * TILENUM_Y / 2 - i * TILEHEIGHT / 2 - j * TILEHEIGHT / 2));
	//		normalTile->SetName("Normal");
	//		auto tile = normalTile->AddComponent<Tile>();
	//		tile->SetIndex(Vector2(i, j));
	//		tile->SetAttribute(ATTRIBUTE::NONE);
	//		auto tilePoly = normalTile->AddComponent<PolygonDraw>();
	//		tilePoly->SetVertices(pos);
	//		tilePoly->SetStrokeWidth(2);

	//		vTotal.push_back(normalTile);

	//	}
	//}
	//

	//GENERAL
	testInfo a = { .name = "", .g = 1 };
	//pos.push_back(Vector2(-TILEWIDTH/2, TILEHEIGHT/2));
	//pos.push_back(Vector2(TILEWIDTH/2, TILEHEIGHT/2));
	//pos.push_back(Vector2(TILEWIDTH/2, -TILEHEIGHT/2));
	//pos.push_back(Vector2(-TILEHEIGHT/2, -TILEHEIGHT/2));

	vector<vector<Attribute>> test;

	for (int i = 0; i < MapManager::GetInstance()->GetTileMap().second.y; i++)
	{
		vector<Attribute> now;
		for (int j = 0; j < MapManager::GetInstance()->GetTileMap().second.x; j++)
		{
			now.push_back(MapManager::GetInstance()->GetTileMap().first[i][j]);
		}
		test.push_back(now);
	}

	for (int i = 0; i < TILENUM_X; i++)
	{
		for (int j = 0; j < TILENUM_Y; j++)
		{
			Object* normalTile = Object::CreateObject();
			
			normalTile->GetTransform()->SetPosition(Vector2(-937 + i*TILEWIDTH, +517 - j*TILEHEIGHT));
			normalTile->SetTag("Normal");
			auto tile = normalTile->AddComponent<Tile>();
			tile->SetIndex(Vector2(i, j));
			tile->SetAttribute(ATTRIBUTE::NONE);

			if(i>=80 || j>=80)
				tile->SetAttribute(ATTRIBUTE::WALL);

			if (MapManager::GetInstance()->GetTileMap().first[j][i] == Attribute::Wall)
				tile->SetAttribute(ATTRIBUTE::WALL);

			if (MapManager::GetInstance()->GetTileMap().first[j][i] == Attribute::Undiscovered)
				tile->SetAttribute(ATTRIBUTE::UNDISCOVERED);
			
			vTotal.push_back(normalTile);

		}
	}

	//for expansion test
	for (int i = 0; i < TILENUM_X; i++)
	{
		for (int j = 80 - 22; j < 81; j++)
		{
			auto test = Object::CreateObject();
			test->GetTransform()->SetPosition(vTotal[i*TILENUM_Y+j]->GetTransform()->GetPosition() - Vector2(0,TILEWIDTH/2));
			test->AddComponent<PolygonDraw>();
			test->GetTransform()->SetDepth(9999999999999);
			vector<Vector2> pos;

			//Vector2 startPos = Vector2(test->GetTransform()->GetPosition() - Vector2(TILEWIDTH / 2, 0));
			//Vector2 endPos = Vector2(test->GetTransform()->GetPosition() + Vector2(TILEWIDTH / 2, 0));
			//pos.push_back(startPos);
			//pos.push_back(endPos);

			Vector2 startPos = Vector2(0, 0);
			Vector2 endPos = Vector2(0, TILEWIDTH);
			pos.push_back(startPos);
			pos.push_back(endPos);
			test->GetComponent<PolygonDraw>()->SetVertices(pos);
			test->GetComponent<PolygonDraw>()->SetColor({ 0,0,0,0.6 });
			test->GetComponent<PolygonDraw>()->SetStrokeWidth(TILEWIDTH);
			test->GetTransform()->SetDepth(1);

			vUndiscovered.push_back(test);

		}
	}

	//tileView 
	tileView = Object::CreateObject();
	tileView->GetTransform()->SetDepth(100);
	for (int i = 0; i < TILENUM_X; i++)
	{
		Object* tileChild = Object::CreateObject(tileView);
		auto poly = tileChild->AddComponent<PolygonDraw>();
		vector<Vector2> pos;
		Vector2 startPos = Vector2(vTotal[i*TILENUM_Y]->GetTransform()->GetPosition().x - TILEWIDTH/2, vTotal[0]->GetTransform()->GetPosition().y + TILEHEIGHT / 2);
		Vector2 endPos =   Vector2(vTotal[i * TILENUM_Y]->GetTransform()->GetPosition().x - TILEWIDTH / 2, vTotal[TILENUM_Y-1]->GetTransform()->GetPosition().y - TILEHEIGHT / 2);
		pos.push_back(startPos);
		pos.push_back(endPos);
		poly->SetVertices(pos);

	}
	for (int i = 0; i < TILENUM_Y; i++)
	{
		Object* tileChild = Object::CreateObject(tileView);
		auto poly = tileChild->AddComponent<PolygonDraw>();
		vector<Vector2> pos;
		Vector2 startPos = Vector2(vTotal[0]->GetTransform()->GetPosition().x - TILEWIDTH / 2, vTotal[i]->GetTransform()->GetPosition().y + TILEHEIGHT / 2);
		Vector2 endPos = Vector2(vTotal[vTotal.size() -TILENUM_Y]->GetTransform()->GetPosition().x + TILEWIDTH / 2, vTotal[i]->GetTransform()->GetPosition().y + TILEHEIGHT / 2);
		pos.push_back(startPos);
		pos.push_back(endPos);
		poly->SetVertices(pos);
	}

	//추가 라인 
	Object* tileChild1 = Object::CreateObject(tileView);
	auto poly1 = tileChild1->AddComponent<PolygonDraw>();
	vector<Vector2> pos1;
	Vector2 startPos1 = Vector2(vTotal[(TILENUM_X-1) * TILENUM_Y]->GetTransform()->GetPosition().x + TILEWIDTH / 2, vTotal[0]->GetTransform()->GetPosition().y + TILEHEIGHT / 2);
	Vector2 endPos1 = Vector2(vTotal[(TILENUM_X - 1) * TILENUM_Y]->GetTransform()->GetPosition().x + TILEWIDTH / 2, vTotal[TILENUM_Y - 1]->GetTransform()->GetPosition().y - TILEHEIGHT / 2);
	pos1.push_back(endPos1);
	pos1.push_back(startPos1);
	poly1->SetVertices(pos1);

	Object* tileChild2 = Object::CreateObject(tileView);
	auto poly2 = tileChild2->AddComponent<PolygonDraw>();
	vector<Vector2> pos2;
	Vector2 startPos2 = Vector2(vTotal[0]->GetTransform()->GetPosition().x - TILEWIDTH / 2, vTotal[TILENUM_Y-1]->GetTransform()->GetPosition().y - TILEHEIGHT / 2);
	Vector2 endPos2 = Vector2(vTotal[vTotal.size() - TILENUM_Y]->GetTransform()->GetPosition().x + TILEWIDTH / 2, vTotal[TILENUM_Y-1]->GetTransform()->GetPosition().y - TILEHEIGHT / 2);
	pos2.push_back(endPos2);
	pos2.push_back(startPos2);
	poly2->SetVertices(pos2);

	tileView->SetIsActive(false);

	//테스트 코드  
	testInfo infoNone;
	infoNone.r = infoNone.g = infoNone.b = 1;
	infoNone.depth = 1;
	infoNone.name = "None";

	testInfo infoWall;
	infoWall.r = infoWall.b = 0;
	infoWall.g = 1;
	infoWall.depth = 2;
	infoWall.name = "Wall";

	testInfo infoPlayer;
	infoPlayer.r = infoPlayer.b = 1;
	infoPlayer.b = 0;
	infoPlayer.depth = 4;
	infoPlayer.name = "Player";

	testInfo infoEnemy;
	infoEnemy.r = infoEnemy.g = 0;
	infoEnemy.b = 1;
	infoEnemy.depth = 4;
	infoEnemy.name = "Enemy";

	attributeInfo.insert(make_pair(ATTRIBUTE::NONE, infoNone));
	attributeInfo.insert(make_pair(ATTRIBUTE::WALL,infoWall));
	attributeInfo.insert(make_pair(ATTRIBUTE::PLAYER, infoPlayer));
	attributeInfo.insert(make_pair(ATTRIBUTE::ENEMY, infoEnemy));


}

void TileMap::Update()
{
	//테스트 코드 

	


}


void TileMap::SetTile(Vector2 index, ATTRIBUTE attribute)
{         
	auto tile = vTotal[index.x * TILENUM_Y + index.y]->GetComponent<Tile>();
	//auto tilePoly = vTotal[index.x * TILENUM_Y + index.y]->GetComponent<PolygonDraw>();
	tile->SetAttribute(attribute);

	//테스트 코드 
	vTotal[index.x * TILENUM_Y + index.y]->SetName(attributeInfo[attribute].name);
	//tilePoly->SetColor(Color{attributeInfo[attribute].r,attributeInfo[attribute].g,attributeInfo[attribute].b,1});
	//tilePoly->SetDepth(attributeInfo[attribute].depth);
}
