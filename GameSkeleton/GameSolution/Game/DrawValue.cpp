#include<sstream>
#include<iostream>
#include<iomanip>
#include"DrawValue.h"
#include<math.h>,

using std::stringstream;


void DrawValue::drawValue(Core::Graphics& graphic, int x, int y, int num){
	stringstream ss;
	ss << num;
	graphic.DrawString(x, y, ss.str().c_str());
}

void DrawValue::drawValue(Core::Graphics& graphics, int x, int y, float num ) {
	stringstream ss;
	ss << ;
	graphics.DrawString( x, y, ss.str().c_str());
}

void DrawValue::drawValue(Core::Graphics& graphic, int x, int y, Vector2D num){
	stringstream ss;
	ss << std::cout << std::setprecision(2) << num.x;
	ss << ", "; 
	ss << num.y;
	graphic.DrawString(x, y, ss.str().c_str());
}

//void DrawValue::drawValue(Core::Graphics& graphic, int x, int y, Matrix3D num){
//
//	stringstream ss;
//	
//
//}