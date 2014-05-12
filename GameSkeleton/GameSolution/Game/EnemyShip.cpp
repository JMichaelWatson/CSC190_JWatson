#include "EnemyShip.h"

Vector2D enemyshipPoints[] = {
	Vector2D(0,15),
	Vector2D(15,-15),
	Vector2D(-15,-15)
};

Vector2D lerpPath[] = {
	Vector2D(200.0f,200.0f),
	Vector2D(300.0f,100.0f),
	Vector2D(300.0f,500.0f),
	Vector2D(50.0f,100.0f)
};
void EnemyShip::drawShip(Graphics& graphics)
{
	graphics.SetColor(RGB(0,175,230));
	const unsigned int numLines = sizeof(enemyshipPoints) / sizeof(*enemyshipPoints);
	for(unsigned int x = 0; x < numLines; x++){
		const Vector2D& first = enemyshipPoints[x] + position;
		const Vector2D& second = enemyshipPoints[(x+1) % numLines] + position;
		position;
		graphics.DrawLine(first.x, first.y,
			second.x, second.y);
	}
	graphics.SetColor(RGB(100,175,130));
	for(unsigned int x = 0; x < 4; x++){
		const Vector2D& first = lerpPath[x];
		const Vector2D& second = lerpPath[(x+1) % 4];
		graphics.DrawLine(first.x, first.y,
			second.x, second.y);
	}
}
float beta = 0;
int x = 0;
void EnemyShip::update(float dt){
	/*float length=0;
	for(unsigned int x = 0; x < 4; x++){
		length+= Engine::Length(lerpPath[x]);
	}*/
	 beta += dt;
	 if(beta >=1){
		 beta=0;
		 x++;
	 }
	 if(x == 4){
		 x=0;
	 }
	position = Engine::LERP(lerpPath[x], lerpPath[(x+1)%4], beta);
}