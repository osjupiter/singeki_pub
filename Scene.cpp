#include "Scene.h"
#include "SceneManager.h"
#include "Game.h"
TitleScene::TitleScene(){
	LAY_Ptr p(new GraphicLayer(0,0,Images::get("pic/title.png")));
	addLayer(0,p);
	LAY_Ptr q((new ButtonLayer(300,200,Images::get("pic/start.png"),0,0,200,100))->setId("start")->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
	addLayer(1,q);
	LAY_Ptr r(new ButtonLayer(300,350,Images::get("pic/exit.png"),0,0,200,100));
	addLayer(1,r);
	
}
void TitleScene::buttonPushed(string id){
	if(id=="start"){
		SN_Ptr p(new GameScene());
		SceneManager::getIns()->switchScene(p);
	}else{
		DxLib_End() ;
		exit(0);
	}
}
void TitleScene::enterScene(){
	Images::playBGM("sound/ŽR.mp3");
}
void TitleScene::leaveScene(){
	Images::playBGM("");
}

GameScene::GameScene(){
	std::shared_ptr<Game> p(new Game());
	game=p;
	addLayer(0,p);
	//"pic/left.png"
	LAY_Ptr q((new ButtonLayer(0,0,0,0,0,50,450))->setId("left")->setClickType(ButtonLayer::ONMOUSE));
	addLayer(1,q);
	LAY_Ptr r((new ButtonLayer(700,0,0,50,0,50,450))->setId("right")->setClickType(ButtonLayer::ONMOUSE));
	addLayer(1,r);

	//addLayer(5,std::make_shared<MapLayer>(game));
	addLayer(4,std::make_shared<MenuLayer>(game));
	//addLayer(10,std::make_shared<MapLayer>(game));
	notEnd=true;
	old_stage=1;
	
}
void GameScene::enterScene(){
	//PlaySoundMem( Images::getSound("sound/kuma.mp3"),DX_PLAYTYPE_LOOP);
	Images::playBGM("sound/ŽR.mp3");
}
void GameScene::leaveScene(){
	//StopSoundMem( Images::getSound("sound/kuma.mp3")) ;
	Images::playBGM("");
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