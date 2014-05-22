#include "Bullet.h"

Bullet::Bullet(){
	TIMETOLIVE = 5.0f;
}
Vector2D bLines[] = {

	Vector2D(-2,-2),
	Vector2D(2,-2),
	Vector2D(2,2),
	Vector2D(-2,2)
};
void Bullet::draw(Graphics& graphics)
{
	postion = postion + velocity;
	int num = (sizeof(bLines) / sizeof(*bLines));
	for(int count = 0; count < num; count ++){
		Vector2D first = bLines[count] + postion;
		Vector2D second = bLines[(count+1)%num] + postion;
		graphics.DrawLine(first.x, first.y, second.x, second.y);
	}
}

void Bullet::updateFire(float dt, Vector2D tstart, Vector2D mouse){
	TIMETOLIVE -= dt;
	Vector2D temp = mouse - tstart;
	velocity = Engine::Normalized(temp);
	velocity.x *= 5.0f;
	velocity.y *= 5.0f;
	postion = tstart;
	active = true;
}

void Bullet::update(float dt){
	TIMETOLIVE -=dt;
	if(TIMETOLIVE <=0)
	{
		active = false;
	}
}