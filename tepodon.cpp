#include "tepodon.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
tepodon::tepodon(int fx, int fy,int p,int d) :effect(fx, fy){
	type = TEPODON;
	width = WID_TEPODON;
	height = HEI_TEPODON;
	dest = d;
	power = p;
}
void tepodon::main(){
	effect::main();
	x += 40;
	if (x>dest+width) {
		del();
		Game::getIns()->effect_create(x+width/2-WID_NOMALEXP/2,y+height/2-HEI_NOMALEXP/2, NOMALEXP);
		shared_ptr<AttackRange> p(new AttackRange(x - 50, x + width + 50, power, SKY));
		Game::getIns()->push_attack_list(p, MUSUME);
	}
}

void tepodon::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_tepodon[ani_count / ANIM_SPEED % ANI_TEPODON], true);
	effect::draw(cx);
}