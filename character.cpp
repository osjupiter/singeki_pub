#include "character.h"
#include "difine.h"
#include "Game.h"

character::character(int fx, int ln, UnitType u_type) : unit(fx, 0){	
//	int base_y = (pos == Position::RAND) ? WINDOW_Y - _height : 50;
	unit_type = u_type;
	atk = false;
	stopper = false;
	state = UnitState::MOV;
	no_die_flag = false;
	param = Game::getIns()->getParam(static_cast<int>(unit_type));
	no_damage_flag = false;
	visible = true;;

//	y = base_y - ln * 5;
}

UnitState character::getState(){
	return state;
}

PropertyType character::getProperty(){
	return property;
}

bool character::getAtk(){
	return atk;
};

void character::main(int front){
	atk = false;
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

void character::draw(int cx){

	//HP•\Ž¦
	if (state != UnitState::DIE){
		int dx = x + width / 2 - 60 / 2;
		int dy = (type == RAND || type == ALL) ? y + 3 : y + height - 10;
		DrawLine(dx - cx, dy + 3, dx + 60 - cx, dy + 3, GetColor(255, 0, 0), 5);
		int i = hp;
		for (int j = dx; i > 1000; i -= 1000, j += 7){
			DrawLine(j - cx, dy + 9, j - cx, dy + 15, GetColor(0, 255, 0), 3);

		}

		DrawLine(dx - cx, dy + 3, dx + 60 * max(i, 0) / (1000 * 1.0) - cx, dy + 3, GetColor(0, 255, 0), 5);
	}
}

void character::drawHP(int dx_,int cx, int ty){

	//HP•\Ž¦
	if (state != UnitState::DIE){
		int dx = dx_ + width / 2 - 60 / 2;
		int dy = ty;
		DrawLine(dx - cx, dy + 3, dx + 60 - cx, dy + 3, GetColor(255, 0, 0), 5);
		int i = hp;
		for (int j = dx; i > 1000; i -= 1000, j += 7){
			DrawLine(j - cx, dy + 9, j - cx, dy + 15, GetColor(0, 255, 0), 3);

		}

		DrawLine(dx - cx, dy + 3, dx + 60 * max(i, 0) / (1000 * 1.0) - cx, dy + 3, GetColor(0, 255, 0), 5);
	}
}

void character::drawBossHP(int dx_, int cx, int ty){

	//HP•\Ž¦
	if (state != UnitState::DIE){
		int dx = dx_ + width / 2 - 60 / 2;
		int dy = ty;
		DrawLine(dx - cx, dy + 3, dx + 60 - cx, dy + 3, GetColor(255, 0, 0), 5);
		int i = hp;
		for (int j = dx; i > 10000; i -= 10000, j += 7){
			DrawLine(j - cx, dy + 9, j - cx, dy + 15, GetColor(0, 255, 0), 3);

		}

		DrawLine(dx - cx, dy + 3, dx + 60 * max(i, 0) / (10000 * 1.0) - cx, dy + 3, GetColor(0, 255, 0), 5);
	}
}

void character::draw(int cx, int x, int y, int img){
	if((dir == LEFT && !isMusume()) || (dir == RIGHT && isMusume())){
		DrawGraph(x - cx, y, img, true);
	}
	else if ((dir == RIGHT && !isMusume()) || (dir == LEFT && isMusume())){
		DrawTurnGraph(x - cx, y, img, true);
	}
}

bool character::isMusume(){
	return (unit_type < END_MUSUME);
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