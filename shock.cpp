#include "shock.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 2
shock::shock(int fx, int fy) :effect(fx, fy){
	type = SHOCK;
	width = WID_SHOCK;
	height = HEI_SHOCK;
}

void shock::main(){
	effect::main();

	if (ani_count / ANIM_SPEED % ANI_SHOCK == ANI_SHOCK - 1)
		del();
}

void shock::draw(int cx){
	DrawGraph(x - cx, y+15, Images::getIns()->g_shock[ani_count / ANIM_SPEED % ANI_SHOCK], true);
	effect::draw(cx);
}