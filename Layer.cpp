#include "Layer.h"
#include "mouse.h"
#include "SceneNode.h"
#include"Game.h"

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
	_clicktype=CLICK;
}
void ButtonLayer::main(){
	mouse_in* m=mouse_in::getIns();
	if(_clicktype==ONMOUSE|| m->Left()==_clicktype){
		if(x+bx<m->X()&&y+by<m->Y()&&m->X()<x+bx+bw&&m->Y()<y+by+bh){
			if(parentScene!=nullptr)parentScene->buttonPushed(id);
		}
	}
}
ButtonLayer* ButtonLayer::setId(string s){
	id=s;return this;
}
ButtonLayer* ButtonLayer::setClickType(ClickFlag c){
	_clicktype=c;return this;	
}
MapLayer::MapLayer(){}
void MapLayer::main(){
	
}
void MapLayer::draw(){
	DrawBox(100,439,700,440,GetColor(255,0,0),TRUE);

    mouse_in* m=mouse_in::getIns();
	for(int i=0;i<9;i++){
		int _x=game->stage_W[i]/(double)game->stage_W[8]*600+100;
		int _y=425;
		int _w=25;
		double _rate=1.0;
		if(_x-_w<m->X()&&_y-_w<m->Y()&&m->X()<_x+_w&&m->Y()<_y+_w){
			_rate=2.0;//+(35-sqrt((_x-m->X())*(_x-m->X())+(_y-m->Y())*(_y-m->Y())))*0.1;
		}
			
		
		DrawRotaGraph(_x,425,_rate,0,Images::get("pic/tou.png"),TRUE);
	}
    

}
void MapLayer::setGame(std::shared_ptr<Game> g){
	game=g;
	
}