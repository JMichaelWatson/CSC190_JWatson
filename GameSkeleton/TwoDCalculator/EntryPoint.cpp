#include "RenderUI.h"
#include "Engine.h"
#include "Vector2D.h"

using Engine::Vector2D;

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
	left = Vector2D(data.x, data.y);
	normal = Engine::Normalized(left);
	cwPerpendicular = Engine::CW(left);
	ccwPerpendicular = Engine::CCW(left);
}

Vector2D projection;
Vector2D rejection;

void MyDotProductEquationCallBack(const DotProductData& data){
	left = Vector2D(data.v1i, data.v1j);
	right = Vector2D(data.v2i, data.v2j);
	projection = Engine::Projection(left, right);
	rejection = Engine::Rejection(left, right);
}


int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;
	
	renderUI.setBasicVectorEquationData(MyBasicVectorEquationCallBack, left, right, result);
	renderUI.setPerpendicularData(original, normal , cwPerpendicular, ccwPerpendicular, MyPerpendicularEqautionCallBack);
	renderUI.setDotProductData(left, right, projection, rejection, MyDotProductEquationCallBack);
	
	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}