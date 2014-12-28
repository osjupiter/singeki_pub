#pragma once
#include<memory>
#include"DxLib.h"
#include"SceneNode.h"
#include"Images.h"
#include"Layer.h"
#include"Game.h"
class TitleScene : public SceneNode{

public:
	TitleScene();
	void buttonPushed(string);
	void enterScene();
	void leaveScene();

};

class GameScene : public SceneNode{
	
	std::shared_ptr<Game> game;
	int old_stage;
	boolean notEnd;
	int pauseState;
public:
	
	boolean pauseNow;
	static int unitids[6];
	GameScene(int,int[6]);
	void beforemain();
	void enterScene();
	void leaveScene();
	void aftermain();
	void buttonPushed(string);
	void pause();

	std::shared_ptr<Game> getGame();
};

class WorldScene : public SceneNode{
	list<shared_ptr<GraphicLayer>> glist;
	int xpos;
public:
	int stage_id;
	int unit_id[6];
	WorldScene();
	void beforemain();
	void buttonPushed(string);
	void enterScene();
	void leaveScene();
	void moveX(int);

};

class EndScene : public SceneNode{
	int count,endc;
public:
	EndScene();
	void draw();
	void main();
	void enterScene();

};

class LogoScene : public SceneNode{
	int count;
public:
	LogoScene();
	void draw();
	void main();

};


class LoadingScene : public SceneNode{
	int count;
	SN_Ptr next;
public:
	LoadingScene(SN_Ptr);
	void draw();
	void main();

};