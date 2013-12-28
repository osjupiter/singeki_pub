#include "gunshot.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
gunshot::gunshot(int fx, int fy,bool turn) :effect(fx, fy){
	type = GUNSHOT;
	width = WID_GUNSHOT;
	height = HEI_GUNSHOT;
	turnflag = turn;
}
void gunshot::main(){
	effect::main();

	if (ani_count / ANIM_SPEED % ANI_GUNSHOT == ANI_GUNSHOT - 1)
		del();
}

void gunshot::draw(int cx){
	if (turnflag)
		DrawTurnGraph(x - cx, y, Images::getIns()->g_gunshot[ani_count / ANIM_SPEED % ANI_GUNSHOT], true);

	else DrawGraph(x - cx, y, Images::getIns()->g_gunshot[ani_count / ANIM_SPEED % ANI_GUNSHOT], true);
	effect::draw(cx);
}