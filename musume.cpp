#include "musume.h"
#include "Game.h"
#include "Status.h"

musume::musume(int fx, int ln, UnitType u_type) : character(fx, ln ,u_type){
	dir = Direction::RIGHT;
	hp = param->getParam(MAXHP);
	maxhp = hp;
	atk = false;
}

void musume::main(int front){
	switch (state){
	case UnitState::MOV:
	//	wait_time = param->getParam(A_FREQ);

		break;
	}
	character::main(front);
	if (x > STAGE8_W + 200){
		changeState(UnitState::DIE);
	}
	switch (state){
	case UnitState::DIE:
		y += vy;
		x += vx;
		vy -= 10;
		vx -= 5;
		if (y + height<0)
			del();
		break;
	}
}

void musume::draw(int cx){

}

void musume::changeState(UnitState next_state){
	if (state == UnitState::DIE)return;

	if (!state_change_flag && next_state != UnitState::DIE) return;
	switch (next_state){
	case UnitState::MOV:		
		ani_count = 0;
		switch (state){
		case UnitState::ATK:
			wait_time = param->getParam(A_FREQ);
			atk = false;
			break;
		}
		state = next_state;
		break;
	case UnitState::ATK:
		state = UnitState::ATK;
		ani_count = 0;
		
		break;
	case UnitState::WAIT:
		switch (state){
		case UnitState::MOV:
			state = UnitState::WAIT;
			break;
		case UnitState::ATK:
			wait_time = param->getParam(A_FREQ);

			if (wait_time == 0){
				state = UnitState::ATK;
				ani_count = 0;
			}
			else {
				state = UnitState::WAIT;
				ani_count = 0;
				atk = false;
			}
			break;
		default:
			state = UnitState::WAIT;
			ani_count = 0;
			break;
		}
		break;
	case UnitState::ST0:
	case UnitState::ST1:
	case UnitState::ST2:
		state = next_state;
		
		break;
	case UnitState::DIE:
		if (no_die_flag) return;
		state = next_state;
		atk = false;
		state_change_flag = false;
		ani_count = 0;
		break;
	}
}


void musume::del(){
	//Game::getIns()->push_del_musume(*(new shared_ptr<musume>(this)));
	Game::getIns()->push_del_musume(shared_from_this());
}

void musume::damage(int d, Position op_a_type, UnitType op_unit_type){

	if (no_damage_flag) return;
	if (op_a_type == NOATK) return;
	if (op_a_type == ALL || op_a_type == type){
		if (rand() % 30==0){
			int rand_x = rand() % width/2, rand_y = rand() % height/2;
			switch (op_unit_type){
			case UnitType::_TANK:
			case UnitType::_BEEBAR:
			case UnitType::_OHANA:
				Game::getIns()->damage_effect_create(x-WID_CANNONSHOT/2+rand_x, y + height - HEI_CANNONSHOT +35-rand_y, CANNONSHOT);
				break;
			case UnitType::_GEKKO:
			case UnitType::_SHARIN:
				Game::getIns()->damage_effect_create(x - WID_GUNSHOT / 2+rand_x, y + height - HEI_GUNSHOT+25 -rand_y, GUNSHOT, true);
				break;
			case UnitType::_GAJIGAJI:
				Game::getIns()->damage_effect_create(x - WID_GAJIKAMI / 2 + rand_x, y + height - HEI_GAJIKAMI + 25 - rand_y, GAJIKAMI, true);
				break;
			case UnitType::_MONORIS:
				Game::getIns()->damage_effect_create(x - WID_MONOB_H / 2 + rand_x, y + height - HEI_MONOB_H + 25 - rand_y, MONOB_H, true);
				break;
			}
		}
		hp -= max(d - param->getParam(DEFENSE), 0);
	//	printfDx("%d %d\n", op_unit_type, d - param->getParam(DEFENSE));

		if (hp < 0){
			changeState(UnitState::DIE);
		}
	}

	if (state == UnitState::DIE){
		vx = -rand()%80;
		vy = -30;
	}
	
}


int musume::getPower(){
	return param->getParam(POWER)*atk;
}


Position musume::getAtkType(){
	return (Position) param->getParam(A_TYPE);
}



Position musume::decideTargetPos(int target_x_rand, int target_x_sky){
	Position ret;
	switch (param->getParam(A_TYPE)){
	case ALL:
		if(target_x_rand <= target_x_sky) ret = RAND;
		else ret = SKY;
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



void musume::drawWait(int dx_, int cx, int ty){
	character::drawWait(dx_, cx, ty, param->getParam(A_FREQ));
	/*
	//çUåÇë“ã@éûä‘ï\é¶
	if (state != UnitState::DIE){
	int dx = dx_ + width / 2 - 60 / 2;
	int dy = ty;
	DrawLine(dx - cx, dy + 3, dx + 60 - cx, dy + 3, GetColor(205, 149, 12), 5);
	int i = wait_time;
	DrawLine(dx - cx, dy + 3, dx + 60 * max(i, 0) / (freq * 1.0) - cx, dy + 3, GetColor(139, 101, 8), 5);
	}
	*/
}


void musume::decideDirection(int front){
	boolean flag=false;
	switch (unit_type){
	case UnitType::_IKAROS:
		flag = true;
			break;	
	}
	if (!flag) return;
	if (((x  <= front) && dir == LEFT)
		|| ((x > front) && dir == RIGHT))
		switchDirection();
}