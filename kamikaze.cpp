#include "kamikaze.h"
#include "Images.h"
#include "Game.h"

#define ANIM_SPEED 3
#define DIST_KAMIKAZE 250
int kamikaze::num = 0;



kamikaze::kamikaze(int fx, int fy, int ln, shared_ptr<Parameter> pm) : musume(fx, fy, ln, pm){
	dist = dist + DIST_KAMIKAZE;
	
	//hp = param->getParam(MAXHP);
	width = WID_KAMIKAZE;
	height = HEI_KAMIKAZE;
	num++;
	atk = false;
	stopper = false;
	type = SKY;
	gap_y = 0;
	gap_vy=1;
	unit_type=UnitType::_KAMIKAZE;
}
void kamikaze::init(){
	num = 0;

}
void kamikaze::main(int front){
	musume::main(front);
	//	state = ATK;
	switch (state){

	case UnitState::ATK:
	/*	if (gap_y == -3)
			gap_vy = gap_vy*-1;
		else if (gap_y == 0)
			gap_vy = gap_vy*-1;
		gap_y += gap_vy;
		*/
	
		atk = false;
		
		if ((ani_count / ANIM_SPEED == ANI_KAMIKAZE_ATK)){
			Game::getIns()->effect_create(x, y + 75,TEPODON, dir, param->getParam(POWER), front );			
			changeState(DIE);

		}

		break;
	case UnitState::DIE:

		break;
	}
}

void kamikaze::draw(int cx){
	switch (state){
	case UnitState::MOV:
		DrawGraph(x - cx, y+gap_y, Images::getIns()->g_kamikaze[ani_count / ANIM_SPEED%ANI_KAMIKAZE], true);
		break;
	case UnitState::ATK:
		DrawGraph(x - cx, y + gap_y, Images::getIns()->g_kamikaze_atk[ani_count / ANIM_SPEED%ANI_KAMIKAZE_ATK], true);
		break;
	case UnitState::WAIT:
		DrawGraph(x - cx, y + gap_y, Images::getIns()->g_kamikaze_atk[ani_count / ANIM_SPEED%ANI_KAMIKAZE_ATK], true);
		break;
	case UnitState::DIE:
		DrawGraph(x - cx, y + gap_y, Images::getIns()->g_kamikaze[ani_count / ANIM_SPEED%ANI_KAMIKAZE_ATK], true);
		break;

	}

	unit::draw(cx);
}

int kamikaze::getNum(){
	return num;
}

void kamikaze::setNum(int i){
	num = i;
}
