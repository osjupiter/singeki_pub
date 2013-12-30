#include "Layer.h"
#include "mouse.h"
#include "SceneNode.h"
#include"Game.h"
#include"Scene.h"
#include <sstream>

boolean Layer::testBox(int x1,int y1,int x2,int y2){
		mouse_in* m=mouse_in::getIns();
		if(x1<m->X() && y1<m->Y() && m->X()<x2 && m->Y()<y2)
			return true;
		return false;

}
void Layer::removeThis(){
	parentScene->rmLayer(shared_from_this());
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
	time=0;
	px=142;
	py=33;
	 tate=70,yoko=60;
}
void SelectLayer::called(){
	Images::playSE("sound/se_maoudamashii_system49.wav");
}
void SelectLayer::main(){
	
	mouse_in* m=mouse_in::getIns();

	int zahyoux[7]={0,0,yoko,yoko,0,-yoko,-yoko};
	int zahyouy[7]={-tate,0,-tate/2,tate/2,tate,tate/2,-tate/2};
	for(int i=0;i<7;i++){
		if(i==1)continue;
		int tmpx=x+73-px+zahyoux[i]*0.2*time;
		int tmpy=y+196-py+zahyouy[i]*0.2*time;
		if(testBox(tmpx-25,tmpy-25,tmpx+25,tmpy+25)){
			GameScene* p = dynamic_cast<GameScene*>( parentScene );
			if(p==NULL)break;
			auto game=p->getGame();
			string costman="";
			
			if(i!=0){
				stringstream ss;
				ss << "生産コスト:"<< game->getParam(i)->getParam(ParamType::COST);
				costman=ss.str();
			}
			if(m->isntOver()){parentScene->addLayer(18,std::make_shared<HoverLayer>(tmpx,tmpy,game->getUnitName(UnitType(i)),game->getUnitSummary(UnitType(i)),costman));}
			if(m->LeftClick()){
				p->getGame()->setProduct(id,i);
				parentScene->rmLayer(thisLayerID);
				parentScene->rmLayer(18);
				Images::playSE("sound/se_maoudamashii_system42.mp3");
			}
		}
	}


	
	int _tx=x+73-px,_ty=y+196-py;
	if(testBox(_tx-100,_ty-100,_tx+100,_ty+100)){
		m->recieveOver();
		if(m->LeftClick())
			m->Reset();
	}else{
		if(m->LeftClick()||m->isUsed())
			parentScene->rmLayer(thisLayerID);
	}
	
	
}
void SelectLayer::draw(){
	/*
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
		*/
	

	DrawRotaGraph(x+73-px,y+196-py,time*0.2,0,Images::get("pic/ユニット選択ウインドウ２.png"),TRUE);
	
	DrawGraph(x-px,y-py,Images::get("pic/ユニット選択ウインドウ.png"),TRUE);

	int zahyoux[7]={0,0,yoko,yoko,0,-yoko,-yoko};
	int zahyouy[7]={-tate,0,-tate/2,tate/2,tate,tate/2,-tate/2};
	for(int i=0;i<7;i++){
		if(i==1)continue;
		int tmpx=x+73-px+zahyoux[i]*0.2*time;
		int tmpy=y+196-py+zahyouy[i]*0.2*time;
		DrawRotaGraph(tmpx,tmpy,time*0.2,0,Images::getMusumeIcon(i,testBox(tmpx-25,tmpy-25,tmpx+25,tmpy+y)),TRUE);
		if(testBox(tmpx-25,tmpy-25,tmpx+25,tmpy+y)){
			;
		}
	}




	if(++time>=5)time=5;
    

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
		string s,n;
		switch(stage_id){
		case 1:
			s="sound/森.mp3";
			n="sound/夜戦.mp3";
			break;
		case 2:
			s="sound/夜戦.mp3";
			n="sound/橋.mp3";
			break;
		case 3:
			s="sound/橋.mp3";
			n="sound/草原.mp3";
			break;
		case 4:
			s="sound/草原.mp3";
			n="sound/洞窟.mp3";
			break;
		case 5:
			s="sound/洞窟.mp3";
			n="sound/都市.mp3";
			break;
		case 6:
			s="sound/都市.mp3";
			n="sound/闇の世界.mp3";
			break;
		case 7:
			s="sound/闇の世界.mp3";
			n="sound/エンディング.mp3";
			break;
		}
		Images::playBGM(s.c_str());
		Images::LoadSound(n);
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
		auto g=Game::getIns();
		g->setCamera(g->stage_W[g->getNowStage()]-WINDOW_X/2);
}
void GameClearLayer:: main(){
	if(remain_time--<=0){
		parentScene->rmLayer(thisLayerID);
		parentScene->buttonPushed("gotoEnd");
	}
}



GameOverLayer::GameOverLayer(){
		default_time=390;
		remain_time=default_time;
}
void GameOverLayer::draw(){
	//DrawFormatString(0,0,GetColor(0,255,0),"Game is overd. time = %d",remain_time);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA,128);
	DrawBox(0,0,WINDOW_X,WINDOW_Y,GetColor(0,0,0),TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND,0);
	DrawGraph(0,0,Images::get("pic/GAMEOVER.png"),TRUE);
}
void GameOverLayer::called(){
		Images::playBGM("");
		Images::playSE("sound/ゲームオーバー.mp3");
		auto g=Game::getIns();
		
		g->setCamera(g->stage_W[g->getNowStage()-1]-WINDOW_X/2);
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
	lx=306;ly=25;lw=440;lh=10;
	for(int i=0;i<8;i++){
		//xlist[i]=g->stage_W[i]/(double)g->stage_W[7]*lw+lx;
		xlist[i]=i/(double)8*lw+lx;
		ratelist[i]=1.0;
		onmouse[i]=0;
	}
	martop=15;

	mx=338;
	my=100;
	mw=375;
	mh=16;
	customon=0;

}
void MenuLayer::draw(){
	//status
	//DrawBox(0,0,150,50,GetColor(255,0,0),TRUE);
	//DrawGraph(0,0,Images::get("pic/SUI、オプション.png"),TRUE);



	//Menu

	//DrawGraph(0,0,Images::get("pic/MUI.png"),TRUE);
	DrawGraph(0,0,Images::get("pic/SUI.png"),TRUE);
	DrawGraph(0,0,Images::get("pic/まるなしMUI.png"),TRUE);



	DrawRotaGraph(13,13,0.5,0,Images::get("pic/資源.png"),TRUE);
	//DrawFormatString(25,0,GetColor(0,0,255),"%d",game->getResource());
	DrawFormatStringToHandle(20,0,GetColor(0,0,255),Images::getIns()->font,"%d",game->getResource());

	auto numberlist=game->getMusumeNumber();
	for(int i=static_cast<int>(UnitType::_HOHEI);i<static_cast<int>(UnitType::END_MUSUME);i++){
			DrawRotaGraph(5+60*((i-1)%3),30+((i-1)/3)*20,0.5,0,Images::getMusumeIcon(i),TRUE);
			//DrawFormatString(15+60*((i-1)%3)+10,30+((i-1)/3)*20,GetColor(0,255,0),"%d",numberlist.at(i));
			DrawFormatStringToHandle(15+60*((i-1)%3)+10,30+((i-1)/3)*20,GetColor(0,255,0),Images::getIns()->font,"%d",numberlist.at(i));
	}
	int margin=100;
	DrawRotaGraph(margin+40,13,0.5,0,Images::getMusumeIcon(1),TRUE);
	//DrawFormatString(margin+55,0,GetColor(0,0,255),"%d/%d",game->getMusumeSum(),game->getBirthLimit());
	DrawFormatStringToHandle(margin+55,0,GetColor(0,0,255),Images::getIns()->font,"%d/%d",game->getMusumeSum(),game->getBirthLimit());






	for(int i=0;i<8;i++){
		int _x=xlist[i];
		int _y=ly;
		int _w=25;
		double _rate=ratelist[i];
		if(game->getNowStage()>i){
			int tmp=( testBox(_x-_w,_y-_w,_x+_w,_y+_w))?Images::getSiroIcon(i,true):Images::getSiroIcon(i);
			//DrawRotaGraph(_x,_y,1,0,Images::get(("pic/MUIのステージのまる.png")),TRUE);
			DrawRotaGraph(_x,_y,_rate,0,tmp,TRUE);
			DrawRotaGraph(_x,_y+30,1.0,0,Images::getMusumeIcon(game->getProduct(i)),TRUE);
			//メーター
			double f=game->getProductCLKPAR(i);
			if(f!=0){
				DrawBox(_x-25,_y+55,_x-25+50,_y+60,GetColor(255,0,0),TRUE);
				DrawBox(_x-25,_y+55,_x-25+50*f,_y+60,GetColor(0,255,0),TRUE);
			}
		}else{
			//int tmp=Images::get("pic/tou.png");
			//DrawRotaGraph(_x,_y,_rate,0,tmp,TRUE);
		}
		
	}





	//map
	for(int i=0;i<=game->getNowStage();i++){
		int tmp=(i!=game->getNowStage())?Images::getSiroIcon(i):Images::get("pic/tou.png");
		int tmpx=game->stage_W[i]/(double)game->stage_W[game->getNowStage()]*mw+mx;
		DrawRotaGraph(tmpx,my,0.5,0,tmp,TRUE);
	}
	auto hoge=game->getDarkness();
	for(int i=0;i<3;i++){
		for(auto d:hoge.first[i]){
			int tmpx=d->getX()/(double)game->stage_W[game->getNowStage()]*mw+mx;
			DrawBox(tmpx-2,my-2,tmpx+2,my+2,GetColor(255,0,0),TRUE);
		}
		
	}
	for(int i=0;i<3;i++){
		for(auto d:hoge.second[i]){
			int tmpx=d->getX()/(double)game->stage_W[game->getNowStage()]*mw+mx;
			DrawBox(tmpx-2,my-2,tmpx+2,my+2,GetColor(255,255,255),TRUE);
		}
		
	} 
	int tmpman=game->getX()/(double)game->stage_W[game->getNowStage()]*mw+mx;
	int tmpman2=(game->getX()+WINDOW_X)/(double)game->stage_W[game->getNowStage()]*mw+mx;
	DrawBox(tmpman,my-mh,tmpman2,my+mh,GetColor(255,255,255),FALSE);


	//factory
	//DrawBox(221,62,221+66,62+60,GetColor(0,255,0),TRUE);
	DrawGraph(221-30,62-35,(testBox(221,62,221+66,62+60))?Images::get("pic/CUSTUMon.png"):Images::get("pic/CUSTUM.png"),TRUE);

	//option
	//DrawBox(130,50,130+60,50+20,GetColor(0,255,0),TRUE);


	
}
void MenuLayer:: main(){
	auto m= mouse_in::getIns();
	for(int i=0;i<8;i++)ratelist[i]=1.0;
	for(int i=0;i<8;i++){
		int _x=xlist[i];
		int _y=ly;
		int _w=25;
		ratelist[i]=1.0;
		if((game->getNowStage()>i)&& testBox(_x-_w,_y-_w,_x+_w,_y+_w)){
			
			if(onmouse[i]==0){Images::playSE("sound/button03a.mp3");onmouse[i]=1;}
			if(m->LeftClick()){

				m->Reset();
				parentScene->addLayer(3,make_shared<SelectLayer>(_x,_y+35,i));
			}
		}else{
			onmouse[i]=0;
		}
	}
	if(m->LeftClick()&&m->isntOver()){
		if(testBox(221,62,221+66,62+60)){
			GameScene* p = dynamic_cast<GameScene*>( parentScene );
			if( p != NULL )	p->addLayer(15,std::make_shared<PopFactoryLayer>(game));
			m->Reset();
		}/*else	if(testBox(130,50,130+60,50+20)){
			GameScene* p = dynamic_cast<GameScene*>( parentScene );
			if( p != NULL )	p->addLayer(15,std::make_shared<OptionLayer>());
			m->Reset();
		}*/else if(testBox(mx,my-mh,mx+mw,my+mh)){
			int targe=(m->X()-mx)/(double)mw*game->stage_W[game->getNowStage()];
			game->setCamera(targe-WINDOW_X/2);
			m->Reset();
		}
	}
	if(testBox(221,62,221+66,62+60)){
		if(customon==0){
			customon=1;
			Images::playSE("sound/button03a.mp3");
		}
	}else{
			customon=0;
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

PopFactoryLayer::PopFactoryLayer(shared_ptr<Game> g){
	x=100;
	y=100;
	time=0;
	px=28;
	py=49;
	tate=70,yoko=60;
	for(int i=0;i<10;i++)
		livelist[i]=false;
	game=g;



}
void PopFactoryLayer::called(){

	Images::playSE("sound/se_maoudamashii_system49.wav");
}
void PopFactoryLayer::draw(){
		

	//DrawRotaGraph(x+73-px,y+196-py,time*0.2,0,Images::get("pic/カスタム用大ウインドウ.png"),TRUE);
	
	DrawGraph(x-px,y-py,Images::get("pic/カスタム用大ウインドウ.png"),TRUE);

	int zahyoux[7]={0,0,yoko,yoko,0,-yoko,-yoko};
	int zahyouy[7]={-tate,-tate,-tate/2,tate/2,tate,tate/2,-tate/2};
	for(int i=1;i<7;i++){
		int tmpx=x+160-px+zahyoux[i]*0.2*time;
		int tmpy=y+180-py+zahyouy[i]*0.2*time;
		DrawRotaGraph(tmpx,tmpy,time*0.2,0,Images::get("pic/カスタム用小さな歯車.png"),TRUE);
		DrawRotaGraph(tmpx,tmpy,time*0.2,0,Images::getMusumeIcon(i,testBox(tmpx-25,tmpy-25,tmpx+25,tmpy+25)),TRUE);
		
		if(testBox(tmpx-25,tmpy-25,tmpx+25,tmpy+y)){
			;

		}
	}




	if(++time>=5)time=5;
    

	
}
void PopFactoryLayer:: main(){
		
	mouse_in* m=mouse_in::getIns();

	int zahyoux[7]={0,0,yoko,yoko,0,-yoko,-yoko};
	int zahyouy[7]={-tate,-tate,-tate/2,tate/2,tate,tate/2,-tate/2};
	for(int i=1;i<7;i++){
		int tmpx=x+160-px+zahyoux[i]*0.2*time;
		int tmpy=y+180-py+zahyouy[i]*0.2*time;
		if(testBox(tmpx-25,tmpy-25,tmpx+25,tmpy+25)&&!livelist[i]&&m->isntOver()){
			
			GameScene* p = dynamic_cast<GameScene*>( parentScene );
			if( p != NULL )
			{
				//p->getGame()->setProduct(id,i);
				p->addLayer(16,std::make_shared<ChipFactoryLayer>(game,tmpx,tmpy,i,&livelist[i]));
			}
		}
	}


	
	int _tx=x+160-px,_ty=y+180-py;
	if(testBox(_tx-100,_ty-100,_tx+100,_ty+100)){
		if(m->LeftClick())
			m->Reset();
	}else{
		if(m->LeftClick()&&m->isntOver()){
			parentScene->rmLayer(16);
			removeThis();
		}
			
	}
	

	
}





ChipFactoryLayer::ChipFactoryLayer(std::shared_ptr<Game> g,int _x,int _y,int _id,boolean* _live){
	x=_x;
	y=_y;
	id=_id;
	live=_live;
	*live=true;
	game=g;

	iconmarx=50;
	iconsx=30;
	timer=0;
	w=200;
	h=50;


}
void ChipFactoryLayer::draw(){
	int rectw=200*timer/5;
	DrawRectGraph(x+10,y-30,200-rectw,0,rectw,60,Images::get("pic/カスタム用小ウインドウ.png"),TRUE,FALSE);
	for(int i=0;i<3;i++){
		int hogex=x+rectw-iconsx-iconmarx*i;
		if(hogex<x)continue;
		DrawRotaGraph(hogex,y,1,0,Images::getParamTypeIcon( game->getRainForce(id)[i],testBox(hogex-25,y-25,hogex+25,y+25)),TRUE);
		DrawRectGraph(hogex,y-40,420/9*game->getParam(id)->getLevel(game->getRainForce(id)[i]),0,420/9,35,Images::get("pic/Lv.png"),TRUE,FALSE);
	}

	
}
void ChipFactoryLayer:: main(){
	auto m=mouse_in::getIns();


	int rectw=200*timer/5;
	for(int i=0;i<3;i++){
		int hogex=x+rectw-iconsx-iconmarx*i;
		if(hogex<x)continue;
		if(testBox(hogex-25,y-25,hogex+25,y+25)){
			stringstream ss;
			ss << "開発コスト:"<< game->getParam(id)->getCostForLevelUp(game->getRainForce(id)[i]);
			if(timer>=5&&m->isntOver()){
				hov[i]=std::make_shared<HoverLayer>(hogex,y,game->getParamName(game->getRainForce(id)[i]),game->getParamSummary(game->getRainForce(id)[i]),ss.str());
				parentScene->addLayer(18,hov[i]);
				
			}
			if(m->LeftClick()){
				if(game->incParamLevel(id,game->getRainForce(id)[i],game->getParam(id)->getCostForLevelUp(game->getRainForce(id)[i]))){
					m->Reset();
					//parentScene->rmLayer(18);
					stringstream ss2;
					Images::playSE("sound/se_maoudamashii_system39.mp3");
					ss2 << "開発コスト:"<< game->getParam(id)->getCostForLevelUp(game->getRainForce(id)[i]);
					hov[i]->setString(game->getParamName(game->getRainForce(id)[i]),game->getParamSummary(game->getRainForce(id)[i]),ss2.str());
					//parentScene->addLayer(18,std::make_shared<HoverLayer>(hogex,y,game->getParamName(game->getRainForce(id)[i]),game->getParamSummary(game->getRainForce(id)[i]),ss2.str()));
				}
			}
		}

	}
	if(testBox(x-25,y-25,x+10+w,y-25+h)){
		timer++;
		m->recieveOver();
	}else{
		timer--;
	}
	if(timer>=5)timer=5;
	if(timer<=0){removeThis();*live=false;}


	
}

HOHEILayer::HOHEILayer(shared_ptr<Game> g,int _x,int _y){
	x=_x;
	y=_y;
	timer=0;
	game=g;
	flag=0;
}
void HOHEILayer::draw(){
	//歩兵ボタン
	int need=game->getParam(static_cast<int>(UnitType::_HOHEI),ParamType::CLK);
	int tmph=56*(timer/(double)need);

	int bright=0;

	DrawBox(185,20,180+45,20+55,GetColor(0,127,127),TRUE);
	DrawRectGraph(x,y+69-tmph,0,69-tmph,80,tmph,Images::get("pic/歩兵ボタン2.png"),TRUE,FALSE);
	if(flag>0&&flag<21){
		DrawGraph(x,y,Images::get("pic/歩兵ボタン1m.png"),TRUE);
	}else{
		DrawGraph(x,y,Images::get("pic/歩兵ボタン1.png"),TRUE);	
	}


}
void HOHEILayer::main(){
	auto m=mouse_in::getIns();
	int need=game->getParam(static_cast<int>(UnitType::_HOHEI),ParamType::CLK);
	if(++timer>=need){timer=need;if(++flag>40)flag=0;}
	if(testBox(x+5,y+5,x+75,y+75)){
		m->recieveOver();
		if(m->LeftClick()&&(timer==need)){
			m->Reset();
			game->birth(game->getNowStage()-1, HOHEI);
			timer=0;
			flag=0;
			
				Images::playSE("sound/se_maoudamashii_system42.mp3");
		}
	}
}


HoverLayer::HoverLayer(int _x,int _y,string _m1,string _m2,string _m3){
	x=_x;
	y=_y;
	w=100,h=60;
	mes1=_m1;
	mes2=_m2;
	mes3=_m3;
	//if(y<WINDOW_Y/2)flag=1;
	//else flag=0;
	flag=0;

}
void HoverLayer::draw(){
	//DrawBox(x-25,y-25,x+25,y+25,GetColor(255,0,0),TRUE);
	int hogey=y-25-h;
	if(flag==1)hogey+=h+50;
	int hogex=x-25+10;

	DrawGraph(x-25-80,hogey-85,Images::get("pic/ポップアップウインドウ.png"),TRUE);
	DrawGraph(x-25-80,hogey-85,Images::get("pic/ポップアップ歯車.png"),TRUE);

	DrawFormatStringToHandle(hogex,hogey,GetColor(255,255,255),Images::getIns()->font,"%s",mes1.c_str());
	
	DrawFormatStringToHandle(hogex+10,hogey+15,GetColor(0,255,0),Images::getIns()->font,"%s",mes2.c_str());

	DrawFormatStringToHandle(hogex+10,hogey+30,GetColor(255,255,0),Images::getIns()->font,"%s",mes3.c_str());



}
void HoverLayer::called(){Images::playSE("sound/button03a.mp3");}
void HoverLayer::main(){
	if(testBox(x-25,y-25,x+25,y+25)){
		mouse_in::getIns()->recieveOver();
	}else{
		removeThis();
	}
}



void HoverLayer::setString(string m1,string m2,string m3){
		mes1=m1;
	mes2=m2;
	mes3=m3;
}