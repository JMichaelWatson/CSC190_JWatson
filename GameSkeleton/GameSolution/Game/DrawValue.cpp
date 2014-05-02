#include<sstream>
#include<string>
#include"DrawValue.h"
using std::stringstream;





void drawValue(Core::Graphics& graphic, int x, int y, int num){
stringstream ss;
ss << num;
graphic.DrawString(x, y, ss.str().c_str());
}

void drawValue(Core::Graphics& graphics, int x, int y, float num ) {
	stringstream ss;
	ss << num;
	graphics.DrawString( x, y, ss.str().c_str());
}
void drawValue(Core::Graphics& graphic, int x, int y, Vector2D num){
	stringstream ss;
	ss << num.x, num.y;
	graphic.DrawString(x, y, ss.str().c_str());
}
