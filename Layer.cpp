#include "Layer.h"
#include "mouse.h"
#include "SceneNode.h"
#include"Game.h"
#include"Scene.h"

boolean Layer::testBox(int x1,int y1,int x2,int y2){
		mouse_in* m=mouse_in::getIns();
		if(x1<m->X() && y1<m->Y() && m->X()<x2 && m->Y()<y2)
			return true;
		return false;

}

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
					m->Reset();
					parentScene->addLayer(11,make_shared<SelectLayer>(_x,_y-150,i));
				}
			}
		}
	}else{
		if(m->LeftClick()){
			parentScene->rmLayer(10);
			parentScene->rmLayer(9);
			m->Reset();
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
	w=75;h=75;
	id=_id;
}
void SelectLayer::main(){
	mouse_in* m=mouse_in::getIns();
	if(x-w<m->X()&&y-w<m->Y()&&m->X()<x+w&&m->Y()<y+w){
		if(m->LeftClick()){
			m->Reset();
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++){
					int x1,x2,y1,y2;
					x1=x-75+50*i+5;
					x2=x-75+50*i+50-5;
					y1=y-75+50*j+5;
					y2=y-75+50*j+50-5;
					if(x1<m->X() && y1<m->Y() && m->X()<x2 && m->Y()<y2){
							int number=i+j*3;
							
							GameScene* p = dynamic_cast<GameScene*>( parentScene );
							if( p != NULL )
							{
								p->getGame()->setProduct(id,number);

							}
							
					}

		
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
			string s;
			switch (i+j*3){
				case 0:
					s="なし";
					break;
				case 1:
					s="歩兵";
					break;
				case 2:
					s="風船";
					break;
				case 3:
					s="ロボ";
					break;
				case 4:
					s="カミカゼ";
					break;
				case 5:
					s="バズーカ";
					break;
				case 6:
					break;
				case 7:
					break;
				case 8:
					break;
				case 9:
					break;
			}
			DrawString(x-75+50*i+5,y-75+50*j+5,s.c_str(),GetColor(0,0,0));
			
		
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
		if(i==0) DrawString(x1,y1,"生産ユニット変更",GetColor(0,0,0));
		else if(i==1)DrawString(x1,y1,"強化・改造",GetColor(0,0,0));
		else if(i==2)DrawString(x1,y1,"設定",GetColor(0,0,0));
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
					case 1:
						p->addLayer(15,std::make_shared<FactoryLayer>());
						break;
					case 2:
						p->addLayer(20,std::make_shared<OptionLayer>());
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

//MapCloseLayer
MapCloseLayer::MapCloseLayer(){

}
void MapCloseLayer::draw(){
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 0 ) ;
	DrawBox(0,0,WINDOW_X,WINDOW_Y,GetColor(0,0,0),TRUE);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
}
void MapCloseLayer:: main(){

}
	

FactoryLayer::FactoryLayer(){
	x=100;
	y=100;
	w=600;
	h=300;
	lh=30;
	select=0;
}
void FactoryLayer::draw(){
	mouse_in* m=mouse_in::getIns();
	int x1=x,x2=x+w,y1=y,y2=y+h;
	DrawBox(x1,y1,x2,y2,GetColor(255,0,0),TRUE);
	for(int i=0;i<7;i++){
		DrawBox(x,y+5+i*lh,x+50,y+5+(i+1)*lh,GetColor(255-i*30,128,0+i*40),TRUE);
		if(x<m->X() && y+5+i*lh<m->Y() && m->X()<x+50 && m->Y()<y+5+(i+1)*lh){
			SetDrawBlendMode( DX_BLENDMODE_ALPHA , 128 ) ;
			DrawBox(x,y+5+i*lh,x+50,y+5+(i+1)*lh,GetColor(0,255,0),TRUE);
			SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
			

		}
	}

	DrawBox(x+50,y+5,x+w-50,y+5+h-50,GetColor(255-select*30,128,0+select*40),TRUE);
}
void FactoryLayer:: main(){
	mouse_in* m=mouse_in::getIns();
	int x1=x,x2=x+w,y1=y,y2=y+h;

	if( x1<m->X() && y1<m->Y() && m->X()<x2 && m->Y()<y2 ){
		
		for(int i=0;i<7;i++){
			if(m->LeftClick() && x<m->X() && y+5+i*lh<m->Y() && m->X()<x+50 && m->Y()<y+5+(i+1)*lh){
				select=i;
			}
		}
	
	}else{
		if(m->LeftClick()){
			parentScene->rmLayer(thisLayerID);
		}
	}
	
}



OptionLayer::OptionLayer(){
	x=100;
	y=100;
	w=600;
	h=300;

}
void OptionLayer::draw(){
	DrawBox(x,y,x+w,y+h,GetColor(255,0,0),TRUE);
	DrawBox(x+100,y+h-100,x+w-100,y+h-50,GetColor(255,255,0),TRUE);
	DrawString(x+100,y+h-100,"ゲームを終了する",GetColor(0,0,0));
}
void OptionLayer:: main(){
	mouse_in* m=mouse_in::getIns();
		if(testBox(x+100,y+h-100,x+w-100,y+h-50)){
			if(m->LeftClick())parentScene->buttonPushed("exit");
		}else{
			if(m->LeftClick())
				parentScene->rmLayer(thisLayerID);
		}
	
}