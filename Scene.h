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
	void beforemain();
	void enterScene();
	void leaveScene();
	void aftermain();
	void buttonPushed(string);

	std::shared_ptr<Game> getGame();
};

class WorldScene : public SceneNode{

public:
	WorldScene();
	void buttonPushed(string);
	void enterScene();
	void leaveScene();

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
public:
	LoadingScene();
	void draw();
	void main();

};