#include "enemy.h"
#include "Game.h"
enemy::enemy(int fx, int fy, int ln,int lv) :unit(fx, fy, ln){
	level = lv;
	dir = Direction::LEFT;
	atk = false;
}

void enemy::main(int front){
	unit::main();
	if (wait_time>0)
		wait_time--;
	if (dir == LEFT){
		if (x <= front - dist)
			switchDirection();
		switch (state){
		case UnitState::MOV:
			if (x < front + dist){
				if (wait_time == 0)
					changeState(ATK);
				else changeState(WAIT);
			}
			break;
		case UnitState::ATK:
			if (!(x < front + dist)){
				changeState(MOV);
			}
			break;
		case UnitState::WAIT:
			if (!(x < front + dist)) {
				changeState(MOV);
			}

			else if (wait_time == 0){
				changeState(ATK);
			}
			break;
		case UnitState::DIE:

			break;
		}
	}
	else if (dir == RIGHT){
		if (x > front )
			switchDirection();
		
		switch (state){
		case UnitState::MOV:
			if (x+width > front - dist){
				if (wait_time == 0)
					changeState(ATK);
				else changeState(WAIT);
			}
			break;
		case UnitState::ATK:
			if (!(x + width > front - dist)){
				changeState(MOV);
			}
			break;
		case UnitState::WAIT:
			if (!(x + width > front - dist)) {
				changeState(MOV);
			}

			else if (wait_time == 0){
				changeState(ATK);
			}
			break;
		case UnitState::DIE:
			atk = false;
			break;
		}
	}
}

void enemy::draw(int cx){
	
}

void enemy::del(){
	Game::getIns()->push_del_enemy(*(new shared_ptr<enemy>(this)));
	Game::getIns()->gainResource(cost);
}

int enemy::getPower(){
	return power*atk;
}
Position enemy::getAtkType(){
	return atk_type;
}
void enemy::damage(int d, Position op_a_type){
	if (op_a_type == NOATK) return;
	if (op_a_type == ALL || op_a_type == type){
		hp -= max(d - defense, 0);
		if (state!=DIE && hp < 0){
			changeState(DIE);
		}
	}

}


void enemy::changeState(UnitState next_state){
	switch (next_state){
	case UnitState::MOV:
		state = next_state;
		ani_count = 0;
		switch (state){
		case ATK:
		//	wait_time = param->getParam(A_FREQ);
			wait_time = atk_freq;
			atk = false;
			break;
		}
		break;
	case UnitState::ATK:
		switch (state){
		case MOV:
			state = ATK;
			ani_count = 0;

			break;
		case WAIT:
			state = ATK;
			ani_count = 0;
			break;
		}
		break;
	case UnitState::WAIT:
		switch (state){
		case MOV:
			state = WAIT;
			break;
		case ATK:
			//	wait_time = param->getParam(A_FREQ);
			wait_time = atk_freq;
			atk = false;
			ani_count = 0;
			if (wait_time == 0){
				
				state = ATK;
			}
			else{
				state = WAIT;
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



