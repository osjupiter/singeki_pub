#include "missile.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
missile::missile(int fx, int fy) :effect(fx, fy){
	type = MISSILE;
	width = WID_MISSILE;
	height = HEI_MISSILE;
}
void missile::main(){
	effect::main();
	x -= 10;
	y += 7;
	if (y > FIELD_H - HEI_MISSILE) {
		del();
		Game::getIns()->effect_create(x - 50, y - 30, EXP);
	}
}

void missile::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_missile[ani_count / ANIM_SPEED % ANI_MISSILE], true);
	effect::draw(cx);
}