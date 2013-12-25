#include "enemy.h"
#include "Game.h"
enemy::enemy(int fx, int fy, int ln,int lv) :unit(fx, fy, ln){
	level = lv;
	dir = Direction::LEFT;
}

void enemy::main(int front){
	unit::main();
	if (dir == LEFT){
		if (x <= front - dist)
			switchDirection();
		switch (state){
		case MOV:
			if (x < front + dist){
				state = ATK;
				ani_count = 0;
			}
			break;
		case ATK:
			if (!(x < front + dist)){
				state = MOV;
				ani_count = 0;
			}
			break;
		case DIE:

			break;
		}
	}
	else if (dir == RIGHT){
		if (x > front + dist)
			switchDirection();
		
		switch (state){
		case MOV:
			if (x+width > front - dist){
				state = ATK;
				ani_count = 0;
			}
			break;
		case ATK:
			if (!(x + width > front - dist)){
				state = MOV;
				ani_count = 0;
			}
			break;
		case DIE:

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
	return power;
}
Position enemy::getAtkType(){
	return atk_type;
}
void enemy::damage(int d, Position op_a_type){
	if (op_a_type == ALL || op_a_type == type){
		hp -= max(d - defense, 0);
		if (hp < 0){
			state = DIE;
		}
	}

}




