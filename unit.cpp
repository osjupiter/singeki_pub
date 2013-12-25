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

	DrawBox(x - cx, y , x+width-cx,y+height ,GetColor(255, 0, 0), false);
}

int unit::getLine(){
	return line;
}


int unit::getState(){
	return state;
}

Position unit::getType(){
	return type;
}


bool unit::getLife(){
	return life;
}


void unit::switchDirection(){
	if (dir == LEFT)
		dir = RIGHT;
	else if (dir == RIGHT)
		dir = LEFT;
}