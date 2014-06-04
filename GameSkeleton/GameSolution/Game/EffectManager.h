#ifndef _EFFECTMANAGER_H_
#define _EFFECTMANAGER_H_

#include "ParticalEffect.h"

class EffectManager
{
public:
	vector<ParticalEffect> effects;
	void draw(Graphics& graphics);
	void update(float dt);
	void create(int numOfEffect);
	void clearMem();
};

#endif
