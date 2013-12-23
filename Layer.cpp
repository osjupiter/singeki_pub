#include "Layer.h"
#include "mouse.h"
#include "SceneNode.h"
#include"Game.h"
#include"Scene.h"


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
MapLayer::MapLayer(std::shared_ptr<Game> g){
	lx=200;ly=200;lw=400;lh=200;
	for(int i=0;i<9;i++)
		xlist[i]=g->stage_W[i]/(double)g->stage_W[8]*lw+lx;

	

}
void MapLayer::main(){
	mouse_in* m=mouse_in::getIns();
	for(int i=0;i<9;i++)ratelist[i]=1.0;
	if(lx<m->X()&&ly<m->Y()&&m->X()<lx+lw&&m->Y()<ly+lh){
		for(int i=0;i<9;i++){
			int _x=xlist[i];
			int _y=ly+lh/2;
			int _w=25;
			ratelist[i]=1.0;
			if(_x-_w<m->X()&&_y-_w<m->Y()&&m->X()<_x+_w&&m->Y()<_y+_w){
				ratelist[i]=2.0;
				if(m->LeftClick()){
					printfDx("clickd!!!\n");
					m->Reset();
					parentScene->addLayer(11,make_shared<SelectLayer>(_x,_y-150,i));
				}
			}
		}
	}else{
		if(m->LeftClick()){
			parentScene->rmLayer(10);
			parentScene->rmLayer(9);
		}
	}
	
}
void MapLayer::draw(){
	DrawBox(lx,ly,lx+lw,ly+lh,GetColor(255,0,255),TRUE);
		for(int i=0;i<9;i++){
			int _x=xlist[i];
			int _y=ly+lh/2;
			int _w=25;
			double _rate=ratelist[i];
			DrawRotaGraph(_x,_y,_rate,0,Images::get("pic/tou.png"),TRUE);
		}	
    

}


SelectLayer::SelectLayer(int _x,int _y,int _id){
	x=_x;
	y=_y;
	w=100;h=100;
	id=_id;
}
void SelectLayer::main(){
	mouse_in* m=mouse_in::getIns();
		if(x-w<m->X()&&y-w<m->Y()&&m->X()<x+w&&m->Y()<y+w){
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++){
					int x1,x2,y1,y2;
					x1=x-75+50*i+5;
					x2=x-75+50*i+50-5;
					y1=y-75+50*j+5;
					y2=y-75+50*j+50-5;
					if(m->LeftClick()&&x1<m->X() && y1<m->Y() && m->X()<x2 && m->Y()<y2){
							int number=i+j*3;

							GameScene* p = dynamic_cast<GameScene*>( parentScene );
							if( p != NULL )
							{
								p->getGame()->setProduct(id,number);
								printfDx("%d %d\n",id,number);
							}
							//std::shared_ptr<GameScene> b2 = std::dynamic_pointer_cast<GameScene>(parentScene);
							
					}

		
				}
    

		}else{
			if(m->LeftClick()||m->RightClick()||m->isUsed())
				parentScene->rmLayer(thisLayerID);
		}
	
	
}
void SelectLayer::draw(){
	mouse_in* m=mouse_in::getIns();
	DrawBox(x-75,y-75,x+75,y+75,GetColor(255,0,0),TRUE);
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++){
			int x1,x2,y1,y2;
			x1=x-75+50*i+5;
			x2=x-75+50*i+50-5;
			y1=y-75+50*j+5;
			y2=y-75+50*j+50-5;
			DrawBox(x1,y1,x2,y2,GetColor(255,255,0),TRUE);
			if(x1<m->X() && y1<m->Y() && m->X()<x2 && m->Y()<y2){
				DrawBox(x-75+50*i+5,y-75+50*j+5,x-75+50*i+50-5,y-75+50*j+50-5,GetColor(0,255,0),TRUE);
			}
			
		
		}
    

}

StageClearLayer::StageClearLayer(int sid,int d){
		stage_id=sid;
		data=d;
		remain_time=150;
}
void StageClearLayer::draw(){
	DrawFormatString(0,0,GetColor(255,0,0),"%d is cleard. time = %d",stage_id,remain_time);
}
void StageClearLayer:: main(){
	if(remain_time--<=0)
		parentScene->rmLayer(thisLayerID);
	
}

MenuLayer::MenuLayer(shared_ptr<Game> g){
	for(int i=0;i<3;i++){
		onMouseTime[i]=0;
	}
	game=g;

}
void MenuLayer::draw(){
	//Menu
	DrawBox(650,0,800,100,GetColor(255,0,0),TRUE);

	for(int i=0;i<3;i++){
		int x1=650-onMouseTime[i],x2=800,y1=5+i*30,y2=35+i*30;
		DrawBox(x1,y1,x2,y2,GetColor(255,255,0),TRUE);	
	}
	//map
	DrawBox(250,20,550,40,GetColor(255,0,0),TRUE);

	//status
	DrawBox(0,0,200,50,GetColor(255,0,0),TRUE);
}
void MenuLayer:: main(){
	auto m= mouse_in::getIns();
	for(int i=0;i<3;i++){
		int x1=650,x2=800,y1=5+i*30,y2=35+i*30;
		if(x1<m->X() && y1<m->Y() && m->X()<x2 && m->Y()<y2){
			onMouseTime[i]+=10;
			if(onMouseTime[i]>50)onMouseTime[i]=50;
			if(m->LeftClick()){
				GameScene* p = dynamic_cast<GameScene*>( parentScene );
				if( p != NULL ){
					switch (i){
					case 0:
						p->addLayer(10,std::make_shared<MapLayer>(game));
						p->addLayer(9,std::make_shared<MapCloseLayer>());
						break;
					}
				}

			}
		}else{
			onMouseTime[i]-=10;
			if(onMouseTime[i]<0)onMouseTime[i]=0;
		}
	}
}
/*
MapBarLayer::MapBarLayer(){

}
void MapBarLayer::draw(){
	DrawBox(250,20,550,40,GetColor(255,0,0),TRUE);
}
void MapBarLayer:: main(){

}
	
//StatusLayer
StatusLayer::StatusLayer(){

}
void StatusLayer::draw(){
	DrawBox(0,0,200,50,GetColor(255,0,0),TRUE);
}
void StatusLayer:: main(){

}
*/
//MapCloseLayer
MapCloseLayer::MapCloseLayer(){

}
void MapCloseLayer::draw(){
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 128 ) ;
	DrawBox(0,0,WINDOW_X,WINDOW_Y,GetColor(0,0,0),TRUE);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
}
void MapCloseLayer:: main(){

}
	