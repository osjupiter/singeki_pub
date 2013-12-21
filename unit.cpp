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
void unit::draw(int cx){
	//DrawCircle(x + width / 2 - cx, y + height / 2, width / 4, GetColor(255, 0, 0), true);
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

int unit::getType(){
	return type;
}

int unit::getAtkType(){
	return atk_type;
}
bool unit::getLife(){
	return life;
}

void unit::damage(int d,int op_a_type){
//	if (state == ATK){
		if (op_a_type == NONE || op_a_type == type){
			hp -= max(d - defense, 0);
			if (hp < 0){
				state = DIE;
			}
		}
//	}
}