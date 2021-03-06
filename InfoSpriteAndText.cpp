#include "stdafx.h"
#include "InfoSpriteAndText.h"
#include "InfoBox.h"
/*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/        #include "FixButton.h"

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

    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         _mNeededResources = _fixButton->GetMNeededResources();
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         string rAmount2 = to_string(_mNeededResources[_resourceKey]);
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         wstring _resourceKeyW2;
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         _resourceKeyW2.assign(rAmount2.begin(), rAmount2.end());
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         Object* invenStatusText = Object::CreateObject(object->GetParent());
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         invenStatusText->AddComponent<Text>();
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         invenStatusText->GetComponent<Text>()->CreateText(_resourceKeyW2, L"Vivaldi", L"ko-KR", { 1,1,1,1 }, 20, 50, 100);
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         invenStatusText->GetTransform()->SetPosition(Vector2(_textStartPos.x - 50, _textStartPos.y));
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         invenStatusText->GetComponent<Text>()->SetAnchorPoint(AnchorPoint::LeftTop);
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         Color green = { 0.f, 1.f, 0.2f, 1.f };
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         Color red = { 1.f, 0.2f, 0.2f, 1.f };
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         if (_mNeededResources[_resourceKey] >= _mInfo[_resourceKey])
        /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/ {
        /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/            invenStatusText->GetComponent<Text>()->SetColor(green, 0, 3);
        /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/
    }
    /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/         else
        /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/ {
        /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/            invenStatusText->GetComponent<Text>()->SetColor(red, 0, 3);
        /*กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ*/
    }
}

void InfoSpriteAndText::Update()
{

}