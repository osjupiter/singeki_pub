#include "musume.h"
#include "Game.h"

musume::musume(int fx, int ln, UnitType u_type) : character(fx, ln ,u_type){
	dir = Direction::RIGHT;
	hp = param->getParam(MAXHP);
	maxhp = hp;
	atk = false;
}

void musume::main(int front){
	character::main(front);

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
			}
		}
		hp -= max(d - param->getParam(DEFENSE), 0);
		printfDx("%d %d\n", op_unit_type, d - param->getParam(DEFENSE));

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



