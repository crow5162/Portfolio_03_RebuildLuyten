#pragma once
#include "GgaetIp.h"

class BuildingManager;
class Inventory;

struct ObjectData
{
    char name[50];
    Vector2 position;
    int depth;
};

enum class Attribute
{
    None,
    Undiscovered,
    Wall
};

class MapManager : public Script
{
private:
    Attribute** tileMap;
    Vector2 mapSize;
    vector<Object*> vBuilding;
    Inventory* _inventory;
public:
    static MapManager* GetInstance();
    void Load(string name, BuildingManager* manager);
    void Load(string name, Object* obj);

    vector<Object*> GetVBuilding() { return vBuilding; };
    
    pair<Attribute**, Vector2> GetTileMap();
    void SetInventoryLink(Inventory* i) { _inventory = i; }
};
