#include "ParticalEffect.h"

void ParticalEffect::draw(Graphics& graphics,const int count, Vector2D sorigin){
	//parts = vector<Partical>(count);
	origin = sorigin;
	for (int x = 0; x < count; x ++){
		if(partsA[x].active){
			partsA[x].draw(graphics);
		}
	}
}

void ParticalEffect::update(float dt, int count ){
	for (int x = 0; x < count; x ++){
		if(!partsA[x].active)
		{
			partsA[x] = Partical();
			Vector2D rand = RandomUnitVector();
			Vector3D newPath = Engine::Translation3D(origin) * rand;
			Vector2D temp(newPath.x, newPath.y);
			partsA[x].updateFire(dt, origin, temp);
			partsA[x].active = true;
		}else{
			partsA[x].update(dt);
		}
	}
}

float randomFloat() { return (float) rand() / RAND_MAX; }

const float TWO_PI = 2*3.1415926f;

Vector2D ParticalEffect::RandomUnitVector() { 
	float angle = TWO_PI * randomFloat(); 
	return Vector2D( cos(angle), sin(angle) ); 
}

