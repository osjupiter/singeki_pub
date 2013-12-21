#include "bomb.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
bomb::bomb(int fx, int fy) :effect(fx, fy){
	type = BOMB;
	width = WID_BOMB;
	height = HEI_BOMB;
}
void bomb::main(){
	effect::main();
	y += 7;
	if (y > FIELD_H - HEI_BOMB) {
		del();
		Game::getIns()->effect_create(x-50,y-30,EXP);
	}
}

void bomb::draw(int cx){
	DrawGraph(x - cx,y,Images::getIns()->g_bomb[ani_count/ANIM_SPEED % ANI_BOMB],true);
	effect::draw(cx);
}