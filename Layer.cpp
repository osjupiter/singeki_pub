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
	_oldMouseisin=false;
}
void ButtonLayer::main(){
	mouse_in* m=mouse_in::getIns();
	if(x+bx<m->X()&&y+by<m->Y()&&m->X()<x+bx+bw&&m->Y()<y+by+bh){
		if(!_oldMouseisin)
			Images::playSE(_enterSE);
		if(_clicktype==ONMOUSE|| m->Left()==_clicktype){
			if(parentScene!=nullptr){parentScene->buttonPushed(id);Images::playSE(_clickSE);}
		}
		_oldMouseisin=true;
	}else{
		_oldMouseisin=false;
	}

}
ButtonLayer* ButtonLayer::setId(string s){
	id=s;return this;
}
ButtonLayer* ButtonLayer::setClickType(ClickFlag c){
	_clicktype=c;return this;	
}
//setEnterSE
ButtonLayer* ButtonLayer::setEnterSE(string s){
	_enterSE=s;return this;	
}
ButtonLayer* ButtonLayer::setClickSE(string s){
	_clickSE=s;return this;	
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
			int hoge=i+j*3;
			DrawGraph(x-75+50*i+5,y-75+50*j+5,Images::getMusumeIcon(hoge),TRUE);
			
		
		}
    

}

StageClearLayer::StageClearLayer(int sid,int d){
		stage_id=sid;
		data=d;
		default_time=150;
		remain_time=default_time;
}
void StageClearLayer::draw(){
	DrawFormatString(0,0,GetColor(255,0,0),"%d is cleard. time = %d",stage_id,remain_time);
	

}
void StageClearLayer:: main(){
	if(remain_time--<=0){
		string s;
		switch(stage_id){
		case 1:
			s="sound/森.mp3";
			break;
		case 2:
			s="sound/夜戦.mp3";
			break;
		case 3:
			s="sound/橋.mp3";
			break;
		case 4:
			s="sound/草原.mp3";
			break;
		case 5:
			s="sound/洞窟.mp3";
			break;
		case 6:
			s="sound/都市.mp3";
			break;
		case 7:
			s="sound/橋.mp3";
			break;
		}
		Images::playBGM(s.c_str());
		parentScene->rmLayer(thisLayerID);

	}
}


GameClearLayer::GameClearLayer(){
		default_time=150;
		remain_time=default_time;
}
void GameClearLayer::draw(){
	DrawFormatString(0,0,GetColor(0,255,0),"Game is cleard. time = %d",remain_time);
	

}
void GameClearLayer::called(){
		Images::playBGM("");
		Images::playSE("sound/エンディング.mp3");
}
void GameClearLayer:: main(){
	if(remain_time--<=0){
		parentScene->rmLayer(thisLayerID);

	}
}



GameOverLayer::GameOverLayer(){
		default_time=390;
		remain_time=default_time;
}
void GameOverLayer::draw(){
	DrawFormatString(0,0,GetColor(0,255,0),"Game is overd. time = %d",remain_time);
	

}
void GameOverLayer::called(){
		Images::playBGM("");
		Images::playSE("sound/ゲームオーバー.mp3");
}
void GameOverLayer:: main(){
	if(remain_time--<=0){
		parentScene->buttonPushed("exit");
		//parentScene->rmLayer(thisLayerID);

	}
}




MenuLayer::MenuLayer(shared_ptr<Game> g){
	for(int i=0;i<3;i++){
		onMouseTime[i]=0;
	}
	game=g;
	lx=275;ly=30;lw=500;lh=10;
	for(int i=0;i<9;i++){
		xlist[i]=g->stage_W[i]/(double)g->stage_W[8]*lw+lx;
		ratelist[i]=1.0;
	}
	martop=15;

}
void MenuLayer::draw(){
	//Menu

	DrawBox(lx,ly+martop,lx+lw,ly+lh+martop,GetColor(255,0,255),TRUE);
	for(int i=0;i<9;i++){
		int _x=xlist[i];
		int _y=ly;
		int _w=25;
		double _rate=ratelist[i];
		if(game->getNowStage()>i){
			int tmp=Images::getSiroIcon(i);
			DrawRotaGraph(_x,_y,_rate,0,tmp,TRUE);
			DrawRotaGraph(_x,_y+30,1.0,0,Images::getMusumeIcon(game->getProduct(i)),TRUE);
			//メーター
			double f=game->getProductCLKPAR(i);
			if(f!=0){
				DrawBox(_x-25,_y+55,_x-25+50,_y+60,GetColor(255,0,0),TRUE);
				DrawBox(_x-25,_y+55,_x-25+50*f,_y+60,GetColor(0,255,0),TRUE);
			}
		}else{
			int tmp=Images::get("pic/tou.png");
			DrawRotaGraph(_x,_y,_rate,0,tmp,TRUE);
		}
		
	}

	DrawBox(lx,100,lx+lw,100+5,GetColor(255,0,255),TRUE);
	for(int i=0;i<=game->getNowStage();i++){
		int tmp=(i!=game->getNowStage())?Images::getSiroIcon(i):Images::get("pic/tou.png");
		int tmpx=game->stage_W[i]/(double)game->stage_W[game->getNowStage()]*lw+lx;
		DrawRotaGraph(tmpx,100,0.5,0,tmp,TRUE);
	}
	auto hoge=game->getDarkness();
	for(int i=0;i<3;i++){
		for(auto d:hoge.first[i]){
			//int dndn=(d->getX()*lw/(double)STAGE8_W)+lx;
			int tmpx=d->getX()/(double)game->stage_W[game->getNowStage()]*lw+lx;
			DrawBox(tmpx-2,100,tmpx+2,104,GetColor(255,0,0),TRUE);
			//printfDx("ene->X=%d ans %lf  stage5 %d ans %lf\n",d->getX(),d->getX()/(double)game->stage_W[8]*lw+lx,game->stage_W[5],game->stage_W[5]/(double)game->stage_W[8]*lw+lx);
		}
		
	}
	for(int i=0;i<3;i++){
		for(auto d:hoge.second[i]){
			//int dndn=(d->getX()*lw/(double)STAGE8_W)+lx;
			int tmpx=d->getX()/(double)game->stage_W[game->getNowStage()]*lw+lx;
			DrawBox(tmpx-2,100,tmpx+2,104,GetColor(255,255,255),TRUE);
			//printfDx("ene->X=%d ans %lf  stage5 %d ans %lf\n",d->getX(),d->getX()/(double)game->stage_W[8]*lw+lx,game->stage_W[5],game->stage_W[5]/(double)game->stage_W[8]*lw+lx);
		}
		
	}


	//factory
	DrawBox(200,10,200+50,10+50,GetColor(0,255,0),TRUE);

	
	//option
	DrawBox(700,0,750,50,GetColor(0,255,0),TRUE);

	//status
	DrawBox(0,0,150,50,GetColor(255,0,0),TRUE);

	DrawRotaGraph(13,13,0.5,0,Images::get("pic/資源.png"),TRUE);
	DrawFormatString(25,0,GetColor(0,0,255),"%d",game->getResource());

	auto numberlist=game->getMusumeNumber();
	for(int i=static_cast<int>(UnitType::_HOHEI);i<static_cast<int>(UnitType::END_MUSUME);i++){
			DrawRotaGraph(5+40*((i-1)%3),20+((i-1)/3)*20,0.5,0,Images::getMusumeIcon(i),TRUE);
			DrawFormatString(15+40*((i-1)%3)+10,20+((i-1)/3)*20,GetColor(0,255,0),"%d",numberlist.at(i));
		
	}

	
	
}
void MenuLayer:: main(){
	auto m= mouse_in::getIns();
	for(int i=0;i<9;i++)ratelist[i]=1.0;
	for(int i=0;i<9;i++){
		int _x=xlist[i];
		int _y=ly;
		int _w=25;
		ratelist[i]=1.0;
		if((game->getNowStage()>i)&&_x-_w<m->X()&&_y-_w<m->Y()&&m->X()<_x+_w&&m->Y()<_y+_w){
			ratelist[i]=2.0;
			if(m->LeftClick()){
				m->Reset();
				parentScene->addLayer(11,make_shared<SelectLayer>(_x,_y+150,i));
			}
		}
	}
	if(m->LeftClick()){
		if(testBox(200,10,250,60)){
			GameScene* p = dynamic_cast<GameScene*>( parentScene );
			if( p != NULL )	p->addLayer(15,std::make_shared<FactoryLayer>(game));
			m->Reset();
		}else	if(testBox(700,0,750,50)){
			GameScene* p = dynamic_cast<GameScene*>( parentScene );
			if( p != NULL )	p->addLayer(15,std::make_shared<OptionLayer>());
			m->Reset();
		}else if(testBox(lx,100,lx+lw,100+5)){
			int targe=(m->X()-lx)/(double)lw*game->stage_W[game->getNowStage()];
			game->setCamera(targe);
		}
	}
	/*
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
						//p->addLayer(9,std::make_shared<MapCloseLayer>());
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
	*/
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
	

FactoryLayer::FactoryLayer(shared_ptr<Game> g){
	game=g;
	x=100;
	y=100;
	w=600;
	h=300;
	lxmar=30;
	lh=30;
	lw=50;
	lmartop=30;
	select=0;
}
void FactoryLayer::draw(){
	mouse_in* m=mouse_in::getIns();
	int x1=x,x2=x+w,y1=y,y2=y+h;
	DrawBox(x1,y1,x2,y2,GetColor(255,0,0),TRUE);
	DrawString(x1+200,y1,"開発・強化",GetColor(255,255,255),TRUE);
	for(int i=0;i<7;i++){
		DrawBox(x+lxmar,y+lmartop+i*lh,x+lxmar+lw,y+lmartop+(i+1)*lh,GetColor(255-i*30,128,0+i*40),TRUE);
		if(x+lxmar<m->X() && y+lmartop+i*lh<m->Y() && m->X()<x+lxmar+lw && m->Y()<y+lmartop+(i+1)*lh){
			SetDrawBlendMode( DX_BLENDMODE_ALPHA , 128 ) ;
			DrawBox(x+lxmar,y+lmartop+i*lh,x+lxmar+lw,y+lmartop+(i+1)*lh,GetColor(0,255,0),TRUE);
			SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
		}
		DrawRotaGraph(x+lxmar+lw/2,y+lmartop+i*lh+lh/2,0.5,0,Images::getMusumeIcon(i),TRUE);
	}
	int tmpx=x+lw+lxmar,tmpy=y+lmartop;
	DrawBox(x+lw+lxmar,y+lmartop,x+w-lxmar-lw,y+lmartop+h-50,GetColor(255-select*30,128,0+select*40),TRUE);

	DrawBox(tmpx+42,tmpy+10,tmpx+42+50,tmpy+10+50,GetColor(0,0,0),TRUE);
	DrawBox(tmpx+42+50+12,tmpy+10,tmpx+30+300,tmpy+10+50,GetColor(0,0,0),TRUE);

	for(int j=0;j<2;j++)
		for(int i=0;i<4;i++){
			int xx,yy,ww,hh;
			xx=tmpx+12*(i+1)+80*i+30;
			ww=80;
			yy=tmpy+70+90*j;
			hh=80;
			DrawBox(xx,yy,xx+ww,yy+hh,GetColor(0,0,0),TRUE);
			DrawGraph(xx,yy,Images::getParamTypeIcon((ParamType)(i+j*4)),TRUE);
			
		
		}
}

void FactoryLayer:: main(){
	mouse_in* m=mouse_in::getIns();
	int x1=x,x2=x+w,y1=y,y2=y+h;

	if( x1<m->X() && y1<m->Y() && m->X()<x2 && m->Y()<y2 ){
		if(m->LeftClick()){
			for(int i=0;i<7;i++){
				if(x+lxmar<m->X() && y+lmartop+i*lh<m->Y() && m->X()<x+lxmar+50 && m->Y()<y+lmartop+(i+1)*lh){
					select=i;
				}
			}
			int tmpx=x+lw+lxmar,tmpy=y+lmartop;
			for(int j=0;j<2;j++){
				for(int i=0;i<4;i++){
					int xx,yy,ww,hh;
					xx=tmpx+12*(i+1)+80*i+30;
					ww=80;
					yy=tmpy+70+90*j;
					hh=80;
					ParamType hoge=static_cast<ParamType>(j*4+i);
					if(testBox(xx,yy,xx+ww,yy+hh)){
						game->incParamLevel(select,hoge,50);
					}
				}
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