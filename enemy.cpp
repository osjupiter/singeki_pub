#include "enemy.h"
#include "Game.h"
enemy::enemy(int fx, int ln, int lv , UnitType u_type) :character(fx, ln, u_type){
	level = lv;
	dir = Direction::LEFT;
	atk = false;
}

void enemy::main(int front){
	character::main(front);
}

void enemy::draw(int cx){
	
}

void enemy::del(){
	Game::getIns()->push_del_enemy(this->shared_from_this());
	//Game::getIns()->push_del_enemy(*(new shared_ptr<enemy>(this)));
	Game::getIns()->gainResource(cost);
}

int enemy::getPower(){
	return power*atk;
}
Position enemy::getAtkType(){
	return atk_type;
}
void enemy::damage(int d, Position op_a_type,UnitType op_unit_type){
	if (op_a_type == NOATK) return;
	if (op_a_type == ALL || op_a_type == type){
		if (rand() % 30 == 0){
			int rand_x = rand() % width / 2, rand_y = rand() % height / 2;
			switch (op_unit_type){
			case UnitType::_BAZOOKA:
				Game::getIns()->damage_effect_create(x + width /3+rand_x, y + height - HEI_CANNONSHOT+35-rand_y, CANNONSHOT, true);
				break;
			case UnitType::_HOHEI:
				Game::getIns()->damage_effect_create(x + width / 3+rand_x, y + height - HEI_GUNSHOT+25-rand_y, GUNSHOT);
				break;
			}
		}
		hp -= max(d - defense, 0);
		if (state != UnitState::DIE && hp < 0){
			changeState(UnitState::DIE);
		}
	}

}


void enemy::changeState(UnitState next_state){
	if (!state_change_flag && next_state != UnitState::DIE) return;
	switch (next_state){
	case UnitState::MOV:		
		ani_count = 0;
		switch (state){
		case UnitState::ATK:
		//	wait_time = param->getParam(A_FREQ);
			wait_time = atk_freq;
			atk = false;
			break;
		}
		state = next_state;
		break;
	case UnitState::ATK:
		switch (state){
		case UnitState::MOV:
			state = UnitState::ATK;
			ani_count = 0;

			break;
		case UnitState::WAIT:
			state = UnitState::ATK;
			ani_count = 0;
			break;
		}
		break;
	case UnitState::WAIT:
		switch (state){
		case UnitState::MOV:
			state = UnitState::WAIT;
			break;
		case UnitState::ATK:
			//	wait_time = param->getParam(A_FREQ);
			wait_time = atk_freq;
			atk = false;
			ani_count = 0;
			if (wait_time == 0){
				
				state = UnitState::ATK;
			}
			else{
				state = UnitState::WAIT;
			}
			break;
		}
		break;
	case UnitState::DIE:
		state = next_state;
		ani_count = 0;
		atk = false;
		break;
	}
}


Position enemy::decideTargetPos(int target_x_rand, int target_x_sky){
	Position ret;
	switch (atk_type){
	case ALL:
		if (dir == RIGHT){
			if (target_x_rand <= target_x_sky) ret = RAND;
			else ret = SKY;
		}
		else {
			if (target_x_rand >= target_x_sky) ret = RAND;
			else ret = SKY;
		}
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



