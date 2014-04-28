#include<RenderUI>
#include"Engine.h"

using Vector2::Engine;


int main(int argc, char* argv[])
{
	Engine::Init();
	RenderUI renderUI;

	renderUI.setBasicVectorEquationData();
}