#pragma once
#include "GgaetIp.h"

class Building;
/*■■■■■■■■■■■■■■■■*/        class Inventory;

class InfoBox : public Script
{
private:

    Object* _building;

    // 박스 몸체 관련
    Transform* _transform;
    Physics* _physics;
    Sprite* _sprite;

    // 박스에 텍스트 관련
    Object* _infoText;
    Text* _text;
    map<string, int> _mMaterial;
    map<string, int>::iterator _miMaterial;
    int _time;

    // 재료가 0이 아닌 것만 들어가는 새로운 map
    map<string, int> _mValidResources;
    map<string, int>::iterator _miValidResources;

    /*■■■■■■■■■■■■■■■■*/        Inventory* _inventory;



public:
    virtual void Init() override;
    virtual void Update() override;

    //virtual void OnCollisionEnter(Object* obj);
    //virtual void OnCollisionStay(Object* obj);
    //virtual void OnCollisionExit(Object* obj);

    map<string, int> GetMValidResources() { return _mValidResources; }
    map<string, int>::iterator GetMiValidResources() { return _miValidResources; }

    void SetLink(Object* ob) { _building = ob; }
    /*■■■■■■■■■■■■■■■■*/           void SetInventoryLink(Inventory* i) { _inventory = i; }
};