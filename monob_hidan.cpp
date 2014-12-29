#include "monob_hidan.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 2
monob_hidan::monob_hidan(int fx, int fy, bool turn) :effect(fx, fy){
	type = CANNONSHOT;
	width = WID_CANNONSHOT;
	height = HEI_CANNONSHOT;
	turnflag = turn;
}
void monob_hidan::main(){
	effect::main();

	if (ani_count / ANIM_SPEED % ANI_CANNONSHOT == ANI_CANNONSHOT - 1)
		del();
}

void monob_hidan::draw(int cx){
	if (turnflag)
		DrawTurnGraph(x - cx, y, Images::getIns()->g_monob_h[ani_count / ANIM_SPEED % ANI_CANNONSHOT], true);

	else DrawGraph(x - cx, y, Images::getIns()->g_monob_h[ani_count / ANIM_SPEED % ANI_CANNONSHOT], true);
	effect::draw(cx);
}