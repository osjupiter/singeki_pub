#pragma once
#include"DxLib.h"
#include<vector>
#include<list>
#include"SceneNode.h"
#include <memory>
#include<algorithm>
#include"Scene.h"
#include "SceneSwicher.h"

#define SWAPWAIT 60
#define SWAPTIME 30


class SceneManager
{
	static SceneManager ins;
	SN_Ptr nowScene;


public:
	SceneManager(void){}

	static SceneManager* getIns(){return &ins;}

	void loop(){
		nowScene->main();
		nowScene->render();
	}

	void title(){
		SN_Ptr p(new TitleScene());
		nowScene=p;
	}

	void switchScene(SN_Ptr p){
		SN_Ptr s(new SceneSwitcher(nowScene,p));
		nowScene=s;
	}
	void changeScene(SN_Ptr s){
		nowScene=s;
	}




};

