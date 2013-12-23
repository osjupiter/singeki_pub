#include "enemy.h"
#include "Game.h"
enemy::enemy(int fx, int fy, int ln,int lv) :unit(fx, fy, ln){
	level = lv;
}

void enemy::main(int front){
	unit::main();
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

void enemy::draw(int cx){
}

void enemy::del(){
	Game::getIns()->push_del_enemy(*(new shared_ptr<enemy>(this)));
	Game::getIns()->gainResource(cost);
}

void enemy::damage(int d,int op_a_type){
	unit::damage(d,op_a_type);
	
}



