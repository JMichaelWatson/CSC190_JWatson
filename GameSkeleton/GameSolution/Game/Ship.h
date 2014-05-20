#ifndef _SHIP_H_
#define _SHIP_H_


#include "Engine.h"
#include "Core.h"
#include "Vector2D.h"
#include "Matrix3D.h"

using Engine::Vector2D;
using Core::Graphics;
using Engine::Matrix3D;


class Ship
{
public:
	Vector2D position;
	Vector2D velocity;
	Vector3D accel;
	Matrix3D info;
	float angle;
	void drawShip(Graphics& graphics);
	void update(float dt);
};

#endif