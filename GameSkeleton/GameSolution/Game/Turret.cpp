#include "Turret.h"
#include "DrawValue.h"

Vector2D tlines[] = {
	Vector2D(-2,-12),
	Vector2D(2,-12),
	Vector2D(2,0),
	Vector2D(-2,0)
};
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


}

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



	/*Vector2D result = mouse - position;
	Vector2D norm = Engine::Normalized(result);
	Vector2D perp = Engine::CW(norm);
	rotation.m[0][0] =  perp.x;
	rotation.m[1][0] = perp.y;
	rotation.m[0][1] = norm.x;
	rotation.m[1][1] = norm.y;*/
}