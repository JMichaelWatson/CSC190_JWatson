#include "GameManager.h"

using Core::Input;
using Engine::Vector2D;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 750;

GameManager gm;

bool Update (float dt){
	if( Input::IsPressed(Input::KEY_ESCAPE)){
		gm.shutdown();
		return true;
	}
	gm.Update(dt);
	return false;
}

void Draw(Core::Graphics& graphics){
	gm.Draw(graphics);
}



void main()
{
	Core::Init( "Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	gm.init();
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
}

