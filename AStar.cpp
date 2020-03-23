#include "stdafx.h"
#include "AStar.h"
#include "TileMap.h"


void AStar::Init()
{
	vTotal = tileMap->GetVTotal();
	if(targetMove)
		SetTarget(targetIndex);
}

void AStar::Update()
{
	if (InputManager::GetInstance()->GetKeyDown(VK_RETURN))
		_isStart = true;

	count++;

	if (count % 30 == 0 && count != 0)
	{
		FindPath();
		MakeMove();
	}

}

void AStar::AddOpenList()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int nowIndex = (currentIndex.x - 1 + i) * TILENUM_Y + currentIndex.y - 1 + j;

			//예외처리 
			if (nowIndex < 0 || nowIndex > vTotal.size() - 1) continue;
			if ((currentIndex.x == 0 && i == 0)|| (currentIndex.x == TILENUM_X - 1 && i == 2))  continue;
			if ((currentIndex.y == 0 && j == 0) || (currentIndex.y == TILENUM_Y - 1 && j == 2)) continue;
			if (i == 1 && j == 1) continue;

			if (!allowDiagonalMove)
			{
				if ((i == 0 && j == 0) || (i == 0 && j == 2) || (i == 2 && j == 0) || (i == 2 && j == 2))
					continue;
			}

			Tile* current = vTotal[nowIndex]->GetComponent<Tile>();

			//코스트 처리 
			Vector2 temp = vTotal[nowIndex]->GetTransform()->GetPosition() - vTotal[targetIndex.x * TILENUM_Y + targetIndex.y]->GetTransform()->GetPosition();
			float H = temp.Magnitude();

			Vector2 temp2 = vTotal[nowIndex]->GetTransform()->GetPosition() - vTotal[currentIndex.x * TILENUM_Y + currentIndex.y]->GetTransform()->GetPosition();
			float G = temp2.Magnitude() + vTotal[currentIndex.x * TILENUM_Y + currentIndex.y]->GetComponent<Tile>()->GetCostFromStart();

			//필요할 시 코스트 업데이트 
			if (current->GetIsOpen())
			{
				if (G + H < current->GetTotalCost())
				{
					current->SetTotalCost(G + H);
					current->SetParent(vTotal[currentIndex.x*TILENUM_Y + currentIndex.y]->GetComponent<Tile>());
				}

				continue;
			}

			//WALL이지만 본인의 타겟일때 
			if (current->GetAttribute() == ATTRIBUTE::WALL && nowIndex != targetIndex.x * TILENUM_Y + targetIndex.y) continue;
			if (current->GetAttribute() == ATTRIBUTE::UNDISCOVERED) continue;

			//더해지지 않았다면 코스트 정해주고 OPEN LIST에 푸시 
			current->SetCostFromStart(G);
			current->SetCostToGoal(H);
			current->SetTotalCost(G + H);
			current->SetParent(vTotal[currentIndex.x * TILENUM_Y + currentIndex.y]->GetComponent<Tile>());
			current->SetIsOpen(true);

			vOpen.push_back(vTotal[nowIndex]);

		}
	}

}

void AStar::FindPath()
{

	//if (!_isStart)
		//return;

	//리셋 
	vOpen.clear();
	vClosed.clear();
	path.clear();

	for (int i = 0; i < vTotal.size(); i++)
	{
		if (vTotal[i]->GetComponent<Tile>()->GetAttribute() == ATTRIBUTE::WALL && i != targetIndex.x * TILENUM_Y + targetIndex.y) 
			continue;

		vTotal[i]->GetComponent<Tile>()->SetAttribute(ATTRIBUTE::NONE);
		vTotal[i]->GetComponent<Tile>()->SetIsOpen(false);
		//vTotal[i]->GetComponent<PolygonDraw>()->SetColor(Color{ 1,1,1,1 });
	}

	vClosed.push_back(vTotal[startIndex.x * TILENUM_Y + startIndex.y]);
	vTotal[startIndex.x * TILENUM_Y + startIndex.y]->GetComponent<Tile>()->SetIsOpen(true);

	if(targetMove)
		SetTarget(targetIndex);

	currentIndex = startIndex;

	while (true)
	{
		//길 찾기 완료 
		if (targetIndex == currentIndex)
		{
			Vector2 index = targetIndex;
			path.push_back(vTotal[targetIndex.x * TILENUM_Y + targetIndex.y]);
			while (true)
			{
				if (index == startIndex)
					break;

				//auto poly = vTotal[index.x * TILENUM_Y + index.y]->GetComponent<PolygonDraw>();
				//poly->SetColor(Color{ 1,0,0,0.3 });
				//poly->SetDepth(10);

				index = vTotal[index.x * TILENUM_Y + index.y]->GetComponent<Tile>()->GetParent()->GetIndex();
				path.push_back(vTotal[index.x * TILENUM_Y + index.y]);
			}
			return;
		}


		AddOpenList();

		//예외 처리 
		if (!vOpen.size())
			return;

		int cost = 100000;
		int index = 0;
		Vector2 index2 = Vector2::zero;

		//OPEN에서 가장 COST가 낮은 것을 CLOSED 에 더하고 OPEN에서는 뺀다 
		for (int i = 0; i < vOpen.size(); i++)
		{
			if (vOpen[i]->GetComponent<Tile>()->GetTotalCost() < cost)
			{
				cost = vOpen[i]->GetComponent<Tile>()->GetTotalCost();
				index = i;
			}
		}
		vClosed.push_back(vOpen[index]);
		vOpen.erase(vOpen.begin() + index);

		//OPEN LIST 업데이트를 위한 currentindex 업데이트 
		currentIndex = vClosed[vClosed.size() - 1]->GetComponent<Tile>()->GetIndex();

	}

}

void AStar::MakeMove()
{
	if (path.size() < 2)
		return;

	Vector2 index = path[path.size()-2]->GetComponent<Tile>()->GetIndex();
	auto poly = vTotal[startIndex.x * TILENUM_Y + startIndex.y]->GetComponent<PolygonDraw>();
	poly->SetColor(Color{ 0,0,1,1 });
	poly->SetStrokeWidth(2);

	//현재 베스트 무브를 다음 start로 설정 
	startIndex = index;
}

Vector2 AStar::GetNextMove()
{
	FindPath();

	//길이 없을 때 
	if (path.size() == 0)
		return Vector2(-1, -1);

	Vector2 index = Vector2::zero;
	if (path.size() == 1)
		index = path[0]->GetComponent<Tile>()->GetIndex();
	else
		index = path[path.size() - 2]->GetComponent<Tile>()->GetIndex();

	//startIndex = index;
	return index;
                                                  
}

                                                                                                        