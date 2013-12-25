#include "musume.h"
#include "Game.h"

musume::musume(int fx, int fy, int ln, shared_ptr<Parameter> pm) :unit(fx, fy, ln){
	param = pm;
	dir = Direction::RIGHT;
}

void musume::main(int front){
	unit::main();
	switch (state){
	case MOV:
		if (x > front - dist){ 
			state = ATK; 
			ani_count = 0;
		}
		break;
	case ATK:
		if (!(x > front - dist)) {
			state = MOV;
			ani_count = 0;
		}
		break;
	case DIE:
	
		break;
	}

	
	if (x > FIELD_W * 15) {
		life = false; }
}

void musume::draw(int cx){

}

void musume::del(){
	Game::getIns()->push_del_musume(*(new shared_ptr<musume>(this)));
}

void musume::damage(int d, Position op_a_type){
	if (op_a_type == ALL || op_a_type == type){
		hp -= max(d - param->getParam(DEFENSE), 0);
		if (hp < 0){
			state = DIE;
		}
	}

	if (state == DIE){
		vx = -rand()%80;
		vy = -30;
	}
	
}

int musume::getPower(){
	return param->getParam(POWER);
}
Position musume::getAtkType(){
	return (Position) param->getParam(A_TYPE);
}



