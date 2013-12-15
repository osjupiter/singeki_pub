#include "musume.h"
#include "Game.h"

musume::musume(int fx,int fy,int ln):unit(fx,fy,ln){
	
}

void musume::main(int front){
	unit::main();
	switch (state){
	case MOV:
		if (x > front - dist) state = ATK;
		break;
	case ATK:
		if (!(x > front - dist)) state = MOV;
		break;
	case DIE:
	
		break;
	}

	
	if (x > FIELD_W * 15) {
		life = false; }
}

void musume::draw(int cx){}

void musume::del(){
	Game::getIns()->push_del_musume(*(new shared_ptr<musume>(this)));
}

void musume::damage(int d){
	unit::damage(d);
	
}