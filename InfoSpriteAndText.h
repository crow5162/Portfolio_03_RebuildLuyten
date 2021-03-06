#pragma once
#include "GgaetIp.h"

class InfoBox;
/*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/        class FixButton;

class InfoSpriteAndText : public Script
{
private:
    InfoBox* _infoBox;

    Sprite* _sprite;
    Text* _text;

    map<string, int>         _mInfo;
    map<string, int>::iterator   _miInfo;

    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/           map<string, int>         _mNeededResources;

    string _resourceKey;

    Vector2 _spriteStartPos;
    Vector2 _textStartPos;

    Object* _infoBoxOb;

    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/           FixButton* _fixButton;


public:
    virtual void Init() override;
    virtual void Update() override;

    void SetResourceKey(string resourceKey) { _resourceKey = resourceKey; }

    void SetLink(InfoBox* ib) { _infoBox = ib; }
    void SetObLink(Object* ob) { _infoBoxOb = ob; }

    void SetSpriteStartPos(Vector2 pos) { _spriteStartPos = pos; }
    void SetTextStartPos(Vector2 pos) { _textStartPos = pos; }

    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/           void SetFixButtonLink(FixButton* f) { _fixButton = f; }
};