#include "missile.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
missile::missile(int fx, int fy, Direction d,int p) :effect(fx, fy){
	type = MISSILE;
	width = WID_MISSILE;
	height = HEI_MISSILE;
	dir = d;
	power = p;
}
void missile::main(){
	effect::main();
	x += 14*dir;
	y += 7;
	if (y > FIELD_H - HEI_MISSILE) {
		del();
		//Game::getIns()->effect_create(x - 50, WINDOW_Y-HEI_EXP, EXP);
		Game::getIns()->effect_create(x +width/2-WID_NOMALEXP/2, WINDOW_Y-HEI_NOMALEXP, NOMALEXP);
		int center = (x + x + width) / 2;
		Images::playSE("sound/taihou03.mp3");

		shared_ptr<AttackRange> p(new AttackRange(center - WID_NOMALEXP / 2, center + WID_NOMALEXP / 2, power, RAND));
		Game::getIns()->push_attack_list(p, ENEMY);
	}
}

void missile::draw(int cx){
	if (dir == LEFT){
		DrawGraph(x - cx, y, Images::getIns()->g_missile[ani_count / ANIM_SPEED % ANI_MISSILE], true);
//		DrawLine((x + x + width) / 2 - cx, 0, (x + x + width) / 2 - cx, WINDOW_Y, GetColor(255, 255, 0), 5);
//		DrawBox((x + x + width) / 2 - WID_EXP / 2 - cx, WINDOW_Y - HEI_EXP, (x + x + width) / 2 + WID_EXP / 2 - cx, WINDOW_Y, GetColor(255, 0, 0), false);
	}
	else 
		DrawTurnGraph(x - cx, y, Images::getIns()->g_missile[ani_count / ANIM_SPEED % ANI_MISSILE], true);

	effect::draw(cx);
}