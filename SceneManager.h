#pragma once
#include"DxLib.h"
#include<vector>
#include<list>
#include"SceneNode.h"
#include <memory>
#include<algorithm>
#include"titleScene.h"


class SceneManager
{
	static SceneManager ins;
	SN_Ptr nowScene;


public:
	SceneManager(void){}

	static SceneManager* getIns(){return &ins;}

	void loop(){
		nowScene->main();
		nowScene->draw();
	}

	void title(){
		SN_Ptr p(new TitleScene());
		nowScene=p;
	}




};

