#include "hana.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3

#define BIRTH_NUM _NOUKA
#define RAND_UNIT_NUM 7
UnitType rand_unit[RAND_UNIT_NUM] = { _HOHEI, _BIG, _BAZOOKA, _SEGWAY, _YOUJO, _TATEKO, _HIME };

bool isRandUnit(UnitType ut){
	for (int i = 0; i < RAND_UNIT_NUM; i++)
	{
		if(ut == rand_unit[i])
			return true;
	}
	return false;
}

hana::hana(int fx, int fy) :effect(fx, fy){
	type = HANA;
	width = WID_HANA;
	height = HEI_HANA;
	stopper = false;
	spown = static_cast<UnitType>(rand() % BIRTH_NUM);
	spown = (spown == 0) ? _HOHEI:spown;
	fly = false;
	if (!(isRandUnit(spown))){
		dest_y = 100;		
		fly = true;
	}

}
void hana::main(){
	effect::main();
	if (ani_count / ANIM_SPEED == 12){
		if (fly){
			y-=15;
			ani_count--;
			if (y < dest_y){
				fly = false;
			}
		}
	}
	if (ani_count / ANIM_SPEED == 14){
		if (!stopper){			
			Game::getIns()->x_birth(x,0,spown, false);
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