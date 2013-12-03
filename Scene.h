#pragma once
#include<memory>
#include"DxLib.h"
#include"SceneNode.h"
#include"Images.h"
#include"Layer.h"
class TitleScene : public SceneNode{

public:
	TitleScene();
	void buttonPushed(string);
	void enterScene();
	void leaveScene();

};

class GameScene : public SceneNode{

public:
	GameScene();
	void enterScene();
	void leaveScene();

};