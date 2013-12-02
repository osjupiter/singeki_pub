#pragma once
#include"DxLib.h"
#include"SceneSwicher.h"
#include"SceneManager.h"


	SceneSwitcher::~SceneSwitcher(){}
	SceneSwitcher::SceneSwitcher(SN_Ptr b,SN_Ptr a){

		afterScene=a;
		beforeScene=b;
		nowScene=b;

		phase=0;
		dgree=SWAPTIME;


	}
	void SceneSwitcher::main(){
		dgree--;
		if(dgree<=0){
			if(phase==0){
				phase=1;
				nowScene=afterScene;
				dgree=SWAPTIME;
			}else{
				SceneManager::getIns()->changeScene(afterScene);
				afterScene.reset();
				beforeScene.reset();
				nowScene.reset();

			}
		}

	}
	void SceneSwitcher::draw(){
		int tdg=255/KIETIME*(phase==0)?(SWAPTIME-dgree):dgree;
		DrawBlendGraph(0,0,Images::get("pic/black.jpg"),FALSE,Images::get("pic/blend.jpg"),tdg,64);
		nowScene->draw();
	}