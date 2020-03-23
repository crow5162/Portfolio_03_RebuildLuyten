#include "stdafx.h"
#include "FadeIn.h"

void FadeIn::Init()
{
	auto children = object->GetChildren();
	for (auto c : children)
	{
		Sprite* nowSprite = c->GetComponent<Sprite>();
		if (nowSprite)
			childrenSprite.push_back(nowSprite);
	}
}
