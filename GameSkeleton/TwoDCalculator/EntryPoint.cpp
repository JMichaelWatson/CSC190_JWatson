#include "RenderUI.h"
#include "Engine.h"
#include "Vector2D.h"

using Engine::Vector2D;

Vector2D left;
Vector2D right;
Vector2D result;

void MyBasicVectorEquationCallBack(const BasicVectorEquationInfo& data){
	left = data.scalar1 = Vector2D(data.x1, data,y1);
	right = data.scalar2 = Vector2D(data.x2, data.y2);

}


int main(int argc, char* argv[])
{
	Engine::Init();

	RenderUI renderUI;

	if( ! renderUI.initialize(argc, argv))
		return -1;
	return renderUI.run();
}