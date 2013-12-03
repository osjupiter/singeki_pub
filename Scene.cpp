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
	printfDx("playsound\n");
	PlaySoundMem(Images::getIns()->sound[0],DX_PLAYTYPE_LOOP);
	printf("");
}
void TitleScene::leaveScene(){
	printfDx("stopsound\n");
	StopSoundMem( Images::getIns()->sound[0]) ;
}

GameScene::GameScene(){
	Game* g=new Game();
	g->birth(0, 360, HOHEI);
	LAY_Ptr p(g);
	addLayer(0,p);
}
void GameScene::enterScene(){
	printfDx("playsound\n");
	PlaySoundMem( Images::getIns()->sound[0],DX_PLAYTYPE_LOOP);
}
void GameScene::leaveScene(){
	printfDx("stopsound\n");
	StopSoundMem( Images::getIns()->sound[0]) ;
}