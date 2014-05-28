#include "EffectManager.h"


void EffectManager::draw(Graphics& graphics){
	for(unsigned int i = 0; i < effects.size(); i++){
		effects[i].draw(graphics);
	}
}

void EffectManager::update(float dt){
	for(unsigned int i = 0; i < effects.size(); i++){
		effects[i].update(dt);
	}
}

void EffectManager::create(int numOfEffect, Vector2D origin){
	ParticalEffect pEffect;
	int count = 200;
	if(numOfEffect == 2)
	{
		count = 10;
	}
	pEffect.updateFire(0, count, numOfEffect, origin);
	effects.push_back(pEffect);

}

void EffectManager::clearMem(){
	for(unsigned int i = 0; i < effects.size(); i++){
		if(effects[i].timeTOLive <= 0){
			effects[i].clearMem();
			effects.erase(effects.begin() + i);
		}
	}
}