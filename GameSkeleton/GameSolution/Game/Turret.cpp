#include "Turret.h"
#include "DrawValue.h"
#include "Bullet.h"


Vector2D tlines[] = {
	Vector2D(-2,-12),
	Vector2D(2,-12),
	Vector2D(2,0),
	Vector2D(-2,0)
};

Bullet bullets[100];

void Turret::draw(Graphics& graphics, Vector2D ship){
	position = ship;
	DrawValue dValue;
	dValue.drawValue(graphics,500,600,ship);
	dValue.drawValue(graphics,500,610,position);
	dValue.drawValue(graphics,500,620,Engine::Translation3D(ship));
	matrix = Engine::Translation3D(ship)*rotation;
	dValue.drawValue(graphics,500,660, rotation);
	int num = sizeof(tlines)/ sizeof(*tlines);
	for (int x = 0; x < num; x++){
		Vector3D first = tlines[x] * matrix;
		Vector3D second = tlines[(x+1) % num] * matrix;
		graphics.DrawLine(first.x, first.y, second.x, second.y);
	}
	for (int count = 0; count < (sizeof(bullets) / sizeof(*bullets)); count++){
		if(bullets[count].active){
			bullets[count].draw(graphics);
		}
	}


}
float delay = 0.0f;
void Turret::update(float dt){
	dt;
	int mouseX, mouseY;
	Core::Input::GetMousePos( mouseX, mouseY );
	Vector2D mouse((float)mouseX, (float)mouseY);
	Vector2D result = position - mouse;
	Vector2D norm = Engine::Normalized(result);
	Vector2D perp = Engine::CW(norm);
	Vector2D perpc = Engine::CCW(perp);
	rotation = Matrix3D(perp, perpc);
	for (int count = 0; count < (sizeof(bullets) / sizeof(*bullets)); count++){
		if(bullets[count].active){
			bullets[count].update(dt);
		}
	}
	delay -= dt;
	if(Core::Input::IsPressed(Core::Input::BUTTON_LEFT)){
		if(delay <= 0.0f){
			for (int count = 0; count < (sizeof(bullets) / sizeof(*bullets)); count++){
				if(!bullets[count].active){
					bullets[count] = Bullet();
					bullets[count].updateFire(dt,position, mouse);
					delay = 0.25f;
					break;
				}
			}
		}
	}
}