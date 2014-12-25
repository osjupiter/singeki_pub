#include "hana.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3

#define BIRTH_NUM 7
UnitType birth_unit[BIRTH_NUM] = { _HOHEI, _BIG, _BAZOOKA, _SEGWAY, _YOUJO, _TATEKO, _HIME };

hana::hana(int fx, int fy) :effect(fx, fy){
	type = HANA;
	width = WID_HANA;
	height = HEI_HANA;
	stopper = false;
}
void hana::main(){
	effect::main();

	if (ani_count / ANIM_SPEED == 14){
		if (!stopper){
			Game::getIns()->x_birth(x, birth_unit[rand() % BIRTH_NUM], false);
			stopper = true;
		}
	}
	if (ani_count / ANIM_SPEED == ANI_HANA - 1)
		del();
}

void hana::draw(int cx){
	DrawGraph(x - cx, y, Images::getIns()->g_hana[ani_count / ANIM_SPEED % ANI_HANA], true);
	effect::draw(cx);
}