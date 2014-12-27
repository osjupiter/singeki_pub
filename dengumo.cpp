#include "dengumo.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 4
#define DIST_DENGUMO WID_DENKAMI
dengumo::dengumo(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_DENGUMO){
	width = WID_DENGUMO;
	height = HEI_DENGUMO;
	y =40*ln+3;
	atk_type = SKY;
	dist = dist + DIST_DENGUMO;
	type = SKY;
	thunder = false;
	thunder_count = 0;
}

void dengumo::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
		x += speed*dir; //とりあえず横移動
		if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		atk = false;
		state_change_flag = false;
		if (ani_count / ANIM_SPEED%ANI_DENGUMO_A == 6){
			thunder = true;

		}
		if (thunder){
			thunder_count++;

		}
		if (ani_count / ANIM_SPEED%ANI_DENGUMO_A == 7 || ani_count / ANIM_SPEED%ANI_DENGUMO_A == 9){
			if (!stopper){
					stopper = true;
					shared_ptr<AttackRange> p(new AttackRange(x + WID_DENGUMO/2 - 326, x + width/2, power/2, SKY));
					Game::getIns()->push_attack_list(p, ENEMY);

			}
		}	
		else{ stopper = false; }

		if (ani_count / ANIM_SPEED%ANI_DENGUMO_A == 10){
			thunder = false;
			thunder_count = 0;
		}
		if (((ani_count / ANIM_SPEED) == ANI_DENGUMO_A)){
			state_change_flag = true;
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

void dengumo::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_dengumo_w[level / 3][ani_count / ANIM_SPEED%ANI_DENGUMO_W], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_dengumo_a[level / 3][ani_count / ANIM_SPEED%ANI_DENGUMO_A], true);
		if (thunder){
			DrawGraph(x - cx + WID_DENGUMO/2 -326, y+120-99, Images::getIns()->g_denkami[level / 3][thunder_count / ANIM_SPEED%ANI_DENKAMI], true);
		}
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_dengumo_w[level / 3][ani_count / ANIM_SPEED%ANI_DENGUMO_W], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y, Images::getIns()->g_dengumo_w[level / 3][ani_count / ANIM_SPEED %ANI_DENGUMO_W], true);
		break;
	}

	enemy::draw(cx);
}
