#include "gajigaji.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"
#include"SoundController.h"

#define ANIM_SPEED 3
#define ANIM_SPEED_DIE 2
#define DIST_GAJIGAJI 0


gajigaji::gajigaji(int fx, int ln, int lv) : enemy(fx, ln, lv, UnitType::_GAJIGAJI){
	width = WID_GAJIGAJI;
	height = HEI_GAJIGAJI_W;
	y = WINDOW_Y - height - line * 3;

	dist = DIST_GAJIGAJI;
	power = POWER_GAJIGAJI *(1 * lv);
	hp = MAXHP_GAJIGAJI + MAXHP_GAJIGAJI*lv;
	speed = SPEED_GAJIGAJI + 0.5*SPEED_GAJIGAJI*lv;
	defense = DEFENSE_GAJIGAJI*(1 + 0.8*lv);
	type = RAND;
	atk_type = A_TYPE_GAJIGAJI;
	cost = COST_GAJIGAJI + 40 * lv;
	atk_freq = A_FREQ_GAJIGAJI - 0.05*A_FREQ_GAJIGAJI*lv;
	unit_type = UnitType::_GAJIGAJI;
	maxhp = hp;

}


void gajigaji::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //�Ƃ肠�������ړ�
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		if (ani_count / ANIM_SPEED%ANI_GAJIGAJI_A == 3){
			if (!stopper){
				if (!atk){
					atk = true;
					stopper = true;
				}

			}
			else{ atk = false; }
		}else { stopper = false; }
		
		if (((ani_count / ANIM_SPEED) == ANI_GAJIGAJI_A)){
			changeState(UnitState::WAIT);

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

void gajigaji::draw(int cx){
	switch (state){
	case UnitState::MOV:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_W], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_W], true);
		break;
	case UnitState::ATK:
		if (dir == LEFT)
			DrawGraph(x - cx, y-20, Images::getIns()->g_gajigaji_a[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_A], true);
		else
			DrawTurnGraph(x - cx, y-20, Images::getIns()->g_gajigaji_a[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_A], true);
		break;
	case UnitState::WAIT:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_W], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED%ANI_GAJIGAJI_W], true);
		break;
	case UnitState::DIE:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED_DIE%ANI_GAJIGAJI_W], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_gajigaji_w[level / 3][ani_count / ANIM_SPEED_DIE%ANI_GAJIGAJI_W], true);
		break;
	}

	enemy::draw(cx);
}



