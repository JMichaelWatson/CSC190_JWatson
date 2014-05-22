#include "Partical.h"

Vector2D pLines[] = {

	Vector2D(-2,-2),
	Vector2D(2,-2),
	Vector2D(2,2),
	Vector2D(-2,2)
};
void Partical::draw(Graphics& graphics){
	{
		position = position + velocity;
		int num = (sizeof(pLines) / sizeof(*pLines));
		for(int count = 0; count < num; count ++){
			Vector2D first = pLines[count] + position;
			Vector2D second = pLines[(count+1)%num] + position;
			graphics.DrawLine(first.x, first.y, second.x, second.y);
		}
	}
}

void Partical::updateFire(float dt, Vector2D tstart, Vector2D mouse){
	timeToLive -= dt;
	Vector2D temp = mouse - tstart;
	velocity = Engine::Normalized(temp);
	velocity.x *= 5.0f;
	velocity.y *= 5.0f;
	position = tstart;
	active = true;
}



void Partical::update(float dt){
	timeToLive -=dt;
	if(timeToLive <=0)
	{
		active = false;
	}
}
