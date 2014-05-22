#include "GameManager.h"
#include "ParticalEffect.h"

using Core::Input;
using Engine::Vector2D;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 750;

GameManager gm;
ParticalEffect pEffect;

bool Update (float dt){
	if( Input::IsPressed(Input::KEY_ESCAPE)){
		return true;
	}
	gm.Update(dt);
	pEffect.update(dt, 100);
	return false;
}

void Draw(Core::Graphics& graphics){
	pEffect.draw(graphics, 100, Vector2D(500,300));
	gm.Draw(graphics);
}



void main()
{
	Core::Init( "Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
}

