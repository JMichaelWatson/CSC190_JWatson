#ifndef VECTOR2D_H
#define VECTOR2D_h

#include"Math.h"

namespace Engine
{
	struct Vector2D
	{
		float x;
		float y;
		Vector2D(float x =0.0f , float y = 0.0f) : x(x), y(y) {}
		operator float*() {return &x;}
	};

	Vector2D operator+(const Vector2D& left , const Vector2D& right){
		return Vector2D(left.x + right.x, left.y + right.y);
	}
}

#endif