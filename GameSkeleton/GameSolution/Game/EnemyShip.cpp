#include "EnemyShip.h"
#include "DrawValue.h"

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

float length = 0;
float beta = 0;
int index= 0;
DrawValue edValue;
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
	graphics.SetColor(RGB(100,55,230));
	for(unsigned int x = 0; x < 4; x++){
		const Vector2D& first = lerpPath[x];
		const Vector2D& second = lerpPath[(x+1) % 4];
		graphics.DrawLine(first.x, first.y,
			second.x, second.y);
	}
	graphics.SetColor(RGB(100,175,30));
	edValue.drawValue(graphics, 100,300,length);
	edValue.drawValue(graphics, 100,310,(0.1f *(length/Engine::Length(lerpPath[index] - lerpPath[(index+1)%4]))));
	edValue.drawValue(graphics, 100,320,Engine::Length(lerpPath[index] - lerpPath[(index+1)%4]));
	edValue.drawValue(graphics, 100,330,length/Engine::Length(lerpPath[index] - lerpPath[(index+1)%4]));
	graphics.SetColor(RGB(100,175,130));
}
void EnemyShip::update(float dt){
	length=0;
	dt;
	for(unsigned int t = 0; t < 4; t++){
		Vector2D tempResult = lerpPath[t] - lerpPath[(t+1)%4];
		if(Engine::Length(tempResult) > length){
			length = Engine::Length(tempResult);
		}
	}
	float scaler =(length/Engine::Length(lerpPath[index] - lerpPath[(index+1)%4]));
	beta += (.01f * scaler);
	 if(beta >=1){
		 beta=0;
		 index++;
	 }
	 if(index == 4){
		 index=0;
	 }
	position = Engine::LERP(lerpPath[index], lerpPath[(index+1)%4], beta);
}