#include "ParticalEffect.h"
ParticalEffect::ParticalEffect(){
	partsA = new Partical[1000]();
	timeTOLive = 5;
}
void ParticalEffect::draw(Graphics& graphics){
	for (int x = 0; x < count; x ++){
		if(partsA[x].active){
			graphics.DrawString(800,110,"Drawing Partical");
			partsA[x].draw(graphics);
		}
	}
	timeTOLive--;
}

void ParticalEffect::updateFire(float dt, const int scount, int type){
	count = scount;
	for (int x = 0; x < count; x ++){
		if(!partsA[x].active)
		{
			int mouseX, mouseY;
			Core::Input::GetMousePos( mouseX, mouseY );
			Vector2D mouse((float)mouseX, (float)mouseY);
			partsA[x] = Partical();
			float randInt = randomInRange(1,10);
			Vector2D rand;
			if(type == 1){
				rand = RandomUnitVector() * randInt;
			} else{

			}
			Vector2D newPath = mouse + rand;
			partsA[x].updateFire(dt, mouse, newPath);
		}
	}
}

void ParticalEffect::update(float dt){
	for (int x = 0; x < count; x ++){
		partsA[x].update(dt);
	}
}

float ParticalEffect::randomFloat() { return (float) rand() / RAND_MAX; }

float ParticalEffect::randomInRange(float min, float max){
	return randomFloat() * (max - min + 1) + min;
}

const float TWO_PI = 2*3.1415926f;

Vector2D ParticalEffect::RandomUnitVector() { 
	float angle = TWO_PI * randomFloat(); 
	return Vector2D( cos(angle), sin(angle) ); 
}

Vector2D ParticalEffect::RandomUnitVectorHalf() { 
	float angle = (TWO_PI/2.0f) * randomFloat(); 
	return Vector2D( cos(angle), sin(angle) ); 
}

void ParticalEffect::clearMem(){
	delete [] partsA;
}

