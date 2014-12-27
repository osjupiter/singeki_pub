#include "g_voice.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
#define RANGE_ 2
gvoice::gvoice(int fx, int fy, Direction d, int p) :effect(fx, fy){
	type = GVOICE;
//	width = WID_GVOICE;
//	height = HEI_GVOICE;
	width = 200;
	height = 200;
	dir = d;
	pre_atk_x = x -220*dir;
	power = p;
}
void gvoice::main(){
	effect::main();
	x += 21 * dir;
	
	if (dir*(x - pre_atk_x) > 110){
		shared_ptr<AttackRange> p(new AttackRange(x+24, x + 300-24, power/2, RAND));
		Game::getIns()->push_attack_list(p, ENEMY);
		pre_atk_x = x;
	}

	if (ani_count / ANIM_SPEED == 7){
		del();
	}

}

void gvoice::draw(int cx){
//		DrawGraph(x - cx, y, Images::getIns()->g_gvoice[ani_count / ANIM_SPEED % ANI_GVOICE], true);
	DrawExtendGraph(x - cx, y, x + 200 - cx,y + 200,Images::getIns()->g_gvoice[ani_count / ANIM_SPEED % ANI_GVOICE], true);
	

	effect::draw(cx);
}