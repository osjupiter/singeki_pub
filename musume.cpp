#include "musume.h"
#include "Game.h"

musume::musume(int fx,int fy,int ln):unit(fx,fy,ln){
	
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

void musume::damage(int d,int op_a_type){
	unit::damage(d, op_a_type);
	if (state == DIE){
		vx = -rand()%80;
		vy = -30;
	}
	
}