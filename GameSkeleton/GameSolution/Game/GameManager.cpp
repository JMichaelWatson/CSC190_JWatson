#include "GameManager.h"

void GameManager::Draw(Core::Graphics& graphics){
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

void GameManager::Update(float dt){
	myShip.update(dt);
	eShip.update(dt);
	orb.update(dt);
}

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 750;

GameManager::GameManager(){
	myShip.position = Vector2D(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
}

