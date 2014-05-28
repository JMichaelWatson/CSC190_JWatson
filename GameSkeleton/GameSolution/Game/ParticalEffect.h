#ifndef _PARTICALEFFECT_H_
#define _PARTICALEFFECT_H_

#include "Partical.h"
#include <vector>

using std::vector;

class ParticalEffect
{
public:
	ParticalEffect();
	Partical *partsA;
	float timeTOLive;
	int count;
	void draw(Graphics& graphics);
	void update(float dt);
	void updateFire(float dt, const int count, int type, Vector2D origin);
	float randomFloat();
	float randomInRange(float min, float max);
	Vector2D RandomUnitVector();
	Vector2D RandomUnitVectorHalf();
	void clearMem();
};

#endif