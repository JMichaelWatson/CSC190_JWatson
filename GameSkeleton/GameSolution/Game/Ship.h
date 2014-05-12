#ifndef _SHIP_H_
#define _SHIP_H_


#include "Engine.h"
#include "Core.h"
#include "Vector2D.h"

using Engine::Vector2D;
using Core::Graphics;


class Ship
{
public:
	Vector2D position;
	Vector2D velocity;
	void drawShip(Graphics& graphics);
	void update(float dt);
};

#endif