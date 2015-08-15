#include "railgun.h"
#include "Images.h"
#include "Game.h"
#include "Status.h"

#define ANIM_SPEED 1
#define ANIM_SPEED_C 1
#define DIST_RAILGUN 90
int railgun::num = 0;

railgun::railgun(int fx, int ln, int lv) : enemy(fx, ln, lv, UnitType::_RAILGUN){
	dist = dist + DIST_RAILGUN;
	width = WID_RAILGUN;
	height = HEI_RAILGUN;
	num++;
	atk = false;
	type = RAND;
	atk_type = RAND;
	stopper = false;
	y = WINDOW_Y - HEI_RAILGUN - line * 3;
	wait_time = 0;
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
	case UnitState::ATK:
		atk = false;

		if (ani_count == 1){
			SoundController::getSE()->playSE("sound/sen_mi_lasergun01.mp3");
		}
		if ((ani_count / ANIM_SPEED) == ANI_BEAM - 1){
			if (!stopper){
				stopper = true;
	//			atk_freq += 300;
				for (int i = x - WID_BEAM; i + WID_EXP < x ; i += WID_EXP-100)
					Game::getIns()->effect_create(i, WINDOW_Y - 240, EXP);
				shared_ptr<AttackRange> p(new AttackRange(x - WID_BEAM+80, x, power, RAND));
				Game::getIns()->push_attack_list(p, ENEMY);
				SoundController::getSE()->playSE("sound/sen_ge_taihou08.mp3");
			}
		}
		else{
			stopper = false;
		}

		if (((ani_count / ANIM_SPEED) == ANI_BEAM)){
			state_change_flag = true;
			changeState(UnitState::MOV);

		}
		break;
	case UnitState::WAIT:
		if (wait_time>0)
		state_change_flag = false;
		else {
			state_change_flag = true;
			changeState(UnitState::ATK);
			state_change_flag = false;
		}
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

	enemy::draw(cx);
}

int railgun::getNum(){
	return num;
}

void railgun::setNum(int i){
	num = i;
}

