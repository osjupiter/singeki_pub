#include "kirakira.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 2
#define RANGE_ 2
kirakira::kirakira(int fx, int fy, Direction d, int p,int dx, int dy ,int lv) :effect(fx, fy){
	type = KIRAKIRA;

	width = WID_KIRAKIRA;
	height = HEI_KIRAKIRA;
	dir = d;
	pre_atk_x = x - 85 * dir;
	power = p;
	level = lv;
}
void kirakira::main(){
	effect::main();
	x += 21 * dir;

	if (dir*(x - pre_atk_x) > 85){
		shared_ptr<AttackRange> p(new AttackRange(x + 75, x + 160 - 75, power / 2, RAND));
		Game::getIns()->push_attack_list(p, ENEMY);
		pre_atk_x = x;
	}

	if (ani_count / ANIM_SPEED == 9){
		del();
	}

}

void kirakira::draw(int cx){
	//		DrawGraph(x - cx, y, Images::getIns()->g_kirakira[ani_count / ANIM_SPEED % ANI_KIRAKIRA], true);
	DrawGraph(x - cx, y, Images::getIns()->g_kirakira[level/3][ani_count / ANIM_SPEED % ANI_KIRAKIRA], true);


	effect::draw(cx);
}