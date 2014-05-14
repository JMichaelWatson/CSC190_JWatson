#ifndef _VECTOR3D_H_
#define _VECTOR3D_H_

#include"Math.h"

namespace Engine
{
	struct Vector3D
	{
		float x;
		float y;
		float z;
		Vector3D(float x =0.0f , float y = 0.0f, float z = 1.0f) : x(x), y(y), z(z) {}
		operator float*() {return &x;}
	};

	inline Vector3D operator+(const Vector3D& left , const Vector3D& right){
		return Vector3D(left.x + right.x, left.y + right.y);
	}

	inline Vector3D operator-(const Vector3D& left,  const Vector3D& right){
		return Vector3D(left.x - right.x, left.y - right.y);
	}

	inline Vector3D operator*(const Vector3D& vector, const float& scaler){
		return Vector3D(vector.x * scaler, vector.y * scaler);
	}

	inline Vector3D operator*(const float& scaler, const Vector3D& vector){
		return Vector3D(vector.x * scaler, vector.y * scaler);
	}

	inline Vector3D operator/(const Vector3D& vector, const float& scaler){
		return Vector3D(vector.x / scaler, vector.y / scaler);
	}

	inline Vector3D LERP(const Vector3D& left, const Vector3D& right, const float& beta){
		return Vector3D(((1-beta)*left.x + (beta*right.x)),  ((1-beta)*left.y + (beta*right.y)));
	}

	inline float Length(const Vector3D& vector){
		return sqrt(pow(vector.x,2) + pow(vector.y,2));
	}

	inline float SquareLenght(const Vector3D& vector){
		return (pow(vector.x, 2) + pow(vector.y, 2));
	}

	inline Vector3D Normalized(const Vector3D& vector){
		float length = Length(vector);
		return vector / length;		
	}
	
	inline float Dot(const Vector3D& left, const Vector3D& right){
		return ((left.x * right.x) + (left.y * right.y));
	}

	inline Vector3D CW(const Vector3D& vector){
		return Vector3D(-(vector.y), vector.x);
	}

	inline Vector3D CCW(const Vector3D& vector){
		return Vector3D(vector.y, -(vector.x));
	}

	inline Vector3D Projection(const Vector3D& a, const Vector3D& b){
		float vect1lenght = Length(a);
		float projectionLength = Dot(a,b) / vect1lenght;
		Vector3D vect1Normal = Normalized(a);
		return (vect1Normal * projectionLength);
	}    

	inline Vector3D Rejection(const Vector3D& a, const Vector3D& b){
		return (b - Projection(a, b));
	}
}

#endif