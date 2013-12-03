#include "Scene.h"
#include "SceneManager.h"
#include "Game.h"
TitleScene::TitleScene(){
	LAY_Ptr p(new ButtonLayer(0,0,Images::get("pic/title.png"),0,0,100,100));
	addLayer(0,p);
}
void TitleScene::buttonPushed(){
	SN_Ptr p(new GameScene());
	SceneManager::getIns()->switchScene(p);

}

GameScene::GameScene(){
	Game* g=new Game();
	g->birth(0, 360, HOHEI);
	LAY_Ptr p(g);
	addLayer(0,p);
}