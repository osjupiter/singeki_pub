#include "nomalExp.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
nomalExp::nomalExp(int fx, int fy, bool Ex) :effect(fx, fy){
	type = NOMALEXP;
	width = WID_NOMALEXP;
	height = HEI_NOMALEXP;
	ExFlag = Ex;
}
void nomalExp::main(){
	effect::main();
	if (ani_count == 1){
		//SoundController::getSE()->playSE("sound/taihou03.mp3");
		if (!ExFlag)
		SoundController::getSE()->playSE("sound/sen_ge_hasai02.mp3");
	}
	if (ani_count / ANIM_SPEED % ANI_BIGEXP == ANI_NOMALEXP - 1){
		del();
	}
}

void nomalExp::draw(int cx){
	if (!ExFlag)
		DrawGraph(x - cx, y, Images::getIns()->g_nomalExp[ani_count / ANIM_SPEED % ANI_NOMALEXP], true);
	else
		DrawRotaGraph(x+width/2 - cx, y+height/2,0.7,0, Images::getIns()->g_nomalExp[ani_count / ANIM_SPEED % ANI_NOMALEXP], true);
	effect::draw(cx);
}
