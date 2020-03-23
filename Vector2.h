#pragma once
class Vector3;
class Vector2
{
public:
	Vector2() {};
	Vector2(float x, float y) : x(x), y(y) {};

	float x;
	float y;

	static Vector2 Lerp(Vector2 a, Vector2 b, float i);
	static void Swap(Vector2* a, Vector2* b);
	static float Dot(Vector2 a, Vector2 b);
	static Vector3 Cross(Vector2 a, Vector2 b);

	Vector2 Normalize();
	float Magnitude();
	float SqrMagnitude();
	Vector2 Rotate(float rotation);

	static const Vector2 up;
	static const Vector2 down;
	static const Vector2 right;
	static const Vector2 left;
	static const Vector2 zero;

	Vector2 operator-(const Vector2& right);
	Vector2 operator+(const Vector2& right);
	Vector2 operator*(float right);
	Vector2 operator/(int right);
	Vector2 operator*(const Vector2& right);
	Vector2 operator/(const Vector2& right);
	void operator+=(const Vector2& right);
	void operator-=(const Vector2& right);
	bool operator==(const Vector2& right);
	bool operator!=(const Vector2& right);
};

