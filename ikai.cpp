#include "ikai.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 4
#define DIST_IKAI 2000
ikai::ikai(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_AKUUMON){
	width = WID_IKAI;
	height = HEI_IKAI;
	x = x - width + 30;
	y = WINDOW_Y - height;
	atk_type = ALL;
	dist = dist + DIST_IKAI;
	type = ALL;
}

void ikai::main(int front){
	enemy::main(front);

	switch (state){
	case UnitState::MOV:
	//	x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		atk = false;
		if (ani_count / ANIM_SPEED%ANI_IKAI_A1 == 2){
			if (!stopper){
				if (!atk){
		//			Game::getIns()->effect_create(x - (WID_IKAI*1.5)*(rand()*0 % 2 + 1), FIELD_H - 450, GOMI, NODIR, power);

					stopper = true;
				//	atk = true;
				}
			}
		}
		else{ stopper = false; }

		if (((ani_count / ANIM_SPEED) == ANI_IKAI_A1*3)){
			changeState(UnitState::WAIT);

		}
		break;
	case UnitState::WAIT:
		atk = false;
		break;
	case UnitState::DIE:
	
			del();
		
		break;

	}

}

void ikai::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_ikai_w[ani_count / ANIM_SPEED%ANI_IKAI_W], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_ikai_a1[ani_count / ANIM_SPEED%ANI_IKAI_A1], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_ikai_w[ani_count / ANIM_SPEED%ANI_IKAI_W], true);
		break;
	case UnitState::DIE:
//		DrawGraph(x - cx, y, Images::getIns()->g_ikai_dei[level / 3][ani_count / ANIM_SPEED %ANI_IKAI], true);
		break;
	}

	enemy::draw(cx);
}
