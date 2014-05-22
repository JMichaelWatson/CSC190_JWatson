#pragma once
#include "Partical.h"
#include <vector>

using std::vector;

class ParticalEffect
{
public:
	Vector2D origin;
	vector<Partical> parts;
	Partical partsA[100];
	void draw(Graphics& graphics, const int count, Vector2D origin);
	void update(float dt, int count);
	Vector2D RandomUnitVector();
};

