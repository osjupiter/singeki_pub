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
public:
	GameScene();
	void enterScene();
	void leaveScene();
	void aftermain();
	void buttonPushed(string);
	std::shared_ptr<Game> getGame();
};