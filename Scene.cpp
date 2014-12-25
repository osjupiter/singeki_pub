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
	SoundController::getBgm()->playBGM("sound/タイトル.mp3");
}
void TitleScene::leaveScene(){
	SoundController::getBgm()->playBGM("");
}





WorldScene::WorldScene(){



	
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
		
		SceneManager::getIns()->switchScene(std::make_shared<LoadingScene>(make_shared<GameScene>(this->stage_id,this->unit_id)),0,5);
	}
}
void WorldScene::moveX(int dx){
	if(xpos+dx>=0){
		dx=-xpos;
	}
	if(xpos+dx<=WINDOW_X-2400){
		dx=WINDOW_X-2400-xpos;
	}

	for(auto gl:this->glist){
		gl->move(dx,0);
	}
	xpos+=dx;
}
void WorldScene::enterScene(){
	xpos=0;
	//背景
	shared_ptr<GraphicLayer> p(new GraphicLayer(0,0,Images::get("pic/world2.png")));
	addLayer(0,p);
	glist.push_back(p);


	//移動用
	LAY_Ptr r((new ButtonLayer(0,0,Images::get(""),0,0,100,WINDOW_Y))->setId("leftB")->setClickType(ButtonLayer::ClickFlag::ONMOUSE));
	addLayer(9,r);
	LAY_Ptr s((new ButtonLayer(0,0,Images::get(""),WINDOW_X-100,0,100,WINDOW_Y))->setId("rightB")->setClickType(ButtonLayer::ClickFlag::ONMOUSE));
	addLayer(9,s);
	
	//歩兵ボタン3.png
	//ステージへ
	{
		shared_ptr<GraphicLayer> q((new ButtonLayer(76,288,Images::get("pic/world_icon.png"),0,0,70,70))->setId("stage1")->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
		addLayer(1,q);
		glist.push_back(q);
	}
	{
		shared_ptr<GraphicLayer> q((new ButtonLayer(497,53,Images::get("pic/world_icon.png"),0,0,70,70))->setId("stage2")->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
		addLayer(1,q);
		glist.push_back(q);
	}
	{
		shared_ptr<GraphicLayer> q((new ButtonLayer(817,360,Images::get("pic/world_icon.png"),0,0,70,70))->setId("stage3")->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
		addLayer(1,q);
		glist.push_back(q);
	}
	{
		shared_ptr<GraphicLayer> q((new ButtonLayer(1125,94,Images::get("pic/world_icon.png"),0,0,70,70))->setId("stage4")->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
		addLayer(1,q);
		glist.push_back(q);
	}
	{
		shared_ptr<GraphicLayer> q((new ButtonLayer(1286,337,Images::get("pic/world_icon.png"),0,0,70,70))->setId("stage5")->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
		addLayer(1,q);
		glist.push_back(q);
	}
	{
		shared_ptr<GraphicLayer> q((new ButtonLayer(1600,222,Images::get("pic/world_icon.png"),0,0,70,70))->setId("stage6")->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
		addLayer(1,q);
		glist.push_back(q);
	}
	SoundController::getBgm()->playBGM("sound/タイトル.mp3");
}
void WorldScene::leaveScene(){
	SoundController::getBgm()->playBGM("");
}






GameScene::GameScene(int stage_id,int unitids[]){
	printfDx("%d",stage_id);
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
	
}
void GameScene::enterScene(){
	//PlaySoundMem( Images::getSound("sound/kuma.mp3"),DX_PLAYTYPE_LOOP);
	//SoundController::getBgm()->playBGM("sound/山.mp3");
	SoundController::getBgm()->changeBGM(0);
}
void GameScene::leaveScene(){
	//StopSoundMem( Images::getSound("sound/kuma.mp3")) ;
	SoundController::getBgm()->playBGM("");
}
void GameScene::beforemain(){
	char Buf[ 256 ] ;
	GetHitKeyStateAll( Buf ) ;

	if( Buf[ KEY_INPUT_LEFT ] == 1 ||	 Buf[ KEY_INPUT_A ] == 1 )
	{
		game->scrollLeft(15);
	}

	if( Buf[ KEY_INPUT_RIGHT ] == 1||  Buf[ KEY_INPUT_D ] == 1 )
	{
		game->scrollRight(15);
	}



	if( Buf[ KEY_INPUT_ESCAPE ] == 1 ){
		if(pauseState==2||pauseState==0)pauseState=3;
		else pauseState=1;
	}else{
		if(pauseState==1||pauseState==3)pauseState=2;
		else pauseState=0;
	}
	if(pauseState==3)game->turnPauseFlag();

}
void GameScene::buttonPushed(string id){
	if(id=="left"){
		game->scrollLeft(15);
	}else if(id=="right"){
		game->scrollRight(15);
	}else if(id=="birth"){
		game->birth(0, HOHEI);
	}else if(id=="exit"){
		SceneManager::getIns()->switchScene(std::make_shared<TitleScene>());
	}else if(id=="gotoEnd"){
		SceneManager::getIns()->switchScene(std::make_shared<EndScene>());
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
	SoundController::getBgm()->playBGM("sound/エンディング.mp3",false);
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
