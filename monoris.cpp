#include "monoris.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define ANIM_SPEED_A 1
#define ANIM_SPEED_MONOBEAM 4
#define DIST_MONORIS  (150)
#define ANI_MONORIS_A (ANI_MONORIS_A1+ANI_MONORIS_A2+ANI_MONORIS_A1)

monoris::monoris(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_MONORIS){
	width = WID_MONORIS;
	height = HEI_MONORIS;
	y = 50 + ln * 15;
	atk_type = ALL;
	dist = dist + DIST_MONORIS;
	type = SKY;
	beam_count = 0;

}

void monoris::main(int front){
	UnitState pre_state = state;
	enemy::main(front);
	if ((pre_state == UnitState::WAIT)){
		if (dir == LEFT){
			if (state == UnitState::ATK){
				changeState(UnitState::ST0);
				ani_count = 0;

			}
			else if (state != UnitState::WAIT && state != UnitState::ATK){
				changeState(UnitState::ST1);
				ani_count = 0;
			}
		}
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
					stopper = true;
				}
			}
			else { atk = false; }
		}
		else{stopper = false;}
		if (((beam_count / ANIM_SPEED_MONOBEAM) == ANI_MONOBEAM)){
			state_change_flag = true;
			changeState(UnitState::WAIT);
			ani_count = 0;
			wait_time = atk_freq;
//			state_change_flag = false;
			beam_count = 0;
		}

		break;
	case UnitState::ST1:
		state_change_flag = false;
		if (ani_count / ANIM_SPEED_A == ANI_MONORIS_A1){
			state_change_flag = true;
			changeState(UnitState::MOV);
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
	if (dir == LEFT){
		switch (state){
		case UnitState::MOV:
			if (dir==LEFT)
				DrawGraph(x -cx, y, Images::getIns()->g_monoris_w[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_W], true);
			else
				DrawGraph(x - cx, y, Images::getIns()->g_monoris_a2[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_A2], true);
			break;
		case UnitState::ATK:
			DrawGraph(x - cx, y, Images::getIns()->g_monoris_a1[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_A1], true);
			break;
		case UnitState::ST0:
			DrawGraph(x - cx, y, Images::getIns()->g_monoris_a2[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_A2], true);
			DrawGraph(x + 50 - WID_MONOBEAM/2 - cx, y + 80 - HEI_MONOBEAM/2, Images::getIns()->g_monobeam[level / 3][beam_count / ANIM_SPEED_MONOBEAM%ANI_MONOBEAM], true);
			break;
		case UnitState::ST1:
			DrawGraph(x - cx, y, Images::getIns()->g_monoris_a1[level / 3][(ANI_MONORIS_A1 - 1) - ani_count / ANIM_SPEED%ANI_MONORIS_A1], true);
			break;

		case UnitState::WAIT:
			DrawGraph(x - cx, y, Images::getIns()->g_monoris_a2[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_A2], true);
			break;
		case UnitState::DIE:
			DrawGraph(x - cx, y, Images::getIns()->g_monoris_w[level / 3][ani_count / ANIM_SPEED %ANI_MONORIS_W], true);
			break;
		}
	}
	else{
		switch (state){
		case UnitState::MOV:
			DrawTurnGraph(x - cx, y, Images::getIns()->g_monoris_w[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_W], true);
			break;
		case UnitState::ATK:
			DrawTurnGraph(x - cx, y, Images::getIns()->g_monoris_a1[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_A1], true);
			break;
		case UnitState::ST0:
			DrawTurnGraph(x - cx, y, Images::getIns()->g_monoris_a2[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_A2], true);
			DrawTurnGraph(x + 50 - WID_MONOBEAM/2 - cx, y + 80 - HEI_MONOBEAM/2, Images::getIns()->g_monobeam[level / 3][beam_count / ANIM_SPEED_MONOBEAM%ANI_MONOBEAM], true);
			break;
		case UnitState::ST1:
			DrawTurnGraph(x - cx, y, Images::getIns()->g_monoris_a1[level / 3][(ANI_MONORIS_A1 - 1) - ani_count / ANIM_SPEED%ANI_MONORIS_A1], true);
			break;

		case UnitState::WAIT:
			DrawTurnGraph(x - cx, y, Images::getIns()->g_monoris_a2[level / 3][ani_count / ANIM_SPEED%ANI_MONORIS_A2], true);
			break;
		case UnitState::DIE:
			DrawTurnGraph(x - cx, y, Images::getIns()->g_monoris_w[level / 3][ani_count / ANIM_SPEED %ANI_MONORIS_W], true);
			break;
		}
	}
	enemy::draw(cx);
}


void monoris::decideDirection(int front){
//	return;
	if (((x + width <= front - dist) && dir == LEFT)
		|| ((x + width > front) && dir == RIGHT))
		switchDirection();
}

Position monoris::decideTargetPos(int target_x_rand, int target_x_sky){
	Position ret;
	switch (atk_type){
	case ALL:
		if (dir == RIGHT){
			if (target_x_rand <= target_x_sky) ret = RAND;
			else ret = SKY;
		}
		else {
			if (target_x_rand >= target_x_sky) ret = RAND;
			else ret = SKY;
			if (target_x_sky > x) ret == RAND;
		}
		break;
	case RAND:
		ret = RAND;
		break;
	case SKY:
		ret = SKY;
		break;
	case NOATK:
		ret = RAND;
		break;
	}
	atk_position = ret;
	return ret;
}