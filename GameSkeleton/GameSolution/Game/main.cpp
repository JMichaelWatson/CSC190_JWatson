#include "Engine.h"
#include "Core.h"
#include "DrawValue.h"
#include "Ship.h"
#include "EnemyShip.h"
#include "Orbitz.h"

using Core::Input;
using Engine::Vector2D;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 750;

Ship myShip;
EnemyShip eShip;
Orbitz orb;

bool Update (float dt){
	if( Input::IsPressed(Input::KEY_ESCAPE)){
		return true;
	}
	
	myShip.update(dt);
	eShip.update(dt);
	orb.update(dt);
	return false;
}

void Draw(Core::Graphics& graphics){
	graphics.SetBackgroundColor(RGB(0,25,0));
	myShip.drawShip(graphics);
	eShip.drawShip(graphics);
	Matrix3D startTemp = Engine::Translation3D(800,500);
	orb.draw(graphics, startTemp,Vector2D(20,20), 5);
	
	
	
	
	graphics.DrawLine(790,500, 810, 500);
	graphics.DrawLine(800,490, 800, 510);
	graphics.DrawLine(790,500,800,490);
	graphics.DrawLine(810,500,800,490);
	graphics.DrawLine(790,500,800,510);
	graphics.DrawLine(810,500,800,510);
}



void main()
{
	myShip.position = Vector2D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
	Core::Init( "Game Demo", SCREEN_WIDTH, SCREEN_HEIGHT);
	Core::RegisterUpdateFn(Update);
	Core::RegisterDrawFn(Draw);
	Core::GameLoop();
}

