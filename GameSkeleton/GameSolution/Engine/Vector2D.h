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

	Vector2D operator-(const Vector2D& left,  const Vector2D& right){
		return Vector2D(left.x - right.x, left.y - right.y);
	}

	Vector2D operator*(const Vector2D& vector, const float& scaler){
		return Vector2D(vector.x * scaler, vector.y * scaler);
	}

	Vector2D operator*(const float& scaler, const Vector2D& vector){
		return Vector2D(vector.x * scaler, vector.y * scaler);
	}

	Vector2D operator/(const Vector2D& vector, const float& scaler){
		return Vector2D(vector.x / scaler, vector.y / scaler);
	}

	Vector2D LERP(const Vector2D& left, const Vector2D& right, const float& beta){
		return Vector2D(((1-beta)*left.x + (beta*right.x)),  ((1-beta)*left.y + (beta*right.y)));
	}

	float Length(const Vector2D& vector){
		return sqrt(pow(vector.x,2) + pow(vector.y,2));
	}

	float SquareLenght(const Vector2D& vector){
		return (pow(vector.x, 2) + pow(vector.y, 2));
	}

	Vector2D Normalized(const Vector2D& vector){
		float length = Length(vector);
		return vector / length;
		
	}
	
	float Dot(const Vector2D& left, const Vector2D& right){
		return ((left.x * right.x) + (left.y * right.y));
	}

	Vector2D CW(const Vector2D& vector){
		return Vector2D(-(vector.y), vector.x);
	}

	Vector2D CCW(const Vector2D& vector){
		return Vector2D(vector.y, -(vector.x));
	}
}

#endif