#include "railgun.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"

#define ANIM_SPEED 1
#define ANIM_SPEED_C 1
#define DIST_RAILGUN 200
int railgun::num = 0;

railgun::railgun(int fx, int fy, int ln, int lv) : enemy(fx, fy, ln, lv){
	dist = dist + DIST_RAILGUN;
	power = POWER_RAILGUN+POWER_RAILGUN*0.3*lv;
	hp = MAXHP_RAILGUN+MAXHP_RAILGUN*0.5*lv;
	width = WID_RAILGUN;
	height = HEI_RAILGUN;
	num++;
	atk = false;
	defense = DEFENSE_RAILGUN+DEFENSE_RAILGUN*0.5*lv;
	type = RAND;
	atk_type = RAND;
	cost = COST_RAILGUN+500*lv;
	atk_freq = A_FREQ_RAILGUN;
	stopper = false;
	speed = SPEED_RAILGUN*(1+0.3*lv);
	unit_type = UnitType::_RAILGUN;
	maxhp = hp;

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
		wait_time = atk_freq;
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
		if (ani_count / 3 == 0 || ani_count / 3 == 8) {
			for (int i = x -WID_NOMALEXP / 4; i + WID_NOMALEXP / 2< x + width; i += WID_NOMALEXP / 3)
				Game::getIns()->effect_create(i , y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);
		}
		if (ani_count / 3 == 4 || ani_count / 3 == 8) {
			for (int i = x ; i + WID_NOMALEXP/2 < x+ width; i += WID_NOMALEXP/4)
				Game::getIns()->effect_create(i, y + height / 2 - HEI_NOMALEXP / 2, NOMALEXP);
		}
		if (ani_count / 3 > 10){
			del();
		}
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
		if (dir == LEFT)
			DrawGraph(x - cx, y, Images::getIns()->g_rail[0], true);
		else
			DrawTurnGraph(x - cx, y, Images::getIns()->g_rail[0], true);
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

