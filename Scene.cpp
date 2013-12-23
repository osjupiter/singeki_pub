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
	PlaySoundMem(Images::getIns()->sound[0],DX_PLAYTYPE_LOOP);
}
void TitleScene::leaveScene(){
	StopSoundMem( Images::getIns()->sound[0]) ;
}

GameScene::GameScene(){
	//g->birth(0, 360, HOHEI);
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
	
}
void GameScene::enterScene(){
	PlaySoundMem( Images::getIns()->sound[0],DX_PLAYTYPE_LOOP);
}
void GameScene::leaveScene(){
	StopSoundMem( Images::getIns()->sound[0]) ;
}
void GameScene::buttonPushed(string id){
	if(id=="left"){
		game->scrollLeft(15);
	}else if(id=="right"){
		game->scrollRight(15);
	}else if(id=="birth"){
		game->birth(0, HOHEI);
	}else if(id.find("select",0)!=string::npos)
		printfDx("%d\n",id[6]-'0');
}

std::shared_ptr<Game> GameScene::getGame(){return game;}