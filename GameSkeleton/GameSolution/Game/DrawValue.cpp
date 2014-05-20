#include<sstream>
#include<iostream>
#include<iomanip>
#include"DrawValue.h"
#include<math.h>


using std::stringstream;


void DrawValue::drawValue(Core::Graphics& graphic, int x, int y, int num){
	stringstream ss;
	ss << num;
	graphic.DrawString(x, y, ss.str().c_str());
}

void DrawValue::drawValue(Core::Graphics& graphics, int x, int y, float num ) {
	stringstream ss;
	ss << num;
	graphics.DrawString( x, y, ss.str().c_str());
}

void DrawValue::drawValue(Core::Graphics& graphic, int x, int y, Vector2D num){
	stringstream ss;
	ss << ((int)(num.x * 100)) / 100;
	ss << ", "; 
	ss << ((int)(num.y * 100)) / 100;
	graphic.DrawString(x, y, ss.str().c_str());
}

void DrawValue::drawValue(Core::Graphics& graphic, int x, int y, Matrix3D num){

	int spacex  = 0;
	int spacey = 10;
	for(int row = 0; row < 3; row++)
	{
		for(int column = 0; column < 3; column++){
			drawValue(graphic, x+ spacex, y + spacey, floor((num.m[row][column]*100))/100);
			spacex += 50;
		}
		spacey += 10;
		spacex = 0;
	}
}