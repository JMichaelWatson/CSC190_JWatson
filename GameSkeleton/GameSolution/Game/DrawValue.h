#ifndef DRAWVALUE_H
#define DRAWVALUE_H


#include "Core.h"
#include "Engine.h"
#include "Vector2D.h"

using Engine::Vector2D;
using Core::Graphics;

class DrawValue{
public:
	void drawValue(Graphics& graphic, int x, int y, int num);
	void drawValue(Graphics& graphic, int x, int y, float num);
	void drawValue(Graphics& graphic, int x, int y, Vector2D num);
};

#endif