#pragma once

class Direct2D;
class Vector2;
class Matrix3x3;

class Image
{
private:
	ID2D1Bitmap* bitmap;
	D2D1_RECT_F size = D2D1::RectF();
	Vector2 contentSize;
	Image() {};
public:
	ID2D1Bitmap* GetBitmap() { return bitmap; };
	D2D1_RECT_F GetSize() { return size; };
	Vector2 GetContentSize();

	void SetBitmap(ID2D1Bitmap* bitamp) { this->bitmap = bitmap; };

	static shared_ptr<Image> CreateImage(string path);
	static const Matrix3x3 flipMatrix;

	~Image();
};