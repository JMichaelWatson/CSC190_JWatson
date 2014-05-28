#include "EffectManager.h"


void EffectManager::draw(Graphics& graphics){
	for(unsigned int i = 0; i < effects.size(); i++){
		effects[i].draw(graphics);
		graphics.DrawString(800,100, "Drawing effect");
	}
}

void EffectManager::update(float dt){
	for(unsigned int i = 0; i < effects.size(); i++){
		effects[i].update(dt);
	}
}

void EffectManager::create(int numOfEffect){
	ParticalEffect pEffect;
	pEffect.updateFire(0, 200, numOfEffect);
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