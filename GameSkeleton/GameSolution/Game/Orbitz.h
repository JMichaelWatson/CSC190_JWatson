#pragma once
#include "Vector2D.h"
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Engine.h"
#include "Core.h"

using Engine::Vector2D;
using Engine::Vector3D;
using Engine::Matrix3D;
using Core::Graphics;

class Orbitz
{
public:
	float angle;
	Matrix3D info;
	void update(float dt);
	void draw(Graphics& graphics, Vector2D position, float scale);
};

