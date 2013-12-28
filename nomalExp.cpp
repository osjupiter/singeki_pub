#include "nomalExp.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
nomalExp::nomalExp(int fx, int fy) :effect(fx, fy){
	type = NOMALEXP;
	width = WID_NOMALEXP;
	height = HEI_NOMALEXP;
}
void nomalExp::main(){
	effect::main();
	if (ani_count==1)
		Images::playSE("sound/taihou03.mp3");

	if (ani_count / ANIM_SPEED % ANI_BIGEXP == ANI_NOMALEXP - 1){
		del();
	}
}

void nomalExp::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_nomalExp[ani_count / ANIM_SPEED % ANI_NOMALEXP], true);
	effect::draw(cx);
}
