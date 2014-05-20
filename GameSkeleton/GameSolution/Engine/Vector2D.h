#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include"Math.h"
#include"Vector3D.h"

namespace Engine
{
	struct Vector2D
	{
		float x;
		float y;
		Vector2D(float x =0.0f , float y = 0.0f) : x(x), y(y) {}
		operator float*() {return &x;}
	};

	inline Vector2D operator+(const Vector2D& left , const Vector2D& right){
		return Vector2D(left.x + right.x, left.y + right.y);
	}

	inline Vector2D operator+(const Vector2D& left , const Vector3D& right){
		return Vector2D(left.x + right.x, left.y + right.y);
	}

	inline Vector2D operator-(const Vector2D& left,  const Vector2D& right){
		return Vector2D(left.x - right.x, left.y - right.y);
	}

	inline Vector2D operator*(const Vector2D& vector, const float& scaler){
		return Vector2D(vector.x * scaler, vector.y * scaler);
	}

	inline Vector2D operator*(const float& scaler, const Vector2D& vector){
		return Vector2D(vector.x * scaler, vector.y * scaler);
	}

	inline Vector2D operator/(const Vector2D& vector, const float& scaler){
		return Vector2D(vector.x / scaler, vector.y / scaler);
	}

	inline Vector2D LERP(const Vector2D& left, const Vector2D& right, const float& beta){
		return Vector2D(((1-beta)*left.x + (beta*right.x)),  ((1-beta)*left.y + (beta*right.y)));
	}

	inline float Length(const Vector2D& vector){
		return sqrt(pow(vector.x,2) + pow(vector.y,2));
	}

	inline float SquareLenght(const Vector2D& vector){
		return (pow(vector.x, 2) + pow(vector.y, 2));
	}

	inline Vector2D Normalized(const Vector2D& vector){
		float length = Length(vector);
		return vector / length;		
	}
	
	inline float Dot(const Vector2D& left, const Vector2D& right){
		return ((left.x * right.x) + (left.y * right.y));
	}

	inline Vector2D CW(const Vector2D& vector){
		return Vector2D(-(vector.y), vector.x);
	}

	inline Vector2D CCW(const Vector2D& vector){
		return Vector2D(vector.y, -(vector.x));
	}

	inline Vector2D Projection(const Vector2D& a, const Vector2D& b){
		float vect1lenght = Length(a);
		float projectionLength = Dot(a,b) / vect1lenght;
		Vector2D vect1Normal = Normalized(a);
		return (vect1Normal * projectionLength);
	}    

	inline Vector2D Rejection(const Vector2D& a, const Vector2D& b){
		return (b - Projection(a, b));
	}
}

#endif