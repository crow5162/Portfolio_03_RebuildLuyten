#include "stdafx.h"
#include "RandomMove.h"
#include <time.h>

void RandomMove::Init()
{
	transform = object->GetTransform();
	animator = object->GetComponent<Animator>();

	pos.push_back(Vector2(-TILEWIDTH / 2, TILEHEIGHT / 2));
	pos.push_back(Vector2(TILEWIDTH / 2, TILEHEIGHT / 2));
	pos.push_back(Vector2(TILEWIDTH / 2, -TILEHEIGHT / 2));
	pos.push_back(Vector2(-TILEHEIGHT / 2, -TILEHEIGHT / 2));

	vTotal = map->GetComponent<TileMap>()->GetVTotal();

	while (true)
	{
		int randX = rand() % (TILENUM_X - 1);
		int randY = rand() % (TILENUM_Y - 1);

		if (vTotal[randX * TILENUM_Y + randY]->GetComponent<Tile>()->GetAttribute() == ATTRIBUTE::WALL ||
			vTotal[randX * TILENUM_Y + randY]->GetComponent<Tile>()->GetAttribute() == ATTRIBUTE::UNDISCOVERED)
			continue;

		currentIndex = Vector2(randX, randY);
		//vTotal[randX * TILENUM_Y + randY]->GetComponent<Tile>()->SetAttribute(ATTRIBUTE::WALL);
		break;
	}

	transform->SetPosition(vTotal[currentIndex.x * TILENUM_Y + currentIndex.y]->GetTransform()->GetPosition());

	//target setting - test 
	target = Object::CreateObject();
	target->AddComponent<PolygonDraw>();
	SetTarget();

	current = Object::CreateObject();
	current->AddComponent<PolygonDraw>();
	current->GetTransform()->SetPosition(transform->GetPosition());
	
	star = new AStar();
	star->SetLinkMap(map->GetComponent<TileMap>());
	star->Init();
	star->SetStartIndex(currentIndex);
	star->SetTarget(targetIndex);
	star->SetAllowDiagonalMove(false);


	nextIndex = star->GetNextMove();

	if (nextIndex == Vector2(-1, -1))
		nextIndex = currentIndex;
	angle = (GetAngle(vTotal[currentIndex.x * TILENUM_Y + currentIndex.y]->GetTransform()->GetPosition(),
		vTotal[nextIndex.x * TILENUM_Y + nextIndex.y]->GetTransform()->GetPosition()));

}

void RandomMove::Update()
{
	SetDirection();
	Move();
}

void RandomMove::Move()
{
	Vector2 temp = transform->GetPosition() - vTotal[nextIndex.x * TILENUM_Y + nextIndex.y]->GetTransform()->GetPosition();
	float distance = temp.Magnitude();

	//다음 타일에 도착했을 때 
	if (distance < 1)
	{
		//가능한 move가 없다면 RETURN
		if (star->GetNextMove() == Vector2(-1, -1))
			return;

		vTotal[nextIndex.x * TILENUM_Y + nextIndex.y]->GetComponent<Tile>()->SetAttribute(ATTRIBUTE::NONE);

		//타겟 지점에 도착했을 때 
		if (currentIndex == targetIndex)
		{
			transform->SetPosition(vTotal[targetIndex.x * TILENUM_Y + targetIndex.y]->GetTransform()->GetPosition());
			vTotal[targetIndex.x * TILENUM_Y + targetIndex.y]->GetComponent<Tile>()->SetAttribute(ATTRIBUTE::NONE);
			SetTarget();
			star->SetTarget(targetIndex);
			star->SetStartIndex(nextIndex);
			nextIndex = star->GetNextMove();
			vTotal[nextIndex.x * TILENUM_Y + nextIndex.y]->GetComponent<Tile>()->SetAttribute(ATTRIBUTE::WALL);

			SetDirection();
			return;
		}

		star->SetStartIndex(nextIndex);
		currentIndex = nextIndex;
		nextIndex = star->GetNextMove();
		vTotal[nextIndex.x * TILENUM_Y + nextIndex.y]->GetComponent<Tile>()->SetAttribute(ATTRIBUTE::WALL);
		SetDirection();

		return;
	}


	transform->SetPosition(Vector2(transform->GetPosition().x - cosf(angle) * SPEED,
		transform->GetPosition().y + sinf(angle) * SPEED));
}

void RandomMove::SetDirection()
{
	angle = (GetAngle(vTotal[currentIndex.x * TILENUM_Y + currentIndex.y]->GetTransform()->GetPosition(),
		vTotal[nextIndex.x * TILENUM_Y + nextIndex.y]->GetTransform()->GetPosition()));

	int a = 0;

	if ((angle <-3.14 * 2 / 4 + 0.05 && angle > -3.14 * 2 / 4 - 0.05) ||
		(angle < 3 * 3.14 * 2 / 4 + 0.02 && angle > 3 * 3.14 * 2 / 4 - 0.02))
		a = 3;
	if ((angle < 3 * -3.14 * 2 / 4 + 0.05 && angle > 3 * -3.14 * 2 / 4 - 0.05) ||
		(angle < 3.14 * 2 / 4 + 0.02 && angle > 3.14 * 2 / 4 - 0.02))
		a = 1;
	if ((angle < 2 * -3.14 * 2 / 4 + 0.05 && angle > 2 * -3.14 * 2 / 4 - 0.05) ||
		(angle < 2 * 3.14 * 2 / 4 + 0.02 && angle > 2 * 3.14 * 2 / 4 - 0.02))
		object->GetComponent<Sprite>()->SetFlip(true);
	else if (angle < 0.05 && angle >  -0.05)
		object->GetComponent<Sprite>()->SetFlip(false);

	animator->SetParameter("Move", a);

}

void RandomMove::SetTarget()
{
	vector<Vector2> pos;
	pos.push_back(Vector2(-TILEWIDTH / 2, TILEHEIGHT / 2));
	pos.push_back(Vector2(TILEWIDTH / 2, TILEHEIGHT / 2));
	pos.push_back(Vector2(TILEWIDTH / 2, -TILEHEIGHT / 2));
	pos.push_back(Vector2(-TILEHEIGHT / 2, -TILEHEIGHT / 2));


	while (true)
	{
		int randX = rand() % (TILENUM_X - 1);
		int randY = rand() % (TILENUM_Y - 1);

		if (vTotal[randX * TILENUM_Y + randY]->GetComponent<Tile>()->GetAttribute() == ATTRIBUTE::WALL)
			continue;


		targetIndex = Vector2(randX, randY);
		vTotal[randX * TILENUM_Y + randY]->GetComponent<Tile>()->SetAttribute(ATTRIBUTE::WALL);
		break;
	}
	target->GetTransform()->SetPosition(vTotal[targetIndex.x * TILENUM_Y + targetIndex.y]->GetTransform()->GetPosition());
	/*auto poly = target->GetComponent<PolygonDraw>();
	poly->SetVertices(pos);
	poly->SetStrokeWidth(5);
	poly->SetColor(Color{ 0,1,0,1 });*/
}
