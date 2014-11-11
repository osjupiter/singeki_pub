#include "unit.h"

unit::unit(int fx,int fy) : object(fx,fy){
	life = true;
	//line = 0;
	wait_time = 0;
	dist = (rand() / (RAND_MAX + 1.0)*180);
	ani_count = 0;
	state_change_flag = true;
}

void unit::main(){
	
	ani_count++;
}
void unit::draw(int cx){
	//DrawLine(x-cx,y+2,x+width-cx,y+2,GetColor(255,0,0),5);
	//DrawLine(x-cx, y+2, x+max((width)*hp/(maxhp*1.0),0)-cx, y+2, GetColor(0, 255, 0), 5);
	/*
	int dx = x + width/2 - 60/2;
	int dy= (type==RAND)? y+3:y+height-10;
	DrawLine(dx - cx, dy+3, dx+60-cx, dy+3, GetColor(255, 0, 0), 5);
	int i=hp;
	for ( int j = dx; i >1000; i -= 1000, j += 7){
		DrawLine(j - cx, dy+9, j-cx, dy+15, GetColor(0, 255, 0), 3);
		
	}

	DrawLine(dx - cx, dy+3, dx + 60 * max(i,0) / (1000 * 1.0) - cx, dy+3, GetColor(0, 255, 0), 5);
	*/
	//DrawBox(x - cx, y , x+width-cx,y+height ,GetColor(255, 0, 0), false);
}

int unit::getLine(){
	return line;
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
