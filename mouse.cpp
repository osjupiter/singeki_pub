#include "DxLib.h"
#include "mouse.h"

mouse_in* mouse_in::getIns(){return &ins;}
	mouse_in::mouse_in(){
		x=0,y=0,l=0,r=0;
	}
	void mouse_in::input(){
		GetMousePoint(&x,&y);
		if( ( GetMouseInput() & MOUSE_INPUT_LEFT ) != 0 ){
			if(l==2||l==0)l=3;
			else l=1;
		}else{
			if(l!=0)l=2;
			else l=0;
		}
		if( ( GetMouseInput() & MOUSE_INPUT_RIGHT ) != 0 ){
			if(r==2||r==0)r=3;
			else r=1;
		}else{
			if(r!=0)r=2;
			else r=0;
		}
	}
	void mouse_in::Reset(){
		l=4;
		r=4;
	}
	int mouse_in::Left(){return l;}
	int mouse_in::Right(){return r;}
	int mouse_in::X(){return x;}
	int mouse_in::Y(){return y;}

mouse_in mouse_in::ins;