#include "tepodon.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
tepodon::tepodon(int fx, int fy) :effect(fx, fy){
	type = TEPODON;
	width = WID_TEPODON;
	height = HEI_TEPODON;

}
void tepodon::main(){
	effect::main();
	x += 7;
	if (y > FIELD_H - HEI_TEPODON) {
		del();
		Game::getIns()->effect_create(x - 85, WINDOW_Y - 240, EXP);
		shared_ptr<AttackRange> p(new AttackRange(x - 50, x + width + 50, 50, SKY));
		Game::getIns()->push_attack_list(p, MUSUME);
	}
}

void tepodon::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_tepodon[ani_count / ANIM_SPEED % ANI_TEPODON], true);
	effect::draw(cx);
}