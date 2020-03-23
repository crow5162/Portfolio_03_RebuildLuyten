#pragma once
#include "GgaetIp.h"

/*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/        class Inventory;

class FixButton : public Script
{
private:
    Object* _building;
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/        Inventory* _inventory;

    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/        map<string, int> _neededResources;

public:
    virtual void OnMouseDown();
    void SetLink(Object* ob) { _building = ob; }

    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/           void SetInventoryLink(Inventory* i) { _inventory = i; }

    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/           map<string, int> GetMNeededResources() { return _neededResources; }

};