#include "enemy.h"
#include "Game.h"
enemy::enemy(int fx, int fy, int ln) :unit(fx, fy, ln){

}

void enemy::main(int front){
	unit::main();
	switch (state){
	case MOV:
		if (x < front + dist) state = ATK;
		break;
	case ATK:
		if (!(x < front + dist)) state = MOV;
		break;
	case DIE:
		
		break;
	}
}

void enemy::draw(int cx){

}

void enemy::del(){
	Game::getIns()->push_del_enemy(*(new shared_ptr<enemy>(this)));
}

void enemy::damage(int d){
	unit::damage(d);
	
}



