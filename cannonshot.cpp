#include "cannonshot.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
cannonshot::cannonshot(int fx, int fy) :effect(fx, fy){
	type = CANNONSHOT;
	width = WID_CANNONSHOT;
	height = HEI_CANNONSHOT;
}
void cannonshot::main(){
	effect::main();

	if (ani_count / ANIM_SPEED % ANI_CANNONSHOT == ANI_CANNONSHOT - 1)
		del();
}

void cannonshot::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_cannonshot[ani_count / ANIM_SPEED % ANI_CANNONSHOT], true);
	effect::draw(cx);
}