#include "Scene.h"
#include "SceneManager.h"
#include "Game.h"
#include "SoundController.h"
TitleScene::TitleScene(){
	LAY_Ptr p(new GraphicLayer(0,0,Images::get("pic/title.png")));
	addLayer(0,p);
	LAY_Ptr q((new ButtonLayer(0,0,Images::get(""),0,0,WINDOW_X,WINDOW_Y))->setId("start")->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
	addLayer(1,q);
	LAY_Ptr f((new ButtonLayer(0,0,Images::get(""),0,0,200,200))->setId("option")->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
	addLayer(1,f);
	

	
}
void TitleScene::buttonPushed(string id){
	if(id=="start"){
		SceneManager::getIns()->switchScene(std::make_shared<LoadingScene>(make_shared<WorldScene>()),0,5);
	}else if(id=="option"){
		LAY_Ptr q(new OptionLayer());
		addLayer(2,q);
	}else{
		DxLib_End() ;
		exit(0);
	}
}
void TitleScene::enterScene(){
	SoundController::getBgm()->playBGM("sound/システム/title.mp3");
}
void TitleScene::leaveScene(){
	SoundController::getBgm()->playBGM("");
}





WorldScene::WorldScene(){



	
}
void WorldScene::beforemain(){
	char Buf[ 256 ] ;
	GetHitKeyStateAll( Buf ) ;

	if( Buf[ KEY_INPUT_LEFT ] == 1 ||	 Buf[ KEY_INPUT_A ] == 1 )
	{
		moveX(50);
	}

	if( Buf[ KEY_INPUT_RIGHT ] == 1||  Buf[ KEY_INPUT_D ] == 1 )
	{
		moveX(-50);
	}

}
void WorldScene::buttonPushed(string id){
	if(id=="leftB"){
		moveX(50);
	}else if(id=="rightB"){
		moveX(-50);
	}else if(id.find("stage")!=string::npos){
		id.erase(0,5);
		addLayer(10,make_shared<MapUnitSelector>(stoi(id)));
	}else if(id=="gotogame"){
		Images::getIns()->loadStage(this->stage_id);
		SoundController::getBgm()->loadStage(this->stage_id);
		SceneManager::getIns()->switchScene(std::make_shared<LoadingScene>(make_shared<GameScene>(this->stage_id,this->unit_id)),0,5);
	}
}
void WorldScene::moveX(int dx){
	if(xpos+dx>=0){
		dx=-xpos;
	}
	if(xpos+dx<=WINDOW_X-2000){
		dx=WINDOW_X-2000-xpos;
	}

	for(auto gl:this->glist){
		gl->move(dx,0);
	}
	xpos+=dx;
}
template
<
    typename TYPE,
    std::size_t SIZE
>
std::size_t array_length(const TYPE (&)[SIZE])
{
    return SIZE;
}
void WorldScene::enterScene(){
	xpos=0;


{
	shared_ptr<GraphicLayer> p(new GraphicLayer (0,0,Images::get("pic/ワールドマップa.png")));
	addLayer(0,p);
	glist.push_back(p);
}
{
	shared_ptr<GraphicLayer> q(new MoveGraphLayer(0,0,Images::get("pic/ワールドマップb.png"),0,1,10,0));
	addLayer(1,q);
	glist.push_back(q);
}
{
	shared_ptr<GraphicLayer> r(new MoveGraphLayer(0,0,Images::get("pic/ワールドマップc.png"),72,1,10,0));
	addLayer(2,r);
	glist.push_back(r);
}
{
	shared_ptr<GraphicLayer> s(new MoveGraphLayer(0,0,Images::get("pic/ワールドマップd.png"),144,1,10,0));
	addLayer(3,s);
	glist.push_back(s);
}
{
	shared_ptr<GraphicLayer> s(new MoveGraphLayer(0,0,Images::get("pic/ワールドマップe.png"),216,1,10,0));
	addLayer(4,s);
	glist.push_back(s);
}
{
	shared_ptr<GraphicLayer> s(new MoveGraphLayer(0,0,Images::get("pic/ワールドマップf.png"),288,1,10,0));
	addLayer(5,s);
	glist.push_back(s);
}
{
	shared_ptr<GraphicLayer> s(new GraphicLayer(0,0,Images::get("pic/ワールドマップg.png")));
	addLayer(6,s);
	glist.push_back(s);
}

	for(int i=0;i<6;i++){
		this->unit_id[i]=1;
	}


	//移動用
	LAY_Ptr r((new ButtonLayer(0,0,Images::get(""),0,0,100,WINDOW_Y))->setId("leftB")->setClickType(ButtonLayer::ClickFlag::ONMOUSE));
	addLayer(9,r);
	LAY_Ptr s((new ButtonLayer(0,0,Images::get(""),WINDOW_X-100,0,100,WINDOW_Y))->setId("rightB")->setClickType(ButtonLayer::ClickFlag::ONMOUSE));
	addLayer(9,s);

	int tmp[6][2]={
		{76,288},{497,53},{817,330},{1125,44},{1286,277},{1600,222}
	};
	for(int i=1;i<=6;i++){
		if(Data::getIns()->get("stage")+1<i)break;
		shared_ptr<GraphicLayer> q((new ButtonLayer(tmp[i-1][0],tmp[i-1][1],Images::get("pic/world_stage.png"),0,0,275,98))->setId("stage"+to_string(i))->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
		addLayer(8,q); 
		glist.push_back(q);
		
		shared_ptr<GraphicLayer> w((new StringLayer(tmp[i-1][0]+110,tmp[i-1][1]+45,0,Images::getIns()->getStageName(i))));
		addLayer(8,w);
		glist.push_back(w);
	
	}
	
	SoundController::getBgm()->playBGM("sound/システム/stageselect.mp3");
}
void WorldScene::leaveScene(){
	SoundController::getBgm()->playBGM("");
}





int GameScene::unitids[6];
GameScene::GameScene(int _stage_id,int _unitids[]){
	stage_id=_stage_id;

	for(int i=0;i<6;i++){
		GameScene::unitids[i]=_unitids[i];
	}
	pauseState=0;
	std::shared_ptr<Game> p(new Game(stage_id));
	game=p;
	addLayer(0,p);
	LAY_Ptr q((new ButtonLayer(0,0,0,0,0,50,450))->setId("left")->setClickType(ButtonLayer::ONMOUSE));
	addLayer(1,q);
	LAY_Ptr r((new ButtonLayer(700,0,0,50,0,50,450))->setId("right")->setClickType(ButtonLayer::ONMOUSE));
	addLayer(1,r);

	addLayer(4,std::make_shared<MenuLayer>(game));
	addLayer(4,std::make_shared<HOHEILayer>(game,164,7));
	notEnd=true;
	old_stage=1;
	pauseNow=false;
}
void GameScene::enterScene(){
	SoundController::getBgm()->changeBGM(0);
}
void GameScene::leaveScene(){
	Images::getIns()->releaseStage();
	SoundController::getBgm()->playBGM("");
	SoundController::getBgm()->releaseStageBGM();
}
void GameScene::beforemain(){
	if(!notEnd)return;
	
	char Buf[ 256 ] ;
	GetHitKeyStateAll( Buf ) ;

	if(!pauseNow){

		if( Buf[ KEY_INPUT_LEFT ] == 1 ||	 Buf[ KEY_INPUT_A ] == 1 )
		{
			game->scrollLeft(15);
		}

		if( Buf[ KEY_INPUT_RIGHT ] == 1||  Buf[ KEY_INPUT_D ] == 1 )
		{
			game->scrollRight(15);
		}
	}


	if( Buf[ KEY_INPUT_ESCAPE ] == 1 ){
		if(pauseState==2||pauseState==0)pauseState=3;
		else pauseState=1;
	}else{
		if(pauseState==1||pauseState==3)pauseState=2;
		else pauseState=0;
	}
	if(pauseState==3){
		
		pause();
	}

}

void GameScene::pause(){
	game->turnPauseFlag();
	if(pauseNow){
		rmLayer(50);
	}else{
		addLayer(50,make_shared<PauseLayer>());
	}
	pauseNow=!pauseNow;
}
void GameScene::buttonPushed(string id){
	if(id=="left"){
		game->scrollLeft(15);
	}else if(id=="right"){
		game->scrollRight(15);
	}else if(id=="birth"){
		game->birth(0, HOHEI);
	}else if(id=="exit"){
		SceneManager::getIns()->switchScene(std::make_shared<WorldScene>());
	}else if(id=="gotoEnd"){
			int time=game->score_flame;
			if(Data::getIns()->get(to_string(stage_id))==0||time<Data::getIns()->get(to_string(stage_id))){
				Data::getIns()->set(to_string(stage_id),time);
			}
			if(stage_id>Data::getIns()->get("stage")){
				Data::getIns()->set("stage",stage_id);
			}
			Data::getIns()->Write();
		if(stage_id==6){
			SoundController::getIns()->getBgm()->LoadBGM("sound/システム/ending.mp3",true);
			SceneManager::getIns()->switchScene(make_shared<LoadingScene>((std::make_shared<EndScene>())));
		}else{
			SceneManager::getIns()->switchScene(make_shared<LoadingScene>((std::make_shared<WorldScene>())));
		}
	}else if(id=="pause"){
		pause();
	}
}
void GameScene::aftermain(){
	if(old_stage!=game->getNowStage()){
		LAY_Ptr q=std::make_shared<StageClearLayer>(old_stage,100);//((new ButtonLayer(0,0,0,0,0,50,450))->setId("left")->setClickType(ButtonLayer::ONMOUSE));
		addLayer(5,q);
	}
	if(notEnd&&game->isClear()){
		notEnd=false;
		addLayer(100,std::make_shared<GameClearLayer>());
	}
	if(notEnd&&game->isGameover()){
		notEnd=false;
		addLayer(100,std::make_shared<GameOverLayer>());
	}

	old_stage=game->getNowStage();
}

std::shared_ptr<Game> GameScene::getGame(){return game;}





EndScene::EndScene(){
	count=0;
	endc=0;
}
void EndScene::enterScene(){
	SoundController::getBgm()->playBGM("sound/システム/ending.mp3",false);
}
void EndScene::main(){
	count+=6;
	if(10400-WINDOW_X<=count){
		count=10400-WINDOW_X;
		endc++;
		if(endc>=60){
			SceneManager::getIns()->switchScene(std::make_shared<TitleScene>());
		}
	}
}
void EndScene::draw(){
	if(count<=5200)
		DrawRectGraph(0,0,count,0,WINDOW_X,WINDOW_Y,Images::get("pic/エンディング.png"),FALSE,FALSE);
	if(count>=5200-WINDOW_X)
		DrawRectGraph(0,0,count-5200,450,WINDOW_X,WINDOW_Y,Images::get("pic/エンディング.png"),FALSE,FALSE);

	
}

LogoScene::LogoScene(){
	count=0;

}
void LogoScene::draw(){
	int hage=Images::get("pic/定刻ぼるけーの.png");
	DrawGraph(0,0,hage,FALSE);
}
void LogoScene::main(){
	if(count++>60)
		SceneManager::getIns()->switchScene(make_shared<TitleScene>());
	DrawFormatString(0,0,GetColor(255,0,0),"%d",count);
}

LoadingScene::LoadingScene(SN_Ptr s){
	next=s;
}

void LoadingScene::main(){
	if(GetASyncLoadNum()==0){
		SoundController::getSE()->setting();
		SceneManager::getIns()->switchScene(next,0,5);
	}
}

void LoadingScene::draw(){
	DrawString(0,0,"Now Loading...",GetColor(255,255,255));
}
