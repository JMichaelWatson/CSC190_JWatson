#ifndef _MATRIX2D_H_
#define _MATRIX2D_H_

#include "Vector2D.h"
#include "Math.h"

using Engine::Vector2D;

namespace Engine{
	struct Matrix2D{
		float m[2][2];
	public:
		Matrix2D(){
			for ( int x= 0; x < 2; x++){
				for ( int y=0; y < 2; y++){
					if(x == y){
						m[x][y] = 1.0f;
					}else{
						m[x][y] = 0.0f;
					}
				}
			}
		}
		Matrix2D(Vector2D vect1, Vector2D vect2){
			m[0][0] = vect1.x;
			m[0][1] = vect1.y;
			m[1][0] = vect2.x;
			m[1][1] = vect2.y;
		}
	};

	inline Matrix2D Rotation(float angle){
		Matrix2D rotation;
		float c = cos(angle);
		float s = sin(angle);

		rotation.m[0][0] = c;
		rotation.m[1][0] = -s;
		rotation.m[0][1] = s;
		rotation.m[1][1] = c;
		
		return rotation;
	}

	inline Matrix2D Scale(float scale){
		Matrix2D mScale;
		mScale.m[0][0] = scale;
		mScale.m[1][1] = scale;

		return mScale;
	}

	inline Matrix2D ScaleX(float scale){
		Matrix2D mScale;
		mScale.m[0][0] = scale;

		return mScale;
	}

	inline Matrix2D ScaleY(float scale){
		Matrix2D mScale;
		mScale.m[1][1] = scale;

		return mScale;
	}

	inline Matrix2D operator*(Matrix2D mat1, Matrix2D mat2){
		Matrix2D result;
		result.m[0][0] = (mat1.m[0][0] * mat2.m[0][0]) + (mat1.m[1][0] * mat2.m[0][1]);
		result.m[1][0] = (mat1.m[0][0] * mat2.m[1][0]) + (mat1.m[1][0] * mat2.m[1][1]);
		result.m[0][1] = (mat1.m[0][1] * mat2.m[0][0]) + (mat1.m[1][1] * mat2.m[0][1]);
		result.m[1][1] = (mat1.m[0][1] * mat2.m[1][0]) + (mat1.m[1][1] * mat2.m[1][1]);
		return result;
	}

	inline Vector2D operator*(Matrix2D mat1, Vector2D mat2){
		Vector2D theresult;
		theresult.x = (mat1.m[0][0] * mat2.x) + (mat1.m[0][1] * mat2.y);
		theresult.y = (mat1.m[0][1] * mat2.x) + (mat1.m[1][1] * mat2.y);
		return theresult;
	}
}
#endif