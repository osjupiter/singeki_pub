#include "gajikami.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
gajikami::gajikami(int fx, int fy, bool turn) :effect(fx, fy){
	type = GAJIKAMI;
	width = WID_GAJIKAMI;
	height = HEI_GAJIKAMI;
	turnflag = turn;
}
void gajikami::main(){
	effect::main();

	if (ani_count / ANIM_SPEED % ANI_GAJIKAMI == ANI_GAJIKAMI - 1)
		del();
}

void gajikami::draw(int cx){
	if (turnflag)
		DrawTurnGraph(x - cx, y, Images::getIns()->g_gajikami[ani_count / ANIM_SPEED % ANI_GAJIKAMI], true);

	else DrawGraph(x - cx, y, Images::getIns()->g_gajikami[ani_count / ANIM_SPEED % ANI_GAJIKAMI], true);
	effect::draw(cx);
}