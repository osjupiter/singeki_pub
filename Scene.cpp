#include "Scene.h"
#include "SceneManager.h"
TitleScene::TitleScene(){
	LAY_Ptr p(new ButtonLayer(0,0,Images::get("pic/title.png"),0,0,100,100));
	addLayer(0,p);
}
void TitleScene::buttonPushed(){
	SN_Ptr p(new GameScene());
	SceneManager::getIns()->switchScene(p);

}

GameScene::GameScene(){
		LAY_Ptr p(new GraphicLayer(0,0,Images::get("pic/game.png")));
		addLayer(0,p);
	}