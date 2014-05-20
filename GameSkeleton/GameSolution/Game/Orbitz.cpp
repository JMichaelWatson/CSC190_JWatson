#include "Orbitz.h"

Vector2D lines[] = {
	Vector2D(0,-15),
	Vector2D(10,15),
	Vector2D(-10,15)
};


void Orbitz::draw(Graphics& graphics, Vector2D position, float scale){
	graphics.SetColor(RGB(10,255,0));
	Matrix3D translation = Engine::Translation3D(position);
	Matrix3D newLocation = translation * Engine::Rotation3D(angle);
	info = newLocation * Engine::Translation3D(40,40);
	int numLines = sizeof(lines) / sizeof(*lines);
	for(int counter = 0; counter < numLines; counter++){
		Vector3D first = lines[counter] * info;
		Vector3D second = lines[(counter+1) % numLines] * info;
		graphics.DrawLine(first.x, first.y, second.x, second.y);
	}
	if(scale > 1.0f){
		
		Vector2D temp(info.m[0][2], info.m[1][2]);
		Orbitz::draw(graphics,temp,scale/2);
	}
	
	graphics.SetColor(RGB(200,175,30));//orignal color
}

void Orbitz::update(float dt){
	angle += dt;
	
}