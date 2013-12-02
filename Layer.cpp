#include "Layer.h"
#include "mouse.h"
#include "SceneNode.h"

GraphicLayer::GraphicLayer(int tx,int ty,int th){
	x=tx;y=ty;
	hundle=th;
}

void GraphicLayer::draw(){
	DrawGraph(x,y,hundle,TRUE);
}

ButtonLayer::ButtonLayer(int tx,int ty,int th,int ttx,int tty,int ttw,int tth):GraphicLayer(tx,ty,th){
	bx=ttx;
	by=tty;
	bw=ttw;
	bh=tth;
}
void ButtonLayer::main(){
	mouse_in* m=mouse_in::getIns();
	if(m->LeftClick()){
		if(x+bx<m->X(),y+by<m->Y(),m->X()<x+bx+bw,m->Y()<y+by+bh){
			if(parentScene!=nullptr)parentScene->buttonPushed();
		}
	}
}
void ButtonLayer::setId(string s){
	id=s;
}
