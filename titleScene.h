#pragma once
#include<memory>
#include"DxLib.h"
#include"SceneNode.h"
#include"Images.h"
class TitleScene : public SceneNode{

public:
	TitleScene(){}
	void main(){
		clsDx();
		printfDx("Title\n");
		DrawGraph(0,0,Images::getIns()->gs[0],FALSE);
	}
	void init(){
		
	}
};