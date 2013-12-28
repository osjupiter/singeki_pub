#include "musume.h"
#include "Game.h"

musume::musume(int fx, int fy, int ln, shared_ptr<Parameter> pm) :unit(fx, fy, ln){
	param = pm;
	dir = Direction::RIGHT;
	hp = param->getParam(MAXHP);
	maxhp = hp;
	atk = false;
}

void musume::main(int front){
	unit::main();
	if (wait_time>0)
		wait_time--;
	switch (state){
	case UnitState::MOV:
		x += param->getParam(SPEED); //‚Æ‚è‚ ‚¦‚¸‰¡ˆÚ“®
		if (x > front - dist){
			if (wait_time==0)
				changeState(ATK);	
			else changeState(WAIT);
		}
		break;
	case UnitState::ATK:
		if (!(x > front - dist)) {
			changeState(MOV);
		}
		break;
	case UnitState::WAIT:
		if (!(x > front - dist)) {
			changeState(MOV);
		}
		
		else if (wait_time == 0){
			changeState(ATK);
		}
		break;
	case UnitState::DIE:
		y += vy;
		x += vx;
		vy -= 10;
		vx -= 5;
		if (y + height<0)
			del();
		break;
	}

	
	if (x > FIELD_W * 15) {
		life = false; }
}

void musume::draw(int cx){

}

void musume::changeState(UnitState next_state){
	switch (next_state){
	case UnitState::MOV:		
		ani_count = 0;
		switch (state){
		case ATK:
			wait_time = param->getParam(A_FREQ);
			atk = false;
			break;
		}
		state = next_state;
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
			wait_time = param->getParam(A_FREQ);	
			ani_count = 0;
			if (wait_time == 0)
				state = ATK;
			else 
				state = WAIT;

			atk = false;
			break;
		}
		break;
	case UnitState::DIE:
		state = next_state;
		atk = false;
		ani_count = 0;
		break;
	}
}


void musume::del(){
	//Game::getIns()->push_del_musume(*(new shared_ptr<musume>(this)));
	Game::getIns()->push_del_musume(shared_from_this());
}

void musume::damage(int d, Position op_a_type, UnitType op_unit_type){
	if (op_a_type == NOATK) return;
	if (op_a_type == ALL || op_a_type == type){
		if (rand() % 8==0){
			int rand_x = rand() % width/2, rand_y = rand() % height/2;
			switch (op_unit_type){
			case UnitType::_TANK:
				Game::getIns()->damage_effect_create(x-WID_CANNONSHOT/2+rand_x, y + height - HEI_CANNONSHOT +35-rand_y, CANNONSHOT);
				break;
			case UnitType::_GEKKO:
				Game::getIns()->damage_effect_create(x - WID_GUNSHOT / 2+rand_x, y + height - HEI_GUNSHOT+25 -rand_y, GUNSHOT, true);
				break;
			}
		}
		hp -= max(d - param->getParam(DEFENSE), 0);
		if (hp < 0){
			changeState(DIE);
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



