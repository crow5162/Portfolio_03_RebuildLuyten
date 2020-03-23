#include "stdafx.h"
#include "PageButton.h"

void PageButton::OnMouseDown()
{
	if (object->GetTag() == "PageButton_Down")
	{
		if(linked->GetPageNum() > 1)
			linked->SetPageNum(linked->GetPageNum() - 1);
	}
	else if( object->GetTag()=="PageButton_Up")
	{
		if (linked->GetPageNum() < linked->GetMaxPageNum() + 1)
			linked->SetPageNum(linked->GetPageNum() + 1);
	}
	object->GetTransform()->SetScale(Vector2(0.7, 0.7));

}

void PageButton::OnMouseUp()
{
	object->GetTransform()->SetScale(Vector2(0.8, 0.8));
}
