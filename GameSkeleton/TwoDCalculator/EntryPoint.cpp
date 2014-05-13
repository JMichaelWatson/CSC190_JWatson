#include "RenderUI.h"
#include "Engine.h"
#include "Vector2D.h"
#include "Matrix2D.h"

using Engine::Vector2D;
using Engine::Matrix2D;

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

Matrix2D mat1;
Vector2D mat2;
Vector2D matResult;

void myBasicMatrixMult(const LinearTransformationData& data){
	mat1.m[0][0] = data.m00;
	mat1.m[1][0] = data.m10;
	mat1.m[0][1] = data.m01;
	mat1.m[1][1] = data.m11;
	mat2.x = data.v0;
	mat2.y = data.v1;

	matResult = mat1 * mat2;

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
	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}