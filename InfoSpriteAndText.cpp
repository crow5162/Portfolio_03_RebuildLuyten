#include "stdafx.h"
#include "InfoSpriteAndText.h"
#include "InfoBox.h"
/*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/        #include "FixButton.h"

void InfoSpriteAndText::Init()
{
    _mInfo = _infoBox->GetMValidResources();
    _miInfo = _infoBox->GetMiValidResources();

    Object* infoSprite = Object::CreateObject(object->GetParent());
    _sprite = infoSprite->AddComponent<Sprite>();
    _sprite->SetSprite(Image::CreateImage("Sprite/Need_" + _resourceKey + ".png"));
    _sprite->GetTransform()->SetPosition(_spriteStartPos);

    string rAmount = to_string(_mInfo[_resourceKey]);
    wstring _resourceKeyW;
    _resourceKeyW.assign(rAmount.begin(), rAmount.end());

    Object* infoText = Object::CreateObject(object->GetParent());
    _text = infoText->AddComponent<Text>();
    _text->CreateText(_resourceKeyW, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 20, 50, 100);
    _text->GetTransform()->SetPosition(_textStartPos);
    _text->SetAnchorPoint(AnchorPoint::LeftTop);

    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         _mNeededResources = _fixButton->GetMNeededResources();
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         string rAmount2 = to_string(_mNeededResources[_resourceKey]);
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         wstring _resourceKeyW2;
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         _resourceKeyW2.assign(rAmount2.begin(), rAmount2.end());
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         Object* invenStatusText = Object::CreateObject(object->GetParent());
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         invenStatusText->AddComponent<Text>();
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         invenStatusText->GetComponent<Text>()->CreateText(_resourceKeyW2, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 20, 50, 100);
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         invenStatusText->GetTransform()->SetPosition(Vector2(_textStartPos.x - 50, _textStartPos.y));
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         invenStatusText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftTop);
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         Color green = { 0.f, 1.f, 0.2f, 1.f };
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         Color red = { 1.f, 0.2f, 0.2f, 1.f };
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         if (_mNeededResources[_resourceKey] >= _mInfo[_resourceKey])
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/ {
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/            invenStatusText->GetComponent<Text>()->SetColor(green, 0, 3);
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/
    }
    /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/         else
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/ {
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/            invenStatusText->GetComponent<Text>()->SetColor(red, 0, 3);
        /*¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á*/
    }
}

void InfoSpriteAndText::Update()
{

}