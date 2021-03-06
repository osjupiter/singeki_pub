#include "enemy.h"
#include "Game.h"
#include "iostream"
enemy::enemy(int fx, int ln, int lv , UnitType u_type) :character(fx, ln, u_type){
	level = lv;
	dir = Direction::LEFT;
	atk = false;

	hp = param->getParamMag(MAXHP, lv);
	speed = param->getParamMag(SPEED, lv);
	power = param->getParamMag(POWER, lv);
	defense = param->getParamMag(DEFENSE, lv);
	type = RAND;
	atk_type = static_cast<Position> (param->getParam(A_TYPE));
	cost = param->getParamMag(COST, lv);
	atk_freq = param->getParamMag(A_FREQ, lv);
	maxhp = hp;

}

void enemy::main(int front){
	switch (state){
	case UnitState::MOV:
//		wait_time = atk_freq;

		break;
	}
	character::main(front);
}

void enemy::draw(int cx){
	character::draw(cx);
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
	if (no_damage_flag) return;
	if (op_a_type == NOATK) return;
	if (op_a_type == ALL || op_a_type == type || type ==ALL){
		if (rand() % 30 == 0){		
			int rand_x = rand() % width / 2, rand_y = rand() % height / 2;
			switch (op_unit_type){
			case UnitType::_BAZOOKA:
				Game::getIns()->damage_effect_create(x + width /3+rand_x, y + height - HEI_CANNONSHOT+35-rand_y, CANNONSHOT, true);
				break;
			case UnitType::_HOHEI:
			case UnitType::_IKAROS:
				Game::getIns()->damage_effect_create(x + width / 3+rand_x, y + height - HEI_GUNSHOT+25-rand_y, GUNSHOT);
				break;
			case UnitType::_HIME:
				Game::getIns()->damage_effect_create(x + rand_x, y + height - HEI_ZANGEKI + 25 - rand_y, ZANGEKI);
				break;

			}
		}
		if (d > 0){
			hp -= max(d - defense, 1);
		}
//		printfDx("%d %d\n",op_unit_type, d - defense);
		if (state != UnitState::DIE && hp < 0){
			changeState(UnitState::DIE);
		}
	}

}


void enemy::changeState(UnitState next_state){
	if (state == UnitState::DIE)return;
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
		state = UnitState::ATK;
		ani_count = 0;
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
		default:
			state = next_state;

			break;
			
		}

		break;
	case UnitState::DIE:
		if (no_die_flag) return;
		state = next_state;
		ani_count = 0;
		atk = false;
		state_change_flag = false;
		break;
	default:
		if (state == UnitState::ATK)
			wait_time = atk_freq;
		state = next_state;
		ani_count = 0;

		break;
	}
	ani_count = 0;
}


Position enemy::decideTargetPos(int target_x_rand, int target_x_sky){
	Position ret;
	switch (atk_type){
	case ALL:
		if (dir == RIGHT){
			if (abs(x-target_x_rand) <= abs(x-target_x_sky)) ret = RAND;
			else ret = SKY;
		}
		else {
			if (abs(x-target_x_rand) <= abs(x-target_x_sky)) ret = RAND;
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

void enemy::drawWait(int dx_, int cx, int ty){
	character::drawWait(dx_, cx, ty, atk_freq);
	/*
	//攻撃待機時間表示
	if (state != UnitState::DIE){
		int dx = dx_ + width / 2 - 60 / 2;
		int dy = ty;
		DrawLine(dx - cx, dy + 3, dx + 60 - cx, dy + 3, GetColor(205, 149, 12), 5);
		int i = wait_time;
		DrawLine(dx - cx, dy + 3, dx + 60 * max(i, 0) / (freq * 1.0) - cx, dy + 3, GetColor(139, 101, 8), 5);
	}
	*/
}


void enemy::decideDirection(int front){
	/*
	if (((x + width <= front) && dir == LEFT)
		|| ((x + width > front) && dir == RIGHT))
		switchDirection();
		*/
	if (x + width <= front)  dir = RIGHT;
	else if (x > front)dir = LEFT;
}