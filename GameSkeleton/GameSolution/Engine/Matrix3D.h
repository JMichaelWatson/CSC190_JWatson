#ifndef _MATRIX3D_H_
#define _MATRIX3D_H_

#include "Vector2D.h"
#include "Vector3D.h"
#include "Math.h"


using Engine::Vector2D;
using Engine::Vector3D;

namespace Engine{

	struct Matrix3D
	{
		float m[3][3];
	public:
		Matrix3D(){
			for ( int x= 0; x < 3; x++){
				for ( int y=0; y < 3; y++){
					if(x == y){
						m[x][y] = 1.0f;
					}else{
						m[x][y] = 0.0f;
					}
				}
			}
		}
		Matrix3D(Vector2D vect1, Vector2D vect2){
			m[0][0] = vect1.x;
			m[1][0] = vect1.y;
			m[0][1] = vect2.x;
			m[1][1] = vect2.y;
		}
		operator float*() {return &m[0][0];}
			
	};


	inline Matrix3D Rotation3D(float angle){
		Matrix3D rotation;
		float c = cos(angle);
		float s = sin(angle);

		rotation.m[0][0] = c;
		rotation.m[1][0] = -s;
		rotation.m[0][1] = s;
		rotation.m[1][1] = c;

		return rotation;
	}

	inline Matrix3D Scale3D(const float& scale){
		Matrix3D mScale;
		mScale.m[0][0] = scale;
		mScale.m[1][1] = scale;

		return mScale;
	}

	inline Matrix3D  ScaleX3D(const float& scale){
		Matrix3D mScale;
		mScale.m[0][0] = scale;

		return mScale;
	}

	 inline Matrix3D ScaleY3D(const float& scale){
		Matrix3D mScale;
		mScale.m[1][1] = scale;

		return mScale;
	}

	 inline Matrix3D Translation3D(const float& x, const float& y){
		Matrix3D translation;
		translation.m[0][2] = x;
		translation.m[1][2] = y;
		return translation;
	}

	 inline Matrix3D Translation3D(const Vector2D& vect){
		Matrix3D translation;
		translation.m[0][2] = vect.x;
		translation.m[1][2] = vect.y;
		return translation;
	}

	inline Matrix3D operator*(const Matrix3D& mat1, const Matrix3D& mat2){
		Matrix3D result;
		result.m[0][0] = (mat1.m[0][0] * mat2.m[0][0]) + (mat1.m[0][1] * mat2.m[1][0]) + (mat1.m[0][2] * mat2.m[2][0]);
		result.m[0][1] = (mat1.m[0][0] * mat2.m[0][1]) + (mat1.m[0][1] * mat2.m[1][1]) + (mat1.m[0][2] * mat2.m[2][1]);
		result.m[0][2] = (mat1.m[0][0] * mat2.m[0][2]) + (mat1.m[0][1] * mat2.m[1][1]) + (mat1.m[0][2] * mat2.m[2][2]);

		result.m[1][0] = (mat1.m[1][0] * mat2.m[0][0]) + (mat1.m[1][1] * mat2.m[1][0]) + (mat1.m[1][2] * mat2.m[2][0]);		
		result.m[1][1] = (mat1.m[1][0] * mat2.m[0][1]) + (mat1.m[1][1] * mat2.m[1][1]) + (mat1.m[1][2] * mat2.m[2][1]);
		result.m[1][2] = (mat1.m[1][0] * mat2.m[0][2]) + (mat1.m[1][1] * mat2.m[1][1]) + (mat1.m[1][2] * mat2.m[2][2]);

		result.m[2][0] = (mat1.m[2][0] * mat2.m[0][0]) + (mat1.m[2][1] * mat2.m[1][0]) + (mat1.m[2][2] * mat2.m[2][0]);		
		result.m[2][1] = (mat1.m[2][0] * mat2.m[0][1]) + (mat1.m[2][1] * mat2.m[1][1]) + (mat1.m[2][2] * mat2.m[2][1]);
		result.m[2][2] = (mat1.m[2][0] * mat2.m[0][2]) + (mat1.m[2][1] * mat2.m[1][1]) + (mat1.m[2][2] * mat2.m[2][2]);

		return result;
	}

	inline Vector3D operator*(const Matrix3D& mat1, const Vector2D& vect2){
		Vector3D result;
		result.x = (mat1.m[0][0] * vect2.x) + (mat1.m[0][1] * vect2.y) + (mat1.m[0][2] * 1);
		result.y = (mat1.m[1][0] * vect2.x) + (mat1.m[1][1] * vect2.y) + (mat1.m[1][2] * 1);

		return result;
	}

	inline Vector3D operator*(const Vector2D& vect2, const Matrix3D& mat1){
		Vector3D result;
		result.x = (mat1.m[0][0] * vect2.x) + (mat1.m[0][1] * vect2.y) + (mat1.m[0][2] * 1);
		result.y = (mat1.m[1][0] * vect2.x) + (mat1.m[1][1] * vect2.y) + (mat1.m[1][2] * 1);

		return result;
	}

	inline Vector3D operator*(const Vector3D& vect2, const Matrix3D& mat1){
		Vector3D result;
		result.x = (mat1.m[0][0] * vect2.x) + (mat1.m[0][1] * vect2.y) + (mat1.m[0][2] * vect2.z);
		result.y = (mat1.m[1][0] * vect2.x) + (mat1.m[1][1] * vect2.y) + (mat1.m[1][2] * vect2.z);

		return result;
	}

	inline Vector3D operator*(const Matrix3D& mat1, const Vector3D& vect2){
		Vector3D result;
		result.x = (mat1.m[0][0] * vect2.x) + (mat1.m[0][1] * vect2.y) + (mat1.m[0][2] * vect2.z);
		result.y = (mat1.m[1][0] * vect2.x) + (mat1.m[1][1] * vect2.y) + (mat1.m[1][2] * vect2.z);

		return result;
	}


}
#endif