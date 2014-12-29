#include "zangeki.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
zangeki::zangeki(int fx, int fy, bool turn) :effect(fx, fy){
	type = ZANGEKI;
	width = WID_ZANGEKI;
	height = HEI_ZANGEKI;
	turnflag = turn;
}
void zangeki::main(){
	effect::main();

	if (ani_count / ANIM_SPEED % ANI_ZANGEKI == ANI_ZANGEKI - 1)
		del();
}

void zangeki::draw(int cx){
	if (turnflag)
		DrawTurnGraph(x - cx, y, Images::getIns()->g_zangeki[ani_count / ANIM_SPEED % ANI_ZANGEKI], true);

	else DrawGraph(x - cx, y, Images::getIns()->g_zangeki[ani_count / ANIM_SPEED % ANI_ZANGEKI], true);
	effect::draw(cx);
}