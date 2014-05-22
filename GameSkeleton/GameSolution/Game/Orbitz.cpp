#include "Orbitz.h"
#include "DrawValue.h"

DrawValue orbDValue;

Vector2D lines[] = {
	Vector2D(0,-15),
	Vector2D(10,15),
	Vector2D(-10,15)
};


void Orbitz::draw(Graphics& graphics,Matrix3D mat, Vector2D offset, float scale){
	graphics.SetColor(RGB(10,255,0));
	
	
	Matrix3D temp = mat * Engine::Rotation3D(angle) * Engine::Translation3D(offset);
	temp = temp*Engine::Scale3D(scale*.5f);
	info = temp;
	int numLines = sizeof(lines) / sizeof(*lines);
	for(int counter = 0; counter < numLines; counter++){
		Vector3D first = lines[counter] * temp;
		Vector3D second = lines[(counter+1) % numLines] * temp;
		graphics.DrawLine(first.x, first.y, second.x, second.y);
	}
	if(scale > 1.0f){
		draw(graphics, info, offset, scale/2);
		
	}
	
	graphics.SetColor(RGB(200,175,30));//orignal color
}

void Orbitz::update(float dt){
	angle -= dt/2.0f;

	
}
