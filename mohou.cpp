#include "mahou.h"
#include "Images.h"
#include "Game.h"
#include "math.h"

#define ANIM_SPEED 1

mahou::mahou(int fx, int fy, Direction d,int p,int dstx,int dsty) :effect(fx, fy){
	type = MAHOU;
	width = WID_MAHOU;
	height = HEI_MAHOU;
	dir = d;
	destx = dstx;
	desty = dsty;
	fix = fx;
	fiy = fy;
	power = p;
	stopper = false;
}
void mahou::main(){
	effect::main();
	x += 10*dir;
	y += (desty-fiy) /((destx-fix)/10.0);

	if (x > destx) {
		if (!stopper){
			shared_ptr<AttackRange> p(new AttackRange(x, x + width - 20, power, RAND));
			Game::getIns()->push_attack_list(p, MUSUME);
			stopper = true;
			ani_count = 0;
		}
		if (stopper){
			if (ani_count / 3 >3)
				del();
		}
//		Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2, y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);
//		shared_ptr<AttackRange> p(new AttackRange(x - 50, x + width + 50, power, SKY));
	//	Game::getIns()->push_attack_list(p, MUSUME);
	}
}

void mahou::draw(int cx){
	switch (dir){
	case Direction::RIGHT:
		
		if (ani_count / ANIM_SPEED < 7){
	//		DrawRotaGraph2(x - cx, y, 0, 0, 1.0, atan2(desty - fiy, destx - fix), Images::getIns()->g_mahou[ani_count / ANIM_SPEED], true);
			DrawGraph(x - cx, y,  Images::getIns()->g_mahou[ani_count / 2 % 3 + 7], true);

		}
		else if (stopper){
			DrawGraph(x - cx, y, Images::getIns()->g_mahou[6 - (ani_count /3 )%4], true);
		}
		else{
			DrawGraph(x - cx, y,  Images::getIns()->g_mahou[ani_count / ANIM_SPEED % 3 + 7], true);
	//		DrawRotaGraph2(x - cx, y, 0, 0, 1.0, atan2(desty - fiy, destx - fix), Images::getIns()->g_mahou[ani_count / ANIM_SPEED % 3 + 7], true);

			//DrawGraph(x - cx, y, Images::getIns()->g_mahou[ani_count / ANIM_SPEED % (ANI_MAHOU-7)+7], true);
		}
	//	DrawLine(destx-cx, 0, destx - cx, 450, GetColor(0, 0, 255), 2);
	//	DrawLine(0, desty, 800, desty, GetColor(0, 0, 255), 2);

		break;
	case Direction::LEFT:
		DrawTurnGraph(x - cx, y, Images::getIns()->g_mahou[ani_count / ANIM_SPEED % ANI_MAHOU], true);
		break;

	default:
		break;
	}
		effect::draw(cx);
}