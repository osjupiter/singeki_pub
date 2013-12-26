#include "beam.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
beam::beam(int fx, int fy, int pw) :effect(fx, fy){
	type = BEAM;
	width = WID_BEAM;
	height = HEI_BEAM;
	power = pw;
}
void beam::main(){
	effect::main();

	if (ani_count / ANIM_SPEED == ANI_BEAM) {
		del();
		for (int i = x; i + WID_EXP < x + width; i += WID_EXP)
			Game::getIns()->effect_create(i, WINDOW_Y - 240, EXP);
		shared_ptr<AttackRange> p(new AttackRange(x, x + width, power, RAND));
		Game::getIns()->push_attack_list(p, ENEMY);
	}
}

void beam::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_beam[ani_count / ANIM_SPEED % ANI_BEAM], true);
	effect::draw(cx);
}