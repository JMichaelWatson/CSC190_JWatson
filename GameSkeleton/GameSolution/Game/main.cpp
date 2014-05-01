#include "Engine.h"
#include "Core.h"

using Core::Input;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

bool Update (float dt){
	dt;
	if( Input::IsPressed(Input::KEY_ESCAPE)){
		return true;
	}
	return false;
}

void Draw(Core::Graphics& graphics){
	graphics.SetBackgroundColor(RGB(0,25,0));
	graphics.SetColor(RGB(115,25,25));
	graphics.DrawString(SCREEN_WIDTH/2 - 50, SCREEN_HEIGHT/2 -20, "Hello World!");
	graphics.SetColor(RGB(255,0,255));
	graphics.DrawLine(10,10,400,300);
}



void main()
{
	Core::Init( "Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
}

