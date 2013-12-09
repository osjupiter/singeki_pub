#include "unit.h"

unit::unit(int fx,int fy,int ln) : object(fx,fy){
	life = true;
	line = ln;
	dist = rand() / (RAND_MAX + 1.0)*WID_HOHEI * 2;
	ani_count = 0;
}

void unit::main(){
	ani_count++;
}
int unit::getLine(){
	return line;
}

bool unit::getLife(){
	return life;
}
