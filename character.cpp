#include "character.h"
#include "difine.h"
character::character(int fx, int ln, UnitType u_type) : unit(fx, 0){	
//	int base_y = (pos == Position::RAND) ? WINDOW_Y - _height : 50;
	unit_type = u_type;
	
	state = UnitState::MOV;

//	y = base_y - ln * 5;
}

UnitState character::getState(){
	return state;
}

PropertyType character::getProperty(){
	return property;
}

void character::main(int front){
	unit::main();
	if (wait_time>0)
		wait_time--;
	decideDirection(front);

	switch (state){
	case UnitState::MOV:
		if (isInSight(front)){
			if (wait_time == 0)
				changeState(UnitState::ATK);
			else changeState(UnitState::WAIT);
		}
		break;
	case UnitState::ATK:
		if (!isInSight(front)){
			changeState(UnitState::MOV);
		}
		break;
	case UnitState::WAIT:
		if (!isInSight(front)) {
			changeState(UnitState::MOV);
		}
		else if (wait_time == 0){
			changeState(UnitState::ATK);
		}
		break;
	case UnitState::DIE:

		break;
	}
	
}

bool character::isInSight(int front){
	if (dir == LEFT){
		if (x < front + dist)
			return true;
		return false;
	}
	else{
		if (x + width > front - dist)
			return true;
		return false;
	}

}

void character::decideDirection(int front){
	if (((x + width <= front - dist) && dir == LEFT)
		|| ((x + width > front) && dir == RIGHT))
		switchDirection();
}