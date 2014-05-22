#include "Orbitz.h"
#include "DrawValue.h"

DrawValue orbDValue;

Vector2D lines[] = {
	Vector2D(0,-15),
	Vector2D(10,15),
	Vector2D(-10,15)
};


void Orbitz::draw(Graphics& graphics, Vector2D position, float scale){
	graphics.SetColor(RGB(10,255,0));
	//Matrix3D mrotation = Engine::Rotation3D(angle);
	//mrotation.m[0][2] = 200.0f;
	//mrotation.m[1][2] = 200.0f;
	//Matrix3D translation = Engine::Translation3D(position);
	//Matrix3D newLocation = mrotation * translation;
	////info = newLocation * Engine::Translation3D(40,40);
	Matrix3D temp = Engine::Translation3D(position) * Engine::Rotation3D(angle) * Engine::Translation3D(Vector2D(40,40));
	orbDValue.drawValue(graphics,500,480,position);
	orbDValue.drawValue(graphics, 500,500, temp);
	int numLines = sizeof(lines) / sizeof(*lines);
	for(int counter = 0; counter < numLines; counter++){
		Vector3D first = lines[counter] * temp;
		Vector3D second = lines[(counter+1) % numLines] * temp;
		graphics.DrawLine(first.x, first.y, second.x, second.y);
	}
	if(scale > 1.0f){
		/*Matrix3D tempM = Engine::Translation3D(40,40) * newLocation;
		Vector2D temp(tempM.m[0][2], tempM.m[1][2]);
		Orbitz::draw(graphics,temp,scale/2);*/
		
		
		//Vector2D newPosition;
		//newPosition.x = position.x + 10;
		//Matrix3D translate = Engine::Translation3D(position);
		//translate.m[0][2] = 10.0f;
		//translate.m[1][2] = 10.0f;
		//Matrix3D tempM = Engine::Translation3D(newPosition) * Engine::Rotation3D(angle) * translate; //* Engine::Translation3D(newPosition);
		//Vector2D tempN(temp.m[0][2], temp.m[1][2]);
		//Orbitz::draw(graphics, tempN, scale/2);

		Vector2D tempV(temp.m[0][2], temp.m[1][2]);
		/*orbDValue.drawValue(graphics,500,550, tempV);
		Orbitz::draw(graphics, tempV , scale/2);*/
		drawC(graphics, tempV, scale/2);
		
	}
	
	graphics.SetColor(RGB(200,175,30));//orignal color
}

void Orbitz::update(float dt){
	angle -= dt/2.0f;
	updateC(dt);

	
}

void Orbitz::drawC(Graphics& graphics, Vector2D pos, float scaler){
	scaler;
	Matrix3D temp =Engine::Translation3D(pos) * Engine::Rotation3D(angleC) * Engine::Translation3D(Vector2D(50 ,50)) * Engine::Scale3D(.5);
	orbDValue.drawValue(graphics,500,480,pos);
	orbDValue.drawValue(graphics, 500,500, temp);
	int numLines = sizeof(lines) / sizeof(*lines);
	for(int counter = 0; counter < numLines; counter++){
		Vector3D first = lines[counter] * temp;
		Vector3D second = lines[(counter+1) % numLines] * temp;
		graphics.DrawLine(first.x, first.y, second.x, second.y);
	}
}

void Orbitz::updateC(float dt){
	angleC += dt;
}