#include "Images.h"
#include "Game.h"

#define ANIM_SPEED_WISP 3
#define ANIM_SPEED_DROP 3


wisp::wisp(int fx, int fy) :effect(fx, fy){
	type = WISP;
	width = WID_WISP;
	height = HEI_WISP;
	col = rand() % 3;
}
void wisp::main(){
	effect::main();

	if (ani_count / ANIM_SPEED_WISP  == ANI_WISP)
		del();
}

void wisp::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_e_wisp[col][ani_count / ANIM_SPEED_DROP % ANI_DROP], true);
	effect::draw(cx);
}

drop::drop(int fx, int fy) :effect(fx, fy){
	type = DROP;
	width = WID_DROP;
	height = HEI_DROP;
	col = rand() % 3;

}
void drop::main(){
	effect::main();

	if (ani_count / ANIM_SPEED_DROP == ANI_DROP)
		del();
}

void drop::draw(int cx){
	
	DrawGraph(x - cx, y, Images::getIns()->g_e_yamidrop[col][ani_count / ANIM_SPEED_DROP % ANI_DROP], true);
	
	effect::draw(cx);
}


