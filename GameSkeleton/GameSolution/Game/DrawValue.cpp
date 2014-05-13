#include<sstream>
#include"DrawValue.h"

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
	ss << num.x;
	ss << ", "; 
	ss << num.y;
	graphic.DrawString(x, y, ss.str().c_str());
}