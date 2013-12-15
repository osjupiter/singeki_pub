#include "unit.h"

unit::unit(int fx,int fy,int ln) : object(fx,fy){
	life = true;
	line = ln;
	state = MOV;
	
	dist = 100+(rand() / (RAND_MAX + 1.0)*180);
	ani_count = 0;
}

void unit::main(){
	
	ani_count++;
}
int unit::getLine(){
	return line;
}

int unit::getPower(){
	return power;
}

int unit::getState(){
	return state;
}

bool unit::getLife(){
	return life;
}

void unit::damage(int d){
	if (state == ATK){
		hp -= max(d-defense,0);
		if (hp < 0){ 
			state = DIE; 
		}
	}
}