#ifndef _ENEMYSHIP_H_
#define _ENEMYSHIP_H_
#include"Core.h"
#include"Engine.h"
#include"Vector2D.h"

using Engine::Vector2D;
using Core::Graphics;


class EnemyShip
{
public:
	Vector2D position;
	Vector2D velocity;
	void drawShip(Graphics& graphics);
	void update(float dt);
};

#endif

