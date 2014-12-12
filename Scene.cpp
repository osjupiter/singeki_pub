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
		SceneManager::getIns()->switchScene(std::make_shared<WorldScene>(),0,5);
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
	LAY_Ptr p(new GraphicLayer(0,0,Images::get("pic/world2.png")));
	addLayer(0,p);
	LAY_Ptr q((new ButtonLayer(0,0,Images::get(""),0,0,WINDOW_X,WINDOW_Y))->setId("start")->setEnterSE("sound/button03a.mp3")->setClickSE("sound/se_maoudamashii_system49.wav"));
	
	addLayer(1,q);

	
}
void WorldScene::buttonPushed(string id){
	if(id=="start"){
		SceneManager::getIns()->switchScene(std::make_shared<LoadingScene>(),0,5);
	}else if(id=="enter"){
		this->rmLayer(1);
	}else{
		DxLib_End() ;
		exit(0);
	}
}
void WorldScene::enterScene(){
	SoundController::getBgm()->playBGM("sound/タイトル.mp3");
}
void WorldScene::leaveScene(){
	SoundController::getBgm()->playBGM("");
}






GameScene::GameScene(){
	std::shared_ptr<Game> p(new Game());
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


LoadingScene::LoadingScene(){

}
void LoadingScene::main(){
	if(GetASyncLoadNum()==0){
		SoundController::getSE()->setting();
		SceneManager::getIns()->switchScene(make_shared<GameScene>(),0,5);
	}
}
void LoadingScene::draw(){
	DrawString(0,0,"Now Loading...",GetColor(255,255,255));
}
