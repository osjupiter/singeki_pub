#include "unit.h"

unit::unit(int fx,int fy,int ln) : object(fx,fy){
	life = true;
	line = ln;
	state = MOV;
	wait_time = 0;
	dist = (rand() / (RAND_MAX + 1.0)*180);
	ani_count = 0;
}

void unit::main(){
	
	ani_count++;
}
void unit::draw(int cx){
	DrawLine(x-cx,y+2,x+width-cx,y,GetColor(255,0,0),5);
	DrawLine(x-cx, y+2, x+max((width)*hp/(maxhp*1.0),0)-cx, y, GetColor(0, 255, 0), 5);
	//DrawBox(x - cx, y , x+width-cx,y+height ,GetColor(255, 0, 0), false);
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

UnitType unit::getUnitType(){return unit_type;}
