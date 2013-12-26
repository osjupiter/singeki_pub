#include "railgun.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 1
#define ANIM_SPEED_C 1
int railgun::num = 0;

railgun::railgun(int fx, int fy, int ln, int lv) : enemy(fx, fy, ln, lv){

	power = POWER_RAILGUN*lv;
	hp = MAXHP_RAILGUN*lv;
	width = WID_RAILGUN;
	height = HEI_RAILGUN;
	num++;
	atk = false;
	defense = DEFENSE_RAILGUN*lv;
	type = RAND;
	atk_type = RAND;
	cost = COST_RAILGUN;
	atk_freq = A_FREQ_RAILGUN;
	stopper = false;
	speed = SPEED_RAILGUN;
}
void railgun::init(){
	num = 0;

}
void railgun::main(int front){
	enemy::main(front);
	//	state = ATK;
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		break;
	case ATK:
		atk = false;
		if ((ani_count / ANIM_SPEED) == ANI_BEAM - 1){
			if (!stopper){
				stopper = true;
				for (int i = x-WID_BEAM; i + WID_EXP < x ; i += WID_EXP-100)
					Game::getIns()->effect_create(i, WINDOW_Y - 240, EXP);
				shared_ptr<AttackRange> p(new AttackRange(x - WID_BEAM+80, x, power, RAND));
				Game::getIns()->push_attack_list(p, ENEMY);
			}
		}
		else{
			stopper = false;
		}

		if (((ani_count / ANIM_SPEED) == ANI_BEAM)){
			changeState(WAIT);

		}
		break;
	case UnitState::WAIT:

		break;
	case UnitState::DIE:
		del();
		break;
	}
}

void railgun::draw(int cx){
	switch (state){
	case UnitState::MOV:
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
		break;
	case UnitState::ATK:
		if (dir == LEFT){
			DrawGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
			DrawGraph(x + 30 - WID_BEAM +80 - cx, y, Images::getIns()->g_beam[ani_count / ANIM_SPEED%ANI_BEAM], true);
		}
		else{
			DrawTurnGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
			DrawTurnGraph(x - 30 - WID_BEAM - 80 - cx, y, Images::getIns()->g_beam[ani_count / ANIM_SPEED%ANI_BEAM], true);
		}	
		break;
	case UnitState::WAIT:
		if (dir == LEFT){
			DrawGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
			DrawGraph(x+30 - WID_BEAM_C / 2-cx, y, Images::getIns()->g_beam_c[ani_count / ANIM_SPEED_C%ANI_BEAM_C], true);
		}
		else{
			DrawTurnGraph(x - cx, y, Images::getIns()->g_rail[ani_count / ANIM_SPEED%ANI_RAILGUN], true);
			DrawTurnGraph(x-30 +WID_RAILGUN - WID_BEAM_C / 2-cx, y, Images::getIns()->g_beam_c[ani_count / ANIM_SPEED_C%ANI_BEAM_C], true);
		}
		break;
	case UnitState::DIE:
		break;

	}

	unit::draw(cx);
}

int railgun::getNum(){
	return num;
}

void railgun::setNum(int i){
	num = i;
}

