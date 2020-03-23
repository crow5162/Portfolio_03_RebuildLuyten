#include "stdafx.h"
#include "GgaetIp.h"

void DrawComponent::Awake()
{
	this->transform = object->GetTransform();
}

void DrawComponent::SetDepth(int _depth)
{
	object->GetTransform()->SetDepth(_depth);
}

int DrawComponent::GetDepth()
{
	return  object->GetTransform()->GetDepth();
}