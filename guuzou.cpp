
#include "guuzou.h"
#include "Status.h"
#include "Images.h"
#include "Game.h"



#define ANIM_SPEED 3
#define DIST_GUUZOU 1000
guuzou::guuzou(int fx, int ln, int lv) :enemy(fx, ln, lv, UnitType::_GUUZOU){
	width = WID_GUUZOU;
	height = HEI_GUUZOU;
	x = x - width +20;
	y = WINDOW_Y - height;
	atk_type = RAND;
	dist = dist + DIST_GUUZOU;
	type = ALL;
}

void guuzou::main(int front){
	enemy::main(front);
	switch (state){
	case UnitState::MOV:
//		x += speed*dir; //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
	//	if (x + width < 0) state = UnitState::DIE;
		break;
	case UnitState::ATK:
		atk = false;

	if (ani_count / ANIM_SPEED%ANI_GUUZOU_A == ANI_GUUZOU_A - 1){
			if (!stopper){
				if (!atk){
					stopper = true;
					Game::getIns()->effect_create(front - WID_GLIGHT/2, FIELD_H - HEI_GLIGHT, GLIGHT,Direction::NODIR, power);

				//	atk = true;
				}
			}
		}
		else{ stopper = false; }

		if (((ani_count / ANIM_SPEED) == ANI_GUUZOU_A)){
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

void guuzou::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y, Images::getIns()->g_guuzou_w[ani_count / ANIM_SPEED%ANI_GUUZOU_W], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y, Images::getIns()->g_guuzou_a2[ani_count / ANIM_SPEED%ANI_GUUZOU_A], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y, Images::getIns()->g_guuzou_w[ani_count / ANIM_SPEED%ANI_GUUZOU_W], true);

		break;
	case UnitState::DIE:
//		DrawGraph(x - cx, y, Images::getIns()->g_guuzou_dei[level / 3][ani_count / ANIM_SPEED %ANI_GUUZOU], true);
		break;
	}

	enemy::drawBossHP(x, cx, height / 2);
}


#define ANIM_SPEED_L 8
glight::glight(int fx, int fy, int p) :effect(fx, fy){
	type = GLIGHT;
	width = WID_GLIGHT;
	height = HEI_GLIGHT;
	power = p;

}
void glight::main(){
	effect::main();
	if (ani_count == 1){
	}
	if (ani_count / ANIM_SPEED_L % ANI_GLIGHT == 2){
		
	}
	if (ani_count / ANIM_SPEED_L % ANI_GLIGHT == ANI_GLIGHT - 1){
		if (rand() % 3 == 1){
			shared_ptr<AttackRange> p(new AttackRange(x + 80, x + WID_GLIGHT - 80, power, ALL));
			Game::getIns()->push_attack_list(p,ENEMY);
		}
		del();
	}
}

void glight::draw(int cx){

	DrawGraph(x - cx, y, Images::getIns()->g_glight[ani_count / ANIM_SPEED_L % ANI_GLIGHT], true);
		effect::draw(cx);
}

#define ANIM_SPEED_B 4

gbeam::gbeam(int fx, int fy) :effect(fx, fy){
	type = GBEAM;
	width = WID_GBEAM;
	height = HEI_GBEAM;


}
void gbeam::main(){
	effect::main();
	if (ani_count == 1){
	}
	if (ani_count / ANIM_SPEED_L % ANI_GBEAM == 2){

	}
	if (ani_count / ANIM_SPEED_L % ANI_GBEAM == ANI_GBEAM - 1){
//			shared_ptr<AttackRange> p(new AttackRange(x + 80, x + WID_GBEAM - 80, 0, RAND));
	//		Game::getIns()->push_attack_list(p, ENEMY);
		del();
	}
}

void gbeam::draw(int cx){

	DrawGraph(x - cx, y, Images::getIns()->g_gbeam[ani_count / ANIM_SPEED_L % ANI_GBEAM], true);
	effect::draw(cx);
}