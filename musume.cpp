#include "musume.h"
#include "Game.h"

musume::musume(int fx, int fy, int ln, shared_ptr<Parameter> pm) :unit(fx, fy, ln){
	param = pm;
	dir = Direction::RIGHT;
	hp = param->getParam(MAXHP);
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
			state = WAIT;
			atk = false;
			break;
		}
		break;
	case UnitState::DIE:
		state = next_state;
		atk = false;
		break;
	}
}


void musume::del(){
	Game::getIns()->push_del_musume(*(new shared_ptr<musume>(this)));
}

void musume::damage(int d, Position op_a_type){
	if (op_a_type == NOATK) return;
	if (op_a_type == ALL || op_a_type == type){
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



