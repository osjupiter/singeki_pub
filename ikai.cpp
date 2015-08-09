#include "ikai.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
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
		if (ani_count / ANIM_SPEED%(ANI_IKAI_A1)== 2){
			if (!stopper){
				if (!atk){
					Game::getIns()->effect_create(x -(rand() % dist  + 1),0, IKAMINARI, NODIR, power);
					stopper = true;
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
		DrawGraph(x - cx, y, Images::getIns()->g_ikai_a2[ani_count / ANIM_SPEED%ANI_IKAI_A2], true);
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


#define ANIM_SPEED_K 3
i_kaminari::i_kaminari(int fx, int fy, int p) :effect(fx, fy){
	type = IKAMINARI;
	width = WID_IKAMINARI;
	height = HEI_IKAMINARI;
	power = p;
}
void i_kaminari::main(){
	effect::main();
	if (ani_count == ANIM_SPEED_K*4){
		SoundController::getSE()->playSE("sound/‹ô‘œ—‹.mp3");
	}
	if (ani_count / ANIM_SPEED_K % ANI_IKAMINARI == 2){

	}
	if (ani_count / ANIM_SPEED_K % ANI_IKAMINARI == ANI_IKAMINARI - 1){
			shared_ptr<AttackRange> p(new AttackRange(x + 174, x + 278, power, SKY));
			Game::getIns()->push_attack_list(p, ENEMY);
			shared_ptr<AttackRange> p2(new AttackRange(x +74, x + 240, power,RAND));
			Game::getIns()->push_attack_list(p2, ENEMY);

		del();
	}
}

void i_kaminari::draw(int cx){

	DrawGraph(x - cx, y, Images::getIns()->g_ikaminari[ani_count / ANIM_SPEED_K % ANI_IKAMINARI], true);
	effect::draw(cx);
}
