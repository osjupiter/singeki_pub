#include "explode.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 1
explode::explode(int fx, int fy) :effect(fx, fy){
	type = EXP;
	width = WID_EXP;
	height = HEI_EXP;
}
void explode::main(){
	effect::main();
	
	if (ani_count / ANIM_SPEED % ANI_EXP == ANI_EXP - 1)
		del();
}

void explode::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_exp[ani_count / ANIM_SPEED % ANI_EXP], true);
	effect::draw(cx);
}