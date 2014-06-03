#pragma once

#include "Engine.h"
#include "Core.h"
#include "DrawValue.h"
#include "Ship.h"
#include "EnemyShip.h"
#include "Orbitz.h"
#include "EffectManager.h"
#include "DrawValue.h"
#include "Timer.h"

using Core::Input;
using Engine::Vector2D;

class GameManager
{
public:
	GameManager();
	Ship myShip;
	EnemyShip eShip;
	Orbitz orb;
	EffectManager eManager;
	DrawValue dV;
	Clock clock;
	void Draw(Core::Graphics& graphics);
	void Update(float dt);
	void init();
	void shutdown();

};

