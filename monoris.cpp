#include "monoris.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define ANIM_SPEED_A 1
#define ANIM_SPEED_MONOBEAM 4
#define DIST_MONORIS  (10)
#define ANI_MONORIS_A (ANI_MONORIS_A1+ANI_MONORIS_A2+ANI_MONORIS_A1)

monoris::monoris(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_MONORIS){
	width = WID_MONORIS;
	height = HEI_MONORIS;
	y = 40 + ln * 3;
	atk_type = ALL;
	dist = dist + DIST_MONORIS;
	type = SKY;
	beam_count = 0;

}

void monoris::main(int front){
	bool pre_wait = (state == UnitState::WAIT);
	enemy::main(front);
	if (pre_wait && state != UnitState::WAIT){
		changeState(UnitState::ST1);
		ani_count = 0;
	}
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		atk = false;
		state_change_flag = false;

		if (((ani_count / ANIM_SPEED) == ANI_MONORIS_A1)){
			state_change_flag = true;
			ani_count = 0;
			changeState(UnitState::ST0);
			state_change_flag = false;
		}
		break;
	case UnitState::ST0: //ƒr[ƒ€”­ŽË

		if (ani_count > 0){
			beam_count++;
		}
		if (((beam_count / ANIM_SPEED_MONOBEAM) == ANI_MONOBEAM-2)){
			if (!stopper){
				if (!atk){
					atk = true;
				}
			}
			else { atk = false; }
		}
		else{stopper = false;}
		if (((beam_count / ANIM_SPEED_MONOBEAM) == ANI_MONOBEAM)){
			state_change_flag = true;
			changeState(UnitState::WAIT);
			ani_count = 0;

//			state_change_flag = false;
			beam_count = 0;
		}

		break;
	case UnitState::ST1:
		state_change_flag = false;
		if (((ani_count / ANIM_SPEED_A) == ANI_MONORIS_A1)){
			state_change_flag = true;
			changeState(UnitState::WAIT);
			ani_count = 0;

		}
		break;
	case UnitState::WAIT:
		atk = false;

		break;
	case UnitState::DIE:
		if (ani_count == 1){
			Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2, y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);
		}
		if (ani_count == 4)
			Game::getIns()->effect_create(x + width / 2 - WID_NOMALEXP / 2 + 10, y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);

		if (ani_count / 3 == 2){
			del();
		}
		break;

	}

}

void monoris::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_monoris_w[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_W], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_monoris_a1[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_A1], true);
		break;
	case UnitState::ST0:
		DrawGraph(x - cx, y, Images::getIns()->g_monoris_a2[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_A2], true);
		DrawGraph(x +88 -194 - cx, y-30, Images::getIns()->g_monobeam[level / 3][beam_count / ANIM_SPEED_MONOBEAM%ANI_MONOBEAM], true);
		break;
	case UnitState::ST1:
		DrawGraph(x - cx, y, Images::getIns()->g_monoris_a1[level / 3][(ANI_MONORIS_A1-1) - ani_count / ANIM_SPEED%ANI_MONORIS_A1], true);
		break;

	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_monoris_a2[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_A1], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_monoris_w[level / 3][ani_count / ANIM_SPEED %ANI_MONORIS_W], true);
		break;
	}

	enemy::draw(cx);
}