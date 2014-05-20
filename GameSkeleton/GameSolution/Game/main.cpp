#include "Engine.h"
#include "Core.h"
#include "DrawValue.h"
#include "Ship.h"
#include "EnemyShip.h"

using Core::Input;
using Engine::Vector2D;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 750;

Ship myShip;
EnemyShip eShip;

bool Update (float dt){
	if( Input::IsPressed(Input::KEY_ESCAPE)){
		return true;
	}
	
	myShip.update(dt);
	eShip.update(dt);
	return false;
}

void Draw(Core::Graphics& graphics){
	graphics.SetBackgroundColor(RGB(0,25,0));
	myShip.drawShip(graphics);
	eShip.drawShip(graphics);
}



void main()
{
	myShip.position = Vector2D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	Core::Init( "Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
}

