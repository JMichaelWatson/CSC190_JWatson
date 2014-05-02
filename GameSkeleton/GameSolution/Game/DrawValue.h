#ifndef DRAWVALUE_H
#define DRAWVALUE_H

#include"Engine.h"
#include"Core.h"
#include"Vector2D.h"

using Engine::Vector2D;

class DrawValue{
public:
	void drawValue(Core::Graphics graphic, int x, int y, int num);
	void drawValue(Core::Graphics& graphic, int x, int y, float num);
	void drawValue(Core::Graphics& graphic, int x, int y, Vector2D num);
};


#endif