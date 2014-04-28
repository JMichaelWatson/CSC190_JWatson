#ifndef VECTOR2_H
#define VECTOR2_h

#include"Math.h"

namespace Engine
{
	struct Vector2
	{
		float x;
		float y;
		Vector2(float x =0.0f , float y = 0.0f) : x(x), y(y) {}
		operator float*() {return &x;}
	};

	Vector2 operator+(const Vector2& left , const Vector2& right){
		return Vector2(left.x + right.x, left.y + right.y);
	}
}

#endif