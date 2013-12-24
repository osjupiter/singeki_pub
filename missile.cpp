#include "missile.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
missile::missile(int fx, int fy, Direction d) :effect(fx, fy){
	type = MISSILE;
	width = WID_MISSILE;
	height = HEI_MISSILE;
	dir = d;
}
void missile::main(){
	effect::main();
	x += 10*dir;
	y += 7;
	if (y > FIELD_H - HEI_MISSILE) {
		del();
		Game::getIns()->effect_create(x - 50, y - 30, EXP);
	}
}

void missile::draw(int cx){
	if (dir==LEFT)
		DrawGraph(x - cx, y, Images::getIns()->g_missile[ani_count / ANIM_SPEED % ANI_MISSILE], true);
	else 
		DrawTurnGraph(x - cx, y, Images::getIns()->g_missile[ani_count / ANIM_SPEED % ANI_MISSILE], true);

	effect::draw(cx);
}