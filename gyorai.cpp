#include "gyorai.h"
#include "Images.h"
#include "Game.h"
#define ANIM_SPEED 3
gyorai::gyorai(int fx, int fy, Direction d, int p,int destx_,int tarpos_,int lv) :effect(fx, fy){
	type = GYORAI;
	width = WID_GYORAI;
	height = HEI_GYORAI;
	dir = d;
	power = p;
	destx = destx_;
	desty = (tarpos==SKY) ?  0:fy;
	level = lv;
	tarpos = static_cast<Position>(tarpos_);
}
void gyorai::main(){
	effect::main();
	x += 11 * dir;
	if(tarpos==SKY)y -= 7;
	if ((tarpos == RAND && x+width/2 < destx) || ((tarpos == SKY && y < 10))) {
		del();
		//Game::getIns()->effect_create(x - 50, WINDOW_Y-HEI_EXP, EXP);
		int center = (x + x + width) / 2;
		Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2, (y+y+height)/2-HEI_NOMALEXP/2, NOMALEXP);

		//		SoundController::getSE()->playSE("sound/taihou03.mp3");

		shared_ptr<AttackRange> p(new AttackRange(center - WID_NOMALEXP / 2, center + WID_NOMALEXP / 2, power, tarpos));
		Game::getIns()->push_attack_list(p, ENEMY);
	}
}

void gyorai::draw(int cx){
	if (dir == LEFT){
		DrawGraph(x - cx, y, Images::getIns()->g_gyorai[level/3][ani_count / ANIM_SPEED % ANI_GYORAI], true);
	}
	else
		DrawTurnGraph(x - cx, y, Images::getIns()->g_gyorai[level / 3][ani_count / ANIM_SPEED % ANI_GYORAI], true);

	effect::draw(cx);
}