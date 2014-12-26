#include "DxLib.h"
#include "mouse.h"

mouse_in* mouse_in::getIns(){return &ins;}
	mouse_in::mouse_in(){
		x=0,y=0,l=0,r=0,over=false;
	}
	void mouse_in::input(){
		over=false;
		GetMousePoint(&x,&y);
		if( ( GetMouseInput() & MOUSE_INPUT_LEFT ) != 0 ){
			if(l==2||l==0)l=3;
			else l=1;
		}else{
			if(l==1||l==3)l=2;
			else l=0;
		}
		if( ( GetMouseInput() & MOUSE_INPUT_RIGHT ) != 0 ){
			if(r==2||r==0)r=3;
			else r=1;
		}else{
			if(r==1||r==3)r=2;
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

	void mouse_in::recieveOver(){over=true;}

	
	boolean mouse_in::isUsed(){return (l==4||r==4);}
	boolean mouse_in::LeftPush(){return this->isntOver()&&(l==3||l==1);}
	boolean mouse_in::LeftClick(){return this->isntOver()&&l==3;}
	boolean mouse_in::LeftClick(boolean f){return (!f||this->isntOver())&&l==3;}
	boolean mouse_in::LeftLeave(){return this->isntOver()&&l==2;}

	boolean mouse_in::RightPush(){return this->isntOver()&&(r==3||r==1);}
	boolean mouse_in::RightClick(){return this->isntOver()&&r==3;}
	boolean mouse_in::RightLeave(){return this->isntOver()&&r==2;}
	
	boolean mouse_in::isntOver(){return !over;}

	boolean mouse_in::testBox(int x1,int y1,int x2,int y2){
		mouse_in* m=mouse_in::getIns();
		if(x1<m->X() && y1<m->Y() && m->X()<x2 && m->Y()<y2)
			return true;
		return false;
	}

	


mouse_in mouse_in::ins;