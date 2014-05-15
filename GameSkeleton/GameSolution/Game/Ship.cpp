#include "Ship.h"
#include "DrawValue.h"

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 750;

Vector2D shipPoints[]={
	Vector2D(-3.0f, -22.0f),
	Vector2D(+3.0f, -22.0f),
	Vector2D(+3.0f, -22.0f),
	Vector2D(+7.0f,-12.0f),
	Vector2D(+5.0f, +12.0f),
	Vector2D(+20.0f, -5.0f), 
	Vector2D(+10.0f, +30.0f),
	Vector2D(+0.0f, +18.0f),
	Vector2D(-10.0f, +30.0f),
	Vector2D(-20.0f, -5.0f),
	Vector2D(-5.0f, +12.0f),
	Vector2D(-7.0f, -12.0f),
};

Vector2D border[] = {
	Vector2D((float)SCREEN_WIDTH/2, 0.0f),
	Vector2D((float)SCREEN_WIDTH, (float)SCREEN_HEIGHT/2),
	Vector2D((float)SCREEN_WIDTH/2, (float)SCREEN_HEIGHT),
	Vector2D(0.0f, (float)SCREEN_HEIGHT/2)
};

char mode = 'w';
DrawValue dValue;
void Ship::drawShip(Graphics& graphics){
	char* response1 = "Current mode: ";
	char* response ="";
	if(mode == 'w'){
		response = "Wrap";
	}
	if(mode == 'b'){
		response = "Bounce";
	}
	if(mode == 'a'){
		response = "Arbiturary Bounce";
	}
	graphics.DrawString(100,40,"Hit 1..Wrap 2..Bounce 3..Arbitrary Bounce");
	graphics.DrawString(100,50,response1); 
	graphics.SetColor(RGB(100,200,100));
	graphics.DrawString(100,60,response);
	dValue.drawValue(graphics, 100,100, position);
	graphics.SetColor(RGB(200,75,30));
	const unsigned int numLines = sizeof(shipPoints) / sizeof(*shipPoints);
	for(unsigned int x = 0; x < numLines; x++){
		const Vector2D& first = shipPoints[x] + position;
		const Vector2D& second = shipPoints[(x+1) % numLines] + position;
		graphics.DrawLine(first.x, first.y,
			second.x, second.y);

	}
	graphics.SetColor(RGB(200,175,30));
	if(mode == 'a'){
		for(unsigned int x = 0; x < 4; x++){
			const Vector2D& first = border[x];
			const Vector2D& second = border[(x+1) % 4];
			graphics.DrawLine(first.x, first.y,
				second.x, second.y);
		}
	}
}
const int MAXSPEED = 1000;
const int PIXELSPEED = 500;
void Ship::update(float dt){

	if(Core::Input::IsPressed(49)){
		mode = 'w';
	}
	if(Core::Input::IsPressed(50)){
		mode = 'b';
	}
	if(Core::Input::IsPressed(51)){
		mode = 'a';
	}

	if(Core::Input::IsPressed(Core::Input::KEY_RIGHT)){
		if(velocity.x <= MAXSPEED){
			velocity.x += dt * PIXELSPEED;
		}
	}
	if(Core::Input::IsPressed(Core::Input::KEY_LEFT)){
		if(velocity.x >= -MAXSPEED){
			velocity.x -= dt * PIXELSPEED; 
		}
	}
	if(Core::Input::IsPressed(Core::Input::KEY_DOWN)){
		if(velocity.y <= MAXSPEED){
			velocity.y += dt * PIXELSPEED;
		}
	}
	if(Core::Input::IsPressed(Core::Input::KEY_UP)){
		if(velocity.y >= -MAXSPEED){
			velocity.y -= dt * PIXELSPEED;
		}
	}
	if(Core::Input::IsPressed(81)){
		velocity.x = 0;
		velocity.y = 0;
	}

	position = position + (velocity*dt);
	if(mode == 'b'){
		//bounce of edges
		if(position.x < 0 || position.x > 1024){
			velocity.x *=-1;
		}

		if(position.y < 0 || position.y > 750){
			velocity.y *=-1;
		}
	}else if(mode == 'w'){
		//wrap
		if(position.x < -22){
			position.x = 1044;
		}

		if(position.x > 1044){
			position.x = -22;
		}
		if(position.y > 805){
			position.y = -55;
		}
		if(position.y < -55){
			position.y = 805;
		}
	}else if(mode == 'a'){
		//arbiturary bounce
		const unsigned int numLines = sizeof(border) / sizeof(*border);
		for(unsigned int x = 0; x < numLines; x++){
			Vector2D first = border[x];
			Vector2D result = first - position;
			Vector2D wallResult = border[x] - border[(x+1) % numLines];
			Vector2D perp = Engine::CW(wallResult);
			float intResult = Engine::Dot(result, perp);
			if(intResult < 0)
			{
				Vector2D normNormal = Engine::Normalized(perp);
				float velfloat = Engine::Dot(normNormal, velocity);
				Vector2D newResult = velfloat * normNormal;
				velocity = velocity + (-2*newResult);
			}
		}

	}



}