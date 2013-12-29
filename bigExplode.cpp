#include "bigExplode.h"
#include "Images.h"
#include "Game.h"

bigExp::bigExp(int fx, int fy) :effect(fx, fy){
	type = BIGEXP;
	width = WID_BIGEXP;
	height = HEI_BIGEXP;
}
void bigExp::main(){
	effect::main();
	if (ani_count==1)
		Images::getIns()->playSE("sound/sen_ge_bom17.mp3");
	
	if (ani_count / ANIM_SPEED_BIGEXP % ANI_BIGEXP == ANI_BIGEXP - 1)
		del();
}

void bigExp::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_bigexp[ani_count / ANIM_SPEED_BIGEXP % ANI_BIGEXP], true);
	effect::draw(cx);
}
