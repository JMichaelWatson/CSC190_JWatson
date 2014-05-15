#include "RenderUI.h"
#include "Engine.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "Matrix2D.h"
#include "Matrix3D.h"

using Engine::Vector2D;
using Engine::Matrix2D;
using Engine::Matrix3D;
using Engine::Vector3D;

Vector2D left;
Vector2D right;
Vector2D result;

void MyBasicVectorEquationCallBack(const BasicVectorEquationInfo& data){
	left = data.scalar1 * Vector2D(data.x1, data.y1);
	right = data.scalar2 * Vector2D(data.x2, data.y2);

	(data.add) ? result = left + right : result = left - right; 
}

Vector2D original;
Vector2D normal;
Vector2D cwPerpendicular;
Vector2D ccwPerpendicular;

void MyPerpendicularEqautionCallBack(const PerpendicularData& data){
	original = Vector2D(data.x, data.y);
	normal = Engine::Normalized(original);
	cwPerpendicular = Engine::CW(original);
	ccwPerpendicular = Engine::CCW(original);
}
Vector2D dotLeft;
Vector2D dotRight;
Vector2D projection;
Vector2D rejection;

void MyDotProductEquationCallBack(const DotProductData& data){
	if(data.projectOntoLeftVector){
		dotLeft = Vector2D(data.v2i, data.v2j);
		dotRight = Vector2D(data.v1i, data.v1j);
	}else{
		dotLeft = Vector2D(data.v1i, data.v1j);
		dotRight = Vector2D(data.v2i, data.v2j);
	}
	projection = Engine::Projection(dotLeft, dotRight);
	rejection = Engine::Rejection(dotLeft, dotRight);
}

Vector2D lerpLeft;
Vector2D lerpRight;
Vector2D aMinusb;
Vector2D aLerp;
Vector2D bLerp;
Vector2D lerpResult;

void MyLerbEquationCallBack(const LerpData& data)
{
	lerpLeft = Vector2D(data.a_i, data.a_j);
	lerpRight = Vector2D(data.b_i, data.b_j);
	aMinusb = lerpRight - lerpLeft;
	lerpResult = Engine::LERP(lerpLeft, lerpRight, data.beta);
	aLerp = (1 - data.beta) * lerpLeft;
	bLerp = data.beta * lerpRight;
}

Vector2D matResult;

void myBasicMatrixMult(const LinearTransformationData& data){
	Matrix2D mat1;
	Vector2D mat2;

	mat1.m[0][0] = data.m00;
	mat1.m[1][0] = data.m10;
	mat1.m[0][1] = data.m01;
	mat1.m[1][1] = data.m11;
	mat2.x = data.v0;
	mat2.y = data.v1;

	matResult = mat1 * mat2;

}

Vector3D mat3Dresult[5];
Matrix3D mat3D1;
Vector3D vect3D1;
Vector3D vect3D2;
Vector3D vect3D3;
Vector3D vect3D4;
Vector3D vect3D5;
void myAflineTransformationCallBack(const AffineTransformationData& data){


	mat3D1.m[0][0] = data.data[0];
	mat3D1.m[0][1] = data.data[1];
	mat3D1.m[0][2] = data.data[2];

	mat3D1.m[1][0] = data.data[3];
	mat3D1.m[1][1] = data.data[4];
	mat3D1.m[1][2] = data.data[5];

	mat3D1.m[2][0] = data.data[6];
	mat3D1.m[2][1] = data.data[7];
	mat3D1.m[2][2] = data.data[8];
	/////////////////////////////////////
	vect3D1.x = data.data[9];
	vect3D1.y = data.data[10];
	vect3D1.z = data.data[11];

	mat3Dresult[0]= mat3D1 * vect3D1;
	////////////////////////////////////
	vect3D2.x = data.data[12];
	vect3D2.y = data.data[13];
	vect3D2.z = data.data[14];

	mat3Dresult[1]= mat3D1 * vect3D2;
	////////////////////////////////////
	vect3D3.x = data.data[15];
	vect3D3.y = data.data[16];
	vect3D3.z = data.data[17];

	mat3Dresult[2]= mat3D1 * vect3D3;
	//////////////////////////////////////
	vect3D4.x = data.data[18];
	vect3D4.y = data.data[19];
	vect3D4.z = data.data[20];

	mat3Dresult[3]= mat3D1 * vect3D4;
	///////////////////////////////////////
	vect3D5.x = data.data[21];
	vect3D5.y = data.data[22];
	vect3D5.z = data.data[23];

	mat3Dresult[4]= mat3D1 * vect3D5;
	/////////////////////////////////////
}

const float span = 0.3f;
Vector2D bottomLeft(-span, -span);
Vector2D topLeft(-span, span);
Vector2D topRight(span, span);
Vector2D bottomRight(span, -span);
Vector2D roofTop(0, span + .25f);
Vector2D lines[] = {
	bottomLeft, topLeft,
	topLeft, topRight,
	topRight, bottomRight,
	bottomRight, bottomLeft,
	topLeft, roofTop,
	topRight, roofTop
};
int numLines = sizeof(lines) / (sizeof(*lines) * 2);

Matrix3D matrixArray[10];
Matrix3D currentTran;
void myTanslationCallBack(const MatrixTransformData2D& data){
	Matrix3D mScale;
	mScale = Engine::ScaleX3D(data.scaleX);
	Matrix3D mScale2;
	mScale2 = Engine::ScaleY3D(data.scaleY);
	Matrix3D mTranslation;
	mTranslation = Engine::Translation3D(data.translateX, data.translateY);
	Matrix3D mRotate;
	mRotate = Engine::Rotation3D(data.rotate);
	//matrixArray[data.selectedMatrix] = mRotate;//* (mScale*mScale2);
	matrixArray[data.selectedMatrix] = mTranslation * mRotate * (mScale*mScale2);
	for(int i =0; i < 10; i ++)
	{
	currentTran = currentTran * matrixArray[i];
	}
	
}

int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;

	renderUI.setBasicVectorEquationData(MyBasicVectorEquationCallBack, left, right, result);
	renderUI.setPerpendicularData(original, normal , cwPerpendicular, ccwPerpendicular, MyPerpendicularEqautionCallBack);
	renderUI.setDotProductData(dotLeft, dotRight, projection, rejection, MyDotProductEquationCallBack);
	renderUI.setLerpData(lerpLeft, lerpRight, aMinusb, aLerp, bLerp, lerpResult, MyLerbEquationCallBack);
	renderUI.setLinearTransformationData(matResult,myBasicMatrixMult);
	renderUI.setAffineTransformationData(mat3Dresult[0],myAflineTransformationCallBack);
	renderUI.set2DMatrixVerticesTransformData(lines[0], numLines,matrixArray[0],currentTran,myTanslationCallBack);
	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}