#pragma once
#include "GgaetIp.h"

enum class ATTRIBUTE
{
	NONE,
	WALL,
	PLAYER,
	ENEMY,
	UNDISCOVERED
};


class Tile : public Script
{
private:
	Vector2 index;
	ATTRIBUTE attribute;
	map<ATTRIBUTE, string> attribute_to_string;


	float totalCost = 5000;
	float costFromStart = 5000;
	float costToGoal = 5000;

	bool isOpen = false;

	Tile* parent;


public:
	void SetIndex(Vector2 index) { this->index = index; }
	void SetAttribute(ATTRIBUTE attribute) { this->attribute = attribute; }
	void SetParent(Tile* parent) { this->parent = parent; }
	void SetIsOpen(bool isOpen) { this->isOpen = isOpen; }

	void SetTotalCost(float cost) { this->totalCost = cost; }
	void SetCostFromStart(float cost) { this->costFromStart = cost; }
	void SetCostToGoal(float cost) { this->costToGoal = cost; }


	Vector2 GetIndex() { return index; }
	bool GetIsOpen() { return isOpen; }
	ATTRIBUTE GetAttribute() { return attribute; }
	Tile* GetParent() { return parent; }
	map<ATTRIBUTE, string> GetAttributeToString() { return attribute_to_string; }

	float GetTotalCost() { return totalCost; }
	float GetCostFromStart() { return costFromStart; }
	float GetCostToGoal() { return costToGoal; }

};

