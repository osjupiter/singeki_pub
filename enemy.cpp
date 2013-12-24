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

}

int enemy::getPower(){
	return 0;
}
int enemy::getAtkType(){
	return 0;
}
void enemy::damage(int d, int op_a_type){
	
}




