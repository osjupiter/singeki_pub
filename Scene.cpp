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
		SceneManager::getIns()->switchScene(std::make_shared<GameScene>());
	}else{
		DxLib_End() ;
		exit(0);
	}
}
void TitleScene::enterScene(){
	Images::playBGM("sound/�^�C�g��.mp3");
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
	addLayer(4,std::make_shared<HOHEILayer>(game,164,7));
	//addLayer(10,std::make_shared<MapLayer>(game));
	notEnd=true;
	old_stage=1;
	
}
void GameScene::enterScene(){
	//PlaySoundMem( Images::getSound("sound/kuma.mp3"),DX_PLAYTYPE_LOOP);
	Images::playBGM("sound/�R.mp3");
}
void GameScene::leaveScene(){
	//StopSoundMem( Images::getSound("sound/kuma.mp3")) ;
	Images::playBGM("");
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
	Images::playBGM("sound/�G���f�B���O.mp3",false);
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
		DrawRectGraph(0,0,count,0,WINDOW_X,WINDOW_Y,Images::get("pic/�G���f�B���O.png"),FALSE,FALSE);
	if(count>=5200-WINDOW_X)
		DrawRectGraph(0,0,count-5200,450,WINDOW_X,WINDOW_Y,Images::get("pic/�G���f�B���O.png"),FALSE,FALSE);

	
}