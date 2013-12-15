#include "DxLib.h"
#include "Images.h"
#include "effect.h"
#include "GV.h"


effect::effect(int fx,int fy):object(fx,fy){
	
	ani_count=0;
}


void effect::main(){
	ani_count++;
}


void effect::draw(int cx){
	
}

