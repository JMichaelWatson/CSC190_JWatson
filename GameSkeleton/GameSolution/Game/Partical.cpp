#include "Partical.h"

Vector2D pLines[] = {

	Vector2D(-1,-1),
	Vector2D(1,-1),

};

Partical::Partical(){
	timeToLive = 2.0f;;
	active = false;
}
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
	velocity = temp;
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
