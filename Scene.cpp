#include "Scene.h"
#include "SceneManager.h"
#include "Game.h"
TitleScene::TitleScene(){
	LAY_Ptr p(new GraphicLayer(0,0,Images::get("pic/title.png")));
	addLayer(0,p);
	LAY_Ptr q((new ButtonLayer(300,200,Images::get("pic/start.png"),0,0,200,100))->setId("start"));
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
	PlaySoundMem(Images::getSound("sound/kuma.mp3"),DX_PLAYTYPE_LOOP);
}
void TitleScene::leaveScene(){
	StopSoundMem( Images::getSound("sound/kuma.mp3")) ;
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
	LAY_Ptr s((new ButtonLayer(500,350,Images::get("pic/right.png"),0,0,100,100))->setId("birth")->setClickType(ButtonLayer::PUSH));
	addLayer(1,s);
	LAY_Ptr t(new MapLayer(game));
	addLayer(5,t);
	addLayer(2,std::make_shared<MenuLayer>());
	/*
	addLayer(3,std::make_shared<MapBarLayer>());
	addLayer(4,std::make_shared<StatusLayer>());
	*/
	old_stage=1;
	
}
void GameScene::enterScene(){
	PlaySoundMem( Images::getSound("sound/kuma.mp3"),DX_PLAYTYPE_LOOP);
}
void GameScene::leaveScene(){
	StopSoundMem( Images::getSound("sound/kuma.mp3")) ;
}
void GameScene::buttonPushed(string id){
	if(id=="left"){
		game->scrollLeft(15);
	}else if(id=="right"){
		game->scrollRight(15);
	}else if(id=="birth"){
		game->birth(0, HOHEI);
	}
}
void GameScene::aftermain(){
	if(old_stage!=game->getNowStage()){
		LAY_Ptr q=std::make_shared<StageClearLayer>(old_stage,100);//((new ButtonLayer(0,0,0,0,0,50,450))->setId("left")->setClickType(ButtonLayer::ONMOUSE));
		addLayer(20,q);
	}
	old_stage=game->getNowStage();
}

std::shared_ptr<Game> GameScene::getGame(){return game;}