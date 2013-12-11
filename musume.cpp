#include "musume.h"

musume::musume(int fx,int fy,int ln):unit(fx,fy,ln){
	
}

void musume::main(int front){
	unit::main();
	if (x > front - dist) state = ATK;
	else state = MOV;
}
